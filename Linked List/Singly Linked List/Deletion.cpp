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
        
        int deleteit(int pos)
        {
            int x;
            Node *p, *q;
            p=first;
            q=NULL;
            if(pos==1)
            {
                first = first->next;
                x=p->data;
                delete p;
            }
            else
            {
                for(int i=0; i<pos-1; i++)
                {
                    q=p;
                    p=p->next;
                }
                q->next = p->next;
                x = p->data;
                delete p;
                return x;
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
	cout<<l1.deleteit(4)<<'\n';
	l1.display();
	
    return 0;
}
