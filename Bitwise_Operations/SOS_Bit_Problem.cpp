// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m=1<<20;
    cin>>n;
    
    vector<int> f(m, 0), g, a(n);

    for(auto& u:a){
        cin>>u;
        f[u]++;
    }g=f;
    
    for(int bit=1; bit<m; bit*=2){
        for(int i=0; i<m; i++){
            if(i&bit)f[i]+=f[i^bit];
        }
    }

    for(int bit=1; bit<m; bit*=2){
        for(int i=0; i<m; i++){
            if(!(i&bit))g[i]+=g[i|bit];
        }
    }

    for(auto& u:a){
        cout<<f[u]<<' '<<g[u]<<' '<<n-f[(~u)&(m-1)]<<"\n";
    }
    
    return 0;
}
