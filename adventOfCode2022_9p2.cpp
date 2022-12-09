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
int r[10];
int c[10];
int dr,dc;
char dir;

void solve(){
    
    
    if(dir=='U'){
        r[0]--;
    }
    if(dir=='D'){
        r[0]++;
    }
    if(dir=='L'){
        c[0]--;
    }
    if(dir=='R'){
        c[0]++;
    }

    for(int i = 1; i<10; i++){
        dr = r[i-1] - r[i];
        dc = c[i-1] - c[i]; 
        if((r[i-1] == r[i]) && abs(dc)>1){
            c[i]+= (c[i-1]>c[i]?1:-1);
            vis[r[i]][c[i]] = (i==9?1:vis[r[i]][c[i]]);
            continue;;
        }
        if((c[i-1] == c[i])&& abs(dr)>1){
            r[i]+= (r[i-1]>r[i]?1:-1);
            vis[r[i]][c[i]] = (i==9?1:vis[r[i]][c[i]]);
            continue;
        }
        if(abs(dr) <=1 && abs(dc)<=1){
            vis[r[i]][c[i]] = (i==9?1:vis[r[i]][c[i]]);
            continue;
        }
        dr = (dr>0?min(dr,1):max(dr,-1));
        dc = (dc>0?min(dc,1):max(dc,-1));
        c[i]+=dc;
        r[i]+=dr;
        vis[r[i]][c[i]] = (i==9?1:vis[r[i]][c[i]]);
    }

}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    freopen("in.txt", "r",stdin);
    for(int i = 0; i<10; i++){
        r[i]= 500;
        c[i]=500;
    }
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

