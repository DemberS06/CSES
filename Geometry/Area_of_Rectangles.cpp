// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct SGT{
    int n;
    vector<long long> sgt, val;
    
    SGT(int _n): n(_n), sgt(4*n, 0), val(4*n, 0){}
 
    void update(int p, int q, int delta, int i, int l, int r){
        if(l>r || l>q || r<p)return;
        
        if(p<=l && r<=q)sgt[i]+=delta;
        else{
            update(p, q, delta, 2*i+1, l, (l+r)/2);
            update(p, q, delta, 2*i, (l+r)/2+1, r);
        }
        if(sgt[i]>0)val[i]=r-l+1;
        else if(l==r)val[i]=0;
        else val[i]=val[2*i]+val[2*i+1];
    }
 
    void update(int p, int q, int delta){
        update(p, q, delta, 1, 0, n);
    }
 
    long long query(){
        return val[1];
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, k=1e6;
    cin>>n;

    vector<vector<vector<int>>> sweep(2*k+2);
    SGT sgt(2*k+2);

    for(int i=0, x, y, p, q; i<n; i++){
        cin>>x>>y>>p>>q;
        if(q!=y)sweep[x+1e6].push_back({y+k, q+k-1, 1});
        if(q!=y)sweep[p+1e6].push_back({y+k, q+k-1, -1});
    }

    long long ans=0;

    for(int i=0; i<=2e6; i++){
        for(auto& v:sweep[i])sgt.update(v[0], v[1], v[2]);
        ans+=sgt.query();
    }

    cout<<ans;

    return 0;
}