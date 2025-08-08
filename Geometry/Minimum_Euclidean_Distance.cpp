// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    long long ans=8e18, d;
    int n;
    cin>>n;

    vector<pair<long long, long long>> v(n);
    set<pair<long long, long long>> f;

    for(auto& [x, y]:v)cin>>x>>y;
    sort(v.begin(), v.end());

    for(int i=0, j=0; i<n; i++){
        auto& [x, y]=v[i];

        d=sqrt(ans);
        while(j<i && x-v[j].first>d)f.erase({v[j].second, v[j].first}), j++;

        for(auto l=f.lower_bound({y-d, -1e9}), r=f.upper_bound({y+d, 1e9}); l!=r; l++){
            auto& [q, p] = *l;
            ans=min(ans, (x-p)*(x-p)+(y-q)*(y-q));
        }

        f.insert({y, x});
    }
    
    cout<<ans;

    return 0;
}