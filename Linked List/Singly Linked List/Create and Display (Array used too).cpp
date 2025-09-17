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
        Node *first; //important
    public:
        LinkedList()
        {
            first=NULL;
        }
        LinkedList(int A[], int n)
        {
            Node *last, *t;
            
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
                last = last->next;
            }
        }
        
        void display()
        {
            Node *p = first;
            while(p!=NULL)
            {
                cout<<p->data<<" ";
                p = p->next;
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
    
    return 0;
}
