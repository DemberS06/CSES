// hola soy Dember :D
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k, p=0, x;
    cin>>n>>k;
    
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> f;
    
    for(int i=0; i<n; i++)f.insert(i+1);
    
    while(!f.empty()){
        p=(p+k)%f.size();
        x=*f.find_by_order(p);
        cout<<x<<' ';
        f.erase(x);
    }
    
    return 0;   
}