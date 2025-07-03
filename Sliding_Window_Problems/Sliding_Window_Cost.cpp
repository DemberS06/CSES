// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, k, x=0, y=0;
    cin>>n>>k;
    
    vector<int> v(n);
    multiset<int> a, b;
    for(auto &u:v)cin>>u;
    
    for(int i=0; i<n; i++){
        a.insert(v[i]); x+=v[i];
        if(i<k-1)continue;
        while(a.size()>b.size()){
            auto z=*a.rbegin();
            a.erase(a.find(z));
            b.insert(z);
            x-=z, y+=z;
        }
        while(b.size()>a.size()){
            auto z=*b.begin();
            b.erase(b.find(z));
            a.insert(z);
            y-=z, x+=z;
        }
        
        cout<<a.size()*(*a.rbegin())-x+y-b.size()*(*a.rbegin())<<' ';
        
        if(a.count(v[i-k+1]))a.erase(a.find(v[i-k+1])), x-=v[i-k+1];
        else b.erase(b.find(v[i-k+1])), y-=v[i-k+1];
        
        while(a.size()>b.size()){
            auto z=*a.rbegin();
            a.erase(a.find(z));
            b.insert(z);
            x-=z, y+=z;
        }
        while(b.size()>a.size()){
            auto z=*b.begin();
            b.erase(b.find(z));
            a.insert(z);
            y-=z, x+=z;
        }
    }
}