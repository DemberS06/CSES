#include <bits/stdc++.h>

using namespace std;

int ans=0;
bool v[50][50];
string s;

bool sp(int x, int y){
    if(x<1 || x>7)return 0;
    if(y<1 || y>7)return 0;
    return !v[x][y];
}

void dfs(int x, int y, int i){
    if(i==48 || (x==1 && y==7)){
        if(i==48 && x==1 && y==7)ans++;
        return;
    }

    if(!sp(x+1, y) && !sp(x-1, y) && sp(x, y+1) && sp(x, y-1))return;
    if(!sp(x, y+1) && !sp(x, y-1) && sp(x+1, y) && sp(x-1, y))return;

    v[x][y]^=1;

    if((s[i]=='D' || s[i]=='?') && sp(x, y+1))dfs(x, y+1, i+1);
    if((s[i]=='U' || s[i]=='?') && sp(x, y-1))dfs(x, y-1, i+1);
    if((s[i]=='R' || s[i]=='?') && sp(x+1, y))dfs(x+1, y, i+1);
    if((s[i]=='L' || s[i]=='?') && sp(x-1, y))dfs(x-1, y, i+1);

    v[x][y]^=1;

    return;
}

int main(){
    cin>>s;

    dfs(1,1,0);

    cout<<ans;

    return 0;
}