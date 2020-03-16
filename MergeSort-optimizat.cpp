//MERGESORT OPTIMIZAT
#include <iostream>

using namespace std;

void InsertionSort(int *temp,int n)
{
    int i,key,j;
       for (i = 1; i < n; i++)
   {
       key = temp[i];
       j = i-1;
       while (j >= 0 && temp[j] > key)
       {
           temp[j+1] = temp[j];
           j = j-1;
       }
       temp[j+1] = key;
   }
}

void Merge(int *a, int low, int high, int mid)
{
    int i,j,k,temp[high-low+1];
    if (high-low+1<=10)
    {for (i=low;i<=high;i++)
            temp[i-low]=a[i];
        int n=high-low+1;
        InsertionSort(temp,n);
    for (i=low;i<=high;i++)
        a[i]=temp[i-low];
    }
    else
    {
    i=low;
    k=0;
    j=mid+1;
     while (i<=mid && j<=high)
    {
        if (a[i] < a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[i];
            k++;
            j++;
        }
    }
     while (i<=mid)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while (j<=high)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
     for (i=low;i<=high;i++)
        a[i]=temp[i-low];
    }

}

void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low<high)
    {
        mid=low+(high-low)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,high,mid);
        }
}

int main()
{
     int n,i;
    cout<<"Introduceti numarul de elemente ce doriti a fi sortate: ";
    cin>>n;

    int arr[n];
    for (i=0;i<n;i++)
    {
        cout<<"Elementul "<<i+1<<" este: ";
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1);

    //Printati vectorul sortat
    cout<<"Vectorul sortat este: ";
    for (i=0;i<n;i++)
        cout<<"->"<<arr[i];
    return 0;
}
