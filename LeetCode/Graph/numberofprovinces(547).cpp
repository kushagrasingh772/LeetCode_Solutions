class Solution {
public:
    vector<vector<int>> arr;
    vector <int> vis;
    void dfs(int v)
    {
        vis[v]=1;
        for(int child: arr[v])
        {
            if(vis[child]==0)
            {
                dfs(child);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        if(n==0)
            return 0;
        arr.resize(n);
        vis.resize(n);
        vis.assign(vis.size(),0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j and isConnected[i][j]==1)
                    arr[i].push_back(j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                count++;
            }
        }
        return count;
    }
};