输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。


class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr) return pHead2;
        if(pHead2 == nullptr) return pHead1;
    	ListNode *p1,*p2,*p3 = pHead1;
        while(pHead1&&pHead1->next){
        	while(pHead2->next){
        		if(pHead2->val>=pHead1->val&&pHead2->val<=pHead1->next->val){
        			p1=pHead1->next; p2 = pHead2->next; 
        			pHead2->next = p1;
        			pHead1->next = pHead2;
        			pHead1 = p1; pHead2 = p2; 
					continue;
				}
				if(pHead2->next) pHead2 = pHead2->next;
			}
			if(pHead1->next) pHead1 = pHead1->next;
		}
		pHead1->next = pHead2;
        return p3;
    }
};
