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
vector<string> grid;
unsigned long long int solve(int row,int col){
    unsigned long long int res = 1;
    unsigned long long int aux = 0;

    aux=0;
    for(int d = row+1; d<grid.size(); d++){
        if(grid[d][col]>=grid[row][col]){
            aux++;
            break;
        }
        aux++;
    }
    res*=aux;


    aux=0;
    for(int d = row-1; d>=0; d--){
        if(grid[d][col]>=grid[row][col]){
            aux++;
            break;
        }
        aux++;
    }
    res*=aux;


    aux=0;
    for(int d = col+1; d<grid[0].size(); d++){
        if(grid[row][d]>=grid[row][col]){
            aux++;
            break;
        }
        aux++;
    }
    res*=aux;


    aux=0;
    for(int d = col-1; d>=0; d--){
        if(grid[row][d]>=grid[row][col]){
            aux++;
            break;
        }
        aux++;
    }
    res*=aux;

    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    freopen("in.txt", "r",stdin);
    string s;
    while(cin>>s){
        grid.push_back(s);
    }
    unsigned long long int res = 0;

    for(int r   = 0; r<grid.size(); r++){
        for(int c = 0; c<grid[r].size(); c++){
            res = max(res,solve(r,c));
        }
    }
    cout<<res<<endl;
}

/*


    for(int r   = 0; r<grid.size(); r++){
        curr = '/';
        for(int c = 0; c<grid[r].size(); c++){
            if(grid[r][c]>curr && !vis[r][c]){
                vis[r][c] = 1;
                res++;
                curr = max(curr,grid[r][c]);
            }
            curr = max(curr,grid[r][c]);
        }
    }


    for(int r   = 0; r<grid.size(); r++){
        curr = '/';
        for(int c = grid[r].size()-1; c>=0; c--){
            
            if(grid[r][c]>curr && !vis[r][c]){
                vis[r][c] = 1;
                res++;
            }
            curr = max(curr,grid[r][c]);
        }
    }


    for(int c =0; c<grid[0].size(); c++){
        curr = '/';
        for(int r = 0; r<grid.size(); r++){
            if(grid[r][c]>curr && !vis[r][c]){
                vis[r][c] = 1;
                res++;
            }
            curr = max(curr,grid[r][c]);
        }
    }


    for(int c =0; c<grid[0].size(); c++){
        curr = '/';
        for(int r = grid.size()-1; r>=0; r--){
            if(grid[r][c]>curr && !vis[r][c]){
                vis[r][c] = 1;
                res++;
            }
            curr = max(curr,grid[r][c]);
        }
    }
*/