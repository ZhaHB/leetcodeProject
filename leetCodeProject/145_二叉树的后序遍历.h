#pragma once

#include"wholeImport.h"


class Solution {
public:
	/* 递归调用 后续遍历*/
	vector<int> postorderTraversal1(TreeNode* root) {
		vector<int> ret;
		postOrder(root, ret);
		return ret;
	}

	void postOrder(TreeNode* root, vector<int> &ret) {
		if (!root) return;
		postOrder(root->left, ret);
		postOrder(root->right, ret);
	}

	/* 迭代， 后续遍历*/

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>ret;
		stack<TreeNode*> stc;

		TreeNode* node = root;
		while (node || !stc.empty()) {
			while (node) {
				ret.push_back(node->val);
				stc.push(node->left);
				node = node->right;
			}

			node = stc.top();
			stc.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}

};