输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）


//自己的找规律方法
//出栈序列对应成入栈元素的索引，出栈序列中第二个元素开始一旦满足后面第一个比它小的最大元素不是排在最前面，则返回false

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    	
        int j = popV.size() ;
        int jud = 1;
        int max = 0;
        for(int i = 0;i<j;++i){               //转换为索引序列
        	for(int i1 = 0; i1<j; ++i1){
        		if(pushV[i1] == popV[i]) 
				{popV[i] = i1; break;}
				if(i1==j-1) return false;
			}
		}
		
        for(int i = 0;i<j;++i){           //判断
        	for(int k = i+1; k<j; ++k){
        		if(popV[i]>popV[k]&&jud) {
        			max = popV[k]; jud = 0;
        			for(int m = k+1; m<j; ++m ){
        				if(popV[i]>popV[m]&&popV[m]>max) return false;
					}
				}
				jud = 1;
    
				 	
			}
		}
		return true;
    }
};



//模拟出栈方法
//将出栈过程模拟出来，如果最后栈内还有元素，则返回false   即返回辅助栈.empty()


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    	stack<int> ret;
    	int i = 0;
    	for(auto c:pushV) {
    		ret.push(c);
    		while(popV[i]&&popV[i] == ret.top()) {      //popV[i]存在切popV[i]第一个数和ret顶相同，则出栈
    			ret.pop();
				  ++i; 
			}
		}
		return ret.empty() ;
	}
};







