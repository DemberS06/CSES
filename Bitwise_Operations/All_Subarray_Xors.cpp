// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

void fwht(vector<long long>& a, bool invert) {
    int n=a.size();
    for(int len=1; len<n; len<<=1) {
        for(int i=0; i<n; i+=2*len) {
            for(int j=0; j<len; j++) {
                long long u=a[i+j];
                long long v=a[i+j+len];
                a[i+j]     = u+v;
                a[i+j+len] = u-v;
            }
        }
    }
    if(invert)for(long long &x: a)x/=n;
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    vector<long long> p(n+1, 0), fr(1<<20, 0), A(1<<21, 0), ans;
    for(int i=1, x; i<=n; i++){
        cin>>x;
        p[i]=p[i-1]^x;
        fr[p[i]]++;
        if(ans.empty() && (fr[p[i]]==2 || p[i]==0))ans.push_back(0);
        A[p[i]]=1;
    }A[0]=1;

    fwht(A, 0);
    for(auto& u:A)u*=u;
    fwht(A, 1);

    for(int i=1; i<A.size(); i++){
        if(!A[i])continue;
        ans.push_back(i);
    }

    cout<<ans.size()<<"\n";
    for(auto& u:ans)cout<<u<<' ';


    return 0;
}
