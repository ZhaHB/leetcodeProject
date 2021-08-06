#pragma once
#include"wholeImport.h"


class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == nullptr || k == 0)return head;
		
		ListNode* ptr = head;
		int count = 1;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
			count++;
		}

		int add = count - k % count;
		if (add == count)return head;

		ptr->next = head;

		while (add--)ptr = ptr->next;
		ListNode* ret = ptr->next;
		ptr->next = nullptr;

		return ret;
	} 
};