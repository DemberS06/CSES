// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<int> dp(1e6+1, 0), vis(64, 0);

    for(int n=3, k=1, mex; n<=1e4; n++){
        ++k;
        int h=n/2;
        for(int i=1; i<=h; i++){
            if(i==n-i)continue;
            int x=dp[i]^dp[n-i];
            if(x<64)vis[x]=k;
        }
        mex=0;
        while(mex<64 && vis[mex]==k)mex++;
        dp[n]=mex;
    }

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n>1e4 || dp[n])cout<<"first\n";
        else cout<<"second\n";
    }

    return t+1;
}