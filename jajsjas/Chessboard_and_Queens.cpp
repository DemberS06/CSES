#include<bits/stdc++.h>

using namespace std;

int ans=0;

bool sp(int x, int y){
    if(x<0 || y<0 || x>7 || y>7)return 0;
    return 1;
}

void backingtrack(vector<vector<int>> v, int i){
    if(i==8)return ans++, void();

    for(int j=0; j<8; j++){
        auto a=v;
        if(v[i][j])continue;

        for(int x=-8; x<=8; x++){
            if(sp(i-x, j-x))a[i-x][j-x]=1;
            if(sp(i-x, j+x))a[i-x][j+x]=1;
            if(sp(i+x, j))a[i+x][j]=1;
            if(sp(i, j+x))a[i][j+x]=1;
        }a[i][j]=2;

        backingtrack(a, i+1);
    }

    return;
}

int main(){
    cin.tie(); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<vector<int>> v(8, vector<int> (8, 0));
    char c;

    for(auto &w:v)for(auto &u:w){
        cin>>c;
        u+=(c=='*');
    }

    backingtrack(v, 0);

    cout<<ans<<"\n";

    return 0;
}