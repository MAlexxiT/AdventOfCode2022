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
std::vector<string> explode(std::string const& s, char delim) {
	std::vector<string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		result.push_back(std::move(token));
	}
	return result;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    freopen("in.txt", "r",stdin);
    string s;
    vector<string> tok,itok;
    pair<int,int> l,r;
    int res = 0;
    while(cin>>s){
        tok.clear(); itok.clear();
        tok = explode(s,',');
        itok.clear();
        itok = explode(tok[0],'-');
        l.first = stoi(itok[0]);
        l.second = stoi(itok[1]);

        itok.clear();
        itok = explode(tok[1],'-');
        r.first = stoi(itok[0]);
        r.second = stoi(itok[1]);

        if(!((l.first>r.second || l.second < r.first ))){
            res++;
        }
    }
    cout<<res<<endl;

}