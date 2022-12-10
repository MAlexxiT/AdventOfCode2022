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
    int ciclo = 0,sprite = 1;
    string dump;
    long long int res=0,x=1,d;
    while(cin>>dump){
        ciclo++;
        cout<<((ciclo%40)>=x && (ciclo%40)<x+3?'#':'.');
        cout<<(ciclo%40==0?"\n":"");

        if(dump=="addx"){
            cin>>d;
            ciclo++;
            cout<<((ciclo%40)>=x && (ciclo%40)<x+3?'#':'.');
            cout<<(ciclo%40==0?"\n":"");
            x+=d;
        }
    }

}

