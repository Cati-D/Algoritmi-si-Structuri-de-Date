#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *prim, *ultim, *p;


void add_final (int val)
{
    p = new nod;
    p->info = val;
    p->next = NULL;

    if (prim == NULL)
        prim = ultim = p;
    else
    {
        ultim->next = p;
        ultim = p;
    }
}

void add_inceput (int val)
{
    p = new nod;
    p->info = val;
    p->next = prim;
    prim = p;
}

void add_elem_fata(int val, int x)
{
    p = prim;

    if (p->info == val)
    {
        nod *aux = new nod;
        aux->info = x;
        aux->next = prim;
        prim=aux;
    }
    else
    {

        while (p->next->info != val&&p!=NULL)
            p = p->next;
        if (p!=NULL)
        {
            nod *aux = new nod;
            aux->info=x;
            aux->next = p->next;
            p->next = aux;
        }
    }
}
void citire (int n)
{
    int x;
    cout << "Cititi elemente:" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "elementul " << i << " este: ";
        cin >> x;
        cout << endl;
        add_final (x);
    }
}
void afisare()
{
    p = prim;

    while (p!= NULL)
    {
        cout << p->info << ' ';
        p = p->next;
    }

}

void caut_elem_pozitie (int poz)
{
    p = prim;
    int nr = 0;

    while (nr < poz && p->next != NULL)
    {
        p = p->next;
        nr++;
    }

    if (poz - nr > 1)
        cout << "Lista are mai putin de" << poz << " elemente";
    else
        cout << p->info;
}

int caut_elem_valoare (int val)
{
    p = prim;
    while (p->info != val&&p->next!=NULL)
        p = p->next;

    if (p->info == val)
        return 1;
    return 0;
}

void stergere_elem_poz (int poz)
{
    p = prim;

    if (poz == 1)
    {
        prim = prim->next;
        delete p;
    }
    else
    {int nr=2;
        while (nr < poz)
        {
            p = p->next;
            nr++;
        }

        nod *aux = p->next;
        p->next = p->next->next;
        delete aux;
    }
}

void stergere_elem_val (int val)
{
    p = prim;

    if (prim->info == val)
    {
        prim = prim->next;
        delete p;
    }
    else
    {
        while (p->next->info != val)
            p = p->next;

        nod *aux = p->next;
        p->next = p->next->next;
        delete aux;
    }
}

void eliberare()
{
    p = prim;

    while (p->next != NULL)
    {
        prim = prim->next;
        delete p;
        p = prim;
    }

    delete p;
}

int main()
{
    citire (7);
    cout << endl;
    cout<<"Lista dupa adaugarea lui 21 in fata primei aparitii a lui 2: ";
    add_elem_fata (2,21);
    afisare();
    cout << endl;
    cout<<"Afisare exista sau nu elementul cu valoarea 3: ";
    cout<<caut_elem_valoare (3);
    cout << endl;
    cout<<"Afisare valoare element de pe pozitia 3: ";
    caut_elem_pozitie (3);
    cout << endl;
    cout<<"Afisare lista dupa stergerea primului element cu valoarea 1: ";
    stergere_elem_val (1);
    afisare();
    cout << endl;
    cout<<"Afisare lista dupa stergerea elementului de pe pozitia 2: ";
    stergere_elem_poz (2);
    afisare();
    cout << endl;
    eliberare();
    return 0;
}
