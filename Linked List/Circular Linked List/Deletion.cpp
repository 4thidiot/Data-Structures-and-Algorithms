#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *next;
}*Head;

void create(int A[], int n)
{
    node *t, *last;
    
    Head = new node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    
    for(int i=1; i<n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = Head;
        last->next = t;
        last = t;
    }
}


int Delete(int pos)
{
    node *p, *q;
    int x;
    if(pos==1)
    {
        p = Head;
        while(p->next != Head)
            p = p->next;
        x = Head->data;
        
        if(p==Head)
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        p = Head;
        for(int i=0; i<pos-2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}


void Display()
{
    node *p;
    p = Head;
    
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=Head);
}

int main() 
{
	int A[5] = {1, 2, 3, 4, 5};
	create(A, 5);
    Delete(3);
    Display();
}
