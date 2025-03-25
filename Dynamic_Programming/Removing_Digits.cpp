//Hola soy Dember :D
#include<bits/stdc++.h>
 
using namespace std;
 
const long long inf=1e7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n;
    cin>>n;

    vector<int> dp(n+1, inf);
    dp[0]=0;
    
    for(int i=1, k; i<=n; i++){
        k=i;
        while(k)dp[i]=min(dp[i],dp[i-k%10]+1), k/=10;
    }
    
    cout<<dp[n];
    
    return 0;
}