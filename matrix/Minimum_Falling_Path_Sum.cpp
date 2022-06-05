// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right


class Solution {
public:
    int solveT(vector<vector<int>> &grid, int n)
    {
        int dp[n][n];
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=grid[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==n-1)
                    continue;
            int d1=INT_MAX, d2= INT_MAX;
            if(i<=n-2)
             d1= grid[i][j]+ dp[i+1][j];
                if(i<=n-2 && j<=n-2)
             d2= grid[i][j] + dp[i+1][j+1]; 
                  int d3;
                if(i<=n-2 && j>0)
                    d3=grid[i][j]+dp[i+1][j-1];
                else
                    d3=INT_MAX;
            cout<<d1<<" "<<d2<<" "<<d3<<endl;
            dp[i][j]=min(d1,min(d2,d3));
            }
        }
        int mn= INT_MAX;
        for(int i=0;i<n;i++)
        {
            mn=min(mn,dp[0][i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        return mn;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        return solveT (grid, grid.size());
    }
};
