#include "sequence.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

const int SEQUENCE_MAXLEN = 1024;

// sequence_init() creates and returns an initialized seq to be empty
//   with maximum capacity SEQUENCE_MAXLEN
struct sequence sequence_init(){
    struct sequence seq = {0, SEQUENCE_MAXLEN};
    return seq;
}

// sequence_length(seq) returns the number of items in seq
int sequence_length(const struct sequence seq) {
    return seq.len;
}

// sequence_item_at(seq, pos) returns the item in seq at position pos
// requires: 0 <= pos < sequence_length(seq)
int sequence_item_at(const struct sequence seq, int pos){
    return seq.data[pos];
}

// sequence_insert_at(seq, pos, val) inserts(adds) a new item with value val
//   at position pos in seq
// note: changes the position of items that were at position >= pos
// requires: 0 <= pos <= sequence_length(seq) < SEQUENCE_MAXLEN
struct sequence sequence_insert_at(struct sequence seq, int pos, int val){
    for (int i=seq.len; i>pos; i--){
        seq.data[i] = seq.data[i-1];
    }
    seq.data[pos] = val;
    seq.len++;
    return seq;
}

// sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the updated sequence
// note: changes the position of items that were at position > pos
// requires: 0 <= pos < sequence_length(seq)
struct sequence sequence_remove_at(struct sequence seq, int pos){
    for (int i=pos; i<seq.len; i++){
        seq.data[i] = seq.data[i+1];
    }
    seq.len--;
    return seq;
}

// sequence_equiv(seq1, seq2) determines if seq1 and seq2 are equivalent
//   (they both have the same length and have identical sequences of items)
bool sequence_equiv(const struct sequence seq1, const struct sequence seq2){
    if (seq1.len != seq2.len){
        return false;
    }

    for (int i=0; i<seq1.len; i++){
        if (seq1.data[i] != seq2.data[i]){
            return false;
        }
    }

}

// sequence_print(seq) prints out the items in seq
//   using the format: "[item_0,item_1,...,item_last]\n"
//   or "[empty]\n"
// examples: [1,3,7]
//           [42]
//           [empty]
// effects: produces output
void sequence_print(const struct sequence seq){
    if (seq.len == 0){
        printf("[empty]\n");
    }
    else{
        printf("[%d", seq.data[0]);
        for (int i=1; i<seq.len; i++){
            printf(",%d", seq.data[i]);
        }
        printf("]\n");
    }
}


// sequence_append(seq1, seq2) returns a new sequence with all items from seq1 
//     followed by all items from seq2
// requires: sequence_length(seq1) + sequence_length(seq2) <= SEQUENCE_MAXLEN
struct sequence sequence_append(struct sequence seq1, const struct sequence seq2) {
    struct sequence ret = { seq1.len + seq2.len , SEQUENCE_MAXLEN};

    for (int i=0; i<seq1.len; i++){
        ret.data[i] = seq1.data[i];
    }
    for (int i=0; i<seq2.len; i++){
        ret.data[i + seq1.len] = seq2.data[i];
    }

    return ret;
}

// sequence_remove_dups(seq) creates a new copy of seq after removeing all duplicates from seq
//   (keeping each first occurrence)
// examples: [1,3,7] => [1,3,7]
//           [1,1,3,1,7,1,3] => [1,3,7]
struct sequence sequence_remove_dups(struct sequence seq){
    struct sequence ret = {0, SEQUENCE_MAXLEN};

    for (int i=0; i<seq.len; i++){
        bool dup = false;
        for (int j=0; j<ret.len; j++){
            dup = dup || (ret.data[j] == seq.data[i]);
        }

        if (!dup){
            ret.data[ret.len] = seq.data[i];
            ret.len++;
        }
    }

    return ret;
}
