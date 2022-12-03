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
    bitset<256> ocurr1,ocurr2,ocurr3;
    long long int res = 0;long long int d;
    string s;
    while(getline(cin,s)){
        ocurr1.reset();ocurr2.reset();ocurr3.reset();
        for(char l: s){
            ocurr1[l]=1;
        }

        getline(cin,s);
        for(char l: s){
            ocurr2[l]=1;
        }

        getline(cin,s);
        for(char l: s){
            ocurr3[l]=1;
        }

        d = 0;
        for(char l = 'a'; l<='z'; l++){
            d++;
            if(ocurr1[l] && ocurr2[l]&&ocurr3[l]){
                res+=d;
                break;
            }
        }

        if(!(ocurr1['a'+d-1] && ocurr2['a'+d-1]&&ocurr3['a'+d-1])){
            d = 26;
            for(char l = 'A'; l<='Z'; l++){
                d++;
                if(ocurr1[l] && ocurr2[l]&&ocurr3[l]){
                    res+=d;
                    break;
                }
            }
        }
        
    }
    cout<<res<<endl;
}