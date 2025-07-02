//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k, ans=0;
    cin>>n>>k;

    multiset<int> f;
    
    for(int i=0, x; i<n; i++){
        cin>>x;
        f.insert(-x);
    }

    f.insert(2e9);

    while(f.size()>1){
        auto x=*f.begin();
        f.erase(f.find(x));
        auto y=*f.lower_bound(-k-x);
        if(y!=2e9)f.erase(f.find(y));
        ans++;
    }
    
    cout<<ans;
    
    return 0;
}