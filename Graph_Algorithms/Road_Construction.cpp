// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    int ans=1;
    vector<int> root(n);
    vector<vector<int>> component(n);

    for(int i=0; i<n; i++)root[i]=i, component[i]={i};

    auto dsu = [&](int x, int y){
        if(component[x].size()<component[y].size())swap(x, y);
        for(auto& u:component[y]){
            root[u]=x;
            component[x].push_back(u);
        }
        component[y].clear();

        ans=max(ans, (int)component[x].size());
    };

    while(m--){
        int x, y;
        cin>>x>>y;

        if(root[--x]!=root[--y])dsu(root[x], root[y]), n--;

        cout<<n<<' '<<ans<<"\n";
    }
    
    return m+1;
}