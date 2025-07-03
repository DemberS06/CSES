//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, k, ans=0;
    cin>>n>>k;

    vector<long long> a(n);
    for(auto& u:a)cin>>u;

    auto Simulation = [&](long long x){
        long long sum=0;

        for(auto& u:a){
            sum+=x/u;
            if(sum>=k)return 1;
        }
        return 0;
    };

    function<void(long long, long long)> Binary = [&](long long l, long long r){
        if(l>r)return;
        long long md=l+(r-l)/2;
        if(Simulation(md))ans=md, Binary(l, md-1);
        else Binary(md+1, r);
    };

    Binary(1, 1e18+1);
    cout<<ans;
 
    return 0;
}