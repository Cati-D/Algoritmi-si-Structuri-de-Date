#include <iostream>

using namespace std;

int n;

struct nod
{
    int info;
    nod *next;
};

nod  *stiva, *p;

void push(int x,nod *stiva )
{
    stiva->info=x;
    p=new nod;
    p->next=stiva;
    stiva=p;
}

int pop(nod *stiva)
{
    int aux=stiva->info;
    nod *aux1=stiva;
    stiva=stiva->next;
    delete aux1;
    return aux;
}

int peek(nod *stiva)
{
    return stiva->info;
}

bool empty(nod *stiva)
{
    return (stiva==NULL);
}

int search(int a, nod *stiva)
{
    p=stiva;
    int nr=0;
    for (int i=1; i<n; i++)
    {
        if(p->info==a)
            return nr;
        else
        {
            p=p->next;
            nr++;
        }
    return -1;
    }
}
void afisare(nod *stiva)
{
    p=stiva;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}

void eliberare()
{
    p=stiva;
    while(stiva!=NULL)
    {
        delete stiva;
        stiva=p;
        p=p->next;
    }
}
int main()
{
    int x;
    stiva=new nod;
    stiva->next=NULL;
    cout<<"n=";
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        push(x,stiva);
        cout<<"elementul din varful stivei la pasul curent este: "<<peek(stiva)<<endl;
    }
    cout<<"elementul sters este "<<pop(stiva);
    cout<<endl;
    cout<<"Verfic este stiva goala "<<empty(stiva)<<endl;
    cout<<"Verific exista 2 in stiva"<<search(2,stiva)<<' ';
    eliberare();
    return 0;
}
