//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k=0;
    cin>>n;

    multiset<vector<int>> f;
    vector<int> v, ans(n);

    for(int i=0, x, y; i<n; i++){
        cin>>x>>y;
        f.insert({x, 0, y, i});
    }

    while(!f.empty()){
        auto p=*f.begin();
        f.erase(f.begin());

        if(p[1])v.push_back(p[2]);
        else{
            if(v.empty())ans[p[3]]=++k;
            else ans[p[3]]=v.back(), v.pop_back();
            f.insert({p[2], 1, ans[p[3]]});
        }
    }

    cout<<k<<"\n";
    for(auto& u:ans)cout<<u<<' ';
 
    return 0;
}