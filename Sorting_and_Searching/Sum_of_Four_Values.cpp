// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, x;
    map<long long, vector<long long>> mp;
    
    cin>>n>>x;
    
    vector<long long> v(n);
    for(auto &u:v)cin>>u;
    
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<i; j++)if(!mp[x-v[i]-v[j]].empty()){cout<<j+1<<' '<<i+1<<' '<<mp[x-v[i]-v[j]][0]<<' '<<mp[x-v[i]-v[j]][1]; return 0;}
        for(int j=i+1; j<n; j++)mp[v[i]+v[j]]={i+1, j+1};
    }
    
    cout<<"IMPOSSIBLE";
    
    return 0;
}