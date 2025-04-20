class Solution {
    public:
        void inorder(TreeNode* root, std::vector<int>& result) {
            if (root == nullptr) return;
    
            inorder(root->left, result);      // 1. Traverse Left
            result.push_back(root->val);      // 2. Visit Node
            inorder(root->right, result);     // 3. Traverse Right
        }
    
        std::vector<int> inorderTraversal(TreeNode* root) {
            std::vector<int> result;
            inorder(root, result);
            return result;
        }
    };
