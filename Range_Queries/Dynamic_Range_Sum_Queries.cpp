// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

struct SGT{
    int n;
    vector<long long> sgt;
    
    SGT(int _n): n(_n), sgt(4*n, 0){}

    void update(int p, int delta, int i, int l, int r){
        if(l>r || l>p || r<p)return;
        if(l==r){
            sgt[i]=delta;
            return;
        }
        update(p, delta, 2*i+1, l, (l+r)/2);
        update(p, delta, 2*i, (l+r)/2+1, r);

        sgt[i]=sgt[2*i]+ sgt[2*i+1];
    }

    void update(int p, int delta){
        update(p, delta, 1, 1, n);
    }

    long long query(int p, int q, int i, int l, int r){
        if(l>r || l>q || r<p)return 0;
        if(l>=p && r<=q)return sgt[i];
        return query(p, q, 2*i+1, l, (l+r)/2)+ 
               query(p, q, 2*i, (l+r)/2+1, r);
    }

    long long query(int l, int r){
        return query(l, r, 1, 1, n);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, q;
    cin>>n>>q;

    SGT sgt(n);
    
    for(int i=1, x; i<=n; i++){
        cin>>x;
        sgt.update(i, x);
    }

    while(q--){
        int x, l, r;
        cin>>x>>l>>r;
        if(x==1)sgt.update(l, r);
        else cout<<sgt.query(l, r)<<"\n";
    }
    
    return q+1;
}