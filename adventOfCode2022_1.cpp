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
    //freopen("El_Hoyo.txt", "w",stdout);
    string s;
    long long int tot;
    long long int res = 0;
    vector<long long int> arr;
    while(getline(cin,s)){
        tot = stoll(s);
        while(getline(cin,s) && s!=""){
            tot+= stoll(s);
        }

        arr.push_back(tot);
    }

    sort(arr.begin(),arr.end(),greater<long long int>());

    cout<<arr[0]+arr[1]+arr[2]<<endl;
}