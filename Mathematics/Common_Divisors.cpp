// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<int> fr(1e6+1, 0);

    int n, ans=1;
    cin>>n;

    for(int i=0, x; i<n; i++){
        cin>>x;
        fr[x]++;
    }

    for(int i=2; i<=1e6; i++){
        for(int j=2*i; j<=1e6; j+=i)fr[i]+=fr[j];
        if(fr[i]>1)ans=i;
    }

    cout<<ans;

    return 0;
}