class Solution {
public:
    bool isBipartite(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> cl;
        int i=0;
        int nm=edges.size();
        for(auto vl: edges)
        {
            for(auto vc: vl)
            {
                mp[i].push_back(vc);
                mp[vc].push_back(i);
                cl[i]=-1;
                cl[vc]=-1;
            }
            i++;
        }
        queue<int> q;
        vector<int> vis(nm+1, 0);
        for(int i=0;i<=nm;i++)
        {
        if(vis[i]!=1)
         {
              q.push(i);
              vis[i]=1;
              cl[i]=0;
        while(!q.empty())
        {
            int nd=q.front();
            q.pop();
            for(auto e: mp[nd])
            {
                if(vis[e]!=1)
                {
                    vis[e]=1;
                    q.push(e);
                    cl[e]=!cl[nd];
                }
                else
                {
                    for(auto e: mp[nd])
                    {
                        if(cl[e]==cl[nd])
                        {
                            return false;
                        }
                    }
                }
            }
            }
            }
        }
        return true;
    }
};