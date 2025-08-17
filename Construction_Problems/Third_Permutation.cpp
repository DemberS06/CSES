// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;

    if(n<3){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<int> a(n), b(n);

    for(auto& u:a)cin>>u;
    for(auto& u:b)cin>>u;

    vector<int> c=a;
    reverse(c.begin(), c.end());

    if(n&1 && c[n/2]==a[n/2])swap(c[n/2], c[0]);

    function<void(int, int)> construction = [&](int l, int r){
        for(int i=l; i<r; i++){
            if(c[i]==b[i])swap(c[i], c[i+1]);
        }if(c[r]==b[r])swap(c[l], c[r]);
    };

    construction(0, n/2-1);
    construction(n/2+(n&1), n-1);

    for(auto& u:c)cout<<u<<' ';

    return 0;
}