//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    multiset<int> f;
    f.insert(1e9+7);

    for(int i=0, x; i<n; i++){
        cin>>x;

        auto y=*f.upper_bound(x);
        if(y!=1e9+7)f.erase(f.find(y));
        f.insert(x);
    }

    cout<<f.size()-1;

    return 0;
}