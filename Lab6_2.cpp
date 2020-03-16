#include <iostream>

using namespace std;

struct nod
{
    int info;
    int prioritate;
    nod *next;
};

nod *prim, *p, *ultim, *s;
int n,MaxPrioritate;

void afisare()
{
    s=prim;
    while(s!=NULL)
    {
        cout<<"*"<<s->info<<" cu prioritatea "<<s->prioritate<<' ';
        s=s->next;
    }
}
void add(int elem,int prior)
{
    p=new nod;
    p->info=elem;
    p->prioritate=prior;
    if (prim==NULL)
        prim=ultim=p;
        else
        {
            s=prim;
            while (s->next->prioritate<=prior && s->next!=NULL)
                s=s->next;
            if (s->next==NULL)
                {ultim->next=s;
                ultim=s;
                }
                else
                {
                   nod *r=new nod;
                   r->next=s->next;
                   s->next=r;
                }

        }
    afisare();
}

void extragere( int MaxPrioritate)
{
    int j;
    for(int i=1; i<=MaxPrioritate; i++)
    {

    }
    afisare();
}

void citire()
{
    int elem,prior;
    MaxPrioritate=0;
    for(int i=1; i<=n; i++)
    {
        cout<<"elementul este ";
        cin>>elem;
        cout<<" iar prioritatea este ";
        cin>>prior;
        if (prior>MaxPrioritate)
            MaxPrioritate=prior;
        add(elem,prior);
        cout<<endl;
    }
}

int main()
{
    cout<<"n=";
    cin>>n;
    citire();
    extragere(MaxPrioritate);

    return 0;
}
