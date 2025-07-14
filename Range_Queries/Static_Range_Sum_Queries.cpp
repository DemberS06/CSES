// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, q;
    cin>>n>>q;

    vector<long long> a(n+1, 0);
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    
    while(q--){
        int l, r;
        cin>>l>>r;
        
        cout<<a[r]-a[l-1]<<"\n";
    }
    
    return q+1;
}