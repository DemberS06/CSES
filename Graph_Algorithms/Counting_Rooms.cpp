// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, ans=0;
    cin>>n>>m;

    vector<vector<int>> a(n, vector<int> (m, 0));

    for(auto& v:a){
        for(auto& u:v){
            char c;
            cin>>c;
            u=(c=='#');
        }
    }

    function<void(int, int)> dfs = [&](int x, int y){
        if(a[x][y])return;
        a[x][y]++;
        if(x>0)dfs(x-1, y);
        if(y>0)dfs(x, y-1);
        if(x<n-1)dfs(x+1, y);
        if(y<m-1)dfs(x, y+1);
    };

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!a[i][j])dfs(i, j), ans++;
        }
    }    

    cout<<ans;

    return 0;
}