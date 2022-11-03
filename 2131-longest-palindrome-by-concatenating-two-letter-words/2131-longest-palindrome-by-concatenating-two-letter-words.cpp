class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_multiset<string> mp;
        int cn=0;
        for(auto w: words)
        {
            string r="";
            r+=w[1];
            r+=w[0];
            if(mp.find(r)!=mp.end())
            {
             cn+=2;
             mp.erase(mp.find(r));
            }
            else
            {
                mp.insert(w);
            }
        }
        int dp=0;
        for(auto m: mp)
        {
            string t=m;
                if(t[0]==t[1])
                {   dp++;
                 break;
                }
        }
        if(dp==1)
        cn+=1;
        return cn*2;
    }
};