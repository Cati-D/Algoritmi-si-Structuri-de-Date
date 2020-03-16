#include <iostream>
#include <string.h>

using namespace std;

strict nod
{
    char info;
    int bal;
    nod *left,*right;
}

nod *p;

bool inserare(char cuv, nod *&p)
{
    nod *t=new nod;
    t->info=cuv;
    t->left=NULL;
    t->right=NULL;
    t->bal=0;
    if (p==NULL)
       {
           p=t;
           return true;
       }
    if (strcmp(p->info,cuv)==0)
        return false;
    if (strcmp(p->info,cuv)>0)
        if (inserare(cuv,p->left)==true)
            p->bal--;
            else
            return false;
    else
        if (inserare(char,p->right)==true)
            p->bal++;
            else return false;

}

void rotatie_dreapta(nod *&p)
{
    nod *t=p->right;
    p->left=t->right;
    t->right=p;
    p->bal+=(i-min(t->bal,0));
    t->bal+=(i+max(p->bal,0));
    p=t;
}

void rotatie_stanga(nod *&p)
{
    nod *t=p->right;
    p->right=t->left;
    t->left=p;
    p->bal+=(1-max(t->bal,0));
    t->bal-=(1-min(p->bal,0));
    p=t;
}

void rotatie_dreapta_stanga(nod *&p)
{
    rotatie_dreapta(p->right);
    rotatie_stanga(p);

}

void rotatie_stanga_dreapta(nod *&p)
{
    rotatie_stanga(p->left);
    rotatie_dreapta(p);
}

void echilibreaza(nod *&p)
{
    if (p->bal==-2)
    {

    }
}
int main()
{

    return 0;
}
