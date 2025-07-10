// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, k;
    cin>>n>>k;

    vector<int> ans;
    ans.reserve(n);
    
    for(int l=1, r=n; l<=r; l++){
        while(k>=r-l && l<=r){
            ans.push_back(r);
            k-=r-l;
            r--;
        }
        if(l<=r)ans.push_back(l);
    }

    for(auto& u:ans)cout<<u<<' ';

    return 0;
}