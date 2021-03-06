
//Accepted	4 ms	c
typedef long long Int;
int divide(int dividend, int divisor) {
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    int flag = (dividend < 0) ^ (divisor < 0);
    Int divL = labs(dividend);
    Int disL = labs(divisor);
    Int disTmpL = disL;
    int cnt = 1;
    while((disTmpL << 1) <= divL){
    	disTmpL <<= 1;
    	cnt <<= 1;
    }

    int ans = 0;
    while(disTmpL >= disL){
    	if(divL >= disTmpL){
    		divL -= disTmpL;
    		ans += cnt;
    	}
    	cnt >>= 1;
    	disTmpL >>= 1;
    }

    return (flag ? -ans : ans);
}
