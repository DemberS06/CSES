// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, ans=0;
    cin>>n;
    
    vector<long long> a(n);
    map<int, long long> mp;

    for(int i=0; i<n; i++){
        cin>>a[i];
        if(i)a[i]+=a[i-1];
    }
    
    for(int i=0; i<n; i++){
        a[i]=(a[i]%n+n)%n;
        mp[a[i]]++;
    }mp[0]++;
    
    for(auto& [x,y]:mp)ans+=y*(y-1)/2;
    
    cout<<ans;
    
    return 0;
}