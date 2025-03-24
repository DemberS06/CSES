#include <bits/stdc++.h>

using namespace std;

void dfs(int x, int y, int p){
    if(p==1){
        cout<<x<<' '<<y<<"\n";
        return;
    }

    int z=6-x-y;

    dfs(x, z, p-1);
    cout<<x<<' '<<y<<"\n";
    dfs(z, y, p-1);

    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n";

    dfs(1,3,n);

    return 0;
}