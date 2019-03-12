定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。


//定义辅助栈  并初步解决重复问题
class Solution {
public:
	stack<int> p1,p2;
    void push(int value) {
        p1.push(value);
		if(p2.empty()) p2.push(value);
		if(value<=p2.top()) p2.push(value);   
    }
    void pop() {
    	if(p1.top() == p2.top()) p2.pop();
        p1.pop();
    }
    int top() {
        return p1.top(); 
    }
    int min() {
        return p2.top();
    }
};


//优化解决重复问题 辅助栈内存索引
class Solution {
public:
	stack<int> minv;
	vector<int> data;
    void push(int value) {
        data.push_back(value);
		if(minv.empty()) minv.push(data.size()-1);
		if(value<data[minv.top()]) minv.push(data.size()-1);   
    }
    void pop() {
    	if((data.size() - 1)== minv.top()) minv.pop();
        data.pop_back(); 
    }
    int top() {
        return data[data.size() -1 ]; 
    }
    int min() {
        return data[minv.top()];
    }
};
