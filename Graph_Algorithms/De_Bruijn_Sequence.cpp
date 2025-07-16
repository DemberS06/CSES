// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int m, n;
    cin>>m; m--;
    n=(1<<m);

    vector<int> vis(2*n+2, 0), ans(m, 0);
    vector<vector<int>> adj(n), jda(n);

    for(int i=0, x, y; i<n; i++){
        x=(2*i); y=(2*i+1);
        adj[i].push_back(y);
        adj[i].push_back(x);
    }

    int x=1;

    while(x!=0){
        vis[x]=1;
        ans.push_back(x&1);
        x%=(1<<m);
        for(auto& u:adj[x]){
            if(!vis[u]){
                x=u;
                break;
            }
        }
    }ans.push_back(0);

    for(auto &u:ans)cout<<u;
    

    return 0;
}