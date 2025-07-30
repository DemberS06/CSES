// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    function<long long(long long)> gauss = [&](long long x){
        long long y=x+1;
        if(x&1)y/=2;
        else   x/=2;

        return (x%mod)*(y%mod);
    };

    long long n, ans=0;
    cin>>n;

    for(long long h=1, t=n, x; h*h<=n; h++){
        ans=(ans+(n/h)*h)%mod;
        if(n/h<=h)continue;
        x=n/(h+1);
        ans=(ans+(gauss(t)-gauss(x)+mod)%mod*h%mod)%mod;
        t=x;
    }

    cout<<ans;

    return 0;
}