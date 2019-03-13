输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。


//基本排序法
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> a;
        if(k>input.size()) return a;
        a.insert(a.end(),k,0); 
        sort(input.begin(),input.end());
        for(int i =0 ;i<k;++i) a[i] = input[i];
        return a;
    }
};
