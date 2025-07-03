// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, x, ans=0, sum=0;
    cin>>n>>x;
    
    map<long long, long long> mp; mp[0]++;
    
    for(long long i=0, u; i<n; i++){
        cin>>u; sum+=u;
        ans+=mp[sum-x];
        mp[sum]++;
    }
    
    cout<<ans;
    
    return 0;
}