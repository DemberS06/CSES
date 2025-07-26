// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    vector<vector<vector<pair<int, int>>>> adj(8, vector<vector<pair<int, int>>> (8));
    vector<vector<int>> ans(8, vector<int> (8, 0));
    
    int dx[]={1, 1, -1, -1, 2, 2, -2, -2};
    int dy[]={2, -2, 2, -2, 1, -1, 1, -1};
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            for(int h=0; h<8; h++){
                int x=i+dx[h], y=j+dy[h];
                if(x<0 || x>7 || y<0 || y>7)continue;
                adj[i][j].push_back({x, y});
            }
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            sort(adj[i][j].begin(), adj[i][j].end(), [&](auto& a, auto& b){
                if(adj[a.first][a.second].size()!=adj[b.first][b.second].size())return adj[a.first][a.second].size()<adj[b.first][b.second].size();
                return min(a.first, 7-a.first) + min(a.second, 7-a.second) < min(b.first, 7-b.first) + min(b.second, 7-b.second);
            });
        }
    }

    int a, b, k=0;
    cin>>a>>b;
    
    function<void(int, int)> dfs = [&](int x, int y){
        k++;
        ans[x][y]=k;
        if(k==64)return;

        for(auto& [p, q]:adj[x][y]){
            if(ans[p][q])continue;
            dfs(p, q);
            if(k==64)return;
        }
        
        ans[x][y]=0;
        k--;
    };

    dfs(b-1, a-1);

    for(auto& v:ans){
        for(auto& u:v)cout<<u<<' ';
        cout<<"\n";
    }

    return 0;
}