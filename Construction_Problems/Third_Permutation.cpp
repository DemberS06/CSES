// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, p=0;
    cin>>n;
    
    vector<int>a(n), b(n), c(n), x, y;
    for(auto& u:a)cin>>u;
    for(auto& u:b)cin>>u;

    if(n==2){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    for(int i=0; i<n; i++){
        if(b[(i+1)%n]!=a[i])c[(i+1)%n]=a[i];
        else x.push_back((i+1)%n), y.push_back(a[i]);
    }
    n=x.size();
    for(int i=0; i<n; i++){
        c[x[i]]=y[(i+n-1)%n];
    }

    if(n==1)swap(c[x[0]], c[(x[0]+n-1)%n]);

    for(auto& u:c)cout<<u<<' ';

    return 0;
}