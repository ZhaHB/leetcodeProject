#include "25_K ��һ�鷭ת����.h"

int main() {
	ListNode* a = new ListNode(3);
	ListNode* b = new ListNode(5);
	ListNode* c = new ListNode(7);
	ListNode* d = new ListNode(9);

	c->next = d;
	b->next = c;
	a->next = b;


	
	system("pause");
	return 0;

}