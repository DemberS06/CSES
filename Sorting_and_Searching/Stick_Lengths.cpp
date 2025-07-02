//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, ans=1e15;
    cin>>n;
    
    vector<int> a(n);

    for(auto& u:a)cin>>u;

    auto Simulation = [&](int x){
        long long sum=0;

        for(auto& u:a)sum+=abs(u-x);

        return sum;
    };

    function<void(int, int)> Ternary = [&](int l, int r){
        if(l>r)return;
        int m1=l+(r-l)/3, m2=l+2*(r-l)/3;
        long long p1=Simulation(m1), p2=Simulation(m2);
        ans=min({ans, p1, p2});

        if(p1<p2)Ternary(l, m2-1);
        else Ternary(m1+1, r);
    };

    Ternary(1, 1e9+7);

    cout<<ans;
    
    return 0;
}