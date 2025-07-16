// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    vector<int> ans, a(n, 0), st;
    vector<vector<int>> adj(n), used(n);

    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
        a[x]++;
        a[y]++;
    }

    for(int i=0;  i<n; i++){
        if(a[i]&1){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    st.push_back(0);

    while(!st.empty()){
        auto x=st.back();
        st.pop_back();
        ans.push_back(x);
        
        int y=adj[x].back();
        for(auto& u:adj[x]){
            if(!used[u].empty() && x==used[u].back())continue;
            if(a[u]==1){
                y=u;
                break;
            }
            if(a[u]>a[y])y=u;
        }
        if(a[y]){
            a[x]--;
            a[y]--;
            st.push_back(y);
            used[x].push_back(y);
        }
    }

    for(auto &u:ans)cout<<u+1<<' ';

    return 0;
}