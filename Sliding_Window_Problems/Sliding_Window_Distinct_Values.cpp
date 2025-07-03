// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k, ans=0;
    cin>>n>>k;

    vector<int> a(n);
    map<int, int> mp;
    for(auto& u:a)cin>>u;

    for(int i=0; i<n; i++){
        mp[a[i]]++;
        if(mp[a[i]]==1)ans++;
        if(i>=k-1){
            cout<<ans<<' '; 
            mp[a[i-k+1]]--;
            if(mp[a[i-k+1]]==0)ans--;
        }
    }
    
    return 0;
}