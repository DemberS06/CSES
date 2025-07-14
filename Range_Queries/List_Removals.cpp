// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
struct SGT{
    int n;
    vector<long long> sgt;
    
    SGT(int _n): n(_n), sgt(4*n, 0){}
 
    void update(int p, int delta, int i, int l, int r){
        if(l>r || l>p || r<p)return;
        
        sgt[i]+=delta;
        if(l==r)return;
        
        update(p, delta, 2*i+1, l, (l+r)/2);
        update(p, delta, 2*i, (l+r)/2+1, r);
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
    
    int n;
    cin>>n;
 
    SGT sgt(n);
    vector<int> a(n);
    
    for(auto& u:a)cin>>u;

    function<int(int, int, int)> Binary = [&](int l, int r, int x){
        if(l==r)return l;
        int md=(l+r)/2;

        if(md-sgt.query(1, md)>=x)return Binary(l, md, x);
        return Binary(md+1, r, x);
    };
 
    for(int i=0, x, p; i<n; i++){
        cin>>x;
        
        p=Binary(1, n, x);
        sgt.update(p, 1);

        cout<<a[p-1]<<' ';
    }
    
    return 0;
}