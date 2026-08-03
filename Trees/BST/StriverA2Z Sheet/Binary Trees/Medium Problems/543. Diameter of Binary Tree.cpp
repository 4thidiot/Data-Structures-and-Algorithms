class Solution 
{
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int dia = 0;
        diameter(root, dia);
        return dia;
    }

    int diameter(TreeNode* root, int &maxi)
    {
        if (root==NULL)
            return 0;
        int lh = diameter(root->left, maxi);
        int rh = diameter(root->right, maxi);

        maxi = max(maxi, lh+rh); //Only line extra from height of a tree code

        return 1+max(lh, rh);
    }
};
