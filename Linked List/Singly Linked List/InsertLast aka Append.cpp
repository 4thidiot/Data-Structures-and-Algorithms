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
        
        void InsertLast(int x)
        {
            Node *r;
            r = new Node;
            r->data = x;
            r->next = NULL;
            if(first==NULL)
                last=first=r;
            else
            {
                last->next = r;
                last = r;
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
	l1.InsertLast(21);
	l1.display();
	
    return 0;
}
