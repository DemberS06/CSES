//Hola soy Dember :D
#include<bits/stdc++.h>
 
using namespace std;
 
const long long md=1e9+7;
 
long long fermat(long long x, long long y=md-2){
    long long res=1;
    
    while(y){
        if(y&1)res=res*x%md;
        x=x*x%md;
        y/=2;
    }
    
    return res;
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, sum;
    cin>>n; sum=(n*(n+1)/2);
    
    if(sum&1){
        cout<<0;
        return 0;
    }

    sum/=2;
    vector<long long> dp(sum+1);
    
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=sum; j>=i; j--)dp[j]=(dp[j]+dp[j-i])%md;
    }
    
    cout<<(dp[sum]*fermat(2))%md;
    
    return 0;
}