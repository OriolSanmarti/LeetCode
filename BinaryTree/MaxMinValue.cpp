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
	int maxElement(TreeNode* root) {
        if(root == nullptr) return 0;
		int actual = root->val;
        return max( max(actual,maxElement(root->left)), max(actual, maxElement(root->right)) );
    }
    int minElement(TreeNode* root) {
        if(root == nullptr) return 10E7;
		int actual = root->val;
        return min( min(actual,minElement(root->left)), min(actual, minElement(root->right)) );
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
	cout << sol.maxElement(root) << endl;
	cout << sol.minElement(root) << endl;
}
