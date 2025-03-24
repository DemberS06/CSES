//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

long long dp[20], p, k;
 
void solve(){ 
    vector<int> ans;
    
    cin>>k;

    if(k<=9)return cout<<k<<'\n', void();
        
    for(int i=0; i<17; i++)if(dp[i]<k)p=i;
    k-=dp[p]; p++;
        
    long long num=1;
    for(int i=1; i<p; i++)num*=10;

    if(p==1)num=0;
    num+=(k-1)/p;
    
    k%=p;
    if(k==0)k=p;
    p-=k;
    while(num)ans.push_back(num%10), num/=10;
    
    cout<<ans[p]<<"\n";
    
    return;
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    for(long long i=1, pt=9; i<20; i++, pt*=10)dp[i]=dp[i-1]+pt*i;
    
    int t=1;
    cin>>t;

    while(t--)solve();
 
    return t+1;
}