/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> postIndex;
    TreeNode* buildTree(int preStart, int preEnd, int postStart, 
                       vector<int>& preorder, vector<int>& postorder)
    {
       if(preStart>preEnd) return NULL;
       if(preStart==preEnd) return new TreeNode(preorder[preStart]);
       int leftSubtreeRoot=preorder[preStart+1];
       int leftSubtreeSize=postIndex[leftSubtreeRoot]-postStart+1;
       TreeNode* root=new TreeNode(preorder[preStart]);
       root->left=buildTree(preStart+1, preStart+leftSubtreeSize, postStart, preorder, postorder);
       root->right=buildTree(preStart+leftSubtreeSize+1, preEnd, postStart+leftSubtreeSize, preorder, postorder);
       return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++) postIndex[postorder[i]]=i;
        return buildTree(0,preorder.size()-1,0,preorder,postorder);
    }
};
