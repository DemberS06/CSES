//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;

    multiset<int> f;
    
    for(int i=0, x; i<n; i++){
        cin>>x;
        f.insert(-x);
    }

    f.insert(2e9);

    for(int i=0, x; i<m; i++){
        cin>>x;
        auto y=*f.lower_bound(-x);
        if(y!=2e9){
            f.erase(f.find(y));
            cout<<-y<<"\n";
        }
        else cout<<"-1\n";
    }
    
    return 0;
}