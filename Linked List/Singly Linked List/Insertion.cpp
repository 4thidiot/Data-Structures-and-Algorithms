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
        
        void Insert(int pos, int n)
        {
            Node *p, *temp;
            if(pos==0)
            {
                temp = new Node;
                temp->data = n;
                temp->next = first;
                first = temp;
            }
            else if(pos>0)
            {
                p = first;
                for(int i=0; i<pos-1 && pos!=NULL; i++)
                    p = p->next;
                    
                temp = new Node;
                temp->data = n;
                temp->next = p->next;
                p->next = temp; //p->next and not only p
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
	l1.Insert(0, 99);
	l1.display();
	
    return 0;
}
