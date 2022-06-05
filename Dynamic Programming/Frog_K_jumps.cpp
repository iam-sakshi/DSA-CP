#include<bits/stdc++.h>
using namespace std;

int solve_tab(int n,int k,int arr[])
{
  if(n==0)
    return 0;
   int dp[n+1];
   dp[0]=0;

   for(int i=1;i<=n;i++)
   {
      int l=INT_MAX;
      int r=INT_MAX;
      for(int j=1;j<=k;j++)
   {
       if(i>=j)
       l= dp[i-j] + abs(arr[i-j]-arr[i]);
       r=min(l,r);
   }
      dp[i]=r;
   }
   
   return dp[n];
}

int main()
{
  int n ;
  cin>>n;
  int k;
  cin>>k;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  cout << solve_tab(n-1,k,arr);
}
