// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--){
        int n, ans=0;
        cin>>n;

        for(int i=0, x; i<n; i++){
            cin>>x;
            ans^=x%4;
        }

        if(ans)cout<<"first\n";
        else cout<<"second\n";
    }

    return t+1;
}