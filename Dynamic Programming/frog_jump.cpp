#include<bits/stdc++.h>
using namespace std;
int solve_rec(int n,int arr[])
{
  if(n==0)
    return 1;
  if(n==1)
    return 1;
  int l= solve(n-1, arr)+ abs(arr[n-1]-arr[n]);
  int r= INT_MAX;
  if(n>1)
    r=solve(n-2,arr)+abs(arr[n]-arr[n-2]);
  return min(l,r);
}

int solve_tab(int n,int arr[])
{
  if(n==0)
    return 0;
   int dp[n+1];
   dp[0]=0;
   for(int i=1;i<=n;i++)
   {
       int l= dp[i-1] + abs(arr[i-1]-arr[i]);
       int r= INT_MAX;
       if(i>1)
      r= dp[i-2] + abs(arr[i-2]-arr[i]);
      dp[i]=min(l,r);
   }
   return dp[n];
}

int main()
{
  int n ;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  cout << solve_tab(arr);
}
