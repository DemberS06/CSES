// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

struct SGT{
    int n;
    vector<long long> sgt;
    
    SGT(int _n): n(_n), sgt(4*n, 1e9){}

    void update(int p, int delta, int i, int l, int r){
        if(l>r || l>p || r<p)return;
        if(l==r){
            sgt[i]=delta;
            return;
        }
        update(p, delta, 2*i+1, l, (l+r)/2);
        update(p, delta, 2*i, (l+r)/2+1, r);

        sgt[i]=max(sgt[2*i], sgt[2*i+1]);
    }

    void update(int p, int delta){
        update(p, delta, 1, 1, n);
    }

    long long query(int p, int q, int i, int l, int r){
        if(l>r || l>q || r<p)return 0;
        if(l>=p && r<=q)return sgt[i];
        return max(query(p, q, 2*i+1, l, (l+r)/2), 
                   query(p, q, 2*i, (l+r)/2+1, r));
    }

    long long query(int l, int r){
        return query(l, r, 1, 1, n);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, q;
    cin>>n>>q;

    SGT sgt(n+1);
    vector<int> a(n+1);
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sgt.update(i, a[i]);
    }sgt.update(n+1, 1e9+7);

    function<int(int, int, int)> Binary = [&](int l, int r, int x){
        if(l==r)return l;
        int md =(l+r)/2;
        if(sgt.query(1, md)>=x)return Binary(l, md, x);
        return Binary(md+1, r, x);
    };

    while(q--){
        int x, y;
        cin>>x;
        y=Binary(1, n+1, x);
        if(y<=n){
            a[y]-=x;
            sgt.update(y, a[y]);
            cout<<y<<' ';
        }
        else cout<<"0 ";
    }
    
    return q+1;
}