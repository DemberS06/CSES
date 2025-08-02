// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    auto mult = [](vector<vector<long long>>& a, vector<vector<long long>>& b, int n){
        vector<vector<long long>> ans(n, vector<long long>(n, 2e18));
    
        for(int i=0; i<n; i++){
            for(int k=0; k<n; k++){
                if(a[i][k]>1e18)continue;
                for(int j=0; j<n; j++){
                    if(b[k][j]>1e18)continue;
                    ans[i][j]=min(ans[i][j], a[i][k]+b[k][j]);
                }
            }
        }
        return ans;
    };

    auto expbin = [&](vector<vector<long long>> x, long long y, int n){
        vector<vector<long long>> ans(n, vector<long long> (n, 2e18));
        for(int i=0; i<n; i++)ans[i][i]=0;

        while(y){
            if(y&1)ans=mult(ans, x, n);
            x=mult(x, x, n);
            y/=2;
        }
        return ans[0].back();
    };
    
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<long long>> ady(n, vector<long long> (n, 2e18));
    for(int i=0, x, y, z; i<m; i++){
        cin>>x>>y>>z;--x; --y;
        ady[x][y]=min(ady[x][y], z+0ll);
    }

    long long ans = expbin(ady, k, n);

    if(ans<=1e18)cout<<ans;
    else cout<<-1;
    
    return 0;
}