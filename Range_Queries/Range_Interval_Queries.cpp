// hola soy Dember :D
#include<bits/stdc++.h>

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
    
    int n, m;
    cin>>n>>m;

    vector<int> ans(m, 0);
    vector<vector<int>> f;

    for(int i=1, x; i<=n; i++){
        cin>>x;
        f.push_back({x, i});
    }

    for(int i=0, a, b, c, d; i<m; i++){
        cin>>a>>b>>c>>d;
        f.push_back({c-1, b, a, i});
        f.push_back({d  , b, a, i, 0});
    }

    sort(f.begin(), f.end(), [](vector<int>& a, vector<int>& b){
        if(a[0]!=b[0])return a[0]<b[0];
        return a.size()<b.size();
    });

    Fenwick fnw(n);

    for(auto& v:f){
        if(v.size()==2)fnw.update(v[1], 1);
        else if(v.size()==4)ans[v[3]]-=fnw.query(v[2], v[1]);
        else ans[v[3]]+=fnw.query(v[2], v[1]);
    }

    for(auto& u:ans)cout<<u<<'\n';

    return 0;
}