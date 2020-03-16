#include <iostream>

using namespace std;

int n;

struct nod
{
    int info;
    nod *next;
};

nod *coada, *p,*ultim;

void push (int a, nod *coada)
{
    ultim->info=a;
    p=new nod;
    ultim->next=p;
    ultim=p;
}

int pop (nod *coada)
{
    int aux=coada->info;
    p=coada->next;
    delete coada;
    coada=p;
    return aux;
}

int peek (nod *coada)
{
    return coada->info;
}

bool empty(nod *coada)
{
    return (coada==NULL);
}

int search(int a, nod *coada)
{
    int nr=0;
    p=coada;
    while (p!=NULL)
       {
           nr++;
        if (coada->info==a)
            return nr;
        p=p->next;
       }
return -1;
}

void afiseaza(nod *coada)
{
    p=coada;
    while (p!=NULL)
    {
        cout<<p->info<<' ';
        p=p->next;
    }
}

void eliberare(nod *coada)
{
    p=coada->next;
    while (p!=NULL)
    {
        delete coada;
        coada=p;
        p=p->next;
    }
}
int main()
{
    int x;
    cout<<"n=";
    cin>>n;
    coada=new nod;
    ultim=coada;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        push(x,coada);
    }
    pop(coada);
    //cout<<"Coada dupa eliminarea primului element este: ";afiseaza(coada);cout<<endl;
    cout<<"Este coada goala? "<<empty(coada)<<endl;
    cout<<"Se gaseste elementul 2 in coada? "<<search(2,coada)<<endl;
    eliberare(coada);
    return 0;
}
