#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

const int N=2e5+5;

int a[N], n, m, x, y;
char c;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> f;
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
        f.insert({a[i], i});
    }
    
    while(m--){
        cin>>c>>x>>y;
        if(c=='!'){
            f.erase({a[x], x});
            a[x]=y;
            f.insert({a[x], x});
        }
        else cout<<f.order_of_key({y+1, 0})-f.order_of_key({x,0})<<"\n";
    }
    
    return 0;
}