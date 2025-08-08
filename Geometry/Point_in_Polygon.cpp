// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct Node{
    long long x, y;
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    auto touch = [](Node& a, Node& b, Node& c){
        if(c.y<min(a.y, b.y) || c.y>max(a.y, b.y))return 0;
        if(c.x<min(a.x, b.x) || c.x>max(a.x, b.x))return 0;
        if((b.x-a.x)*(c.y-a.y)==(c.x-a.x)*(b.y-a.y))return 1;
        return 0;
    };

    int n, m;
    cin>>n>>m;

    vector<Node> point(n);
    vector<pair<Node, Node>> lines;
    
    for(auto& u:point)cin>>u.x>>u.y;

    for(int i=0; i<n; i++)lines.push_back({point[i], point[(i+1)%n]});

    while(m--){
        int k=0;
        Node a;
        cin>>a.x>>a.y;

        for(auto& v:lines){
            if(touch(v.first, v.second, a)){
                k++;
                break;
            }
        }

        if(k){
            cout<<"BOUNDARY\n";
            continue;
        }
        
        for(auto& [p, q]:lines){
            if(q.y<p.y)swap(p, q);
            if(a.y<p.y || a.y>=q.y)continue;
            if((a.x-p.x)*(q.y-p.y)<(q.x-p.x)*(a.y-p.y))k^=1;
        }
        
        if(k)cout<<"INSIDE\n";
        else cout<<"OUTSIDE\n";
    }

    return m+1;
}