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
    char o,y;
    long long int res = 0;
    int ov,yv;
    while(cin>>o>>y){
        //perder
        //roca-tijeras  || papel-roca || tijeras-papel
        //(o=='A'&&y=='Z') || (o=='B'&&y=='X') || (o=='C'&&y=='Y')
        if(y == 'X'){
            if(o=='A'){
                y = 'Z';
            }
            if(o=='B'){
                y = 'X';
            }
            if(o=='C'){
                y = 'Y';
            }
            if(y=='Z'){
                res+=3;
            }
            if(y=='X'){
                res+=1;
            }
            if(y=='Y'){
                res+=2;
            }
            continue;
        }
        
        //ganar
        //(o=='A'&&y=='Y')||(o=='B'&&y=='Z')||(o=='C'&&y=='X')
        if(y=='Z'){
            if(o=='A'){
                y = 'Y';
            }
            if(o=='B'){
                y = 'Z';
            }
            if(o=='C'){
                y = 'X';
            }
            if(y=='Z'){
                res+=3;
            }
            if(y=='X'){
                res+=1;
            }
            if(y=='Y'){
                res+=2;
            }
            res+=6;
            continue;
        }
        //empatar
        //(o=='A'&&y=='X')||(o=='B'&&y=='Y')||(o=='C'&&y=='Z')
        if(y=='Y'){
            if(o=='A'){
                y = 'X';
            }
            if(o=='B'){
                y = 'Y';
            }
            if(o=='C'){
                y = 'Z';
            }
            if(y=='Z'){
                res+=3;
            }
            if(y=='X'){
                res+=1;
            }
            if(y=='Y'){
                res+=2;
            }
            res+=3;
            continue;
        }
    }
    cout<<res<<endl;
}