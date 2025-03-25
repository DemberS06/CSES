//Hola soy Dember :D
#include<bits/stdc++.h>
 
using namespace std;

const long long md=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, k;
    cin>>n>>k;
    
    vector<long long> a(n), dp(k+1, 0);
    dp[0]=1;
    
    for(auto &u:a){
        cin>>u;
        for(int i=u; i<=k; i++)dp[i]=(dp[i]+dp[i-u])%md;
    }
    
    cout<<dp[k];
    
    return 0;
}