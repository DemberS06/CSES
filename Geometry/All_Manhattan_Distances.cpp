// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

using i128 = __int128_t;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    i128 ans=0, sum=0;

    int n;
    cin>>n;

    vector<i128> x(n), y(n);

    for(int i=0, a, b; i<n; i++){
        cin>>a>>b;
        x[i]=a; y[i]=b;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for(i128 i=0; i<n; i++){
        ans+=i*(x[i]+y[i])-sum;
        sum+=x[i]+y[i];
    }

    string s;
    
    if(ans==0)s="0";
    while(ans){
        s+=(ans%10)+'0';
        ans/=10;
    }

    reverse(s.begin(), s.end());

    cout<<s;

    return 0;
}