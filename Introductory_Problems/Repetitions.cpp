//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long ans=1, cont=1;
    string s;
    cin>>s;
    
    for(int i=1; i<s.size(); i++){
        if(s[i]==s[i-1])cont++;
        else cont=1;
        ans=max(ans, cont);
    }
    
    cout<<ans;
    
    return 0;
}
