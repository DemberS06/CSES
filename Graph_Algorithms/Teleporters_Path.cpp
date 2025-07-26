// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector<int> ans, st, d(n, 0);

    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        d[y]++;
    }

    if(d[0]+1!=adj[0].size() || d[n-1]-1!=adj[n-1].size()){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    for(int i=1; i<n-1; i++){
        if(d[i]!=adj[i].size()){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    st.push_back(0);

    while(!st.empty()){
        auto x=st.back();

        if(!adj[x].empty()){
            auto u=adj[x].back();
            adj[x].pop_back();
            
            st.push_back(u);
        }
        else{
            ans.push_back(x);
            st.pop_back();
        }
    }

    reverse(ans.begin(), ans.end());

    if(ans.size()!=m+1 || ans[0]!=0 || ans.back()!=n-1)cout<<"IMPOSSIBLE";
    else for(auto& u:ans)cout<<u+1<<' ';

    return 0;
}