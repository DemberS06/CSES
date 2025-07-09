// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    auto Query = [](int x){
        cout<<"? "<<x<<endl;
        string s;
        cin>>s;
        return s[0]=='Y';
    };

    int ans;
    
    function<void(int, int)> Binary = [&](int l, int r){
        if(l>r)return;
        int md=(l+r)>>1;

        if(Query(md))Binary(md+1, r);
        else ans=md, Binary(l, md-1);
    };

    Binary(1, 1e9);

    cout<<"! "<<ans;
    
    return 0;
}
