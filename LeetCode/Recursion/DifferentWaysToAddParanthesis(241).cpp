class Solution {
public:
    map<string,vector<int>> m;
    vector<int> diffWaysToCompute(string s) {
        if(m.count(s))return m[s];
        vector<int> res;
        for(int i=0;i<s.size();i++)
            if(ispunct(s[i]))
                for(int a: diffWaysToCompute(s.substr(0,i)))
                    for(int b: diffWaysToCompute(s.substr(i+1)))
                        if(s[i]=='+')res.push_back(a+b);
                        else if(s[i]=='-')res.push_back(a-b);
                        else res.push_back(a*b);
        return m[s]=res.size()?res:vector<int>{stoi(s)};
    }
};