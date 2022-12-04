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


//Max Depth recursive algorithm
class Solution {	
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;     
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
	int res = sol.maxDepth(root);
	cout << "Max depth: " << res << endl;
}
