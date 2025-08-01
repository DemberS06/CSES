// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin>>n;

    if(n&1){
        cout<<0;
        return 0;
    }

    function<long long(long long, long long)> Fermat = [&](long long x, long long y){
        long long ans=1;
        while(y){
            if(y&1)ans=ans*x%mod;
            x=x*x%mod;
            y/=2;
        }
        return ans;
    };

    vector<long long> fac(n+1, 1), rev(n+1, 1);

    for(int i=1; i<=n; i++)fac[i]=fac[i-1]*i%mod;
    rev[n]=Fermat(fac[n], mod-2);
    for(int i=n; i>0; i--)rev[i-1]=rev[i]*i%mod;

    n/=2;

    auto nenk = [&](int n, int k){
        return(fac[n]*rev[k])%mod*rev[n-k]%mod;
    };

    cout<<(nenk(2*n, n)-nenk(2*n, n-1)+mod)%mod;

    return 0;
}