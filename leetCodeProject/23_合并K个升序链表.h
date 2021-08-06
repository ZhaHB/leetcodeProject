#pragma once

#include<iostream>
#pragma once

#include "wholeImport.h"

/* Definition for singly-linked list.*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// ����Ŀ���Ȳο�֮ǰʵ�ֵ� merge2Lists() �ú���ʵ��ʹ�õݹ�ʵ��

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL)return l2;
	if (l2 == NULL)return l1;

	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

/* ��������˼· ���Ӧ�ڽ������
	* �ֶ���֮
*/

class Solution {
public:

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)return l2;
		if (l2 == NULL)return l1;

		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}

	ListNode * merge(vector<ListNode*>& lists, int left, int right) {
		if (left == right) return lists[left];
		if (left > right) return nullptr;

		int mid = (left + right) >> 1;

		return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));

	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}
};

