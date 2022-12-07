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
    cin>>s;
    bitset<256> vis;

    for(int i = 13; i<s.size(); i++){
        vis.reset();
        for(int j = i; j>(i-14); j--){
            vis[s[j]] = 1;
        }
        if(vis.count()==14){
            cout<<i+1<<endl;
            break;
        }
    }
}