// hola soy Dember :D

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    function<bool(vector<vector<char>>&, int, int, int)> f = [&](vector<vector<char>>& g, int n, int m, int l){
        if(m%2==0){
            string p[3] = {"JJLL", "JKLM", "KKMM"};
            
            for(int i=0; i<n; i++)for(int j=0; j<m; j++)g[l+i][j]=p[i%3][j%4];
        }
        else if(n%2==0){
            string p[3] = {"EEFF", "EBFD", "BBDD"};
            string q[3] = {"AABB", "ACBD", "CCDD"};
            
            for(int i=0; i<n; i++){
                for(int j=0; j<3  ; j++)g[l+i][j]=p[j][i%4];
                for(int j=0; j<m-3; j++)g[l+i][j+3]=q[i%3][j%4];
            }
        }
        else if(n==3 || m==3)return false;
        else{
            string p[5] = {"GGIIGHHGG", "GHIGGAHIG", "HHAHHAAII", "GAAIHGHHG", "GGIIGGHGG"};
            
            for(int i=0; i<9; i++)for(int j=0; j<5; j++)g[l + i+n-9][j+m-5]=p[j][i];
            
            f(g, n-9, m, l);
            f(g, 9, m-5, l+n-9);
        }
        
        return true;
    };
    
    int t;
	cin>>t;
	
	while(t--){
        int n, m;
		cin>>n>>m;
		
		bool ok=0;
		
		if(n%3)ok=1, swap(n, m);

        vector<vector<char>> g(n, vector<char> (m, 0));
		
		if(n%3 || m==1 || !f(g, n, m, 0)){
			cout<<"NO\n";
			continue;
		}
		
		cout<<"YES\n";
		
		if(ok)
			for(int i=0; i<m; i++){
				for(int j=0; j<n; j++)cout<<g[j][i];
                cout<<"\n";
			}
		else
			for(auto& v:g){
                for(auto& u:v)cout<<u;
                cout<<"\n";
            }
	}

    return t+1;
}