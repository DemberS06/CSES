//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    set<int> f;

    for(int i=0, x; i<n; i++){
        cin>>x;
        f.insert(x);
    }

    cout<<f.size();
    
    return 0;
}