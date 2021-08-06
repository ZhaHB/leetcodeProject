#pragma once
#include"wholeImport.h"


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;
		
		ListNode *start, *end, *pre, *next;
		pre = end = dummyNode;
		
		while (end->next != nullptr) {
			for (int i = 0; i < k && end != NULL; i++)end = end->next;
			if (end == NULL)break;
			start = pre->next;
			next = end->next;

			/*cut next domain*/
			end->next = nullptr;

			pre->next = reverse(start);
			start->next = next;
			pre = start;
			end = pre;
		}

		return dummyNode->next;
		
	}

	/*递归法就地逆置*/
	ListNode* reverse(ListNode* head) {
		if (head == nullptr || head->next == nullptr)return head;

		ListNode* reverseNode = reverse(head->next);
		head->next->next = head;
		head->next == NULL;

		return reverseNode;
	}


	/*头插法就地逆置 (不含头节点版本)*/
	ListNode* reverse_Head_Insert(ListNode* head) {
		ListNode* curr, *pre, *temp;

		curr = head;
		pre = temp = NULL;

		while (curr) {
			pre = curr->next;
			curr->next = temp;
			temp = curr;
			curr = pre;
		}

		return temp;

	}

};


