//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, ans=-1e15, sum=0, mn=0;
    cin>>n;
    
    for(int i=0, x; i<n; i++){
        cin>>x;
        sum+=x;
        ans=max(ans, sum-mn);
        mn=min(mn, sum);
    }

    cout<<ans;
    
    return 0;
}