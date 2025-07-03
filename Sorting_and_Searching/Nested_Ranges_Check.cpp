//Hola soy Dember :D
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
        long long ans=0;
        for(; i>0; i-=-i&i)ans+=sum[i];
        return ans;
    }

    long long query(int l, int r){
        return query(r)-query(l-1);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m=0;;

    cin>>n;
 
    vector<vector<int>> v(n, vector<int> (3));
    vector<int> in(n), on(n);
    set<int> f;
    map<int, int> coor;
    
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1]; v[i][2]=i;
        f.insert(v[i][0]);
    }
    
    for(auto &u:f)coor[u]=++m;
    for(auto &u:v)u[0]=coor[u[0]]; 
    
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
        if(b[1]==a[1])return a[0]>b[0];
        return a[1]<b[1];
    });

    Fenwick Pre, Pos;
    Pre.Resize(m);
    Pos.Resize(m);
    
    for(auto &u:v){
        in[u[2]]+=Pre.query(u[0], m);
        Pre.update(u[0], 1);
    }
 
    reverse(v.begin(), v.end());

    for(auto &u:v){
        on[u[2]]=Pos.query(1, u[0]);
        Pos.update(u[0], 1);
    }
 
    for(auto& u:in)cout<<(u>0)<<' ';cout<<"\n";
    for(auto& u:on)cout<<(u>0)<<' ';
 
    return 0;
}