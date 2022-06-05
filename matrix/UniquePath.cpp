class Solution {
public:
    int solve ( int m, int n)
    {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    dp[0][0]=1;
                else{
                int u=0, l=0;
                if(i>0)
                 u= dp[i-1][j];
                if(j>0)
                 l= dp[i][j-1];
                dp[i][j]=u+l;
                }
            }
        }
        return dp[m-1][n-1];
        
      
        // reccursive approach  
        // if (m==0 && n==0) return 1;
        // else if(m<=0 || n<=0)
        //     return 0;
        // int up =uniquePaths(m-1,n);
        // int left= uniquePaths(m,n-1);
        // return up+ left;
    }
    int uniquePaths(int m, int n) {
        return solve(m,n);
    }
};

// where m and n are dimenson of the matrix (m*n)
