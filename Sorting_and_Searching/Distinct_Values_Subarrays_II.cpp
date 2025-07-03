// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, k, ans=0;
    cin>>n>>k;

    vector<int> a(n);
    set<int> f;
    map<int,int> mp;
    
    for(auto& u:a)cin>>u;
    
    for(int i=0, j=0; i<n; i++){
        mp[a[i]]++;
        f.insert(a[i]);
        while(j<n && f.size()>k){
            mp[a[j]]--;
            if(mp[a[j]]==0)f.erase(a[j]);
            j++;
        }
        ans+=i-j+1;
    }
    
    cout<<ans;
 
    return 0;
}
