/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


int findMinimum(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}

// time : O(height)

int findMaximum(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}


bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true; // assume empty tree to be a BST since there is no violation of BST prop.
	}

	// recursive case

	// f(root) : check if the given tree is a BST

	// 1. ask your friend to check if the LST is a BST

	bool leftIsBst = checkBST(root->left);

	// 2. ask your friend to check if the RST is a BST

	bool rightIsBst = checkBST(root->right);

	// 3. check yourself if the BST prop. works at the root node

	bool bstPropWorksAtRoot = root->val > findMaximum(root->left) and
	                          root->val < findMinimum(root->right) ? true : false;

	return leftIsBst and rightIsBst and bstPropWorksAtRoot;

}

class triple {
public:
	int minVal;
	int maxVal;
	bool isBst;
};

// time : O(n)

triple checkBSTOptimised(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		t.isBst = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;
		return t;
	}

	// recursive case

	triple left = checkBSTOptimised(root->left);
	triple right = checkBSTOptimised(root->right);

	bool bstPropWorksAtRoot = root->val > left.maxVal and
	                          root->val < right.minVal ? true : false;


	t.isBst = left.isBst and right.isBst and bstPropWorksAtRoot;
	t.minVal = min(left.minVal, min(right.minVal, root->val));
	t.maxVal = max(left.maxVal, max(right.maxVal, root->val));

	return t;

}

// time : O(n)

bool checkBSTUsingRange(TreeNode* root, long long lb, long long ub) {
	// base case
	if (root == NULL) {
		return true;
	}

	// recursive case

	return root->val > lb and root->val < ub and
	       checkBSTUsingRange(root->left, lb, root->val) and
	       checkBSTUsingRange(root->right, root->val, ub);
}


int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	checkBST(root) ? cout << "true" << endl : cout << "false" << endl;

	triple t = checkBSTOptimised(root);

	t.isBst ? cout << "true" << endl : cout << "false" << endl;

	long long lb = (long long)INT_MIN - 1;
	long long ub = (long long)INT_MAX + 1;

	checkBSTUsingRange(root, lb, ub) ? cout << "true" << endl :
	                                        cout << "false" << endl;

	return 0;
}