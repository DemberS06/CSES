// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
struct Fenwick{
    int n;
    vector<long long> sum;
 
    Fenwick(int _n): n(_n), sum(n+1, 0){}
 
    void update(int i, long long delta){
        for(; i<=n; i+=-i&i)sum[i]+=delta;
    }
 
    long long query(int i){
        long long res=0;
        for(; i>0; i-=-i&i)res+=sum[i];
        return res;
    }
 
    long long query(int l, int r){
        return query(r)-query(l-1);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
 
    map<int, vector<int>> mp;
 
    for(int i=1, x; i<=n; i++){
        cin>>x;
        mp[x].push_back(i);
    }
 
    vector<vector<int>> v;
    Fenwick fwk(n);
 
    for(auto &[x, u]:mp){
        u.push_back(n+3);
        fwk.update(u[0], +1);
        for(int i=1; i<u.size(); i++){
            v.push_back({u[i-1], u[i], 0});
        }
    }
 
    vector<int> ans(m);
 
    for(int i=1, x, y; i<=m; i++){
        cin>>x>>y;
        v.push_back({x, y, i});
    }
 
    sort(v.begin(), v.end());
 
    for(auto u:v){
        if(!u[2]){
            fwk.update(u[0], -1);
            fwk.update(u[1], +1);
        }
        else ans[u[2]-1]=fwk.query(u[0], u[1]);
    }
 
    for(auto& u:ans)cout<<u<<'\n';
    
    return 0;
}