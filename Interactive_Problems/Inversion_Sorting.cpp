// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    auto Query = [](int l, int r){
        cout<<l<<' '<<r<<endl;
        int x;
        cin>>x;
        return x;
    };

    int n, k;
    cin>>n;
    
    k=Query(1, 1);
    if(k==0)return 0;

    for(int i=2; i<=n; i++){
        int p=Query(1, i);
        if(p==0)return 0;
        int x=(p-k-(i-2)*(i-1)/2+i)/2;
        k=Query(1, i);
        if(x<i-1)k=Query(x+1, i);
        if(x<i-2)k=Query(x+2, i);
        if(k==0)return 0;
    }
    
    return 0;
}
