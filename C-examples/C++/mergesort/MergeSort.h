
#include <iostream>

using namespace std;

/**
   Sorts an array of integer using mergesort.
*/
class MergeSort
{
public:
    /**
      Merges two adjacent subranges of an array
      @param a the array with entries to be merged
      @param from the index of the first element of the
         first range
      @param mid the index of the last element of the
         first range
      @param to the index of the last element of the
         second range
    */
    static void merge(int* a, int from, int mid, int to)
    {
        int n = to - from + 1;
        // size of the range to be merged

        // merge both halves into a temporary array b
        int *b = new int[n];

        int i1 = from;
        // next element to consider in the first range
        int i2 = mid + 1;
        // next element to consider in the second range
        int j = 0;
        // next open position in b

        // as long as neither i1 nor i2 past the end, move
        // the smaller element into b
        while (i1 <= mid && i2 <= to) {
            if (a[i1] < a[i2]) {
                b[j] = a[i1];
                i1++;
            } else {
                b[j] = a[i2];
                i2++;
            }
            j++;
        }

        // note that only one of the two while loops
        // below is executed

        // copy any remaining entries of the first half
        while (i1 <= mid) {
            b[j] = a[i1];
            i1++;
            j++;
        }

        // copy any remaining entries of the second half
        while (i2 <= to) {
            b[j] = a[i2];
            i2++;
            j++;
        }

        // copy back from the temporary array
        for (j = 0; j < n; j++)
            a[from + j] = b[j];
    }

    /**
       Sorts a range of an array, using the merge sort
       algorithm.
       @param a the array to sort
       @param from the first index of the range to sort
       @param to the last index of the range to sort
    */
    static void mergeSort(int* a, int from, int to)
    {
        // return if only one element to sort
        if (from == to) return;

        int mid = (from + to) / 2;

        // sort the first and the second half
        mergeSort(a, from, mid);
        mergeSort(a, mid + 1, to);

        // merge the two sorted halves
        merge(a, from, mid, to);
    }

    /**
       Sorts an array, using the merge sort algorithm.
       @param a the array to sort
    */
    static void sort(int* a, int length)
    {
        mergeSort(a, 0, length - 1);
    }

}; //MergeSort

// set vim: set ts=3:
