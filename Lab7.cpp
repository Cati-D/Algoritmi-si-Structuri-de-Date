#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *st;
    nod *dr;
};

nod *t;

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

void srd(nod *t)
{
    if (t)
    {
        srd(t->st);
        cout<<t->info<<' ';
        srd(t->dr);
    }
}

void aflu_index(nod *t,int &index)
{
    if (t)
    {
        srd(t->st);
        index++;
        srd(t->dr);
    }
}

int main()
{
    //Problema 3
    t=NULL;
    int n;
    cout<<"n=";
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cout<<"nr este ";
        cin>>x;
        adaug(x);
    }
    srd(t);

    //problema 4

    int index=1;
    aflu_index(t,index);




    return 0;
}
