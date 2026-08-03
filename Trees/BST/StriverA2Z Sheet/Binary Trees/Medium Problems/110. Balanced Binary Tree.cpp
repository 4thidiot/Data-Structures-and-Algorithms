class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        if(height(root)==-1)
            return false;
        else
            return true;
    }

    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh==-1|| rh==-1)
            return -1;
        if(abs(lh-rh)>1)
            return -1;

        return 1+max(lh, rh);
    }
