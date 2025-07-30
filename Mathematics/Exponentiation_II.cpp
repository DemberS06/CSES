// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    function<long long(long long, long long, long long)> expbin = [](long long x, long long y, long long mod){
        long long ans=1;

        while(y){
            if(y&1)ans=ans*x%mod;
            x=x*x%mod;
            y/=2;
        }

        return ans;
    };

    int t;
    cin>>t;

    while(t--){
        long long a, b, c;
        cin>>a>>b>>c;
        cout<<expbin(a, expbin(b, c, 1e9+6), 1e9+7)<<"\n";
    }

    return t+1;
}