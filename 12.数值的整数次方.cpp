//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。


class Solution {
public:
    double Power(double base, int exponent) {
    	if(exponent == 0) return 1;
    	double ans = base;
        if(exponent > 0 ) {
        	while(--exponent){
    		ans *= base;
		}
			return ans;	
		}
		while(++exponent){
			ans *=base;
		}
		return 1/ans;

    }
};
