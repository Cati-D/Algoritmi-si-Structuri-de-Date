#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *prim, *ultim, *p;
int n;

void add(int val)
{
    p=new nod;
    p->info=val;
    p->next=NULL;
    if (prim==NULL)
        prim=ultim=p;
    else
    {
        ultim->next=p;
        ultim=p;
    }
}

void citire()
{
    int i,x;
    for (i=1; i<=n; i++)
    {
        cout<<"elementul "<<i<<" este: ";
        cin>>x;
        cout<<endl;
        add(x);
    }
}
//Problema 2
int nr_elem_pare()
{
    int nr=0;
    p=prim;
    while (p!=NULL)
    {
        nr+=1-(p->info)%2;
        p=p->next;
    }
    return nr;
}

float medie_elem_impare()
{
    float  s=0;
    p=prim;
    while(p!=NULL)
    {
        if (p->info%2)
            s+=p->info;
        p=p->next;
    }
    return s/(n-nr_elem_pare());
}
//Problema 3
void add_medie()
{
    p=prim;
    while (p->next!=NULL)
    {
        nod *aux=new nod;
        aux->info=(p->info+p->next->info)/2;
        aux->next=p->next;
        p->next=aux;
        p=p->next->next;

    }
}
//Problema 4
void suma(unsigned long long x, unsigned long long y)
{

    while (x)
    {
        add(x%10);
        x/=10;
    }
    p=prim;
    int s=0;
    while (y)
    {
        s=p->info+y%10;
        p->info=s%10;
        p->next->info+=s/10;
        y=y/10;
        p=p->next;

    }
}


void afisare()
{
    p=prim;
    while (p!=NULL)
    {
        cout<<p->info<<' ';
        p=p->next;
    }
}

void eliberare()
{
    p=prim;
    while (p!=NULL)
    {
        prim=prim->next;
        delete p;
        p=prim;
    }
}

int main()
{

    int i;
    cout<<"Introduceti numarul problemei dorite:";
    cin>>i;
    switch (i)
    {
    case 2:
        //2. Să se creeze o listă simplu înlănţuită alocată dinamic în care se vor reţine numere întregi. Să se scrie un program pentru numărarea elementelor pare din listă şi pentru calcularea mediei aritmetice a celor impare.
        cout<<"Lista este: ";
        cout<<"n=";
        cin>>n;
        citire();
        cout<<"Numarul de elemente pare este: ";
        cout<<nr_elem_pare()<<endl;
        cout<<"Media aritmetica a elementelor impare este: "<<medie_elem_impare();
        eliberare();
        break;
    case 3:
        // Să se creeze o listă simplu înlănţuită alocată dinamic în care se vor reţine numere întregi. Să se scrie o funcţie care să modifice lista, adăugând între fiecare 2 elemente consecutive în listă media lor aritmetică.
        cout<<"Lista este: ";
        cout<<"n=";
        cin>>n;
        citire();
        cout<<"Lista dupa inserarea mediei aritmetice intre oricare 2 valori alaturate este: ";
        add_medie();
        afisare();
        eliberare();
        break;
    case 4:
        //Scrieţi un program în care se citesc două numere “mari” şi se construieşte o listă în care se va salva suma lor.
        unsigned long long x,y;
        cout<<"x=";
        cin>>x;
        cout<<"y=";
        cin>>y;
        if (x<y)
            swap(x,y);
        suma(x,y);
        afisare();
        eliberare();
        break;
    case 5:
        //Folosind reprezentarea de la problema anterioară, scrieți un program în care se citesc două numere “mari” și se construiește o listă în care se va salva produsul lor.

        unsigned long long a, b;
        cout<<"a=";
        cin>>a;
        cout<<"b=";
        cin>>b;
        unsigned long long c;
        c=a*b;
        while (c)
        {
            int d=c%10;
            add(d);
            c/=10;
        }
        afisare();
        break;
    default:
        cout<<"Switch incorect";
    }

    return 0;
}
