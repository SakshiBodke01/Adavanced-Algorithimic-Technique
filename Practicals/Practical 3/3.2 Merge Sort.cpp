//Merge Sort
#include <iostream>
using namespace std;
void MERGE(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[100];
    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            temp[k] = A[i];
            i++;
        }
        else
        {
            temp[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = A[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        A[x] = temp[x];
    }
}
void MERGE_SORT(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        MERGE_SORT(A, low, mid);
        MERGE_SORT(A, mid + 1, high);
        MERGE(A, low, mid, high);
    }
}
int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    MERGE_SORT(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}

