#include <iostream>

using namespace std;

struct nod
{
    int info;
    int bal;
    nod *left, *right;
};

nod *minim(nod *x)
{
    while (x->left)
        x=x->left;
    return x;
}

nod *p;

bool inserare(int val, nod *&p)
{
    nod *t=new nod;
    t->info=val;
    t->bal=0;
    t->left=NULL;
    t->right=NULL;
    if (p==NULL)
    {
        p=t;
        return true;
    }

    if(p->info==val)
        return false;

    if (p->info>val)
        if (inserare(val,p->left)==true)
            p->bal--;
        else
            return false;
    else if(inserare(val,p->right)==true)
        p->bal++;
    else
        return false;

}


void rotatie_dreapta(nod *&p)
{
    nod *t=p->left;
    p->left=t->right;
    t->right=p;
    p->bal=p->bal+(1-min(t->bal,0));
    t->bal=t->bal+(1+max(p->bal,0));
    p=t;
}

void rotatie_stanga(nod *&p)
{
    nod *t=p->right;
    p->right=t->left;
    t->left=p;
    p->bal=p->bal+(1-max(t->bal,0));
    t->bal=t->bal-(1-min(p->bal,0));
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
        if (p->left->bal==1)
            rotatie_stanga_dreapta(p);
        else
            rotatie_dreapta(p);
    else if(p->bal==2)
        if (p->right->bal==-1)
            rotatie_dreapta_stanga(p);
        else
            rotatie_stanga(p);
}

bool sterge(int val, nod *&p)
{
    if (p==NULL)
        return false;

    if (p->info>val)
        if (sterge(val,p->left)==true)
            p->bal++;
        else
            return false;
    else if (p->info<val)
        if (sterge(val,p->right)==true)
            p->bal--;
        else
            return false;
    else if (p->left==NULL || p->right==NULL)
        if (p->left!=NULL)
        {
            p->info=p->left->info;
            p->left=NULL;
            p->bal++;
            return true;
        }
        else if (p->right!=NULL)
        {
            p->info=p->right->info;
            p->right=NULL;
            p->bal--;
            return true;
        }
        else
        {
            nod *y=minim(p->right);
            p->info=y->info;
            if (sterge(y->info,p->right)==true)
                p->bal--;
            else
                return false;
        }
        if (p->bal==2 || p->bal==-2)
            echilibreaza(p);
        if(p->bal==0)
            return true;
        else
            return false;

}

int cauta(int val,nod *&p)
{
    nod *t=p;
    while (t!=NULL)
    {
        if (t->info==val)
            return 1;
        if (val<t->info)
            t=t->left;
        else if (t->info<val)
            t=t->right;
    }
    return 0;
}

int maxim(nod *&p)
{
    nod *t=p;
    while (t->right!=NULL)
        t=t->right;
    return t->info;
}

void srd(nod *&p)
{
    if (p)
    {
        srd(p->left);
        cout<<p->info<<' ';
        srd(p->right);
    }
}

int main()
{
    int sw=1;
    p=NULL;
    while (sw)
    {
        cout<<"Introduceti valoarea pe care doriti sa o inserati in arbore: ";
        int val;
        cin>>val;
        inserare(val,p);
        cout<<"Mai doriti sa inserati?(1-da/0-nu)=> ";
        cin>>sw;
    }
    cout<<endl<<"Ce valoare doriti sa cautati?=> ";
    int val;
    cin>>val;
    if (cauta(val,p))
        cout<<"exista"<<endl<<endl;
        else
            cout<<"nu exista"<<endl<<endl;
    cout<<"Maximul este "<<maxim(p)<<endl<<endl;
    cout<<"Ce nod doriti sa stergeti?=>";
    cin>>val;
    sterge(val,p);
    srd(p);

    return 0;
}
