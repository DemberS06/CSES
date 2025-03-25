//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
long long sol(long long x){
    if(x<10)return x;
 
    long long ans=0;
    vector<int> v(20, 0), d;
 
    while(x)d.push_back(x%10), x/=10;
    reverse(d.begin(), d.end());
 
    function<int(int i)> sp = [&](int i){
        if(i==0)return 1;
        if(d[i]==d[i-1])return 0;
        return sp(i-1);
    };
 
    vector<vector<long long>> dp(10, vector<long long> (d.size(), 0));
 
    for(int h=1; h<d[0]; h++)dp[h][0]++;
 
    for(int i=1; i<d.size(); i++){
        if(sp(i-1))for(int h=0; h<d[i]; h++)if(h!=d[i-1])dp[h][i]++;
        
        for(int h=1; h<10; h++)dp[h][i]++;
 
        for(int p=0; p<10; p++){
            for(int q=0; q<10; q++){
                if(p==q)continue;
                dp[q][i]+=dp[p][i-1];
            }
        }
    }
 
    ans+=sp(d.size()-1);
    for(auto &u:dp)ans+=u.back();
 
    return ans;
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
 
    long long n, m;
    cin>>n>>m;
 
    cout<<sol(m)-sol(n-1);
 
    return 0;
}