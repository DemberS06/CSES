//Hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long md=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, k;
    cin>>n>>k;

    vector<long long> a(n), dp(k+1, 0);
    
    for(auto &u:a){
        cin>>u;
        dp[u]++;
    }
    
    sort(a.begin(), a.end());
    
    for(int i=0; i<=k; i++){
        for(auto &u:a){
            if(i+u>k)break;
            dp[i+u]=(dp[i+u]+dp[i])%md;
        }
    }
    
    cout<<dp[k]%md;
 
    return 0;
}