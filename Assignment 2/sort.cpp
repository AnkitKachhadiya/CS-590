#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

#include "sort.h"

using namespace std;

/* 
 * HW 2 part
 */
int string_compare(char *s1, char *s2)
{
    /*
 * We assume that s1 and s2 are non-null pointers
 */
    int i;

    i = 0;
    while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
        i++;

    if (s1[i] == s2[i])
        return 0;
    else
    {
        if (s1[i] < s2[i])
            return -1;
        else
            return 1;
    }
} /*>>>*/

void insertion_sort(char **A, int l, int r)
{
    int i;
    char *key;

    for (int j = l + 1; j <= r; j++)
    {
        key = A[j];
        i = j - 1;

        while ((i >= l) && (string_compare(A[i], key) > 0))
        {
            A[i + 1] = A[i];
            i = i - 1;
        }

        A[i + 1] = key;
    }
}

void insertion_sort_digit(char **A, int *A_len, int l, int r, int d)
{
    int i;
    char key;
    char *tempString;
    int tempLength;

    for (int j = l + 1; j <= r; j++)
    {
        key = A[j][d];

        //store the entire string instead of character
        tempString = A[j];

        //store the string length
        tempLength = A_len[j];

        i = j - 1;

        //ASCII comparison of the character
        while ((i >= l) && (A[i][d] > key))
        {
            A[i + 1] = A[i];
            A_len[i + 1] = A_len[i];
            i = i - 1;
        }

        A[i + 1] = tempString;
        A_len[i + 1] = tempLength;
    }
}

void counting_sort_digit(char **A, int *A_len, char **B, int *B_len, int n, int d)
{
    //used to store (auxiliary storage) the counter on index corressponding ASCII value of the string's d
    int counter[256] = {0};

    //increment the counts based on matched index with ASCII value
    for (int counterIterator = 0; counterIterator < n; counterIterator++)
    {
        //need to add 1 to overcome segmentation fault
        int nextAsciiValue = int(A[counterIterator][d]) + 1;
        counter[nextAsciiValue]++;
    }

    //cumulative sum
    for (int counterIterator = 1; counterIterator < 257; counterIterator++)
    {
        counter[counterIterator] += counter[counterIterator - 1];
    }

    //based on counter values store the original strings to sorted storage along with lengths
    for (int inputIterator = n - 1; inputIterator >= 0; inputIterator--)
    {
        int nextAsciiValue = int(A[inputIterator][d]) + 1;

        B[counter[nextAsciiValue] - 1] = A[inputIterator];
        B_len[counter[nextAsciiValue] - 1] = A_len[inputIterator];

        counter[nextAsciiValue]--;
    }

    //retransfer the sorted strings to original array for final result
    for (int inputIterator = 0; inputIterator < n; inputIterator++)
    {
        A[inputIterator] = B[inputIterator];
        A_len[inputIterator] = B_len[inputIterator];
    }
}

void radix_sort_is(char **A, int *A_len, int n, int m)
{
    int charPosition = m - 2;
    for (charPosition; charPosition >= 0; charPosition--)
    {
        insertion_sort_digit(A, A_len, 0, n - 1, charPosition);
    }
}

void radix_sort_cs(char **A, int *A_len, int n, int m)
{
    char **sortedArray;
    int *sortedArrayLength;

    //used for temporary storage
    sortedArray = new char *[n];
    sortedArrayLength = new int[n];

    int charPosition = m - 2;

    for (charPosition; charPosition >= 0; charPosition--)
    {
        counting_sort_digit(A, A_len, sortedArray, sortedArrayLength, n, charPosition);
    }
}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(char **A, int l, int r)
{
    for (int i = l + 1; i < r; i++)
        if (string_compare(A[i - 1], A[i]) > 0)
            return false;
    return true;
}
