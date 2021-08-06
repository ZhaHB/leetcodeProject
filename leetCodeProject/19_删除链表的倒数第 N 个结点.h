#pragma once


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:


	//嵌入空的头节点
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr || head->next == nullptr && n<1 )return head;
		
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* fast = dummyHead;
		ListNode* slow = dummyHead;

		while (n!=0){
			fast = fast->next;
			n--;
		}

		while (fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}

		slow->next = slow->next->next;

		return dummyHead->next;
	}
};


class Solution {
public:
	//不嵌入空的头节点
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode* fast = head;
		ListNode* slow = head;

		while (n--) fast = fast->next;

		if (fast == nullptr)return head->next;

		while (fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}

		slow->next = slow->next->next;

		return head;
	}
};