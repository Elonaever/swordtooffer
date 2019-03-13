输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

注意random是指向节点

//可以通过将新复制节点接到原对应节点后面以达到对应效果




//比较自然想到的map配对法

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr) return nullptr;
    	map<RandomListNode*,RandomListNode*> now;
    	
        RandomListNode* nph = new RandomListNode(pHead->label);
        now.insert(make_pair(pHead,nph)); 
        RandomListNode* npre = nph,*npnow,*npo = pHead;
        pHead = pHead->next;
        
        while(pHead){
        	npnow = new RandomListNode(pHead->label); 
        	now.insert(make_pair(pHead,npnow)); 
        	npre->next = npnow;
        	npre = npnow;
        	pHead = pHead->next ;
		}
		npnow = nph;
		while(npo){
			if(npo->random){
				auto it = now.find(npo->random);
				nph->random = it->second;
			}
			nph = nph->next;
			npo = npo->next;
		}
		return npnow;
    }
};
