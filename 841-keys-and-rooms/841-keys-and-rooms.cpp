class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& edges) {
          unordered_map<int,vector<int>> mp;
        int i=0;
        int nm=edges.size();
        for(auto vl: edges)
        {
            for(auto vc: vl)
            {
                mp[i].push_back(vc);
//                 if(mp[i]!=mp.end())
                
//                 else{
//                   vector<int> v;
//                     v.push_back(vc);
//                     mp[i]=v;
//                 }
            }
            i++;
        }
        queue<int> q;
        vector<int> vis(nm, 0);
        vis[0]=1;
        q.push(0);
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
                }
            }
        }
        for(auto v: vis)
        {
            if(v==0)
                return false;
        }
        return true;
    }
};