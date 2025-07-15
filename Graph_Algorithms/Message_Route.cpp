// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;

    vector<int> a(n+1, 0);
    vector<vector<int>> adj(n+1);
    vector<int> ans;
    ans.reserve(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(n);
    a[n]=2;

    while(!q.empty()){
        auto x=q.front();
        q.pop();

        for(auto& u:adj[x]){
            if(a[u])continue;
            a[u]=a[x]+1;
            q.push(u);
        }
    }

    if(!a[1]){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    function<void(int)> dfs = [&](int x){
        ans.push_back(x);
        for(auto& u:adj[x]){
            if(a[u]!=a[x]-1)continue;
            dfs(u);
            return;
        }
    };

    dfs(1);

    cout<<ans.size()<<'\n';
    for(auto& u:ans)cout<<u<<' ';

    return 0;
}