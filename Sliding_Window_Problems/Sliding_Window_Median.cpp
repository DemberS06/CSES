// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k;
    cin>>n>>k;
    
    vector<int> v(n);
    multiset<int> a, b;
    for(auto &u:v)cin>>u;
    
    for(int i=0; i<n; i++){
        a.insert(v[i]);
        if(i<k-1)continue;
        while(a.size()>b.size()){
            auto x=*a.rbegin();
            a.erase(a.find(x));
            b.insert(x);
        }
        while(b.size()>a.size()){
            auto x=*b.begin();
            b.erase(b.find(x));
            a.insert(x);
        }
        cout<<*a.rbegin()<<' ';
        
        if(a.count(v[i-k+1]))a.erase(a.find(v[i-k+1]));
        else b.erase(b.find(v[i-k+1]));
        
        while(a.size()>b.size()){
            auto x=*a.rbegin();
            a.erase(a.find(x));
            b.insert(x);
        }
        while(b.size()>a.size()){
            auto x=*b.begin();
            b.erase(b.find(x));
            a.insert(x);
        }
    }
}