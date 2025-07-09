// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, x, ans=0;
    cin>>n;
    vector<int> basis(30, 0); 
    
    while(n--){
        cin>>x;

        for(int h=29; h>=0; h--) {
            if ((x>>h)&1){
                if(!basis[h]){
                    basis[h]=x;
                    break;
                }
                x^=basis[h];
            }
        }
    }

    for(auto& u:basis)ans+=(u!=0);

    cout<<(1<<ans);

    return n+1;
}
