// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, k, ans=0;
    cin>>n>>k;

    vector<long long> v(k);
    for(auto& u:v)cin>>u;

    function<void(long long, int, int)> backtracking = [&](long long x, int i, int d){
        if(d&1)ans+=n/x;
        else ans-=n/x;

        for(++i; i<k; i++){
            if(n/v[i]<x || x*v[i]>n)continue;
            backtracking(x*v[i], i, d+1);
        }
    }; backtracking(1, -1, 0);

    cout<<ans+n;

    return 0;
}