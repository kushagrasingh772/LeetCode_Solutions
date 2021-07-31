class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)return n;
        map<int,int>trusts;
        map<int,int>istrusted;
        for(auto p:trust)
        {
            istrusted[p[1]]+=1;
            trusts[p[0]]=p[1];
        }
        for(auto it=istrusted.begin();it!=istrusted.end();it++)
        {
            if((it->second)==n-1 and trusts.find(it->first)==trusts.end())
                return it->first;
        }
        return -1;
        
    }
};