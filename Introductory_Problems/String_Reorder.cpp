//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    string s;
    
    cin>>s;

    int n=s.size(), ok=1;

    vector<int> f(26, n+1);
    for(char& u:s)f[u-'A']-=2;
    
    for(int i=0; i<n && ok; i++){
        for(int j=25; j>=0 && ok; j--){
            if(f[j]<i)ok=0;
            if(f[j]>n || (i>0 && j==s[i-1]-'A'))continue;
            s[i]=j+'A';
            if(f[j]==i)break;
        }
        f[s[i]-'A']+=2;
    }

    if(ok)cout<<s;
    else cout<<-1;
 
    return 0;
}