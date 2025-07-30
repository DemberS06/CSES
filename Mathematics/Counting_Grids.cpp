// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long mod=1e9+7;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    function<long long(long long, long long)> expbin = [](long long x, long long y){
        long long ans=1;

        while(y){
            if(y&1)ans=ans*x%mod;
            x=x*x%mod;
            y/=2;
        }

        return ans;
    };

    long long n;
    cin>>n;

    long long r0=expbin(2, n*n), r180=expbin(2, (n*n+(n&1))/2), r90=expbin(2, (n*n+3*(n&1))/4);

    cout<<((r0+r180+2*r90)%mod)*expbin(4, mod-2)%mod;

    return 0;
}