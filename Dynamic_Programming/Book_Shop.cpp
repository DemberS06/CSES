//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, x, ans=0;
    cin>>n>>x;

    vector<long long> a(n), b(n), dp(x+1, 0);

    for(auto &u:a)cin>>u;
    for(auto &u:b)cin>>u;
    
    for(int i=0; i<n; i++)
        for(int j=x; j>=a[i]; j--)dp[j]=max(dp[j], dp[j-a[i]]+b[i]);
    
    for(int i=0; i<=x; i++)ans=max(dp[i], ans);
    
    cout<<ans;

    return 0;
}