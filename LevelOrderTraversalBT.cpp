/*
  Binary Tree Level Order Traversal - LeetCode:
  https://leetcode.com/problems/binary-tree-level-order-traversal/
  Runtime: 4 ms, faster than 94.37% of C++ online submissions for Binary Tree Level Order Traversal.
  Memory Usage: 13.7 MB, less than 95.96% of C++ online submissions for Binary Tree Level Order Traversal.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL)
            return vector<vector<int>>();
        
        /*
        The vector to hold the level by level layers of the tree
        */
        vector<vector<int>> levelList;
        
        /*
        Our queue to enforce a traversal in a breadth-first manner.
        */
        queue<TreeNode*> q;
        
        q.push(root);
        
        /*
        We will traverse the tree untill the nodes in the queue is not empty.
        */
        while(!q.empty())
        {
            /*
            The vector to store the current nodes of the level.
            */
            vector<int> currList;
            
            int len = q.size();
            
            for(int i=0;i<len;i++)
            {
                TreeNode *currNode = q.front();
                q.pop();
                currList.push_back(currNode->val);
                
                if(currNode->left != NULL){
                    q.push(currNode->left);
                }
                if(currNode->right != NULL){
                    q.push(currNode->right);
                }                
            }
            /*
            Push the current vector list of the level to the main level vector.
            */
            levelList.push_back(currList);
        }         
     return levelList;   
    }
};
