// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    set<pair<int, int>> f;
    vector<pair<int, int>> ans, v;
    ans.reserve(n); v.reserve(n);
    
    for(int i=1, x; i<=n; i++){
        cin>>x;
        f.insert({x, i});
    }

    while(!f.empty()){
        auto [x, id] = *f.rbegin();
        f.erase({x, id});
        while(x--){
            if(f.empty()){
                cout<<"IMPOSSIBLE";
                return 0;
            }
            auto [y, p] = *f.rbegin();
            f.erase({y, p});
            if(y==0){
                cout<<"IMPOSSIBLE";
                return 0;
            }
            ans.push_back({id, p});
            v.push_back({y-1, p});
        }
        for(auto& u:v)f.insert(u);
        v.clear();
    }

    cout<<ans.size()<<"\n";
    for(auto& [x, y]:ans)cout<<x<<' '<<y<<"\n";

    return 0;
}