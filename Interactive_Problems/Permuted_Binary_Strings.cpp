// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, m=0;
    cin>>n;
    while((1<<m)<=n)m++;

    vector<int> p(n, 0);

    for(int h=0; h<m; h++){
        string s(n, '0');
        for(int i=0; i<n; i++){
            if((i>>h)&1)s[i]++;
        }

        cout<<"? "<<s<<endl;
        cin>>s;

        for(int i=0; i<n; i++){
            if(s[i]=='1')p[i]|=1<<h;
        }
    }

    cout<<"! ";
    for(auto& u:p)cout<<u+1<<' ';

    return 0;
}
