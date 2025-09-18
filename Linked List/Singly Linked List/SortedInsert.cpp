#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class LinkedList
{
    private:
        Node *first;
    public:
        Node *t, *last;
        
        LinkedList(int A[], int n)
        {
            first = new Node;
            first->data = A[0];
            first->next = NULL;
            last = first;
        
            for(int i=1; i<n; i++)
            {
                t = new Node;
                t->data = A[i];
                t->next = NULL;
                last->next = t;
                last = t;
            }
        }
        
        void display()
        {
            Node *l;
            l = first;
            while(l!=NULL)
            {
                cout<<l->data<<" ";
                l = l->next;
            }
            cout<<'\n';
        }
        
        void SortedInsert(int x)
        {
            Node *p, *q, *l;
            q=NULL;
            p=first;
            l = new Node;
            l->data=x;
            l->next=NULL;
            
            while(p!=NULL && p->data<x)
            {
                q=p;
                p=p->next;
            }
            if(p==first)
            {
                l->next=first;
                first=l;
            }
            else
            {
                l->next=q->next;
                q->next=l;
            }
        }
};

int main() 
{
	int n;
	cin>>n;
	int v[n];
	for(int i=0; i<n; i++)
	    cin>>v[i];
	    
	LinkedList l1(v, n);
	l1.display();
	l1.SortedInsert(9);
	l1.display();
	
    return 0;
}
