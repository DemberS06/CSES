//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, ans=0;
    cin>>n;

    vector<vector<int>> a(n, vector<int> (2));

    for(auto& v:a)for(auto& u:v)cin>>u;

    sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y){
        return x[1]<y[1];
    });

    for(int i=0, j=0; i<n; i++){
        if(a[i][0]<j)continue;
        ans++;
        j=a[i][1];
    }

    cout<<ans;
    
    return 0;
}