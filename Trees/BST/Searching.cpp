#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right;
        
        node(int value)
        {
            data = value;
            left=right=NULL;
        }
};

node* insert(node* root, int target)
{
    if(root==NULL)
    {
        node* temp = new node(target);
        return temp;
    }
    
    if(target<root->data)
        root->left = insert(root->left, target);
    else
        root->right = insert(root->right, target);
        
    return root;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main() 
{
	node *root = NULL;
	
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 100);
	root = insert(root, 20);
	root = insert(root, 40);
	
	inorder(root);

}
