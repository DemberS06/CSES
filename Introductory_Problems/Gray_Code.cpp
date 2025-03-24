//Hola soy Dember :D
#include<bits/stdc++.h>
 
using namespace std;
 
int bt[20], n;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
 
    cin>>n;
 
    for(int i=1; i<=(1<<n); i++){
        for(int h=n-1; h>=0; h--)cout<<bt[h];cout<<"\n";
        for(int h=0; h<n; h++){
            if((i>>h)&1){
                bt[h]^=1;
                break;
            }
        }
    }
 
    return 0;
}