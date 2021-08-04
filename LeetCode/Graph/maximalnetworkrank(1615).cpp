class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cities(n,0);
        map<pair<int,int>,int> mp;
        
        for(auto x : roads){
            cities[x[0]]++;
            cities[x[1]]++;
            mp[{x[0],x[1]}]++;
            mp[{x[1],x[0]}]++;
        }
        
        int res  = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(mp.find(make_pair(i,j)) != mp.end()){
                    //cout<<i<<" "<<j<<" "<<cities[i]+cities[j]-1<<"\n";
                    res = max(res,cities[i]+cities[j]-1);  
                }
                else{
                    //cout<<i<<" "<<j<<" "<<cities[i]+cities[j]<<"\n";
                    res = max(res,cities[i]+cities[j]); 
                }
            }
        }
          
        
        return res;
    }
};