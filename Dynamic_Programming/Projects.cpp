//Hola soy Dember :D
#include<bits/stdc++.h>
 
#define pb push_back
#define ll long long
#define F first
#define S second
 
using namespace std;
 
const ll N=2e5+5, md=1e9+7, inf=1e15;
 
ll n, a[N], b[N], p[N], dp[N], xd, zd, ans;;
vector<pair<ll,pair<ll,ll>>> v;
 
int main(){
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>xd>>zd>>p[i];
        v.pb({xd,{0,i}});
        v.pb({zd,{1,i}});
    }
    
    sort(v.begin(), v.end());
    
    xd=0;
    
    for(auto u:v){
        ll i=u.S.S;
        if(!u.S.F)dp[i]=dp[xd]+p[i];
        else{
            dp[i]=max(dp[i], dp[xd]);
            xd=i;
        }
    }
    
    for(int i=1; i<=n; i++)ans=max(ans,dp[i]);
    
    cout<<ans;
    
    return 0;
}