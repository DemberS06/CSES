// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    vector<int> fr(1e6+1, 1);
    for(int i=2; i<=1e6; i++){
        for(int j=i; j<=1e6; j+=i)fr[j]++;
    }

    int t;
    cin>>t;

    while(t--){
        int x;
        cin>>x;
        cout<<fr[x]<<"\n";
    }

    return t+1;
}