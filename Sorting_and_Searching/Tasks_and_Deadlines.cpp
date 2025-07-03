//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, ans=0;
    cin>>n;
    vector<long long> v(n);
    
    for(int i=0, x; i<n; i++){
        cin>>v[i]>>x;
        ans+=x;
    }
    
    sort(v.rbegin(), v.rend());
    for(int i=0; i<n; i++)ans-=(i+1)*v[i];
    
    cout<<ans;

    return 0;
}