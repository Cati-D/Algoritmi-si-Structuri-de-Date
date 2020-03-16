#include <iostream>

using namespace std;

int n,m;

struct nod
{
    int coloana;
    int info;
    nod *next;
};

nod *prima, *pa, *ultima, *primb, *pb, *ultimb, *primc, *pc, *ultimc;

struct lista_aditionala
{
    int linie;
    lista_aditionala *urmlinie;
    nod *primelem;
};

lista_aditionala *fronta, *pra, *backa, *frontb, *prb, *backb, *frontc, *prc, *backc;

void adda(int x, int y)
{
    pa=new nod;
    pa->info=x;
    pa->coloana=y;
    pa->next=NULL;
    if (prima==NULL)
        prima=ultima=pa;
    else
    {
        ultima->next=pa;
        ultima=pa;
    }
}

void citirea()
{
    cout<<"Matricea A"<<endl;
    int x;
    fronta=new lista_aditionala;
    fronta=NULL;
    for (int i=1; i<=n; i++)
    {
        cout<<"Linia "<<i<<" are elementele: "<<endl;
        for (int j=1; j<=m; j++)
        {
            cin>>x;
            if (x)
            {
                prima=new nod;
                prima=NULL;
                adda(x,j);
            }
        }
        pra=new lista_aditionala;
        pra->urmlinie=NULL;
        pra->primelem=prima;
        if (fronta==NULL)
            fronta=backa=pra;
        else
        {
            backa->urmlinie=pra;
            backa=pra;
        }
    }
}

void addb(int x, int y)
{
    pb=new nod;
    pb->info=x;
    pb->coloana=y;
    pb->next=NULL;
    if (primb==NULL)
        primb=ultimb=pb;
    else
    {
        ultimb->next=pb;
        ultimb=pb;
    }
}

void citireb()
{
    cout<<"Matricea B"<<endl;
    int x;
    frontb=new lista_aditionala;
    frontb=NULL;
    for (int i=1; i<=n; i++)
    {
        cout<<"Linia "<<i<<" are urmatoarele elemente: "<<endl;
        for (int j=1; j<=m; j++)
        {
            cin>>x;
            if (x)
            {
                primb=new nod;
                primb=NULL;
                addb(x,j);
            }
        }
        prb=new lista_aditionala;
        prb->urmlinie=NULL;
        prb->primelem=primb;
        if (frontb==NULL)
            frontb=backb=prb;
        else
        {
            backb->urmlinie=prb;
            backb=prb;
        }
    }
}

void crearec()
{
    pra=fronta;
    prb=frontb;
    frontc=new lista_aditionala;
    frontc=NULL;
    for (int i=1; i<=n; i++)
    {
        pa=pra->primelem;
        pb=prb->primelem;
        primc=new nod;
        primc=NULL;
        while (pa!=NULL || pb!=NULL)
        {
            pc=new nod;
            pc->next=NULL;
            if (pa->coloana<pb->coloana)
            {
                pc->info=pa->info;
                pc->coloana=pa->coloana;
                pa=pa->next;
            }
            else if (pb->coloana<pa->coloana)
            {
                pc->info=pb->info;
                pc->coloana=pb->coloana;
                pb=pb->next;
            }
            else
            {
                pc->info=pa->info+pb->info;
                pc->coloana=pa->coloana;
                pa=pa->next;
                pb=pb->next;
            }
            if (primc==NULL)
            {
                primc=ultimc=pc;
                prc->primelem=primc;
            }
            else
            {
                ultimc->next=pc;
                ultimc=pc;
            }
        }
        if (frontc==NULL)
            frontc=backc=prc;
        else
        {
            backc->urmlinie=prc;
            backc=prc;
        }
    }

}

void afisarec()
{
    for (prc=frontc; prc!=NULL; prc=prc->urmlinie)
        for(pc=frontc->primelem; pc!=NULL; pc=pc->next)
            cout<<"elemntul este "<<pc->info<<" si se afla pe coloana "<<pc->coloana<<endl;
}

void eliberarea()
{
    pra=fronta->urmlinie;
    while(fronta!=NULL)
    {
        prima=fronta->primelem;
        pa=prima->next;
        while (prima!=NULL)
        {
            delete prima;
            prima=pa;
            pa=pa->next;
        }
        delete fronta;
        fronta=pra;
        pra=pra->urmlinie;
    }
}

void eliberareb()
{
    prb=frontb->urmlinie;
    while(frontb!=NULL)
    {
        primb=frontb->primelem;
        pb=primb->next;
        while (primb!=NULL)
        {
            delete primb;
            primb=pb;
            pb=pb->next;
        }
        delete frontb;
        frontb=prb;
        prb=prb->urmlinie;
    }
}

void eliberarec()
{
    prc=frontc->urmlinie;
    while(frontc!=NULL)
    {
        primc=frontc->primelem;
        pc=primc->next;
        while (primc!=NULL)
        {
            delete primc;
            primc=pc;
            pc=pc->next;
        }
        delete frontc;
        frontc=prc;
        prc=prc->urmlinie;
    }
}

int main()
{
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    citirea();
    citireb();
    crearec();
    afisarec();
    eliberarea();
    eliberareb();
    eliberarec();
    return 0;
}
