class Solution {
public:
    int mod = 1000000007 ;
    
    long long power(long long x, long long y)
    {
        if(y==0)
            return 1 ;
        
        long long a = power(x,y/2);
        
        a*=a ;
        a%=mod ;
        if(y%2)
            a*=x ;
        
         a%=mod ;
        
        return a ;
    }
    
    int countGoodNumbers(long long n) {
        long odd = n/2 ;
        long even = n/2 + n%2 ;
        
        return (power(5,even)*power(4,odd))%mod ;
    }
};