// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const int N = 1e7+1;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<int> s, a(N, -1), b(N, -1), ans(N, 0);
    s.reserve(N);

    for(int i=0; i*i<N; i++)s.push_back(i*i), ans[i*i]=i;

    for(auto& x:s)for(auto& y:s){
        if(x+y>=N)break;
        a[x+y]=ans[x];
        b[x+y]=ans[y];
    }

    int t;
    cin>>t;

    while(t--){
        int n, ok=1;
        cin>>n;
        for(int i=0; i<s.size() && ok; i++){
            for(int j=i; j<s.size() && ok; j++){
                if(s[i]+s[j]>n)break;
                if(a[n-s[i]-s[j]]==-1)continue;
                cout<<ans[s[i]]<<' '<<ans[s[j]]<<' '<<a[n-s[i]-s[j]]<<' '<<b[n-s[i]-s[j]]<<"\n";
                ok=0;
            }
        }
    }
    

    return t+1;
}