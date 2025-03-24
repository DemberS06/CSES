#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

long long n, m, ans[N], a[N], sgt[4*N], p, q;
vector<vector<long long>> adj[N];

void act(int i=1, int l=1, int r=n){
    if(l>p || r<p || l>r)return;
    if(l==r)return sgt[i]=a[p], void();
    act(2*i, l, l+r>>1), act(2*i+1, (l+r)/2+1, r);
    return sgt[i]=sgt[2*i]+sgt[2*i+1], void();
}

long long que(int i=1, int l=1, int r=n){
    if(l>q || r<p || l>r)return 0;
    if(l>=p && r<=q)return sgt[i];
    return que(2*i, l, l+r>>1)+que(2*i+1, (l+r)/2+1, r);
}

void dfs(int x){
    for(auto &u:adj[x]){
        if(u[0]==-1)dfs(u[1]);
        else if(u[0])p=u[1], q=u[2], ans[u[0]]=que();
        else p=u[1], swap(a[p], u[2]), act();
    }
    reverse(adj[x].begin(), adj[x].end());
    for(auto &u:adj[x]){
        if(u[0])continue;
        p=u[1];
        swap(a[p], u[2]);
        act();
    }
    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;

    for(p=1; p<=n; act(), p++)cin>>a[p];
    
    int x=1, y=0;

    for(long long t, a, b, k; m; m--){
        cin>>t;
        if(t==1){
            cin>>k>>a>>b;
            adj[k].push_back({0, a, b});
        }
        if(t==2){
            cin>>k>>a>>b;y++;
            adj[k].push_back({y, a, b});
        }
        if(t==3){
            cin>>k;x++;
            adj[k].push_back({-1, x});
        }
    }
    
    dfs(1);

    for(int i=1; i<=y; i++)cout<<ans[i]<<'\n';

    return 0;
}