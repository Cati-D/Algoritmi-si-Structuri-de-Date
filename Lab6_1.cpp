#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *precedent;
    nod *next;
};

nod *prim, *p,*q, *ultim;
int n;

void frnt(int x)
{
    p=new nod;
    p->precedent==NULL;
    p->info=x;
    p->next=NULL;
    if (prim==NULL)
        prim=ultim=p;
    else
    {
        p->next=prim;
        prim->precedent=p;
        prim=p;
    }
}

void sfarsit(int x)
{
    p=new nod;
    p->precedent=NULL;
    p->next=NULL;
    p->info=x;
    if (prim==NULL)
        prim=ultim=p;
    else
    {
        ultim->next=p;
        p->precedent=ultim;
        ultim=p;
    }
}

//adaug elementul in fata unei valori
void mid(int x,int val)
{
    if (prim->info==val)
        frnt(x);
    else
    {
        p=prim->next;
        while(p->next!=NULL&& p->info!=val)
            p=p->next;
        if (p->next=NULL)
            sfarsit(x);
        else
        {
            nod *q=new nod;
            q->next=p;
            q->precedent=p->precedent;
            p=p->precedent;
            p->next=q;
            p=q->next;
            p->precedent=q;
        }
    }
}

void afisaref()
{
    p=prim;
    while(p!=NULL)
    {
        cout<<p->info<<' ';
        p=p->next;
    }
}

void afisareb()
{
    p=ultim;
    while (p->precedent!=NULL)
    {
        cout<<p->info<<' ';
        p=p->precedent;
    }
    cout<<p->info<<' ';
}

void stergelpoz(int poz)
{
    if (poz==1)
    {
        p=prim;
        prim=prim->next;
        prim->precedent=NULL;
        delete p;
    }
    else
    {
        p=prim->next;
        int i=2;
        while (poz!=i)
        {
            p=p->next;
            i++;
        }
        if (i==n)
        {
            p=ultim;
            ultim=ultim->precedent;
            ultim->next=NULL;
            delete p;
        }
        else
        {
            nod *q=p;
            p=p->precedent;
            p->next=q->next;
            q=q->next;
            p=q->precedent;
            q->precedent=p->precedent;
            delete p;
        }
    }
}

void stergelval(int val)
{
    if (prim->info==val)
    {
        p=prim;
        prim=prim->next;
        prim->precedent=NULL;
        delete p;
    }
    else
    {
        p=prim->next;
        while (p->next!=NULL&&p->info!=val)
            p=p->next;
        if (p->next==NULL)
        {
            ultim=p->precedent;
            delete p;
        }
        else
        {
            nod *q=p;
            p=p->precedent;
            p->next=q->next;
            q=q->next;
            p=q->precedent;
            q->precedent=p->precedent;
            delete p;
        }
    }
}

void eliberare()
{
    p=prim->next;
    while (p!=NULL)
    {
        delete prim;
        prim=p;
        p=p->next;
    }
}

int main()
{
    //Problema 1
    cout<<"n=";
    cin>>n;
    int x;
    prim=NULL;
    for (int i=0; i<n; i++)
    {
        cout<<"elementul este ";
        cin>>x;
        sfarsit(x);
    }
    cout<<"Adauga un element la inceputul listei ";
    cin>>x;
    frnt(x);
    cout<<"Afisare incepand cu prim ";
    afisaref();
    cout<<endl<<"Adaug elemntul x in fata unei val ";
    cout<<"x=";
    cin>>x;
    cout<<"val=";
    int val;
    cin>>val;
    mid(x,val);
    cout<<"Afisare lista incepand cu prim ";
    afisaref();
    cout<<endl<<"Stergerea unui element stiind numarul de ordine ";
    cin>>x;
    stergelpoz(x);
    afisaref();
    cout<<endl<<"Stergerea unui element dupa valoarea data ";
    cin>>x;
    stergelval(x);
    cout<<"Afisare incepand cu ultimul element ";
    afisareb();
    eliberare();

    return 0;
}
