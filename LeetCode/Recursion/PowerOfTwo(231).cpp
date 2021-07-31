class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        while(true)
        {
            if(n == 1)
            {
                return true;
            }
            else if(n%2 == 0 && n != 0)
            {
                return isPowerOfTwo(n/2);
            }
            else
            {
                break;
            }
        }
        return false;
    }
};