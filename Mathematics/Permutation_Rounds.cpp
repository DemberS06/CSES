// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long mod=1e9+7, N=2e5+1;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<int> f(N, 0);

    for(int i=2; i<N; i++){
        if(f[i])continue;
        for(int j=i; j<N; j+=i)f[j]=i;
    }

    int n;
    long long ans=1, sz=0;
    cin>>n;

    vector<int> p(n), vis(n, 0), fr(n+1, 0);

    for(auto& u:p){
        cin>>u;
        u--;
    }

    for(int i=0, cnt=0; i<n; i++){
        if(vis[i])continue;
        for(int x=i; !vis[x]; x=p[x])sz++, vis[x]=1;
        while(sz>1){
            cnt++;
            if(f[sz/f[sz]]!=f[sz])fr[f[sz]]=max(fr[f[sz]], cnt), cnt=0;
            sz/=f[sz];
        }sz--;
    }

    for(int i=2; i<=n; i++){
        if(!fr[i])continue;
        while(fr[i]--)ans=ans*i%mod;
    }

    cout<<ans;

    return 0;
}