// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
const long long md=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    auto mult = [](vector<vector<long long>>& a, vector<vector<long long>>& b){
        vector<vector<long long>> res={
                            {a[0][0]*b[0][0]+a[0][1]*b[1][0], a[0][0]*b[0][1]+a[0][1]*b[1][1]}, 
                            {a[1][0]*b[0][0]+a[1][1]*b[1][0], a[1][0]*b[0][1]+a[1][1]*b[1][1]}};
        for(auto &u:res){
            for(auto &w:u){
                w%=md;
            }
        }
        return res;
    };

    function<long long(long long)> expbin = [&](long long y){
        vector<vector<long long>> x={{1, 1}, {1, 0}}, ans={{1, 0}, {0, 1}};
        while(y){
            if(y&1)ans=mult(ans, x);
            x=mult(x, x);
            y/=2;
        }
        return ans[0][0];
    };
    
    long long n;
    cin>>n;
    
    if(n==0)cout<<0;
    else cout<<expbin(n-1);
    
    return 0;
}