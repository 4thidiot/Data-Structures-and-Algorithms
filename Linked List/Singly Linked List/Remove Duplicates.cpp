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
        
        void RemoveDuplicates()
        {
            Node *p, *q;
            p=first;
            q=p->next;
            
            while(q!=NULL)
            {
                if(p->data!=q->data)
                {
                    p=q;
                    q=q->next;
                }
                else
                {
                    p->next = q->next;
                    delete q;
                    q = p->next; //not q=q->next since q to delete hogaya hai
                }
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
	l1.RemoveDuplicates();
	l1.display();
	
    return 0;
}
