//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, k, ans=0;
    cin>>n>>m>>k;

    vector<int> a(n), b(m);
    
    for(auto& u:a)cin>>u;
    for(auto& u:b)cin>>u;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0, j=0; i<n; i++){
        while(j<m && b[j]+k<a[i])j++;
        if(j<m && b[j]<=a[i]+k)ans++, j++;
    }

    cout<<ans;
    
    return 0;
}