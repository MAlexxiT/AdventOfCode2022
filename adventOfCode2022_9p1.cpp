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

bitset<1001> vis[1001];
int rt,ct,rh,ch;
int dr,dc;
char dir;

void solve(){
    
    
    if(dir=='U'){
        rh--;
    }
    if(dir=='D'){
        rh++;
    }
    if(dir=='L'){
        ch--;
    }
    if(dir=='R'){
        ch++;
    }

    dr = rh - rt;
    dc = ch - ct; 
    if((rh == rt) && abs(dc)>1){
        ct+= (ch>ct?1:-1);
        vis[rt][ct] = 1;
        return;
    }
    if((ch == ct)&& abs(dr)>1){
        rt+= (rh>rt?1:-1);
        vis[rt][ct] = 1;
        return;
    }
    if(abs(dr) <=1 && abs(dc)<=1){
        vis[rt][ct] = 1;
        return;
    }
    dr = (dr>0?min(dr,1):max(dr,-1));
    dc = (dc>0?min(dc,1):max(dc,-1));
    ct+=dc;
    rt+=dr;
    vis[rt][ct] = 1;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    //freopen("in.txt", "r",stdin);
    rt=500; ct = 500;
    rh=500; ch = 500; 
    int d = 0;
    

    while(cin>>dir>>d){
        while(d--){
            solve();
            //cout<<rh<<" "<<ch<<" -- "<<rt<<" "<<ct<<endl;
        }
    }
   
   
    int res =0;
    for(int i = 0; i<=1000; i++){
        res+=vis[i].count();
    }

    /*for(int r = 995; r<=1000; r++){
        for(int c = 0; c<=5; c++){
            cout<<vis[r][c];
        }
        cout<<endl;
    }*/
    cout<<res<<endl;
}

