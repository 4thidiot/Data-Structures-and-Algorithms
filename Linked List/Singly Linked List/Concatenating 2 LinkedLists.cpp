#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *next;
};

class LinkedList
{
    private:
        node *first;
    public:

        LinkedList(int A[], int n)
        {
            node *last, *t;
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
                last = t;
            }
        }
        
        void display()
        {
            node *p = first;
            while(p != NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << '\n';
        }
        
        void concat(LinkedList &l2)
        {
            node *p = first;
            while(p->next!=NULL) //not p!=NULL
                p = p->next;
            
            p->next = l2.first;
            l2.first = NULL;
        }
        
};

int main() 
{
	int a[] = {1,2,3,4,5};
	int b[] = {6,7,8,9,10};
	
	LinkedList l1(a, 5), l2(b, 5);
	
	l1.display();
	l2.display();
	
	l1.concat(l2);
	l1.display();
	
}
