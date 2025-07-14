// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
struct Fenwick{
    int n;
    vector<long long> sum;

    Fenwick(int _n): n(_n), sum(n+1, 0){}
 
    void update(int i, int delta){
        for(; i<=n; i+=-i&i)sum[i]+=delta;
    }
 
    int query(int i){
        int res=0;
        for(; i>0; i-=-i&i)res+=sum[i];
        return res;
    }
 
    int query(int l, int r){
        return query(r)-query(l-1);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k, x=0;
    cin>>n>>k;
 
    vector<int> a(n), f;
    vector<vector<int>> v(k, vector<int> (3));
    map<int, int> mp;
    f.reserve(n+k);
    
    for(auto& u:a){
        cin>>u;
        f.push_back(u);
    }
    
    char c;
    for(auto& u:v){
        cin>>c>>u[1]>>u[2];
        u[0]=(c=='?');
        if(!u[0])f.push_back(u[2]);
    }
    
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());
    set<int> g;
    
    for(auto& u:f)mp[u]=++x, g.insert(u);

    for(auto& u:v){
        if(!u[0])continue;
        u[1]=*g.lower_bound(u[1]);
        auto x=g.upper_bound(u[2]);
        x--;
        u[2]=*x;
    }
 
    Fenwick b(x);

    for(auto& u:a)b.update(mp[u], 1);
 
    for(auto& u:v){
        if(u[0])cout<<b.query(mp[u[1]], mp[u[2]])<<"\n";
        else{
            b.update(mp[a[u[1]-1]], -1);
            b.update(mp[u[2]], 1);
            a[u[1]-1]=u[2];
        }
    }
    
    return 0;
}