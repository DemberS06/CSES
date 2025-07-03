// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

struct Fenwick{
    int n;
    vector<long long> sum;
    
    void Resize(int _n){
        n=_n;
        sum.resize(n+1, 0);
    }

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
    
    long long n, k, ans=0, x=0;
    cin>>n>>k;

    vector<int> a(n);
    map<int, int> mp;
    set<int> f;

    for(auto& u:a){
        cin>>u;
        f.insert(u);
    }

    for(auto& u:f)mp[u]=++x;
    for(auto& u:a)u=mp[u];

    Fenwick b;
    b.Resize(x);

    for(int i=0; i<n; i++){
        ans+=b.query(a[i]+1, x);
        b.update(a[i], 1);
        if(i>=k-1){
            cout<<ans<<' '; 
            ans-=b.query(a[i-k+1]-1);
            b.update(a[i-k+1], -1);
        }
    }
    
    return 0;
}