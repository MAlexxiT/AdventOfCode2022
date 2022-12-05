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
    vector<char> pilas[11];
    while(getline(cin,s)){
        if(s[1] == '1'){
            break;
        }
        for(int d = 0; (1+d*4)<s.size(); d++){
            if(s[1+d*4]==' '){
                continue;
            }
            pilas[d+1].push_back(s[1+d*4]);
        }
    }
    for(int i  = 0; i<=10; i++){
        reverse(pilas[i].begin(),pilas[i].end());
    }
    //come el enter
    getline(cin,s);
    
    vector<string> tt;
    int t,i,f;
    while(getline(cin,s)){
        tt = explode(s,' ');
        t = stoi(tt[1]);
        i = stoi(tt[3]);
        f = stoi(tt[5]);
        for(int j = pilas[i].size()-t; j<pilas[i].size(); j++){
            pilas[f].push_back(pilas[i][j]);
        }
        while(t--){
            //pilas[f].push_back(pilas[i].back());
            pilas[i].pop_back();
        }
    }
    string res = "";
    for(int i  = 0; i<=10; i++){
        if(pilas[i].size()){
            res+=pilas[i].back();
        }
        
    }
    cout<<res<<endl;
}