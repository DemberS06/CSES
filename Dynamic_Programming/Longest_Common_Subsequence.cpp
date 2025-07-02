//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;

    vector<int> a(n), b(m), ans;
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(auto& u:a)cin>>u;
    for(auto& u:b)cin>>u;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=dp[i-1][j-1];
            if(a[i-1]==b[j-1])dp[i][j]++;
            dp[i][j]=max({dp[i][j], dp[i-1][j], dp[i][j-1]});
        }
    }

    cout<<dp[n][m]<<"\n";

    while(n && m && dp[n][m]){
        while(dp[n][m]==dp[n][m-1])m--;
        while(dp[n][m]==dp[n-1][m])n--;
        ans.push_back(a[n-1]);
        if(dp[n][m]==dp[n-1][m]+1)n--;
        else m--;
    }

    reverse(ans.begin(), ans.end());
    for(auto& u:ans)cout<<u<<' ';

    return 0;
}