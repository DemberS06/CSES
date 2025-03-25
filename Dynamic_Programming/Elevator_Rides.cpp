//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    
    int n, k;
    
    cin>>n>>k;
 
    vector<int> v(n);
    for(auto &u:v)cin>>u;
 
    vector<vector<int>> dp(1<<n, vector<int> (2, 0)); dp[0][0]=1;
 
    for(int h=1; h<(1<<n); h++){
        dp[h][0]=n+6;
        for(int i=0; i<n; i++){
            if((h>>i)&1){
                auto u=dp[h^(1<<i)];
                if(u[1]+v[i]>k)u[0]++, u[1]=v[i];
                else u[1]+=v[i];
 
                dp[h]=min(u, dp[h]);
            }
        }
    }
 
    cout<<dp[(1<<n)-1][0];
 
    return 0;
}