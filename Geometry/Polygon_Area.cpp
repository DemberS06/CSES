// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    long long ans=0;
    int n;
    cin>>n;

    vector<long long> x(n), y(n);

    for(int i=0; i<n; i++)cin>>x[i]>>y[i];
    for(int i=0; i<n; i++)ans+=x[i]*y[(i+1)%n]-y[i]*x[(i+1)%n];

    cout<<abs(ans);

    return 0;
}