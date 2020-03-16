//MERGESORT
#include <stdio.h>
#include <stdlib.h>

int *b;

void merge(int *a, int left, int mid, int right)
{
    int l1,l2,i;
    for(l1=left,l2=mid+1,i=left;l1<=mid && l2<=right;i++)
    {
        if(a[l1]<=a[l2])
            b[i]=a[l1++];
        else
            b[i]=a[l2++];
    }
    while(l1<=mid)
        b[i++]=a[l1++];
    while(l2<=right)
        b[i++]=a[l2++];
    for (i=left;i<=right;i++)
    a[i]=b[i];
}

void MergeSort(int arr[],int left, int right)
{
    if (left<right)
    {
        int mid=left+(right-left)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void afisare(int A[], int n)
{
    int i;
    for (i=1;i<=n;i++)
        printf("%d ",A[i]);
}

int main()
{
    int *arr;
    arr=(int)malloc(100*sizeof(int));
    b=(int)malloc(100*sizeof(int));
    int i;
    printf("Doriti sa cititi numere?(nu-0/Daca da,introduceti pozitia acestuia in vector in ordinea corespunzatoare): \n");
    scanf("%d",&i);
    while (i)
    {
        int x;
        scanf("%d",&x);
        arr[i]=x;
        printf("Doriti sa cititi numere?(indicele pozitiei urmatoare-da/0-nu)\n");
        scanf("%d",&i);
    }
    int arr_size=i;
    printf("vectorul initial era: ");
    afisare(arr,arr_size);

    MergeSort(arr,0,arr_size-1);

    printf("Vectorul sortat este: ");
    afisare(arr,arr_size);

    return 0;
}
