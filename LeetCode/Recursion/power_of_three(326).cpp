#include <bits/stdc++.h>
using namespace std;

bool is_power(int n)
{
    int max_permissible=INT_MAX;
    int max_power=(log10(max_permissible)/log10(3));
    int max_limit=pow(3,max_power);
    if(n>0 && max_limit%n == 0)
        return true;
    else 
        return false;
}

int main()
{
    int n;
    cin>>n;
    bool ans=is_power(n);
    cout<<ans;
    return 0;
}
