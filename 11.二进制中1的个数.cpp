输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示

//初级想法 判断最后一位，之后每次/2或者右移1位

//负数第一位为1 因此右移会导致补1造成无限循环,因此右移前要先将n转为unsigned(unsigned右移无符号) /2操作在无符号情况下等价于右移一位


class Solution {
public:
     int  NumberOf1(int n) {
     	 unsigned a = n,i = 0;
         while(a){
             if(a%2==1) ++i;
             a /=2;       //a >>= 1;
         }
         return i;
     }
};

//另一思路
//用1与n按位与，每次之后1左移一位（乘2）

class Solution {
public:
     int  NumberOf1(int n) {
     	 unsigned a = 1,i = 0;
         while(a){
             if(n&a) ++i;
             a <<= 1;
         }
         return i;
     }
};


//神奇思路
// n &= n-1   相当于把n最左位1置零，其余不变
class Solution {
public:
     int  NumberOf1(int n) {
     	 unsigned i = 0;
         while(n){
             ++i;
             n &= n-1;
         }
         return i;
     }
};
