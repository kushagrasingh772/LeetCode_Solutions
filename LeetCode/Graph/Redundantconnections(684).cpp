class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    void makeset(){
        for(int i=0; i<parent.size(); i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findParent(int node){
        if(parent[node]==node) 
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void join(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(rank[u]>rank[v])
            parent[v] = u;
        else if(rank[u]<rank[v])
            parent[u] = v;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size()+1);
        rank.resize(edges.size()+1);
        makeset();
        for(auto x: edges){
            if(findParent(x[0])!=findParent(x[1]))
                join(x[0],x[1]);
            else
                return x;
        }
        return {-1,-1};
    }
};