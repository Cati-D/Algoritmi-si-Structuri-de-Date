#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;
};
nod *prim,*ultim,*p;

void add_sp(int val)
{
    p=new nod;
    p->info=val;
    p->next=NULL;
    ultim->next=p;
    ultim=p;

}

void add_inter(int val, nod *p)
{
    nod *aux=new nod;
    aux->info=val;
    aux->next=p->next;
    p->next=aux;


}

void add_fata_lista(int val)
{
    p=new nod;
    p->info=val;
    p->next=prim;
    prim=p;
}

void InsertionSort(int x)
{
        p=prim;
        if (prim->info>x)
            add_fata_lista(x);
        else
        {
            while (p->next!=NULL&&p->next->info<x)
                p=p->next;
            if (p->next!=NULL)
                add_inter(x,p);
            else
                add_sp(x);
        }
}

void afisare()
{
    p=prim;
    while (p->next!=NULL)
    {
        cout<<p->info<<' ';
        p=p->next;
    }
}

void stergere()
{
    p=prim;
    while (p->next!=NULL)
    {
        prim=p->next;
        delete p;
        p=prim;
    }
    delete p;
}
int main()
{
    int x,n,i;
    cout<<"n=";cin>>n;
    cout<<"x=";cin>>x;
    prim=new nod;
    nod *ultim=new nod;
    ultim->info=99999;
    ultim->next=NULL;
    prim->next=ultim;
    prim->info=x;
    for ( i=2; i<=n; i++)
    {
        cout<<"x=";cin>>x;
        InsertionSort(x);
    }
    afisare();
    stergere();


    return 0;
}
