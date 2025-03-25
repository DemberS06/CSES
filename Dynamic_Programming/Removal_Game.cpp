//Hola soy Dember :D
#include<bits/stdc++.h>
using namespace std;
 
const long long N=5e3+5;
 
long long n, a[N], b[N], dp[N][N];
 
int main(){
    cin>>n;
    for(int i=1; i<=n; b[i]=a[i]+b[i-1], i++)cin>>a[i];
    
    for(int x=1; x<=n; x++){
        for(int i=x; i<=n; i++){
            if(x==1){dp[i][i]=a[i];continue;}
            dp[i-x+1][i]=max(b[i]-b[i-x]-dp[i-x+2][i], b[i]-b[i-x]-dp[i-x+1][i-1]);
        }
    }
    
    cout<<dp[1][n];
    
    return 0;
}