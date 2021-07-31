class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][1];
        int b=edges[0][0];
        if(a==edges[1][1] || a==edges[1][0])
            return a;
        else
            return b;
    }
};