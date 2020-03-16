#include <iostream>

using namespace std;

int cautare_secv(int v[],int n,int x)
{
    for (int i=0; i<n; i++)
        if (v[i]==x)
            return i;
    return -1;
}

int cautare_bin(int v[],int st, int dr, int x)
{
    while (st<=dr)
    {
        int mij=(st+dr)/2;//mij=st+(dr-st)/2;
        if (v[mij]==x)
            return mij;
        if (v[mij]>x)
            dr=mij-1;
        else
            st=mij+1;
    }
    return -1;
}

void BubbleSort(int v[],int n)
{
    bool ordonat;
    int i;
    do
    {
        ordonat=true;
        for (i=0; i<n-1; i++)
            if (v[i]>v[i+1])
            {
                swap(v[i],v[i+1]);
                ordonat=false;
            }
    }
    while (ordonat==false);
}

void interschimbare1(int v[],int n)
{
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (v[i]>v[j])
                swap(v[i],v[j]);
}

void interschimbare2(int v[],int n)
{
    for (int j=1; j<n; j++)
        for (int i=n-1; i>=j; i--)
            if (v[i-1]>v[i])
                swap(v[i],v[i-1]);
}

void insertie_directa(int v[], int n)
{
    for (int i=1; i<n; i++)
    {
        int x=v[i];
        int j=i-1;
        while (j>=0&&v[j]>x)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=x;
    }
}

void selectie(int v[],int n)
{
    for (int i=0; i<n-1; i++)
    {
        int min=v[i],pozmin=i;
        for (int j=i+1; j<n; j++)
            if (v[j]<min)
            {
                min=v[j];
                pozmin=j;
            }
        v[pozmin]=v[i];
        v[i]=min;
    }
}

void afisare(int v[],int n)
{
    for (int i=0; i<n; i++)
        cout<<v[i]<<' ';

}

int main()
{
    int a[100]= {5,1,2,4,6,3};
    int n=6;
    afisare(a,6);
    cout<<endl;
    cout<<cautare_secv(a,6,4);
    cout<<endl;
    cout<<cautare_secv(a,6,10);
    cout<<endl;
    BubbleSort(a,6);
    cout<<cautare_bin(a,0,5,4);
    cout<<endl;
    cout<<cautare_bin(a,0,5,10);
    cout<<endl;
    int b[100]= {5,1,2,4,6,3};
    interschimbare1(b,6);
    afisare(b,6);
    cout<<endl;
    int c[100]= {5,1,2,4,6,3};
    interschimbare2(c,6);
    afisare(c,6);
    cout<<endl;
    int d[100]= {5,1,2,4,6,3};
    insertie_directa(d,6);
    afisare(d,6);
    cout<<endl;
    int e[100]= {5,1,2,4,6,3};
    selectie(e,6);
    afisare(e,6);
    return 0;
}
