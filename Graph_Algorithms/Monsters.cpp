// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, x, y, ok=0;
    cin>>n>>m;

    vector<vector<int>> a(n, vector<int> (m, 0)), b=a;

    string s="RLUD", ans;
    int dx[]={0, 0, 1, -1};
    int dy[]={-1, 1, 0, 0};

    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin>>c;
            a[i][j]-=(c=='#');
            if(c=='A')x=i, y=j;
            if(c=='M')a[i][j]=2, q.push({i, j});
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

    b[x][y]=2;
    q.push({x, y});

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for(int h=0; h<4; h++){
            if(block(i+dx[h], j+dy[h]) || b[i+dx[h]][j+dy[h]] || (a[i+dx[h]][j+dy[h]]<=b[i][j]+1 && a[i+dx[h]][j+dy[h]]))continue;
            b[i+dx[h]][j+dy[h]]=b[i][j]+1;
            q.push({i+dx[h], j+dy[h]});
        }
    }

    function<void(int, int)> dfs = [&](int x, int y){
        for(int h=0; h<4; h++){
            if(block(x+dx[h], y+dy[h]) || b[x+dx[h]][y+dy[h]]!=b[x][y]-1)continue;
            ans+=s[h];
            return dfs(x+dx[h], y+dy[h]);
        }
    };

    for(int i=0 ; i<n && ans.empty(); i++){
        if     (b[i][0]  >0)dfs(i, 0  ), ok=1;
        else if(b[i][m-1]>0)dfs(i, m-1), ok=1;
    }
    for(int i=0 ; i<m && ans.empty(); i++){
        if     (b[0][i]  >0)dfs(0, i  ), ok=1;
        else if(b[n-1][i]>0)dfs(n-1, i), ok=1;
    }

    if(!ok)cout<<"NO";
    else{
        cout<<"YES\n";
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<'\n'<<ans;
    }


    return 0;
}