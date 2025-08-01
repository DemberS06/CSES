// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    auto expbin = [](long long x, long long y){
        long long ans=1;
        while(y){
            if(y&1)ans=ans*x%mod;
            x=x*x%mod;
            y/=2;
        }
        return ans;
    };

    int n, m;
    cin>>n>>m;

    long long ans=0;
    for(int i=0; i<n; i++)ans=(ans+expbin(m, __gcd(i, n)))%mod;

    cout<<ans*expbin(n, mod-2)%mod;;

    return 0;
}