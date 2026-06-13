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
    unordered_map<int,int> mp;
    TreeNode* createTree(vector<int>& preorder, int pre_start, int pre_end,
        vector<int>& inorder, int in_start, int in_end){
            if(in_start>in_end || pre_start>pre_end)return NULL;
            TreeNode* root =new TreeNode(preorder[pre_start]);
            int root_index = mp[root->val];
            int left_size =root_index-in_start;

            root->left = createTree(
                preorder, pre_start+1,  pre_start+left_size,
                inorder, in_start, root_index-1
            );
            root->right = createTree(
                preorder, pre_start+left_size+1, pre_end,
                inorder, root_index+1, in_end
            );
            return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0; i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return createTree(preorder, 0,  preorder.size()-1,
        inorder, 0, inorder.size()-1);
    }
};
