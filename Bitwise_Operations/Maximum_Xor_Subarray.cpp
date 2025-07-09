// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

struct Trie{
    struct Node{
        int child[2];
    };

    vector<Node> trie;

    Trie(){
        trie.reserve(6000000);
        trie.push_back({0, 0});
    }

    void insert(int x){
        int v=0, bit;
        for(int h=29; h>=0; h--){
            bit=(x>>h)&1;
            if(!trie[v].child[bit]){
                trie[v].child[bit]=trie.size();
                trie.push_back({0, 0});
            }
            v=trie[v].child[bit];
        }
    }

    int query(int x){
        int v=0, res=0, bit, want;

        for(int h=29; h>=0; h--){
            bit=(x>>h)&1; want=!bit;

            if(trie[v].child[want]){
                v=trie[v].child[want];
                res|=(want)<<h;
            }
            else{
                v=trie[v].child[bit];
                res|=bit<<h;
            }
        }

        return x^res;
    }
    
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, ans=0, sum=0, x;
    cin>>n;

    Trie f;

    f.insert(0);

    while(n--){
        cin>>x;
        sum^=x;

        ans=max(ans, f.query(sum));
        f.insert(sum);
    }

    cout<<ans;

    return n+1;
}