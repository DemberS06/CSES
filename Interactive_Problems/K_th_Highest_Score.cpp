// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, k;
    cin>>n>>k; 

    vector<int> F(n+1, 0), S(n+1, 0);

    auto Query = [&](char c, int x){
        int y;
        if(c=='F'){
            if(!F[x]){
                cout<<c<<' '<<x<<endl;
                cin>>F[x];
            }
            y=F[x];
        }

        if(c=='S'){
            if(!S[x]){
                cout<<c<<' '<<x<<endl;
                cin>>S[x];
            }
            y=S[x];
        }
        
        return y;
    };
    
    int x=0, y=0;
    while(k>1 && x<n && y<n) {
        int i=min(n-x, max(1, k/2));
        int j=min(n-y, max(1, k/2));

        if(Query('F', x+i)<Query('S', y+j)) y+=j, k-=j;
        else                                x+=i, k-=i;
    }

    int ans=0;
    if(x!=n)ans=max(ans, Query('F', x+k));
    if(y!=n)ans=max(ans, Query('S', y+k));

    cout<<"! "<<ans;
    
    return 0;
}


