#pragma once

#include"wholeImport.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* swapPairs(ListNode* head) {

		// �ж�Ϊ�յ�����
		if (head->next == nullptr || head == nullptr) return head;

		// �ݹ齻��������ǰ�����ڵ�
		ListNode* newhead = head->next;
		head->next = swapPairs(newhead->next);
		newhead->next = head;
		return newhead;
	}
};