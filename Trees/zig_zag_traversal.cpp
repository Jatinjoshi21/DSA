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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> sample;
        queue<TreeNode*> q;
        int lefttoright = 1;
        if(root==NULL){
           return sample;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            int front = 0;
            int last = size - 1;
            while(size!=0){
                
                TreeNode* t = q.front();
                q.pop();
                if(lefttoright==1){
                    temp[front] = t->val;
                    front++;
                }
                else{
                    temp[last] = t->val;
                    last--;
                }
                size--; 
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            sample.push_back(temp);
            lefttoright = 1 - lefttoright;

        }
        return sample;
    }
};