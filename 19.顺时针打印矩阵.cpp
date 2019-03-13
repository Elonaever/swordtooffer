输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

//按圈循环
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> ans;
    if(matrix.empty()||matrix[0].empty()) return ans;
	int m = matrix.size()-1; 
	int n = matrix[0].size()-1;
	for(int i=0;i<=m/2&&i<=n/2;++i){
		for(int j=i;j<=n-i;++j) ans.push_back(matrix[i][j]); 
		for(int j=i+1;j<=m-i;++j) ans.push_back(matrix[j][n-i]);
		for(int j=n-i-1;j>=i&&(m-i)!=i;--j) ans.push_back(matrix[m-i][j]);  //反向打印需要判断是否和正向同一行/列
		for(int j=m-i-1;j>i&&(n-i)!=i;--j) ans.push_back(matrix[j][i]);
	}
	return ans;
    }
};
