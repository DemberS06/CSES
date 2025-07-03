// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, k, ans=0, x, a, b, c;
    cin>>n>>k>>x>>a>>b>>c;

    vector<long long> v(n, x);
    deque<int> q;
    for(int i=1; i<n; i++)v[i]=(a*v[i-1]+b)%c;


    for(int i=0; i<n; i++){
        while(!q.empty() && v[q.front()]>=v[i])q.pop_front();
        q.push_front(i);
        if(i>=k-1)ans^=v[q.back()];
        while(!q.empty() && i-q.back()>=k-1)q.pop_back();
    }

    cout<<ans;
    
    return 0;
}