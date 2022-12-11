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

struct car{
    vector<unsigned long long int> arr;
   //vector<unsigned long long int> nuevos;
    bool cuadrado=false;
    bool suma=false;
    bool mult=false;
    unsigned long long int d;
    unsigned long long int mod;
    int pf=0,pv=0;
    int revs=0;
    /*void act(){
        for(unsigned long long int el: nuevos){
            arr.push_back(el);
        }
        nuevos.clear();
    }*/
};
car monos[10];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    freopen("in.txt", "r",stdin);
    string s,aux;int id = 0;
    unsigned long long int div = 1;

    vector<string> tt;
    while (getline(cin,s)){
        //Items iniciales
        getline(cin,s);
        tt = explode(s,' ');
        for(string el: tt){
            if(el[0]>='0' && el[0]<='9'){
                aux = "";
                for(char l: el){
                    if(l==','){
                        break;
                    }
                    aux+=l;
                }
                monos[id].arr.push_back(stoll(aux));   
            }
        }
        //Operacion
        getline(cin,s);
        tt = explode(s,' ');
        if(tt[tt.size()-2]=="*"){
            if(tt.back()=="old"){
                monos[id].cuadrado = true;
            }else{
                monos[id].mult = true;
                monos[id].d = stoull(tt.back());
            }
        }else{
            monos[id].suma = true;
            monos[id].d = stoull(tt.back());
        }
        //modulo
        getline(cin,s);
        tt = explode(s,' ');
        monos[id].mod = stoull(tt.back());
        div*= monos[id].mod;
        //true
        getline(cin,s);
        tt = explode(s,' ');
        monos[id].pv = stoull(tt.back());
        //false
        getline(cin,s);
        tt = explode(s,' ');
        monos[id].pf = stoull(tt.back());
        //se come enter
        getline(cin,s);
        id++;
    }       
    for(int tc = 0; tc<10000; tc++){
        for(int i = 0; i<id; i++){
            for(unsigned long long int el: monos[i].arr){
                monos[i].revs++;
                if(monos[i].suma){
                    el+=monos[i].d;   
                }
                if(monos[i].mult){
                    el*=monos[i].d;
                }
                if(monos[i].cuadrado){
                    el*=el;
                }
                el = el%div;
                if(el%monos[i].mod==0ULL){
                    monos[monos[i].pv].arr.push_back(el);
                }else{
                    monos[monos[i].pf].arr.push_back(el);
                }
            }
            monos[i].arr.clear();
        }
    }
    vector<unsigned long long int> res;
    for(int i = 0; i<id; i++){
        res.push_back(monos[i].revs);
        //cout<<monos[i].revs<<" ";
    }
    //cout<<endl;
    sort(res.begin(),res.end());
    //cout<<res[id-1]<<" "<<res[id-2]<<endl;
    cout<<res[id-1]*res[id-2]<<endl;
}
/*
void sim(){
        for(unsigned long long int el: arr){
            revs++;
            if(suma){
                el+=d;   
            }
            if(mult){
                el*=d;
            }
            if(cuadrado){
                el*=el;
            }
            el = round((long double)el/3.0);

        }
        arr.clear();
    }
    */
