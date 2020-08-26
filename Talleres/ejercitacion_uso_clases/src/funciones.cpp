#include <vector>
#include "algobot.h"


using namespace std;


// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> c;
    vector<int> res;
    for(int n=0; n<s.size(); n++ ) {
        if (c.count(s[n]) == 0) {
            c.insert(s[n]);
            res.push_back(s[n]);
        }
    }
    return res;

}
// test mio
vector<int> a = {1,2,3,1,2,5};
vector<int> res = quitar_repetidos(a);
// fin test mio

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> c;
    vector<int> res;
    for(int n=0; n<s.size(); n++ ) {
        if (c.count(s[n]) == 0) {
            c.insert(s[n]);
            res.push_back(s[n]);
        }
    }
    return res;

}

// Ejercicio 3

void copyVectorInSet(set<int>& s,vector<int> v){ //aux
    for (int i = 0; i < v.size() ; ++i) {
        s.insert(v[i]);
    }
}

bool subSetInt(set<int> a,set<int> b){ //aux
    for (int n : a) {
        if (b.count(n) == 0 ){
            return false;
        }
    }
    return true;
}

bool mismos_elementos(vector<int> a, vector<int> b) {

    set<int> sa;
    set<int> sb;
    copyVectorInSet(sa,a);
    copyVectorInSet(sb,b);
    return subSetInt(sa,sb) && subSetInt(sb,sa);
}


// test mio
set<int> saj;


// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return mismos_elementos(a,b);
}



// Ejercicio 5

map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> res;
    for (int i = 0; i < s.size() ; ++i) {
        if (res.count(s[i]) == 0){
            res[s[i]] = 1;
        } else{
            res[s[i]] = res[i]+1;
        }
    }
    return res;
}


// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> v) {
    map<int,int> m = contar_apariciones(v);
    vector<int> res = {};
    for (int i = 0; i < v.size(); ++i) {
        if (m[v[i]] == 1){
            res.push_back(v[i]);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int n : a) {
        if(b.count(n) == 1){
            res.insert(n);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int,set<int>> res;
    for (int n: s) {
        int resto = n % 10;
        if (res.count(resto)==0){
            res[resto]={};
        }
        res[resto].insert(n);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    map<char,char> m;
    for (int i = 0; i < tr.size(); ++i) { // paso el tr que es vector a tipo map, copiandolo
        m[tr[i].first] = tr[i].second;
    }
    for (int j = 0; j < str.size(); ++j) {
        if (m.count(str[j]) == 1){
            res.push_back(m[str[j]]);
        } else{
            res.push_back(str[j]);
        }
    }
    return res;
}

// Ejercicio 10

//bool subSetLU(set<LU> a,set<LU> b){ //aux
//    for (LU lu : a) {
//        for (LU lub : b) {
//            if (lu==lub){
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//bool mismoGrupo(set<LU> a, set<LU> b) {
//
//    bool emMismoGrupo = subSetLU(a,b) && subSetLU(b,a);
//    return emMismoGrupo;
//}
//
//void completarMapaDeRepeticiones (map<LU,vector<int>>& repeticiones ,LU lu,vector<Mail>& mails,int& nMailActual){
//    for (int i = 0; i < mails.size() ; ++i) {
//        if (i!=nMailActual ){  // miro si el lu observado pertenece a otro mail?
//            for (LU lus:mails[i].libretas()) {
//                if (lu==lus){
//                    repeticiones[lu].push_back(i);
//                }
//            }
//        }
//    }
//}
//
//bool hayRepeticionIlegal (map<LU,vector<int>>& repeticiones ,LU lu,set<LU> grupoLu,vector<Mail>& mails){
//    vector<int> candidatos=repeticiones[lu];
//    for (int i = 0; i < candidatos.size(); ++i) {
//        if(!mismoGrupo(grupoLu,mails[candidatos[i]].libretas() )){
//            return false;
//        }
//    }
//}
//
//bool integrantes_repetidos(vector<Mail> s) {
//
//    for (int i = 0; i < s.size() ; ++i) {
//        for (LU lu: s[i].libretas() ) {
//            map<LU,vector<int>> repeticiones = {};
//            completarMapaDeRepeticiones(repeticiones,lu,s,i);
//            if (repeticiones.size()>0){
//                if (hayRepeticionIlegal(repeticiones,lu,s[i].libretas(),s)){ // no se porque no da nunca true
//                    return true;
//                }
//            }
//        }
//    }
//
//    return false;
//}


set<LU> interseccion_lu(set<LU> a, set<LU> b){
    set<LU> res;
    for (LU lu : a) {
        if(b.count(lu) == 1){
            res.insert(lu);
        }
    }
    return res;
}

bool conj_lu_iguales(set<LU> a, set<LU> b){
    if(a.size()!=b.size()){
        return false;
    } else if (interseccion_lu(a,b).size()==a.size()){
        return true;
    }
    return false;
}

bool integrantes_repetidos(vector<Mail> s){
    for (int i = 0; i < s.size() ; ++i) {
        for (int j = i; j < s.size() ; ++j) {
            set<LU> inter = interseccion_lu(s[i].libretas(),s[j].libretas() );
            if(inter.size()>0 && !conj_lu_iguales(s[i].libretas(),s[j].libretas()) ){
                return true;
            }
        }
    }
    return false;
}


// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}






