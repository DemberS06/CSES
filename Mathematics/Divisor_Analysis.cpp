// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7, N=1e6+1; 

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    function<long long(long long, long long)> expbin = [&](long long x, long long y){
        long long ans=1;
        while(y){
            if(y&1)ans=ans*x%mod;
            x=x*x%mod;
            y/=2;
        }
        return ans;
    };

    int n, sp=0;
    cin>>n;
    long long  x=1, sum=1, num=1, prod, exp=1, s=1;
    
    while(n--){
        long long p, k;
        cin>>p>>k;

        num=num*(k+1)%mod;
        sum=(sum*(expbin(p, k+1)+mod-1)%mod)*expbin(p-1, mod-2)%mod;

        x=x*expbin(p, k)%mod;
        s=s*expbin(p, k/2)%mod;

        if(!sp && k&1)exp=(k+1)/2*exp%(mod-1), sp=1;
        else exp=exp*(k+1)%(mod-1);
    }

    if(sp)prod=expbin(x, exp);
    else  prod=expbin(s, exp);

    cout<<num<<' '<<sum<<' '<<prod;

    return n+1;
}