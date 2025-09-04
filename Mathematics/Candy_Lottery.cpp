//hola soy Dember :D

#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    function<long double(long double, int)> expbin = [](long double x, int y){
        long double res=1;

        while(y){
            if(y&1)res*=x;
            x*=x;
            y/=2;
        }

        return res;
    };

    long double n, k, ans=0;
    cin>>n>>k;
    
    for(long double i=1; i<=k; i++){
        for(long double j=1; j<=n; j++){
            ans+=expbin((i-1)/k, j-1)*expbin(i/k, n-j+1);
        }
    }

    cout<<fixed<<setprecision(6)<<ans;

    return 0;
}