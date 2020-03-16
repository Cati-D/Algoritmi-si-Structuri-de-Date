#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *st;
    nod *dr;
    int LeftSize;
};

int *t;

void adaug (int x)
{
    nod *p=new nod,*caut1,*caut2;
    p->st=p->dr=NULL;
    p->info=x;
    if (t==NULL)
        t=p;
    else
    {
        caut1=t;
        while (caut1!=NULL)
        {
            if (x<caut1->info)
            {
                caut2=caut1;
                caut1=caut1->st;
            }
            else
            {
                caut2=caut1;
                caut1=caut1->dr;
            }
        }
        if (x<caut1->info)
            caut2->st=p;
        else
            caut2->dr=p;

    }

}

void creez_vector(nod *t,int v[100],int &m)
{
    if (t)
    {
        srd(t->st);
        v[m]=t->info;
        m++;
        srd(t->dr);
    }
}

int main()
{
     t=NULL;
    int n;
    cout<<"n=";
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cout<<"nr este";
        cin>>x;
        adaug(x);
    }
     int v[100],m=1,k1,k2;
    cout<<"k1=";
    cin>>k1;
    cout<<"k2=";
    cin>>k2;
    creez_vector(t,v,m);
    for (int i=1; i<=m; i++)
        if (v[i]>=k1&&v[i]<=k2)
            cout<<v[i]<<' ';
    return 0;
}
