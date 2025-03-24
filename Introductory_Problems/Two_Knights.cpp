//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const long long N=1e4+4;

long long dp[N], n;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin>>n;
    for(int i=2; i<=n; i++)dp[i]=dp[i-1]+8*i-16;
    for(int i=1; i<=n; i++)cout<<(i*i)*(i*i-1)/2-dp[i]<<"\n";
 
    return 0;
}