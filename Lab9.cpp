#include <iostream>
#include <cstdlib>

using namespace std;

void lomuto(int arr[20],int low, int high)
{
    int s=low,d=high;
    int loc=low-1;
    int pivot=arr[high];
    while (low<=high)
    {
        while (arr[low]>pivot)
           low++;
        loc++;
        swap(arr[low],arr[loc]);
        low++;
    }
        if (loc>s)
            lomuto(arr,s,loc-1);
        if (loc<d)
            lomuto (arr,loc+1,d);
}


void quick(int arr[20],int low,int high)
{
    int m=low+rand()%(high-low+1);
    swap (arr[m],arr[high]);
    lomuto(arr,low,high);
}

void print(int arr[20],int size_arr)
{
    int i;
    for (i=1;i<=size_arr;i++)
        cout<<arr[i]<<' ';
}

int main()
{
    int arr[20];
    int size_arr;
    cout<<"Lungimea vectorului este: ";
    cin>>size_arr;
    for (int i=1;i<=size_arr;i++)
    {
        cout<<"Elementul "<<i<<" este: ";
        cin>>arr[i];
    }
    quick(arr,1,size_arr);
    cout<<"Vectorul sortat este: ";
    print(arr,size_arr);
    return 0;
}
