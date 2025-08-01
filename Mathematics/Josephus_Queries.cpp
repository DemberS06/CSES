// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    function<int(int,  int)> Josephus = [&](int n, int k){
        if(n==1)return 1;
        if(k<=n/2)return k*2;
        if(k==(n+1)/2)return 1;
        if(n&1)return 2*Josephus(n/2, k-n/2-1)+1;
        return 2*Josephus(n/2, k-n/2)-1;
    };

    int t;
    cin>>t;
    
    while(t--){
        int n, k;
        cin>>n>>k;
        cout<<Josephus(n, k)<<"\n";
    }

    return 0;
}