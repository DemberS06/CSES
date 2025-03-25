//Hola soy Dember :D

#include <bits/stdc++.h>

using namespace std;
 
const long long N=1e6+6, md=1e9+7;

long long dp[N];
 
void solve(){
    long long n;
    cin>>n;
    
    cout<<dp[n]<<"\n";
    
    return;
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    dp[1]=2; dp[2]=8;
        
    for(int i=3; i<N; i++)dp[i]=(dp[i-1]*6-dp[i-2]*7%md+md)%md;

    int t=1;
    cin>>t;
    
    while(t--)solve();
 
    return t+1;
}