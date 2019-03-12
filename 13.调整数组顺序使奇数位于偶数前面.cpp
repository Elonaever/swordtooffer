输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//只新建一个数组，但需要遍历两次
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> arr = array;
        int i = 0,j = array.size()-1;
        for(auto c: array){
        	if(c%2){
        		arr[i] = c;
        		++i;
			}
		}
		for(int i = j;i>=0;--i){
			if(array[i]%2==0){
				arr[j] = array[i];
				--j;
			}
		}
		array = arr;
    }
};

//新建两个数组，只遍历一次

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd,even;
        for(auto c: array){
        	if(c%2) odd.push_back(c);
        	else even.push_back(c);
		}
    //array.clear();
		array = odd;
		array.insert(array.end(),even.begin(),even.end()); 
    }
};
