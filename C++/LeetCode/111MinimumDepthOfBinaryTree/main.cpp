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
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        int answer = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});

        while (!q.empty())
        {
            TreeNode *cur = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (!cur)
                continue;
            if (cur->left == nullptr && cur->right == nullptr)
            {
                answer = depth;
                break;
            }
            q.push({cur->left, depth + 1});
            q.push({cur->right, depth + 1});
        }

        return answer;
    }
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        if (!root->left)
            return 1 + minDepth(root->right);
        if (!root->right)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};