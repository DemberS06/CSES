//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, ans=1e18;
    cin>>n;
    
    vector<long long> a(n);
    for(auto &u:a)cin>>u;
    
    for(int h=0; h<(1<<n); h++){
        long long sum=0;
        for(auto &u:a)sum+=u;
        for(int i=1; i<=n; i++)if((h>>i)&1)sum-=a[i-1];
        ans=min(ans, abs(sum));
    }
    
    cout<<ans;
 
    return 0;
}