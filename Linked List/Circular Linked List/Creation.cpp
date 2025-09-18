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


int main() 
{
	int A[5] = {1, 2, 3, 4, 5};
	create(A, 5);

  return 0;
}
