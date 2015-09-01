#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return NULL;

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);


    }

    TreeNode* build(vector<int>& preorder, int sp, int ep, vector<int>& inorder, int si, int ei){
        TreeNode* root = new TreeNode(preorder[sp]);

        if(sp == ep){
            return root;
        }

        int mid;
        for(mid = si; mid <= ei; mid++){
            if(inorder[mid] == preorder[sp])
                break;
        }

        //有左子树

        if(mid > si){
            root->left = build(preorder, sp+1, sp + mid - si, inorder, si, mid-1 );
        }

        //有右子树
        if(mid != ei){
            root->right = build(preorder, sp + mid - si + 1, ep, inorder, mid + 1, ei);
        }
        return root;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty() || postorder.size() != inorder.size())
            return NULL;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>&inorder, int si, int ei, vector<int>& postorder, int sp, int ep){
        TreeNode* root = new TreeNode(postorder[ep]);
        if(sp == ep )
            return root;

        int mid;
        for(mid = si; mid<=ei; mid++)
            if(inorder[mid] == postorder[ep])
                break;
        //有左子树
        if(mid > si){
            root->left = build(inorder, si, mid - 1, postorder, sp, sp + mid - si - 1);
        }
        //有右子树
        if(mid < ei){
            root->right = build(inorder, mid + 1, ei, postorder, sp + mid - si, ep - 1);
        }
        return root;
    }
};