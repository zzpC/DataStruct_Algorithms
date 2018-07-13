#include <iostream>
#include <stack>

using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution{
public:
	bool isPalindrome(ListNode* head){
		if(!head || !head->next){
			return true;
		}
		ListNode* p,*q;
		ListNode tempNode(0);
		tempNode.next=head;
		p=q=&tempNode;
		for(;q && q->next;){
			q=q->next->next;
			p=p->next;

		}


		q=p->next;
		for(;q!=nullptr;){
			ListNode* temp=q->next;
			q->next=p;
			p=q;
			q=temp;
		}
		ListNode* k=head;
		for(int i=0;p!=k;i++){
			if(p->val!=k->val){
				return false;
			}
			p=p->next;
			k=k->next;
		}
		return true;
	}
};

class Solution1 {
public:
	bool isPalindrome(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL) return true;
		//翻转后半部分链表
		ListNode* fast = pHead, *slow = pHead;
		while (fast->next != NULL) {
			fast = fast->next;
			if (fast->next != NULL) {
				fast = fast->next;
				slow = slow->next;
			}
		}
		while (slow->next != fast) {
			ListNode* tmp = slow->next;
			slow->next = tmp->next;
			tmp->next = fast->next;
			fast->next = tmp;
		}
		//分别从中间和后半部分开始遍历
		while (fast != NULL) {
			if (fast->val != pHead->val)
				return false;
			fast = fast->next;
			pHead = pHead->next;
		}
		return true;
	}
};


int main(){
	ListNode p1(0);
	ListNode p2(1);
	ListNode p3(2);
	ListNode p4(1);
	ListNode p5(4);
	ListNode p6(5);
	ListNode p7(6);

	p2.next=&p3;
	p3.next=&p4;
	p4.next=nullptr;

	p5.next=&p6;
	p6.next=&p7;
	p7.next=nullptr;

	ListNode* h0=nullptr;
	ListNode* h1=&p1;

	ListNode* h2=&p2;
	
	ListNode* h3=&p5;



	Solution1 s;
	cout << "true? " << s.isPalindrome(h0) << endl;
	cout << "true?" << s.isPalindrome(h1) << endl;
	cout << "true?" << s.isPalindrome(h2) << endl;
	cout << "false?" << s.isPalindrome(h3) << endl;

	return 0;
}
