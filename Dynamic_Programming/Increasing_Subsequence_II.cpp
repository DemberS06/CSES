//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const long long mod=1e9+7;

struct Fenwick{
    int n;
    vector<long long> sum;

    void Resize(int _n){
        n=_n;
        sum.resize(n+1, 0);
    }

    void update(int i, long long delta){
        for(; i<=n; i+=-i&i){
            sum[i]=(sum[i]+delta)%mod;
        }
    }

    long long query(int i){
        long long ans=0;
        for(; i>0; i-=-i&i){
            ans=(ans+sum[i])%mod;
        }
        return ans;
    }
    long long query(int l, int r){
        return (query(r)-query(l-1)+mod)%mod;
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, cmp=0;
    cin>>n;
    
    vector<int> a(n);
    set<int> f;
    map<int, int> mp;

    for(auto& u:a){
        cin>>u;
        f.insert(u);
    }

    for(auto& u:f)mp[u]=++cmp;
    for(auto& u:a)u=mp[u];

    long long ans = 0;
    Fenwick v;
    v.Resize(f.size());

    for(auto& u:a){
        ans=(ans+v.query(u)+1)%mod;
        v.update(u+1, v.query(u)+1);
    }

    cout<<ans;

    return 0;
}