//Hola soy Dember :D
#include<bits/stdc++.h>
  
using namespace std;
 
const long long inf=1e10;
 
int main(){
    long long n, k;
    cin>>n>>k;

    vector<vector<long long>> dp(n+1, vector<long long> (k+1, inf));

    for(int i=1; i<=min(n, k); i++)dp[i][i]=0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            for(int h=1; h<i; h++)dp[i][j]=min(dp[i][j], dp[h][j]+dp[i-h][j]+1);
            for(int h=1; h<j; h++)dp[i][j]=min(dp[i][j], dp[i][h]+dp[i][j-h]+1);
        }
    }
    
    cout<<dp[n][k];
    
    return 0;
}