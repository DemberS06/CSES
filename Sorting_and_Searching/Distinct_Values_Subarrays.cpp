//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, ans=0;
    cin>>n;
 
    multiset<int> f;
    vector<int> a(n);
    for(auto& u:a)cin>>u;
 
    for(int i=0, j=0; i<n; i++){
        f.insert(a[i]);
        while(f.count(a[i])>1)f.erase(f.find(a[j])), j++;
        ans+=f.size();
    }
 
    cout<<ans;
 
    return 0;
}