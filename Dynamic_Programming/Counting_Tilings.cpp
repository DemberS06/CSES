//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
const int N=11, M=1001, mod=1e9+7;
 
long long dp[N][M][1<<N];
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
 
    int n, m;
    cin>>n>>m;
 
    dp[n][0][0]=1;
 
    for(int i=1; i<=m; i++){
        for(int h=0; h<(1<<n); h++)dp[0][i][h]=dp[n][i-1][h];
        for(int j=1; j<=n; j++)
            for(int h=0; h<(1<<n); h++){
                auto x=(1<<j-1);
                if(x&h)dp[j][i][h]+=dp[j-1][i][h-x];
                else{
                    dp[j][i][h]+=dp[j-1][i][h+x];
                    if(j>1 && !((x/2)&h))dp[j][i][h]+=dp[j-2][i][h];
                }
                dp[j][i][h]%=mod;
            }
    }
    
    cout<<dp[n][m][0];
 
    return 0;
}