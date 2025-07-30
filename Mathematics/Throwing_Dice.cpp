// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
const long long mod=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    auto mult = [](vector<vector<long long>>& a, vector<vector<long long>>& b){
        vector<vector<long long>> ans(6, vector<long long>(6, 0));
    
        for(int i=0; i<6; i++){
            for(int k=0; k<6; k++){
                if(a[i][k]==0)continue;
                for(int j=0; j<6; j++) {
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
                }
            }
        }
        return ans;
    };

    auto expbin = [&](long long y){
        vector<vector<long long>> x(6, vector<long long> (6, 0)), ans=x;
        for(int i=0; i<6; i++)ans[i][i]=1, x[0][i]=1;
        for(int i=1; i<6; i++)x[i][i-1]=1;

        while(y){
            if(y&1)ans=mult(ans, x);
            x=mult(x, x);
            y/=2;
        }
        return ans;
    };
    
    long long n, ans=0;
    cin>>n;
    
    vector<int> v(7, 1);
    for(int i=2; i<7; i++)v[i]=v[i-1]*2;

    if(n<=6){
        cout<<v[n];
        return 0;
    }

    auto a=expbin(n-5);

    for(int i=0; i<6; i++){
        ans=(ans+a[0][i]*v[5-i])%mod;
    }

    cout<<ans;
    
    return 0;
}