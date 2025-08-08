// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;

    set<long long> a, b;

    for(int i=0, x, y; i<n; i++){
        cin>>x>>y;
        a.insert(x+y);
        b.insert(x-y);
        long long l=*b.rbegin()-*b.begin(), r=*a.rbegin()-*a.begin();
        cout<<max(l, r)<<"\n";
    }

    return 0;
}