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
    
    int n, k=1e6+1;
    cin>>n;
 
    Fenwick fwk(2*k);
    vector<vector<int>> sweep;
    sweep.reserve(n);
 
    for(int i=0, x, y, p, q; i<n; i++){
        cin>>x>>y>>p>>q;
        if(x==p)sweep.push_back({x, y+k, q+k});
        else sweep.push_back({x, -1, y+k}), sweep.push_back({p+1, -2, q+k});
    }
 
    sort(sweep.begin(), sweep.end());
    
    long long ans=0;
 
    for(auto &v:sweep){
        if(v[1]==-1)fwk.update(v[2], 1);
        else if(v[1]==-2)fwk.update(v[2], -1);
        else ans+=fwk.query(v[1], v[2]);
    }
 
    cout<<ans;
    
    return 0;
}