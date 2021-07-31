    vector<int>v;
    
    for(int i=1;i<=n;i++)
    {
        v.push_back(i);
    }
    
    k--;
    int ans=solve(v,k,0);
    return ans;
}
int solve(vector<int>& vx,int k,int indx)
{
    if(vx.size()==1)
    {
        return vx[0];
    }
    indx=(indx+k)%vx.size();
    vx.erase(vx.begin()+indx);
    return solve(vx,k,indx);        
}
};