/*
Binary Tree Level Order Traversal II
https://leetcode.com/problems/binary-tree-level-order-traversal-ii
Passed all test cases.
Runtime: 8 ms, faster than 72.30% of C++ online submissions for Binary Tree Level Order Traversal II.
Memory Usage: 14 MB, less than 50.00% of C++ online submissions for Binary Tree Level Order Traversal II.
*/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)
            return vector<vector<int>>();
        
        vector<vector<int>> Levels;
        
        stack<vector<int>> s;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            
            vector<int> currLevel;
            
            int len = q.size();
            
            for(int i=0;i<len;i++){
                
                TreeNode* currNode = q.front();
                q.pop();
                
                currLevel.push_back(currNode->val);
                
                if(currNode->left != NULL)
                    q.push(currNode->left);
                
                if(currNode->right != NULL)
                    q.push(currNode->right);
                
            }
            s.push(currLevel); 
        }
        
        while(!s.empty()){
            Levels.push_back(s.top());
            s.pop();
        }
        
        return Levels;
    }
};
