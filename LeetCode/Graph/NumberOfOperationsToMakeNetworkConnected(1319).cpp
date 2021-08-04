class Solution {
public:
    void dfs(int n, vector<vector<int>>& graph,vector<int>&visited,int sv)
    {
        if(sv>=n) return;
        
        visited[sv]=1;
       for(auto it:graph[sv])
       {
           if(!visited[it]) dfs(n,graph,visited,it);
       }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> visited(n,0);
        int count=0;
        vector<vector<int>> graph(n);
        for(auto con : connections){
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i]) {dfs(n,graph,visited,i); count++;}
        }
        int edges=connections.size();
        int redundant=edges-(n-1)+(count-1);
        if(redundant<count-1) return -1;
        else return count-1;
    }
};