#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "sort.h"

int ivector_length(int *v, int n)
{
    int sum;

    sum = 0;
    for (int i = 0; i < n; i++)
        sum += (v[i] < 0) ? -v[i] : v[i];

    return sum;
}

/*
 * insertion sort
 */
void insertion_sort(int **A, int n, int l, int r)
{
    int i;
    int *key;

    for (int j = l + 1; j <= r; j++)
    {
        key = A[j];
        i = j - 1;

        while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
            A[i + 1] = A[i];
            i = i - 1;
        }

        A[i + 1] = key;
    }
}

/*
*   TO IMPLEMENT: Improved Insertion Sort for problem 1.
*/
void insertion_sort_im(int **A, int n, int l, int r)
{
    int i;
    int *key;

    int sumArrayLength = r - l + 1;

    int sumArr[sumArrayLength];

    //precomputing vector length
    for (int iterator = 0; iterator < sumArrayLength; iterator++)
    {
        sumArr[iterator] = ivector_length(A[iterator], n);
    }

    for (int j = l + 1; j <= r; j++)
    {
        key = A[j];
        i = j - 1;
        int sumKey = sumArr[j];
        while ((i >= l) && sumArr[i] > sumKey)
        {
            A[i + 1] = A[i];
            sumArr[i + 1] = sumArr[i];
            i = i - 1;
        }

        A[i + 1] = key;
        sumArr[i + 1] = sumKey;
    }
}

void merge(int sumArr[], int **ptrArr, int startIndex, int midIndex, int endIndex)
{

    //we will simultanesously sort our pointer array with sum array
    int leftArrLength = midIndex - startIndex + 1;
    int rightArrLength = endIndex - midIndex;

    int leftArr[leftArrLength], rightArr[rightArrLength];
    int **leftPtrArr = new int *[leftArrLength], **rightPtrArr = new int *[rightArrLength];

    for (int leftArrIterator = 0; leftArrIterator < leftArrLength; leftArrIterator++)
    {
        leftArr[leftArrIterator] = sumArr[startIndex + leftArrIterator];
        leftPtrArr[leftArrIterator] = ptrArr[startIndex + leftArrIterator];
    }

    for (int rightArrIterator = 0; rightArrIterator < rightArrLength; rightArrIterator++)
    {
        rightArr[rightArrIterator] = sumArr[midIndex + rightArrIterator + 1];
        rightPtrArr[rightArrIterator] = ptrArr[midIndex + rightArrIterator + 1];
    }

    int marker1, marker2, finalArrMarker;

    marker1 = 0;
    marker2 = 0;
    finalArrMarker = startIndex;

    //swap till smallest array size
    while (marker1 < leftArrLength && marker2 < rightArrLength)
    {
        if (leftArr[marker1] <= rightArr[marker2])
        {
            sumArr[finalArrMarker] = leftArr[marker1];
            ptrArr[finalArrMarker] = leftPtrArr[marker1];
            marker1++;
        }
        else
        {
            sumArr[finalArrMarker] = rightArr[marker2];
            ptrArr[finalArrMarker] = rightPtrArr[marker2];
            marker2++;
        }

        finalArrMarker++;
    }

    //add remaining elements
    while (marker1 < leftArrLength)
    {
        sumArr[finalArrMarker] = leftArr[marker1];
        ptrArr[finalArrMarker] = leftPtrArr[marker1];
        marker1++;
        finalArrMarker++;
    }

    //add remaining elements
    while (marker2 < rightArrLength)
    {
        sumArr[finalArrMarker] = rightArr[marker2];
        ptrArr[finalArrMarker] = rightPtrArr[marker2];
        
        marker2++;
        finalArrMarker++;
    }
}

void mergeSort(int sumArr[], int **ptrArr, int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int midIndex = (startIndex + endIndex) / 2;
        mergeSort(sumArr, ptrArr, startIndex, midIndex);
        mergeSort(sumArr, ptrArr, midIndex + 1, endIndex);
        merge(sumArr, ptrArr, startIndex, midIndex, endIndex);
    }
}

/*
*   TO IMPLEMENT: Improved Merge Sort for problem 2.
*/
void merge_sort(int **A, int n, int p, int r)
{

    int sumArrayLength = r - p + 1;

    int sumArr[sumArrayLength];

    //precomputing vector length
    for (int iterator = 0; iterator < sumArrayLength; iterator++)
    {
        sumArr[iterator] = ivector_length(A[iterator], n);
    }

    mergeSort(sumArr, A, 0, sumArrayLength - 1);
}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int **A, int n, int l, int r)
{
    for (int i = l + 1; i <= r; i++)
        if (ivector_length(A[i - 1], n) > ivector_length(A[i], n))
            return false;
    return true;
}

/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int **create_ivector(int n, int m)
{
    int **iv_array;

    iv_array = new int *[m];
    for (int i = 0; i < m; i++)
        iv_array[i] = new int[n];

    return iv_array;
}

void remove_ivector(int **iv_array, int m)
{
    for (int i = 0; i < m; i++)
        delete[] iv_array[i];
    delete[] iv_array;
}

int **create_sorted_ivector(int n, int m)
{
    int **iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            iv_array[i][j] = (i + j) / n;

    return iv_array;
}

int **create_reverse_sorted_ivector(int n, int m)
{
    int **iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            iv_array[i][j] = ((m - i) + j) / n;

    return iv_array;
}

int **create_random_ivector(int n, int m, bool small)
{
    random_generator rg;
    int **iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            rg >> iv_array[i][j];
            if (small)
                iv_array[i][j] %= 100;
            else
                iv_array[i][j] %= 65536;
        }

    return iv_array;
}
