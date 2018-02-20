#include <iostream>

//TODO remove recursion
int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p-1;
    int temp;
    for (int j=p; j<r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[r];
    A[r] = A[i+1];
    A[i+1] = temp;
    return i+1;
}

//TODO remove recursion
void quicksort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int main()
{
    int len = 100;
    int A[len] = {44, 40, 37, 10, 28, 12, 24, 94, 66, 2, 64, 70, 31, 16, 21, 27, 43, 42, 7, 58, 87, 69, 1, 68, 8, 96, 22, 18, 62, 35, 29, 52, 81, 17, 92, 48, 89, 56, 51, 84, 82, 36, 90, 25, 39, 4, 32, 71, 93, 95, 88, 14, 5, 78, 76, 97, 60, 74, 77, 20, 13, 33, 53, 46, 41, 72, 3, 54, 0, 15, 65, 9, 61, 47, 83, 26, 23, 55, 49, 45, 91, 85, 59, 80, 11, 19, 86, 38, 57, 63, 50, 34, 30, 75, 98, 73, 67, 99, 6, 79};
    quicksort(A, 0, len);
    for (int i = 0; i < len; ++i)
    {
        std::cout << A[i] << "\n";
    }
}
