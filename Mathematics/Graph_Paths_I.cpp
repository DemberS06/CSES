// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
const long long mod=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    auto mult = [](vector<vector<long long>>& a, vector<vector<long long>>& b, int n){
        vector<vector<long long>> ans(n, vector<long long>(n, 0));
    
        for(int i=0; i<n; i++){
            for(int k=0; k<n; k++){
                if(a[i][k]==0)continue;
                for(int j=0; j<n; j++) {
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
                }
            }
        }
        return ans;
    };

    auto expbin = [&](vector<vector<long long>> x, long long y, int n){
        vector<vector<long long>> ans(n, vector<long long> (n, 0));
        for(int i=0; i<n; i++)ans[i][i]=1;

        while(y){
            if(y&1)ans=mult(ans, x, n);
            x=mult(x, x, n);
            y/=2;
        }
        return ans[0].back();
    };
    
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<long long>> ady(n, vector<long long> (n, 0));
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        ady[--x][--y]++;
    }

    cout<<expbin(ady, k, n);
    
    return 0;
}