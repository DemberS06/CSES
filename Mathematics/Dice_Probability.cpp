// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin>>n;

    vector<vector<long double>> dp(n+1, vector<long double> (6*n+1, 0));

    dp[0][0]=1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=6*n; j++){
            for(int k=1; k<=6 && j>=k; k++){
                dp[i][j]+=dp[i-1][j-k];
            }
            dp[i][j]/=6;
        }
    }

    int l, r;
    cin>>l>>r;

    long double ans=0;

    for(int i=l; i<=r; i++)ans+=dp[n][i];

    cout<<fixed<<setprecision(6)<<ans;

    return 0;
}