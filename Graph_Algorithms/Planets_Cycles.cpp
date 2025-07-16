// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;

    vector<int> a(n), b(n, 0), c(n, 1), d(n, 0), v(n, 0);
    vector<vector<int>> adj(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
        adj[--a[i]].push_back(i);
        b[a[i]]++;
    }

    queue<int> q;

    for(int i=0; i<n; i++){
        if(b[i]==0)q.push(i);
    }

    while(!q.empty()){
        auto i=q.front();
        q.pop();
        c[i]=0;
        b[a[i]]--;
        if(!b[a[i]])q.push(a[i]);
    }

    function<void(int)> dfs = [&](int x){
        for(auto& u:adj[x]){
            if(c[u])continue;
            d[u]=d[x]+1;
            dfs(u);
        }
    };

    for(int i=0; i<n; i++){
        if(!c[i] || v[i]==2)continue;
        for(int x=i; x!=i || v[x]<2; x=a[x]){
            v[x]++;
            if(v[x]==1)d[i]++;
            else{
                d[x]=d[i];
                dfs(x);
            }
        }
    }

    for(auto& u:d)cout<<u<<' ';

    return 0;
}