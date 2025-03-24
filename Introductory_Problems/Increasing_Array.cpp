//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, mx, ans=0;
    cin>>n;

    vector<long long> a(n);
    
    for(auto &u:a)cin>>u;
    
    mx=a[0];
    
    for(auto &u:a){
        ans+=max(0ll, mx-u);
        mx=max(mx, u);
    }
    
    cout<<ans;
 
    return 0;
}