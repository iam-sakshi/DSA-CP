class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        int cn=0;
        for(auto w: words)
        {
            string r="";
            r+=w[1];
            r+=w[0];
            if(mp.find(r)!=mp.end() && mp[r]>0)
            {
             cn+=2;
             mp[r]--;
            }
            else
            {
                mp[w]++;
            }
        }
        int dp=0;
        for(auto m: mp)
        {
            string t=m.first;
            if(m.second>0)
            {
                if(t[0]==t[1])
                {   dp++;
                 break;
                }
                
            }
        }
        if(dp==1)
        cn+=1;
        return cn*2;
    }
};