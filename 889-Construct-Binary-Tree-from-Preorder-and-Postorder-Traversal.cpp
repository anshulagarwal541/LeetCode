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
    TreeNode* getAns(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd)
    {
        if(preStart>preEnd || postStart>postEnd)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart+1 <= preEnd)
        {
            auto it = find(postorder.begin(), postorder.end(), preorder[preStart+1]);
        int rootIndex = distance(postorder.begin(), it);
        int length = rootIndex-postStart+1;
        root->left = getAns(preorder, preStart+1, preStart+length, postorder, postStart, rootIndex);
        root->right = getAns(preorder, preStart+length+1, preEnd, postorder, rootIndex+1, postEnd-1);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return getAns(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
};