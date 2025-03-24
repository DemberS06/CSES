//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    string s;
    map<char, int> frec;
    long long cont=0;
    char imp;

    cin>>s;
    for(auto &u:s)frec[u]++;
    s.clear();
    
    for(auto [c, p]:frec){
        if(!p)continue;
        if(p&1)cont++, imp=c;
        
        p/=2;
        while(p--)s+=c;
    }
    
    if(cont>1){
        cout<<"NO SOLUTION";
        return 0;
    }
    
    cout<<s;
    if(cont)cout<<imp;
    reverse(s.begin(), s.end());
    cout<<s;
 
    return 0;
}