class Solution {
public:
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        diaWithVal(root, ans);
        return ans;
    }

    int diaWithVal(TreeNode* root, int &maxi)
    {
        if(root==NULL)
            return 0;
        int lv = max(0, diaWithVal(root->left, maxi)); //Ignoring Negative Values
        int rv = max(0, diaWithVal(root->right, maxi)); 

        maxi = max(maxi, root->val + lv + rv); //Extra from height of tree code

        return root->val + max(rv, lv);
    }

};
