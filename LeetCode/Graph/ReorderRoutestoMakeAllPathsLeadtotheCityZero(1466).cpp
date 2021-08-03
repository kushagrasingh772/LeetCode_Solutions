class Solution {
public:
    
    void dfs(vector<int> graph[], vector<set<int>> &adj, vector<int> &vis, int src, int &ans){
        vis[src] = 1;
        
        for(auto child : graph[src]){
            if(!vis[child]){
                if(adj[src].find(child) != adj[src].end()){
                    ans++;
                }
                dfs(graph, adj, vis, child, ans);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> graph[n+1];
        
        int ans = 0;
        
        for(auto c : connections){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        
        vector<set<int>> adj(n+1);
        
        for(auto x: connections){
            adj[x[0]].insert(x[1]);
        }
        
        vector<int> vis(n+1, 0);
        dfs(graph, adj, vis, 0, ans);
        return ans;
    }
};