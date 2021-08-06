#pragma once
#include"wholeImport.h"

class Solution {
public:
	/* �ݹ�д��, �������*/
	vector<int> preorderTraversal1(TreeNode* root) {
		vector<int>ret;
		preOrder(root, ret);
		return ret;
	}
	void preOrder(TreeNode* root, vector<int> &ret) {
		if (!root) return;
		ret.push_back(root->val);
		preOrder(root->left, ret);
		preOrder(root->right, ret);
	}

	/* ����д�����������*/
	vector<int> preorderTravesal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> stc;

		TreeNode* node = root;
		while (node || !stc.empty()) {
			while (node)
			{
				stc.push(node->right);
				ret.push_back(node->val);
				node = node->left;
			}
			node = stc.top;
			stc.pop();

		}

		return ret;
	}

};