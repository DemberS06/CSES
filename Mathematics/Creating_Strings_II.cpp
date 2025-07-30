// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long mod=1e9+7, N=1e6+1;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    function<long long(long long, long long)> Fermat = [&](long long x, long long y){
        long long ans=1;
        while(y){
            if(y&1)ans=ans*x%mod;
            x=x*x%mod;
            y/=2;
        }
        return ans;
    };

    vector<long long> fac(N, 1), rev(N, 1);

    for(int i=1; i<N; i++)fac[i]=fac[i-1]*i%mod;
    rev[N-1]=Fermat(fac[N-1], mod-2);
    for(int i=N-1; i>0; i--)rev[i-1]=rev[i]*i%mod;

    string s;

    cin>>s;
    long long ans=1, n=s.size();
    vector<int> fr(30, 0);

    for(auto& u:s)fr[u-'a']++;
    for(auto& u:fr)ans=((ans*fac[n]%mod)*rev[u]%mod)*rev[n-u]%mod, n-=u;

    cout<<ans;

    return n;
}