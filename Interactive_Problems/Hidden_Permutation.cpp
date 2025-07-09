// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    auto Query = [](int x, int y){
        cout<<"? "<<x<<' '<<y<<endl;
        string s;
        cin>>s;
        return s[0]=='Y';
    };

    int n;
    cin>>n;

    vector<int> p(n), ans(n+1);
    for(int i=1; i<=n; i++)p[i-1]=i;

    function<void(int, int)> Sort = [&](int l, int r){
        if(l==r)return;
        int m=(l+r)/2;
        Sort(l, m);
        Sort(m+1, r);

        vector<int> v;
        v.reserve(r-l+1);

        int x=l, y=m+1;
        
        while(x<=m && y<=r){
            if(Query(p[x], p[y]))v.push_back(p[x]), x++;
            else v.push_back(p[y]), y++;
        }

        while(x<=m)v.push_back(p[x]), x++;
        while(y<=r)v.push_back(p[y]), y++;

        for(int i=0; i<=r-l; i++)p[l+i]=v[i];

        return;
    };

    Sort(0, n-1);

    for(int i=0; i<n; i++)ans[p[i]]=i+1;

    cout<<"! "; for(int i=1; i<=n; i++)cout<<ans[i]<<' ';
    
    return 0;
}
