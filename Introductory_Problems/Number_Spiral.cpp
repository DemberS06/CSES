//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

long long n, m, ans;

void solve(){
    cin>>n>>m;
    
    ans=max(n,m);
    ans=ans*(ans-1)+1;
    
    if(n>m){
        if(n%2==0)ans+=n-m;
        else ans-=n-m;
    }
    else{
        if(m%2==0)ans+=n-m;
        else ans-=n-m;
    }
    
    cout<<ans<<"\n";
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1;
    cin>>t;

    while(t--)solve();
    
    return t+1;
}
