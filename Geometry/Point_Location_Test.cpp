// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;

    while(t--){
        long long x, y, p, q, a, b;
        cin>>x>>y>>p>>q>>a>>b;

        long long cross=(p-x)*(b-y) - (a-x)*(q-y);

        if(cross==0)    cout<<"TOUCH\n";
        else if(cross>0)cout<<"LEFT\n";
        else            cout<<"RIGHT\n";
    }
    return t+1;
}