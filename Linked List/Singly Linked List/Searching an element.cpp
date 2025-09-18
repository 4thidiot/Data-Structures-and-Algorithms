#include <bits/stdc++.h>
using namespace std;

class node
{
    public:  //important
        int data;
        node *next;
};

class LinkedList
{
    private: 
        node *first;
    public:
        node *last, *t;
        LinkedList(int A[0], int n) //paramterised constructor
        {
            first = new node;
            first->data = A[0];
            first->next = NULL;
            last = first;
            
            for(int i=1; i<n; i++)
            {
                t = new node;
                t->data = A[i];
                t->next = NULL;
                last->next = t;
                last = last->next; //last = t;
            }
        }
        
        void search(int to_find)
        {
            node *p = first; //p also points to where first points(basically to the first node of the linkedlist)
            int node_count = 0;
            while(p!=NULL)
            {
                node_count++;
                if(p->data == to_find)
                {
                    cout<<"Found at node: "<<node_count<<'\n';
                    return;
                }
                else
                    p = p->next;
            }
            cout<<"Not found!\n";
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
	l1.search(8);
    
    return 0;
}
