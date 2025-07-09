// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k, x;
    cin>>n>>k;
    vector<int> basis(30, 0);
    set<pair<int, int>> f;

    if(n>50){
        for(int i=0; i<k; i++)cout<<"0 ";
        return 0;
    }
    
    for(int i=0; i<n; i++){
        cin>>x;

        for(int h=29; h>=0; h--) {
            if ((x>>h)&1){
                if(!basis[h]){
                    basis[h]=x;
                    break;
                }
                x^=basis[h];
            }
        }
    }

    f.insert({0, -1});
    sort(basis.begin(), basis.end());
    for(auto& u:basis)n-=(u!=0);
    n=1<<n;

    while(!f.empty()){
        auto [a, b]=*f.begin();
        f.erase({a, b});

        for(int i=0; i<min(n, k); i++)cout<<a<<' ';
        k-=n;
        if(k<1)break;

        for(int i=b+1; i<30; i++){
            if(!basis[i])continue;
            f.insert({a^basis[i], i});
        }
    }

    return 0;
}
