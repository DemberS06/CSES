//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, k;
    set<long long> f, g;

    cin>>n;
    
    f.insert(0);
    
    while(n--){
        cin>>k;
        
        for(auto &u:f)g.insert(u+k);
        for(auto &u:g)f.insert(u);

        g.clear();
    }
    
    f.erase(0);
    
    cout<<f.size()<<'\n';
    for(auto u:f)cout<<u<<' ';
 
    return n+1;
}