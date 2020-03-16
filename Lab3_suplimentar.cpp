#include <iostream>
#include<conio.h>

using namespace std;

struct pol
{
    int gr;
    int coef;
    pol *next;
};

int n, m;
pol *prim, *ultim, *p, *prim1,*ultim1, *p1, *p2, *prim2, *ultim2;
//Creare polinom P
void addP(int grad, int c)
{
    p=new pol;
    p->gr=grad;
    p->coef=c;
    p->next=NULL;
    if (prim==NULL)
    {
        ultim=p;
        prim=ultim;
    }
    else
    {
        ultim->next=p;
        ultim=p;
    }
}

void citireP()
{
    int x;
    for (int i=0; i<=n; i++)
    {
        cout<<"CoeficientP pentru x la puterea "<<i<<": ";
        cin>>x;
        addP (i,x);

    }
}

//Creare polinom Q
void addQ(int grad, int c)
{
    p1=new pol;
    p1->gr=grad;
    p1->coef=c;
    p1->next=NULL;
    if (prim1==NULL)
        prim1=ultim1=p1;
    else
    {
        ultim1->next=p1;
        ultim1=p1;
    }
}
void citireQ()
{
    int x;
    for (int i=0; i<=m; i++ )
    {
        cout<<"coeficientQ pt x la puterea "<<i<<": ";
        cin>>x;
        addQ(i,x);
    }
}

void afisareQ()
{
    p1=prim1;
    while (p1!=NULL)
    {
        cout<<"gradul este "<<p1->gr<<" iar coeficientul este "<<p1->coef<<endl;
        p1=p1->next;
    }
}

void afisareP()
{
    p=prim;
    while (p!=NULL)
    {
        cout<<"gradul este "<<p->gr<<" iar coeficientul este "<<p->coef<<endl;
        p=p->next;
    }
}

//Problema 2
void inmultire(int a)
{
    p=prim;
    while(p!=NULL)
    {
        p->coef*=a;
        p=p->next;
    }
}
//Problema 3

int rezolvare(int x)
{
    p=prim;
    int s=0,ptr=1;
    while (n)
    {
        ptr*=x;
        n--;
    }
    while (p!=NULL)
    {
        s=s+p->coef*ptr;
        p=p->next;
        ptr/=x;
    }
    return s;
}
//Problema 4

void adunare()
{
    p=prim;
    p1=prim1;
    while (p!=NULL&&p1!=NULL)
    {
        p->coef=p->coef+p1->coef;
        p1->coef=p->coef;
        p=p->next;
        p1=p1->next;

    }
}

//Problema 5
void creare_lista_inmultire()
{
    for (int i=0; i<=n+m; i++)
    {
        p2=new pol;
        p2->coef=0;
        p2->gr=i;
        p2->next=NULL;
        if (prim2==NULL)
            prim2=ultim2=p2;
        else
        {
            ultim2->next=p2;
            ultim2=p2;
        }

    }
}
void inmultire_polinoame()
{
    pol *aux;
    aux=prim2;
    p=prim;
    for (int i=0; i<=n; i++)
    {
        p2=aux;
        p1=prim1;
        for (int j=0; j<=m; j++)
        {
            p2->coef=p2->coef+p->coef*p1->coef;
            p1=p1->next;
            p2=p2->next;
        }
        aux=aux->next;
        p=p->next;
    }

}

void afisareM()
{
    p2=prim2;
    while (p2!=NULL)
    {
        cout<<"gradul este "<<p2->gr<<" iar coeficientul este "<<p2->coef<<endl;
        p2=p2->next;
    }
}
void eliberareQ()
{
    p1=prim1;
    while (p1!=NULL)
    {
        prim1=prim1->next;
        delete p1;
        p1=prim1;
    }
}
void eliberareP()
{
    p=prim;
    while (p!=NULL)
    {
        prim=prim->next;
        delete p;
        p=prim;
    }
}

void eliberareM()
{
    p2=prim2;
    while (p2!=NULL)
    {
        prim2=prim2->next;
        delete p2;
        p2=prim2;
    }
}

int main()
{
    int i;
    cout<<"grad P este ";
    cin>>n;
    cout<<"grad Q este ";
    cin>>m;
    cout<<"Introduceti problema dorita: ";
    cin>>i;
    switch(i)
    {
    case 2:
        prim=new pol;
        prim=NULL;
        prim=NULL;
        citireP();
        inmultire(4);
        afisareP();
        eliberareP();
        break;
    case 3:
        int x0;
        prim=new pol;
        prim=NULL;
        citireP();
        cout<<rezolvare(5);
        eliberareP();
        break;
    case 4:
        prim=new pol;
        prim=NULL;
        prim1=new pol;
        prim1=NULL;
        citireP();
        citireQ();
        adunare();
        if (n>=m)
            afisareP();
        else
            afisareQ();
        eliberareP();
        eliberareQ();
        break;
    case 5:
        prim=new pol;
        prim=NULL;
        prim1=new pol;
        prim1=NULL;
        citireP();
        citireQ();
        creare_lista_inmultire();
        inmultire_polinoame();
        afisareM();
        eliberareM();
        eliberareP();
        eliberareQ();
        break;
    default:
        cout<<"switch incorect";

    }
    return 0;
}
