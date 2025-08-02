// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    auto expbin = [&](long long x, long long y){
        long long ans=1; 

        while(y){
            if(y&1)ans=ans*x%mod;
            x=x*x%mod;
            y/=2;
        }
        
        return ans;
    };

    int n, m, k=0;
    cin>>n>>m;
    vector<vector<long long>> a(n, vector<long long>(m+1));
    
    for(auto& v:a){
        for(auto& u:v){
            cin>>u;
        }
    }

    vector<int> id(m, -1);

    for(int i=0, j; i<m && k<n; i++){
        j=k;
        while(j<n && !a[j][i])j++;
        if(j==n)continue;
        swap(a[k], a[j]);
        id[i]=k;

        long long x=expbin(a[k][i], mod-2);
        for(int h=i; h<=m; h++)a[k][h]=a[k][h]*x%mod;
        
        for(int h=0; h<n; h++){
            if(h!=k && a[h][i]){
                x=a[h][i];
                for(j=i; j<=m; j++)a[h][j]=(mod+a[h][j]-x*a[k][j]%mod)%mod;
            }
        }
        k++;
    }

    for(int i=k; i<n; i++){
        if(a[i][m]!=0){
            cout<<-1;
            return 0;
        }
    }
    
    for(auto& u:id){
        if(u==-1)cout<<"0 ";
        else cout<<a[u][m]<<' ';
    }

    return 0;
}
