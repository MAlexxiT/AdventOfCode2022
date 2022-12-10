#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;

#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    freopen("in.txt", "r",stdin);
    int ciclo = 0;
    string dump;
    long long int res=0,x=1,d;
    while(cin>>dump){
        ciclo++;
        if(ciclo==20 || ciclo == 60 || ciclo == 100 || ciclo == 140 || ciclo == 180|| ciclo == 220){
            res+= x*ciclo; 
            //cout<<x<<" x "<<ciclo<<endl;
        }
        if(dump=="addx"){
            cin>>d;
            ciclo++;
            
            if(ciclo==20 || ciclo == 60 || ciclo == 100 || ciclo == 140 || ciclo == 180|| ciclo == 220){
                res+= x*ciclo;  
                //cout<<x<<" xx "<<ciclo<<endl;
            }
            x+=d;
        }
    }
    cout<<res<<endl;
}

