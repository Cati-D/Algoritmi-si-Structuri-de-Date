#include <iostream>

using namespace std;

struct nod
{
    int linie;
    int coloana;
    nod *next;
};

nod *coada, *p, *q, *ultim;

int a[20][20],m;
//adaug in coada
void push (int x, int y)
{
    p=new nod;
    p->linie=x;
    p->coloana=y;
    ultim->next=p;
}

//elimin primul element din coada
void pop(nod*coada)
{
    q=coada->next;
    delete coada;
    coada=q;
}

//verific vecinii (sus,jos,stanga,dreata) a elementului de pe pozitia data, in cazul in care ecestia sunt 1 modific in matrice valoarea elementului cu nr ul la care s a ajuns
void vecini(int x,int y, int nr)
{
    if (a[x-1][y]==1)
    {
        push(x-1,y);
        a[x-1][y]=nr;
    }
    if (a[x][y-1]==1)
    {
        push(x,y-1);
        a[x][y-1]=nr;
    }
    if (a[x][y+1]==1)
    {
        push(x,y+1);
        a[x][y+1]=nr;
    }
    if (a[x+1][y]==1)
    {
        push(x+1,y);
        a[x+1][y]=nr;
    }
}

//verific daca este coada 0 si deci s-a terminat o zona de pixeli
bool empty(nod *coada)
{
    return coada==NULL;
}

int main()
{
    cout<<"m=";
    cin>>m;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=m; j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
        }
    for (int i=0; i<=m; i++)
    {
        //bordez matricea ca sa nu intampin probleme cu vecinii
        a[0][i]=0;
        a[i][0]=0;
        a[m+1][i]=0;
        a[i][m+1]=0;
    }
    m++;
    int nr=2;
    for (int i=0; i<=m; i++)
        for (int j=0; j<=m; j++)
        {
            if (a[i][j]==1)
            {
                //introduc primul element verificat in coada
                coada=new nod;
                coada->coloana=j;
                coada->linie=i;
                ultim=coada;
            }
            while (empty(coada)==0)
            {
                //introduc urmatoarele elemente in coada verificand totodata pentru ele proprietatea
                vecini(coada->linie,coada->coloana,nr);
                //elimin primul element din coada
                pop(coada);
            }
            nr++;
        }
    for (int i=1; i<m; i++)
    {
        for (int j=1; j<m; j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }


    return 0;
}
