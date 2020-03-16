#include <iostream>

using namespace std;

void heapify(int v[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && v[l] > v[largest])
        largest = l;
    if (r < n && v[r] > v[largest])
        largest = r;
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heapSort(int v[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void printArray(int v[], int n)
{
    for (int i=0; i<n; ++i)
        cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    int v[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(v)/sizeof(v[0]);
    heapSort(v, n);
    cout << "vectorul sortat este: \n";
    printArray(v, n);
}
