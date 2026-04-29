#include <iostream>
#include <string>
using namespace std;
struct Usuario {
string username;
string email;
int id;
int seguidores;
bool ativo; // true = conta ativa, false = conta suspensa
};

struct Post {
string conteudo; // texto do post
int id;
int idAutor; // id do Usuario que criou o post
int curtidas;
bool publico; // true = vis´ıvel para todos, false = apenas seguidores
};

void lerUsuarios(Usuario* v, int n){
    if(v!=nullptr){
        for(int i=0;i<n;i++){
            cout<<"Usuario "<<i+1<<":"<<endl;
            cout<<"Nome:"<<endl;
            cin>>(v+i)->username;
            cout<<endl;
            cout<<"email:"<<endl;
            cin>>(v+i)->email;
            cout<<endl;
            cout<<"id:"<<endl;
            cin>>(v+i)->id;
            cout<<endl;
            cout<<"seguidores:"<<endl;
            cin>>(v+i)->seguidores;
            cout<<endl;
            cout<<"on-line?"<<endl;
            cin>>(v+i)->ativo;
            cout<<endl;
        }
    }
    else{
        cout<<"Erro de entrada de dados"<<endl;
    }
}

void exibirUsuarios(const Usuario* v, int n){
    string Ativo;
    if(v!=nullptr){
        cout<<"Usuarios:"<<endl;
        for(int i=0;i<n;i++){
            cout<<"[ID"<<(v+i)->id<<"]"<<(v+i)->username<<"|E-Mail:"<<(v+i)->email<<"|Seguidores:"<<(v+i)->seguidores;
            if((v+i)->ativo==true){
                Ativo="conta ativa";
            }
            else{
                Ativo="conta suspensa";
            }
            cout<<"|Status:"<<Ativo;
        }
    }
    else{
        cout<<"Erro de entrada de dados"<<endl;
    }
}

Usuario* buscarUsuarioPorId(Usuario* v, int n, int id){
    Usuario* procurado;
    if(v!=nullptr){
        for(int i=0;i<n;i++){
            if((v+i)->id==id){
                procurado=(v+i);
                return procurado;
            }
            cout<<"Usuario nao encontrado."<<endl;
            return nullptr;
        }   
    }
}

void suspenderUsuario(Usuario* u){
    if(u!=nullptr){
        if(u->ativo==true){
            u->ativo=false;
        }
        else{
            cout<<"O usuario ja esta suspenso."<<endl;
        }
    }
}

void reativarUsuario(Usuario* u){

}


int main(){
    int n;
    cout<<"Quantos usuarios? "<<endl;
    cin>>n;
    Usuario * usuarios = new Usuario[n];
    //Resto do código
    //.
    //.
    //.
    delete[] usuarios;
    return 0;
}