// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct Node{
    long long x, y;
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;

    vector<Node> v(n);

    for(auto& u:v)cin>>u.x>>u.y;

    function<bool(Node&, Node&, Node&)> slope = [](Node& a, Node& b, Node& c){
        long long m=(a.y-b.y)*(b.x-c.x)-(b.y-c.y)*(a.x-b.x);
        return m<0;
    };

    auto Convex_Hull = [&](vector<Node> v){
        sort(v.begin(), v.end(), [&](Node& a, Node& b){
            if(a.x==b.x)return a.y<b.y;
            return a.x<b.x;
        });
        
        int n=v.size();
        vector<Node> ans;
        vector<int> st, vis(n, 0);
        ans.reserve(n); st.reserve(n);

        for(int i=0, k=0; i<n; i++){
            while(k>1 && slope(v[st[k-2]], v[st[k-1]], v[i]))vis[st.back()]=0, st.pop_back(), k--;
            st.push_back(i);
            vis[i]=1;
            k++;
        }vis[0]=0;
        
        for(int i=n-1, k=st.size(); i>=0; i--){
            if(vis[i])continue;
            while(k>1 && slope(v[st[k-2]], v[st[k-1]], v[i]))vis[st.back()]=0, st.pop_back(), k--;
            st.push_back(i);
            vis[i]=1;
            k++;
        }st.pop_back();

        for(auto& u:st)ans.push_back(v[u]);

        return ans;
    }; 

    vector<Node> ans=Convex_Hull(v);

    cout<<ans.size()<<"\n";
    for(auto& u:ans)cout<<u.x<<' '<<u.y<<"\n";
    
    return 0;
}