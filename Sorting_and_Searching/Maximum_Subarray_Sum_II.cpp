// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, x, y, ans;
    cin>>n>>x>>y;
    
    vector<long long> a(n);
    multiset<long long> f;

    for(int i=0; i<n; i++){
        cin>>a[i];
        if(i)a[i]+=a[i-1];
    }
    
    for(int i=x; i<=y; i++)f.insert(a[i-1]);
    ans=*f.rbegin();
    
    for(int i=0; i<n-x; i++){
        f.erase((a[i+x-1]));
        f.insert(a[min(n-1, i+y)]);
        ans=max(ans, *f.rbegin()-a[i]);
    }
    
    cout<<ans;
    
    return 0;
}