class Solution {
public:
    
    
    unordered_map<string,vector<int>>dp;
    
    
    int calc(int a,char op,int b)
    {
        if(op=='+')
             return a+b;
        else if(op=='-')
             return a-b;
        else
             return a*b;
    }
    
    
    
    
    
    
    vector<int> diffWaysToCompute(string s) {
        
        vector<int>res;
        bool mark=1;
        
        if(dp.find(s)!=dp.end())
            return dp[s];
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+'||s[i]=='-'||s[i]=='*')
            {
                string k=s.substr(0,i);
                vector<int>l=diffWaysToCompute(k);
                k=s.substr(i+1,s.size()-i);
                vector<int>r=diffWaysToCompute(k);
            
            
              for(auto x:l)
              {
                for(auto y:r)
                {
                    mark=0;
                    res.push_back(calc(x,s[i],y));
                }
              }

            }
        }
        
        
        if(mark)
            res.push_back(stoi(s));
        
        return dp[s]=res;        
    }
};