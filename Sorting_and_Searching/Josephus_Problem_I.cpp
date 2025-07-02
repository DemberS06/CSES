//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++)v[i]=i+1;

    for(int i=0; i<v.size(); i++){
        if(i&1)cout<<v[i]<<' ';
        else v.push_back(v[i]);
    }
 
    return 0;
}