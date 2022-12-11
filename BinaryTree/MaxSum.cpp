#include <iostream>

using namespace std;



  //Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(): val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 //Creation TreeNode
TreeNode* createNode(int val){
	TreeNode* newTreeNode = new TreeNode();
	newTreeNode->val = val;
	newTreeNode->left=newTreeNode->right=nullptr;
	return newTreeNode;
}

class Solution {	
public:
	int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
    }

    int DFS(TreeNode* root, int& maxSum){
        if(!root) return 0;
        int left = max(0, DFS(root->left, maxSum));
        int right = max(0, DFS(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
};


int main(){
	//TreeNode root = (3,9,20,15,7);
	
	TreeNode* root = createNode(3);
	root->left = createNode(9);
	root->right = createNode(20);
	root->right->left = createNode(15);
	root->right->right = createNode(7);
	
	Solution sol;
	cout << sol.maxPathSum(root) << endl;
}
