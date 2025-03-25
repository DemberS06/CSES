//Hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;
 
const long long md=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n;
    char c;
    cin>>n;

    vector<vector<long long>> dp(n+1, vector<long long> (n+1, 0));
    dp[0][1]=1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>c;
            if(c=='*')continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%md;
        }
    }
    
    cout<<dp[n][n];
    
    return 0;
}