// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio();
    
    long long n, k; 
    cin>>k>>n;
    
    multiset<long long> ans; ans.insert(k);
    vector<long long> v(n);
    
    for(auto &u:v)cin>>u; v.push_back(0), v.push_back(k);
    
    vector<pair<long long, int>> cpy(n+2);
    for(int i=0; i<=n+1; i++)cpy[i].first=v[i], cpy[i].second=i;
    sort(cpy.begin(), cpy.end());
    
    vector<int> l(n+2), r(n+2);
    
    for(int i=1; i<=n; i++){
        l[cpy[i].second]=cpy[i-1].second;
        r[cpy[i].second]=cpy[i+1].second;
    }
    
    long long x, y;
    
    for(int i=n-1; i>0; i--){
        x=l[i]; y=r[i];
        r[x]=y;
        l[y]=x;
    }
    
    for(auto &u:l)u=v[u];
    for(auto &u:r)u=v[u];
    
    for(int i=0; i<n; i++){
        x=l[i]; y=r[i];
        ans.erase(ans.find(y-x));
        ans.insert(v[i]-x);
        ans.insert(y-v[i]);
        cout<<*ans.rbegin()<<' ';
    }
    
    return 0;
}