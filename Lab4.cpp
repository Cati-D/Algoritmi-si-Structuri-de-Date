#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *prima, *pa, *ultima, *primb, *pb, *ultimb, *primc, *pc, *ultimc;

int n,m;

void AddA(int x)
{
    pa=new nod;
    pa->info=x;
    pa->next=NULL;
    if (prima==NULL)
        prima=ultima=pa;
    else
    {
        ultima->next=pa;
        ultima=pa;
    }
}

void CitireA()
{
    int x;
    prima=new nod;
    prima=NULL;
    for (int i=1; i<=n; i++)
    {
        cout<<"elementul "<<i<<" este: ";
        cin>>x;
        AddA(x);
    }
}

void AfisareA()
{
    pa=prima;
    while(pa!=NULL)
    {
        cout<<pa->info<<' ';
        pa=pa->next;
    }
}

void EliberareA()
{
    pa=prima;
    while(prima!=NULL)
    {
        delete prima;
        prima=pa;
        pa=pa->next;
    }
}

//Problema 1-crearea unei liste B
void CreareB()
{
    pa=prima;
    for (int i=0; i<n; i++)
    {
        pb=new nod;
        pb->next=NULL;
        pb->info=pa->info;
        if (primb==NULL)
            primb=ultimb=pb;
        else
        {
            if(pb->info<primb->info)
            {
                pb->next=primb;
                primb=pb;
            }
            else
            {
                nod *pb1=primb->next;
                while (pb1!=NULL&&(pb->info>pb1->info))
                    pb1=pb1->next;
                if (pb1!=NULL)
                {
                    pb->next=pb1->next;
                    pb1->next=pb;
                }
                else
                {
                    ultimb->next=pb;
                    ultimb=pb;
                }
            }
        }
        pa=pa->next;
    }
}

void AfisareB()
{
    pb=primb;
    while (pb!=NULL)
    {
        cout<<pb->info<<' ';
        pb=pb->next;
    }
}

void EliberareB()
{
    pb=primb->next;
    while (pb!=NULL)
    {
        delete primb;
        primb=pb;
        pb=pb->next;
    }
}

//ordonarea listei A
void OrdonareA()
{
    pa=prima->next;
    nod *aux=prima;
    while (aux->next!=ultima)
    {
        aux->next=pa->next;
        pa->next=prima;
        prima=pa;
        pa=aux->next;
    }
    ultima->next=prima;
    prima=ultima;
    aux->next=NULL;
    ultima=aux;
}

//Problema 2
void AddB(int x)
{
    pb=new nod;
    pb->info=x;
    pb->next=NULL;
    if (primb==NULL)
        primb=ultimb=pb;
    else
    {
        ultimb->next=pb;
        ultimb=pb;
    }
}
void CitireB()
{
    int x;
    primb=new nod;
    primb=NULL;
    for (int i=1; i<=m; i++)
    {
        cout<<"elementul cu numarul "<<i<<" este: ";
        cin>>x;
        AddB(x);
    }
}

void CreareC()
{
    pa=prima;
    pb=primb;
    primc=new nod;
    primc=NULL;
    while(pa!=NULL || pb!=NULL)
    {
        pc=new nod;
        pc->next=NULL;
        if (pa->info<pb->info)
        {
            pc->info=pa->info;
            if (primc==NULL)
                primc=ultimc=pc;
            else
            {
                ultimc->next=pc;
                ultimc=pc;
            }
            pa=pa->next;
        }
        else
        {
            pc->info=pb->info;
            if (primc==NULL)
                primc=ultimc=pc;
            else
            {
                ultimc->next=pc;
                ultimc=pc;
            }
            pb=pb->next;
        }

    }
    while (pa!=NULL)
    {
        pc=new nod;
        pc->info=pa->info;
        ultimc->next=pc;
        ultimc=pc;
    }
    while (pb!=NULL)
    {
        pc=new nod;
        pc->info=pb->info;
        ultimc->next=pc;
        ultimc=pc;
    }

}

void AfisareC()
{
    pc=primc;
    while (pc!=NULL)
    {
        cout<<pc->info<<' ';
        pc=pc->next;
    }
}

void EliberareC()
{
    pc=primc;
    while (primc!=NULL)
    {
        delete primc;
        primc=pc;
        pc=pc->next;
    }
}

//Problema 3
void AddC(int x)
{
    pc=new nod;
    pc->info=x;
    pc->next=NULL;
    if (primc==NULL)
        primc=ultimc=pc;
    else
    {
        ultimc->next=pc;
        ultimc=pc;
    }
}
void CitireC()
{
    int x;
    primc=new nod;
    primc=NULL;
    for (int i=1; i<=n; i++)
    {
        cout<<"elementul cu numarul "<<i<<" este: ";
        cin>>x;
        AddC(x);
    }
}

void CreareAB()
{
    pc=primc;
    prima=new nod;
    prima=NULL;
    primb=new nod;
    primb=NULL;
    for (int i=1; i<=n; i+=2)
    {
        pa=new nod;
        pa->info=pc->info;
        pa->next=NULL;
        if(prima==NULL)
            prima=ultima=pa;
        else
        {
            ultima->next=pa;
            ultima=pa;
        }
        pc=pc->next;
        if (pc!=NULL)
            pc=pc->next;
    }
    pc=primc->next;
    for (int i=2; i<=n; i+=2)
    {
        pb=new nod;
        pb->info=pc->info;
        pb->next=NULL;
        if(primb==NULL)
            primb=ultimb=pb;
        else
        {
            ultimb->next=pb;
            ultimb=pb;
        }
        pc=pc->next;
        if (pc!=NULL)
            pc=pc->next;
    }
}

int main()
{
    int i;
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    cout<<"Alegeti problema dorita: ";
    cin>>i;
    switch (i)
    {
    case 1:
        CitireA();
        cout<<"Alegeti metoda(1/2): ";
        int q;
        cin>>q;
        if (q==1)
        {
            primb=new nod;
            primb=NULL;
            CreareB();
            AfisareB();
            EliberareB();
        }
        else
        {
            OrdonareA();
            AfisareA();
        }
        EliberareA();
        break;
    case 2:
        CitireA();
        CitireB();
        CreareC();
        AfisareC();
        EliberareA();
        EliberareB();
        EliberareC();
        break;
    case 3:
        CitireC();
        CreareAB();
        AfisareA();
        cout<<endl;
        AfisareB();
        EliberareA();
        EliberareB();
        EliberareC();
        break;
    default:
        cout<<"switch incorect";
    }
    return 0;
}
