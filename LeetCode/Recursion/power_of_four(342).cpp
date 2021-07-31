#define ll long long
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)
            return false;
        ll a = 1;
        while(a<=n)
        {
            if(a==n)
                return true;
            
            a*=4;
        }
        return false;
    }
};