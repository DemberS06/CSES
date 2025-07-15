// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, x, y;
    cin>>n>>m;

    vector<vector<int>> a(n, vector<int> (m, 0));

    string s="LRDU", ans;
    int dx[]={0, 0, 1, -1};
    int dy[]={-1, 1, 0, 0};

    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin>>c;
            a[i][j]-=(c=='#');
            if(c=='A')x=i, y=j;
            if(c=='B')a[i][j]=1, q.push({i, j});
        }
    }

    auto block = [&](int x, int y){
        if(x<0 || y<0)return 1;
        if(x>=n || y>=m)return 1;
        return 0;
    };

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for(int h=0; h<4; h++){
            if(block(i+dx[h], j+dy[h]) || a[i+dx[h]][j+dy[h]])continue;
            a[i+dx[h]][j+dy[h]]=a[i][j]+1;
            q.push({i+dx[h], j+dy[h]});
        }
    }

    if(a[x][y])cout<<"YES\n";
    else{
        cout<<"NO";
        return 0;
    }

    function<void(int, int)> dfs = [&](int x, int y){
        for(int h=0; h<4; h++){
            if(block(x+dx[h], y+dy[h]) || a[x+dx[h]][y+dy[h]]!=a[x][y]-1)continue;
            ans+=s[h];
            return dfs(x+dx[h], y+dy[h]);
        }
    };

    dfs(x, y);

    cout<<ans.size()<<'\n'<<ans;

    return 0;
}