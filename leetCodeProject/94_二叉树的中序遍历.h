#pragma once
#include"wholeImport.h"


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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		Inorder(root, ret);
		return ret;

	}

	void Inorder(TreeNode* root, vector<int> &ret) {
		if (!root) return;
		Inorder(root->left, ret);
		ret.push_back(root->val);
		Inorder(root->right, ret);
	}

	/*µü´ú func()*/
	vector<int> inorderTraversal1(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> stc;

		TreeNode* node = root;
		while (node || !stc.empty()) {
			while (node) {
				stc.push(node);
				node = node->left;
			}
			node = stc.top();
			stc.pop();
			
			ret.push_back(node->val);
			node = node->right;
		}

		return ret;
	}

};