//Quick Sort
#include <iostream>
using namespace std;
int PARTITION(int A[], int low, int high)
{
    int pivot = A[low];
    int P = low + 1;
    int Q = high;
    int temp;
    while (P <= Q)
    {
        while (A[P] <= pivot && P <= high)
        {
            P = P + 1;
        }
        while (A[Q] > pivot)
        {
            Q = Q - 1;
        }
        if (P < Q)
        {
            temp = A[P];
            A[P] = A[Q];
            A[Q] = temp;
        }
    }
    temp = A[low];
    A[low] = A[Q];
    A[Q] = temp;
    return Q;
}
int main()
{
    int A[] = {25, 10, 15, 5, 30};
    int n = 5;
    int pos = PARTITION(A, 0, n - 1);
    cout << "Pivot position: " << pos << endl;
    cout << "Array after partition: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}

