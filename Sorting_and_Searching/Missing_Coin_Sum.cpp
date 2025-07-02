//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, ans=0;
    cin>>n;
    
    vector<int> a(n);
    for(auto& u:a)cin>>u;
    sort(a.begin(), a.end());

    for(auto& u:a){
        if(u<=ans+1)ans+=u;
        else break;
    }

    cout<<ans+1;

    return 0;
}