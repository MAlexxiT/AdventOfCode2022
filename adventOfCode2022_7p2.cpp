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
struct nodo{
    string nom;
    unsigned long long int tot=0;
    vector<string> hijos;
};
map<string,nodo> graph;
map<string,bool> vis;
void dfs(string p){
    vis[p]=1;
    for(string h: graph[p].hijos){
        if(!vis[h]){
            dfs(h);
        }
        graph[p].tot+=graph[h].tot;
    }

}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    freopen("in.txt", "r",stdin);
    vector<string> est; est.push_back("/");
    vector<string> tt;
    string s,id;
    
    while (getline(cin,s)){
        //this is probably not the best idea memory wise, as im pretty sure its a memory leak lol
        tt = explode(s,' ');
        
        if(s[0]=='$'){
            if(tt[1]=="cd"){
                if(tt[2]=="/"){
                    while (est.back()!="/"){
                        est.pop_back();
                    }
                }
                if(tt[2]==".."){
                    est.pop_back();
                }
                if(tt[2]!=".." && tt[2]!="/"){
                    est.push_back(tt[2]);
                }
            }
        }else{
            //not the most efficient way to do so, but considering the size of the input i figured, why not?
            id = "";
            for(string el: est){
                id+=el;
                id+="/";
            }
            if(tt[0]=="dir"){
                graph[id].hijos.push_back(id+tt[1]+"/");
            }else{
                graph[id].tot+=stoull(tt[0]);
            }
        }
    }
    dfs("//");
    unsigned long long int res = 0;
    vector<unsigned long long int> tams;
    for(pair<string,nodo> el: graph){
        tams.push_back(el.second.tot);
        //cout<<el.first<<"-->"<<el.second.tot<<endl;
    }
    sort(tams.begin(),tams.end());
    unsigned long long int d = 70000000 - graph["//"].tot;
    d = max(0ULL,30000000ULL-d); 
    for(unsigned long long int el: tams){
        if(el>=d){
            res = el;
            break;
        }
    }
    cout<<res<<endl;
}
