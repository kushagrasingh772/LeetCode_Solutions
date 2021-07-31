class Solution {
public:
    double myPow(double x, int n) {
        long long int nn = n;
        if(n<0) nn = -1*nn;
        double ans = 1;
        while(nn>0)
        {
            if(nn%2)
            {
                ans*= x;
                nn = nn-1;
            }
            else
            {
                x = x*x;
                nn = nn/2;
            }
        }
        if(n<0)
             return 1.0/ans;
        return ans;
    }
};