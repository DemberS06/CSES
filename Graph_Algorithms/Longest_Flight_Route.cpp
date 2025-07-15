// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
 
    vector<int> a(n, 0), b(n, 0), dis(n, 0), ans;
    vector<vector<int>> adj(n), jda(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        jda[y].push_back(x);
    }

    function<void(int)> vis = [&](int x){
        a[x]=1;
        for(auto& u:adj[x]){
            if(a[u])continue;
            vis(u);
        }
    };

    vis(0);

    if(!a[n-1]){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    for(int i=0; i<n; i++){
        if(!a[i])continue;
        for(auto& u:adj[i])b[u]++;
    }

    queue<int> q;
    q.push(0); dis[0]=2;

    while(!q.empty()){
        auto x=q.front();
        q.pop();

        for(auto& u:adj[x]){
            b[u]--;
            dis[u]=max(dis[u], dis[x]+1);
            if(b[u])continue;
            q.push(u);
        }
    }

    function<void(int)> dfs = [&](int x){
        ans.push_back(x);
        for(auto& u:jda[x]){
            if(dis[u]!=dis[x]-1)continue;
            dfs(u);
            return;
        }
    };

    dfs(n-1);

    cout<<ans.size()<<"\n";
    reverse(ans.begin(), ans.end());
    for(auto& u:ans)cout<<u+1<<' ';
 
    return 0;
}