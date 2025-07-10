// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    vector<int> p(2*n+1, 2), a, b; p[1]=0;
    for(int i=2; i<=2*n; i++){
        if(!p[i])continue;
        for(int j=2*i; j<=2*n; j+=i)p[j]=0;
    }


    for(int i=2*n-1; i>0; i--){
        if(p[i])p[i]=i;
        else p[i]=p[i+1];
    }

    for(int i=n; i>0; i--){
        int q=p[i];
        if(q==i)q=p[i+1];
        if(q>2*i || q==0){
            cout<<"IMPOSSIBLE";
            return 0;
        }

        for(int j=i; j>=q-i; j--){
            a.push_back(j);
            b.push_back(q-j);
        }
        
        i=q-i;
    }

    for(auto& u:a)cout<<u<<' '; cout<<"\n";
    for(auto& u:b)cout<<u<<' ';

    return 0;
}