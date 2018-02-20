#include <iostream>

//returns the parent of A[i]
int parent(int i)
{
    return (i-1)/2;
}

//returns the left child of A[i] (which may not exist)
int left(int i)
{
    return i*2 + 1;
}

//returns the right child of A[i] which may not exist
int right(int i)
{
    return i*2 + 2;
}

//TODO remove recursion
//maintains max-heap property
void maxheapify(int A[], int len, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < len && A[l] > A[i])
    {
        largest = l;
    }
    if (r < len && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxheapify(A, len, largest);
    }
}

//rearranges unordered array into a valid max-heap
void buildmaxheap(int A[], int len)
{
    for (int i = (len-1)/2; i >= 0; i--)
    {
        maxheapify(A, len, i);
    }
}

//performs sort on the array A
void heapsort(int A[], int len)
{
    buildmaxheap(A, len);
    int temp;
    for (int i = len-1; i >= 1; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        maxheapify(A, i, 0);
    }
}

int main()
{
    int len = 100;
    int A[len] = {44, 40, 37, 10, 28, 12, 24, 94, 66, 2, 64, 70, 31, 16, 21, 27, 43, 42, 7, 58, 87, 69, 1, 68, 8, 96, 22, 18, 62, 35, 29, 52, 81, 17, 92, 48, 89, 56, 51, 84, 82, 36, 90, 25, 39, 4, 32, 71, 93, 95, 88, 14, 5, 78, 76, 97, 60, 74, 77, 20, 13, 33, 53, 46, 41, 72, 3, 54, 0, 15, 65, 9, 61, 47, 83, 26, 23, 55, 49, 45, 91, 85, 59, 80, 11, 19, 86, 38, 57, 63, 50, 34, 30, 75, 98, 73, 67, 99, 6, 79};
    heapsort(A, len);
    for (int i = 0; i < len; ++i)
    {
        std::cout << A[i] << "\n";
    }
}
