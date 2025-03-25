//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
const long long MN=1e5+1, md=1e9+7;
 
long long n, x, a[MN], dp[MN][105], ans;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>x;
    
    for(int i=1; i<=n; i++)cin>>a[i];
    
    if(!a[1])for(int j=1; j<=x; j++)dp[1][j]=1;
    else dp[1][a[1]]=1;
    
    for(int i=2; i<=n; i++){
        if(a[i])dp[i][a[i]]=(dp[i-1][a[i]]+dp[i-1][a[i]-1]+dp[i-1][a[i]+1])%md;
        else for(int j=1; j<=x; j++)dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1])%md;
    }
    
    for(int i=1; i<=x; i++)ans+=dp[n][i];
    
    cout<<ans%md;
    
    return 0;
}