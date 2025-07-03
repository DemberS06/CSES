// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    set<pair<int, int>> f; f.insert({-1, 1});
    map<int, int> mp;
    for(auto& u:a)cin>>u;

    for(int i=0; i<n; i++){
        auto [x, y]=*f.lower_bound({mp[a[i]], -a[i]});
        if(y==-a[i])f.erase({x, y});
        mp[a[i]]++;
        f.insert({mp[a[i]], -a[i]});
        
        if(i>=k-1){
            cout<<-(*f.rbegin()).second<<' '; 
            auto u=*f.lower_bound({mp[a[i-k+1]], -a[i-k+1]});
            f.erase(u);
            mp[a[i-k+1]]--;
            f.insert({mp[a[i-k+1]], -a[i-k+1]});
        }
    }
    
    return 0;
}