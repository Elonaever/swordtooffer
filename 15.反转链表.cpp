输入一个链表，反转链表后，输出新链表的表头。

//三个指针 分别指向当前节点、上一节点和下一节点
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
    if(pHead == nullptr) return nullptr;      //调用记得溢出
    if(pHead->next == nullptr) return pHead;
	ListNode* p1=pHead,*p2=pHead->next,*p3=nullptr;
		while(p2){
			p1->next = p3;
			p3 = p1;
			p1 = p2 ; 
			p2 = p2->next ; 
		}
		p1->next = p3;      //以p2作判断，最后一位要多循环一次
	return p1;
    }
};

//循环优化

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
	  ListNode* p1=pHead,*p2=pHead->next,*p3=nullptr;
		while(p1){
			p2 = p1->next;
			p1->next = p3;
			p3 = p1 ; 
			p1 = p2 ; 
		}
	return p3;
    }
};
