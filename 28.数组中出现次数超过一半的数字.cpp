数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

//查重，用map 
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int,int> ret;
        for(auto c:numbers){
            if(++ret[c]>numbers.size()/2) return c;
        }
        return 0;
    }
};


//一抵一思想找出最多元素，然后判断
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int cnt=1,ret = numbers[0];
    	for(int i = 1;i<numbers.size();++i){
    		if(numbers[i] == ret) ++cnt;
    		else {
    		if(--cnt==0) 
			{
			ret = numbers[i];
			cnt = 1;
			}
			}
		}
		cnt = 0;
		for(auto c:numbers){
			if(c == ret) ++cnt;
		}
		if(cnt>numbers.size()/2)	return ret;
        return 0;
    }
};
