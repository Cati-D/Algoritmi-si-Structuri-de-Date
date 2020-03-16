#include <iostream>
#include <cstdlib>

using namespace std;

#define N 1000000
#define NUM 10

void insertionSort(int arr[], int low, int n)
{
    for (int i=low+1;i<=n;i++)
    {
        int value=arr[i];
        int j=i;
        while (j>low && arr[j-1]>value)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=value;
    }
}

int Partition(int a[], int low, int high)
{
    int pivot=a[high];
    int pIndex= low;
    for (int i=low;i<high;i++)
    {
        if (a[i]<= pivot)
        {
            swap(a[i],a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex],a[high]);
    return pIndex;
}

void QuickSort(int a[], int low, int high)
{
    if(low >= high)
        return;
    int pivot=Partition(a,low,high);
    QuickSort(a,low,pivot-1);
    QuickSort(a,pivot+1,high);
}

void optimizedQuickSort(int A[], int low, int high)
{
    while (low<high)
    {
        if(high-low < 10)
        {
            insertionSort(A,low,high);
            break;
        }
        else
        {
            int pivot=Partition(A,low,high);
            if (pivot-low < high-pivot) {
                optimizedQuickSort(A,low,pivot-1);
                low=pivot+1;
            } else {
                optimizedQuickSort(A,pivot+1,high);
                high=pivot-1;
            }
        }
    }
}

int main()
{
    int arr[N], dup[N];
    double t1=0.0,t2 =0.0;
    for(int i=0;i<NUM;i++)
    {
        for (int i=0;i<N;i++)
            dup[i]=arr[i]=rand() % 100000;
    }
    return 0;
}
