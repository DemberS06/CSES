// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    
    vector<int> sgt(4*n, 0), v(n);
    
    function<void(int i, int l, int r, int p, int xd)> update=[&](int i, int l, int r, int p, int xd){
        if(l>r || l>p || r<p)return;
        if(l==r)return sgt[i]=xd, void();
        update(2*i, l, l+r>>1, p, xd), update(2*i+1, (l+r)/2+1, r, p, xd);
        return sgt[i]=max(sgt[2*i], sgt[2*i+1]), void();
    };
    
    function<int(int i, int l, int r, int p)> query=[&](int i, int l, int r, int p){
        if(l>r || l>p)return 0;
        if(r<=p)return sgt[i];
        return max(query(2*i, l, l+r>>1, p), query(2*i+1, (l+r)/2+1, r, p));
    };
    
    map<long long, long long> mp;
    set<long long> f;
    int xd=0;
    
    for(auto &u:v)cin>>u, f.insert(u);
    for(auto u:f)xd++, mp[u]=xd;
    
    for(int i=0; i<n; i++){
        cout<<query(1,1,n, mp[v[i]]-1)<<' ';
        update(1,1,n, mp[v[i]], i+1);
    }
    
    return 0;
}