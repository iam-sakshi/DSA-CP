class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans;
        if(k>1){ 
            sort(s.begin(),s.end());
            ans = s;
        }else{
            int n = s.size();
            ans = s;
            s+=s;
            for(int i=1; i<n;i++){
                ans = min(ans,s.substr(i, n));
            }
        }
        return ans;
    }
};