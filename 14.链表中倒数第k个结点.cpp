输入一个链表，输出该链表中倒数第k个结点。

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    ListNode* p1=pListHead;
    for(int i = 0 ;i<k;++i){
    	if(p1==nullptr) return nullptr;     //若k比数组长度大会报错 注意
    	p1 = p1->next;
	}
	while(p1){
		p1= p1->next ;
		pListHead = pListHead->next;
	}
	return pListHead;
	}
};
