// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, q;
    cin>>n>>m>>q;

    vector<vector<long long>> adj(n, vector<long long> (n, 1e18));
    
    for(int i=0, x, y, w; i<m; i++){
        cin>>x>>y>>w; x--; y--;
        adj[x][y]=adj[y][x]=min(adj[x][y], w+0ll);
    }

    auto floyd = [&](int x){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j]=min(adj[i][j], adj[i][x]+adj[x][j]);
            }
        }
    };

    for(int i=0; i<n; i++)adj[i][i]=0;
    for(int h=0; h<n; h++)floyd(h);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj[i][j]==1e18)adj[i][j]=-1;
        }
    }

    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<adj[--x][--y]<<"\n";
    }

    return q+1;
}