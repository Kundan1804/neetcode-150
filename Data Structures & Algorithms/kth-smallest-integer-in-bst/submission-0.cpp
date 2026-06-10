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
    ;
    vector<int> inorder(TreeNode* root){
        vector<int> ans;
        if(root==NULL) return ans;;
        vector<int> left=inorder(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        vector<int> right=inorder(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans = inorder(root);
        return ans[k-1];
    }
};
