//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const long long mod=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, ans=1;
    cin>>n;
 
    map<int, int> mp;
 
    for(int i=0, x; i<n; i++){
        cin>>x;
        mp[x]++;
    }

    for(auto& [u, x]:mp)ans=ans*(x+1)%mod;
 
    cout<<(ans+mod-1)%mod;
 
    return 0;
}