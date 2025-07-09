// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<char> a(n+1, 0);  
    
    auto Query = [&](int x){
        if(!a[x]){
            cout<<"? "<<x<<endl;
            cin>>a[x];
        }
        return a[x];
    };

    int ans=-1;
    
    function<void(int, int)> Binary = [&](int l, int r){
        if(l>r)return;
        int md=(l+r)>>1;

        if(Query(2*md+1) == Query(1))Binary(md+1, r);
        else ans=2*md+1, Binary(l, md-1);
    };

    Binary(1, n/2);

    if(ans==-1)cout<<"! "<<n;
    else if(Query(ans-1)==Query(ans))cout<<"! "<<ans-1;
    else cout<<"! "<<ans-2;
    
    return 0;
}
