// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const long long mod=1e9+7;

long long expbin(long long x, long long y){
    long long ans=1;
    while(y){
        if(y&1)ans=ans*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return ans;
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m=1;
    cin>>n;
    while(m<=n)m*=2;

    vector<int> f(m, 0);
    for(int i=0, x; i<n; i++){
        cin>>x;
        f[x]++;
    }

    for(int bit=1; bit<m; bit*=2){
        for(int i=0; i<m; i++){
            if(!(bit&i))f[i]=(f[i]+f[i|bit])%mod;
        }
    }

    for(int i=0; i<m; i++){
        f[i]=(expbin(2, f[i])+mod-1)%mod;
    }

    for(int bit=1; bit<m; bit*=2){
        for(int i=0; i<m; i++){
            if(!(bit&i))f[i]=(f[i]-f[i|bit]+mod)%mod;
        }
    }

    for(int i=0; i<=n; i++)cout<<f[i]<<' ';
    
    return 0;
}
