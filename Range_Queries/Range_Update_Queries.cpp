// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

struct SGT{
    int n;
    vector<long long> sgt;
    
    SGT(int _n): n(_n), sgt(4*n, 0){}

    void update(int p, int q, int delta, int i, int l, int r){
        if(l>r || l>q || r<p)return;
        if(l>=p && r<=q){
            sgt[i]+=delta;
            return;
        }
        update(p, q, delta, 2*i+1, l, (l+r)/2);
        update(p, q, delta, 2*i, (l+r)/2+1, r);
    }

    void update(int p, int q, int delta){
        update(p, q, delta, 1, 1, n);
    }

    long long query(int p, int i, int l, int r){
        if(l>r || l>p || r<p)return 0;
        if(l==r)return sgt[i];
        return sgt[i]+
               query(p, 2*i+1, l, (l+r)/2)+ 
               query(p, 2*i, (l+r)/2+1, r);
    }

    long long query(int p){
        return query(p, 1, 1, n);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, q;
    cin>>n>>q;

    SGT sgt(n);
    
    for(int i=1, x; i<=n; i++){
        cin>>x;
        sgt.update(i, i, x);
    }
    
    while(q--){
        int x, p;
        cin>>x>>p;
        if(x==1){
            int q, delta;
            cin>>q>>delta;
            sgt.update(p, q, delta);
        }
        else cout<<sgt.query(p)<<"\n";
    }
    
    return q+1;
}