#include "bank.h"

// CreateBank(money, maxLoan, loanInterest, transferFeeRate) allocates and
//   initializes a new Bank object with the given parameters.
// requires: none
// effects: allocates memory for a new Bank.
Bank* CreateBank(double money, double maxLoan,
                    double loanInterest, double transferFeeRate) {
    // Allocate bank
    Bank *bank = malloc(sizeof(Bank));
    assert(bank);
    // No accounts yet
    bank->accounts = NULL;
    bank->nAcc = 0;
    // Assign inputs
    bank->money = money;
    bank->maxLoan = maxLoan;
    bank->loanInterest = loanInterest;
    bank->transferFeeRate = transferFeeRate;

    return bank;
}

// OpenAccount(bank) creates a new account for the given bank.
// requires: bank is a valid Bank pointer.
// effects: allocates memory for a new Account, mutates bank.
Account* OpenAccount(Bank *bank) {

    bank->accounts = realloc(bank->accounts, (bank->nAcc + 1) * sizeof(Account*));

    bank->nAcc++;

    Account *new_acc = malloc(sizeof(Account));

    new_acc->id = bank->nAcc;
    new_acc->active = true;
    new_acc->balance = 0;
    new_acc->loan.active = false;
    new_acc->loan.amount = 0.0;
    new_acc->loan.interest = 1.0;

    new_acc->bank = bank;
    bank->accounts[bank->nAcc-1] = new_acc;

    return new_acc;
}

// Deposit(amount, account) adds the given amount to the account's balance.
// requires: account is a valid Account pointer.
// effects: mutates account.
void Deposit(double amount, Account *account) {
    account->balance += amount;    
}

// Withdraw(amount, account) subtracts the amount from the account's balance.
// requires: account is a valid Account pointer.
// effects: mutates account.
bool Withdraw(double amount, Account *account) {
    if (account->balance < amount) {
        return false;
    }

    account->balance -= amount;
    return true;
}

// TakeLoan(amount, account) allows an account to take a loan from its bank.
// requires: account is a valid Account pointer.
// effects: mutates account and its associated bank.
bool TakeLoan(double amount, Account *account) {
    if (!account->active || account->loan.active){
        return false;
    }
    if (amount > (account->bank->maxLoan) || amount > (account->bank->money)){
        return false;
    }

    account->bank->money -= amount;
    account->balance += amount;

    account->loan.active = true;
    account->loan.amount = amount;
    account->loan.interest = account->bank->loanInterest;

    return true;
}

// PayLoan(account) pays off an active loan from the account's balance.
// requires: account is a valid Account pointer.
// effects: mutates account and its associated bank.
bool PayLoan(Account *account) {
    if (!account->active || !account->loan.active) {
        return true;
    }
    double amount = account->loan.interest * account->loan.amount;
    bool success = Withdraw(amount, account);

    if (success) account->bank->money += amount;

    return success;
}

// Transfer(amount, sender, receiver) transfers money from a sender account
//   to a receiver account, applying a fee if banks are different.
// requires: sender and receiver are valid Account pointers.
// effects: mutates sender, receiver, and their associated banks.
bool Transfer(double amount, Account *sender, Account *receiver) {
    if (!sender->active || !receiver->active) {
        return false;
    }

    double transfer_fee = amount * sender->bank->transferFeeRate;
    bool success = Withdraw(amount + transfer_fee, sender);
    
    if (success) {
        sender->bank->money += transfer_fee;
        Deposit(amount, receiver);
    }

    return success;
}

// CollectLoanPayments(bank) attempts to collect payments for all active loans
//   from all accounts in the bank.
// requires: bank is a valid Bank pointer.
bool CollectLoanPayments(Bank *bank) {
    bool success = true;    
    for (int i=0; i<bank->nAcc; i++){
        success &= PayLoan(bank->accounts[i]);
    }
    return success;
}

// CloseAccount(account) pays off any active loan and deactivates the account.
// requires: account is a valid Account pointer.
// effects: mutates account and its associated bank.
bool CloseAccount(Account *account) {
    bool success = true;
    if (account->loan.active) {
        double amount = account->loan.amount;
        success = Withdraw(amount, account);

        if (success){
            account->bank->money += amount;

            account->loan.active = false;
            account->loan.amount = 0;
        }
        else {
            return false;
        }
    }

    account->active = false;
    account->balance = 0;

    return true;
}

// ForceDestroyBank(bank) frees all memory associated with a bank and its
//   accounts.
// requires: bank is a valid Bank pointer or NULL.
Bank* ForceDestroyBank(Bank *bank) {
    // Check if bank exists
    if (!bank)
        return NULL;
    // Just free the memory
    for (int i = 0; i < bank->nAcc; i++) {
                  free(bank->accounts[i]);
    }
    free(bank->accounts);
        
    free(bank);
    bank = NULL;
    return NULL;
}

// ShowAccount(account) prints the details of a given account.
// requires: account is a valid Account pointer.
// effects: produces output.
void ShowAccount(Account *account) {
    printf("Account #%d:\n", account->id);
    if (account->active) {
        printf("Balance: %.3f\n", account->balance);
        if (account->loan.active) {
            printf("Loaned %.3f with interest %f\n",
                account->loan.amount, account->loan.interest);
        }
    } else {
        printf("Inactive account\n");
    }
}

// ShowBank(bank) prints the details of a bank and all its accounts.
// requires: bank is a valid Bank pointer.
// effects: produces output.
void ShowBank(Bank *bank) {
    printf("BANK:\n");
    printf("Total money in bank: %.3f\n", bank->money);
    printf("Maximum loan offered: %.3f\n", bank->maxLoan);
    printf("Interest for loans: %f\n", bank->loanInterest);
    printf("Fee for a money transfer: %f\n", bank->transferFeeRate);
    
    for (int i = 0; i < bank->nAcc; i++) {
        ShowAccount(bank->accounts[i]);
        printf("----------------\n");
    }
}
