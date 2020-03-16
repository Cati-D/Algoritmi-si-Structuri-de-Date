#include <iostream>

using namespace std;

int n,m;
char w[256];

struct nod
{
    char info;
    nod* next;
};

nod *stiva, *p, *ultim;

//Problema 2
void push(char x)
{
    p=new nod;
    p->next=NULL;
    p->info=x;
    if (stiva==NULL)
        stiva=ultim=p;
    else
    {
        ultim->next=p;
        ultim=p;
    }
}

void pop(nod *stiva)
{
    p=stiva->next;
    delete stiva;
    stiva=p;
}

bool Empty(nod *stiva)
{
    return (stiva==NULL);
}

void CitireW()
{
    cout<<"n=";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cout<<"w["<<i<<"]=";
        cin>>w[i];
    }
}

bool CreareStiva(nod *stiva)
{
    stiva=new nod;
    stiva=NULL;
    push(w[0]);
    for (int i=1; i<n; i++)
    {
        if (stiva->info==w[i])
            push(w[i]);
        else
            pop(stiva);
    }
    return (Empty(stiva)==0);
}

void eliberare(nod *stiva)
{
    p=stiva;
    while (stiva!=NULL)
    {
        delete stiva;
        p=p->next;
        stiva=p;
    }
}

//Problema 3
int crearestv(int m, nod *stiva)
{
    stiva=new nod;
    char x;
    cout<<"x=";
    cin>>x;
    stiva->info=x;
    p=stiva;
    int nr=1;
    stiva->next=NULL;
    for (int i=1; i<m; i++)
    {
        cin>>x;
        if (s>0)
            if (p->info!=x)
                pop(stiva);
            else
                push(stiva);
        else
            return nr;

    }
    return 1;
}

int suma(int v[])
{


}

int main()
{
    cout<<"Alegeti problema dorita(2-4)"<<endl;
    cin>>i;
    switch (i)
    {
    case 2:
        CitireW();
        if (CreareStiva(stiva)==1)
            cout<<"nr de a este egal cu nr de b";
        else
            cout<<"nr de a nu este egal cu nr de b";
        eliberare(stiva);
        break;
    case 3:
        cin>>m;
        if (m%2==1)
            cout<<"Sirul nu este corect parantezat";
        else
        {
            if (crearestv(stiva)==1)
                cout<<"sirul este parantezat corect";
            else
                cout<<crearestv(stiva)>>" este pozitia pe care se afla prima paranteza')' care strica sirul";
        }
    case 4:

    }


    return 0;
}
