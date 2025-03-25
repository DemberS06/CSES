//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const long long md=1e9+7;
 
int main(){
    long long n;
    cin>>n;

    vector<unsigned long long> dp;
    for(int i=1; i<=32; i*=2)dp.push_back(i);
 
    for(int i=6; i<n; i++){
        dp.push_back(0);
        for(int j=1; j<=6; j++){
            dp[i]+=dp[i-j];
            dp[i]=dp[i]%md;
        }
    }
    cout<<dp[n-1];
 
    return 0;
}