
#include "data.h"

/*
 * Running time is insensitive to input
 * Data movement is minimal
 *
 * Swap count = N, compare count = N * (N - 1) / 2
 */
void selection_sort(Data seq[], int len) {
    int i, j;
    int min;

    for (i = 0; i < len - 1; i++) {

        // exchange seq[i] with the smallest one in seq[i+1...N]
        
        min = i;
        for (j = i + 1; j < len; j++) {
            if (compare(seq + j, seq + min) < 0)
                min = j;
        }

        if (min != i)
            swap(seq + min, seq + i);
    }
}

/*
 * Running time is dependent on the initial order, is good for partially sorted seq
 * 
 * Swap count = number of inversions, compare count is in [number of inversions, number of inversions + N - 1]
 * Best case (already in order): N - 1 compares, 0 swap
 *
 * When len is small, insertion sort is the best choice
 */ 
void insertion_sort(Data seq[], int len) {
    int i, j;

    for (i = 1; i < len; i++) {

        // insert seq[i] into seq[0..i]

        for (j = i; j > 0 && (compare(seq + j - 1, seq + j) > 0); j--) {
            swap(seq + j - 1, seq + j);
        }
    }
}

/*
 * Doing insertion sort for multiple times.
 */
void shell_sort(Data seq[], int len) {
    int i, j, k, h;

    h = 1;
    while (h < len / 3) h = h * 3 + 1;

    while (h) {

        // h array is increment array

        for (i = h; i < len; i++) {

            // use insertion sort to sort seq[i], seq[i + h], seq[i + 2h], ...

            for (j = i; j >= h && compare(seq + j - h, seq + j) > 0; j -= h)
                swap(seq + j - h, seq + j);
        }

        h /= 3;
    }
}

/*
 * The most attractive property is thet it gurrantees to sort any array in time proportional to NlogN
 *
 * The prime disadvantage is that it uses extra space proportional to N
 */
void merge();

void merge_sort(Data seq[], int len) {
    
}

/*
 */ 
void quick_sort(Data seq[], int len) {
    
}

/*
 */ 
void heap_sort(Data seq[], int) {
    
}

void main() {
    const int N = 10000;
    Data seq[N];

    int i;
    // for (i = 0; i < N; i++) { seq[i] = i;}
    for (i = 0; i < N; i++) { seq[i] = N - i;}

    resetProfiling();

    shell_sort(seq, N);
    assert(isSorted(seq, N));

    showProfiling();
    //showSeq(seq, N);
}
