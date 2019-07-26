/*
Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree
All test case passed.
Runtime: 36 ms, faster than 6.30% of C++ online submissions for Average of Levels in Binary Tree.
Memory Usage: 21.9 MB, less than 40.51% of C++ online submissions for Average of Levels in Binary Tree.
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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if(root == NULL)
            return vector<double>();
        
        vector<double> levels;
        
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
            
            double sum = 0;
            int vectLen = currLevel.size();
            for(int j=0;j<vectLen;j++){
                sum+=currLevel[j];
            }
            double result = (double)sum/vectLen;
            levels.push_back(result);
        }
        
        return levels;
    }
};
