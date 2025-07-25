// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n);
    vector<int> ans, st, vis(m, 0), d(n, 0);

    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back({--y, i});
        adj[y].push_back({x, i});
        d[x]++; d[y]++;
    }

    for(int i=0; i<n; i++){
        if(d[i]&1){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    st.push_back(0);

    while(!st.empty()){
        auto x=st.back();

        if(d[x])while(!adj[x].empty()){
            auto [u, i]=adj[x].back();
            adj[x].pop_back();
            
            if(vis[i])continue;
            d[x]--; d[u]--;
            vis[i]=1;
            
            st.push_back(u);
            break;
        }
        else{
            st.pop_back();
            ans.push_back(x);
        }
    }

    if(ans.size()==m+1)for(auto& u:ans)cout<<u+1<<' ';
    else cout<<"IMPOSSIBLE";

    return 0;
}