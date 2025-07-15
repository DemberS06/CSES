// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
 
    vector<int> a(n, 0), b(n, 0), ans;
    vector<vector<int>> adj(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
    }

    function<void(int)> dfs = [&](int x){
        a[x]=1;
        for(auto& u:adj[x]){
            if(a[u])continue;
            dfs(u);
        }

        int ok=1;
        for(auto& u:adj[x])ok&=b[u];

        if(ok){
            ans.push_back(x);
            b[x]=1;
        }
    };

    for(int i=0; i<n; i++){
        if(!a[i])dfs(i);
    }
 
    if(ans.size()!=n)cout<<"IMPOSSIBLE";
    else {
        reverse(ans.begin(), ans.end());
        for(auto& u:ans)cout<<u+1<<' ';
    }
 
    return 0;
}