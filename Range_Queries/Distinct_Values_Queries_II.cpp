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
 
        sgt[i]=min(sgt[2*i], sgt[2*i+1]);
    }
 
    void update(int p, int delta){
        update(p, delta, 1, 1, n);
    }
 
    long long query(int p, int q, int i, int l, int r){
        if(l>r || l>q || r<p)return 1e9;
        if(l>=p && r<=q)return sgt[i];
        return min(query(p, q, 2*i+1, l, (l+r)/2), 
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
    map<int, set<int>> mp;
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
        mp[a[i]].insert(i);
    }

    for(auto &[w, f]:mp){
        f.insert(0);
        f.insert(n+1);

        int x;
        for(auto& u:f){
            if(u)sgt.update(x, u);
            x=u;
        }
    }
 
    while(q--){
        int x, l, r;
        cin>>x>>l>>r;
        if(x==1){
            auto& g=mp[r];
            if(g.empty()){
                g.insert(0);
                g.insert(n+1);
            }
            auto& f=mp[a[l]];
            auto x=f.lower_bound(l), y=x;
            x--; y++;
            sgt.update(*x, *y);
            f.erase(l);

            a[l]=r;
            auto p=g.lower_bound(l), q=p;
            p--;
            sgt.update(*p, l);
            sgt.update(l, *q);
            g.insert(l);
        }
        else {
            if(sgt.query(l, r)>r)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    
    return q+1;
}