// mainly result i.e (res) is height of zig zag path 
// first find height
        // count zig zag path from root level order wise for each node
//-->>>for each node check path start from right and same check path for left
        // when we incerse by one level decrese the height (height=height-level of tree) 
        // if the zigzag path i.e height(zigzag) is greater then height(tree) this mean there is no big zigzag path present further more
// return the result

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
    int Height(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return max(Height(root->left),Height(root->right))+1;
    }
    void maxZigZag(TreeNode *root,int direction,int &count)
    {
        if(root!=NULL)
        {
            if(direction==0)
            {
                maxZigZag(root->left,1,++count);
            }
            else
            {
                 maxZigZag(root->right,0,++count);
            }
        }
    }
    int longestZigZag(TreeNode* root) {
        queue<TreeNode *>A;
        int height=Height(root);
        int res=0;
        A.push(root);
        int level=0;
        
        
        while(!A.empty())
        {
            if(res<height-level)
            {
            int size=A.size();
                level++;
            for(int i=0;i<size;i++)
            {
                int count_left=0;
                int count_right=0;
                TreeNode *temp=A.front();
                A.pop();
              if(temp->left)maxZigZag(temp,0,count_left);// 0 means left
                if(temp->right)maxZigZag(temp,1,count_right);// 1 means right
                res=max(res,max(count_left,count_right)-1);
                if(temp->left)A.push(temp->left);
                if(temp->right)A.push(temp->right);
            }
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
