//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    string a, b;
    cin>>a>>b;
 
    vector<vector<int>> dp(a.size()+1, vector<int> (b.size()+1));
 
    for(int i=0; i<=a.size(); i++){
        for(int j=0; j<=b.size(); j++){
            if(i==0 || j==0){
                if(i==0)dp[i][j]=j;
                else dp[i][j]=i;
                continue;
            }
            if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
        }
    }
 
    cout<<dp[a.size()][b.size()];
 
    return 0;
}