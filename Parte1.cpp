#include <iostream>
#include <string>
using namespace std;

// Só organizando a formatação

struct Usuario
{
    string username;
    string email;
    int id;
    int seguidores;
    bool ativo; // true = conta ativa, false = conta suspensa
};
void lerUsuarios(Usuario *v, int n)
{
    if (v != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Usuario " << i + 1 << ":" << endl;
            cout << "Nome:" << endl;
            cin >> (v + i)->username;
            cout << endl;
            cout << "email:" << endl;
            cin >> (v + i)->email;
            cout << endl;
            cout << "id:" << endl;
            cin >> (v + i)->id;
            cout << endl;
            cout << "seguidores:" << endl;
            cin >> (v + i)->seguidores;
            cout << endl;
            cout << "Digite 1 para Sim e 0 para Nao" << endl << "on-line?";
            cin >> (v + i)->ativo;
            cout << endl;
        }
    }
    else
    {
        cout << "Erro de entrada de dados" << endl;
    }
}
void exibirUsuarios(const Usuario *v, int n)
{
    string Ativo;
    if (v != nullptr)
    {
        cout << "Usuarios:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "[ID" << (v + i)->id << "]" << (v + i)->username << "|E-Mail:" << (v + i)->email << "|Seguidores:" << (v + i)->seguidores;
            if ((v + i)->ativo == true)
            {
                Ativo = "conta ativa";
            }
            else
            {
                Ativo = "conta suspensa";
            }
            cout << "|Status:" << Ativo;
        }
    }
    else
    {
        cout << "Erro de entrada de dados" << endl;
    }
}
Usuario *buscarUsuarioPorId(Usuario *v, int n, int id)
{
    Usuario *procurado;
    if (v != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            if ((v + i)->id == id)
            {
                procurado = (v + i);
                return procurado;
            }
            cout << "Usuario nao encontrado." << endl;
            return nullptr;
        }
    }
}
void suspenderUsuario(Usuario *u)
{
    if (u != nullptr)
    {
        if (u->ativo == true)
        {
            u->ativo = false;
        }
        else
        {
            cout << "O usuario ja esta suspenso." << endl;
        }
    }
}
void reativarUsuario(Usuario *u)
{
    if(u!=nullptr){
        if(u->ativo==false){
            u->ativo=true;
        }
        else{
            cout<<"O usuario ja esta ativo."<<endl;
        }
    }
}

// Fim da Parte do Natanael e começo da parte do Marcus

struct Post
{
    string conteudo; // texto do post
    int id;
    int idAutor; // id do Usuario que criou o post
    int curtidas;
    bool publico; // true = vis´ıvel para todos, false = apenas seguidores
};
void lerPosts(Post *v, int p, const Usuario *usuarios, int n)
{
        for (size_t i = 0; i < p; i++){

                if (usuarios[n].ativo == true){
                    cout << "Post " << i + 1 << ":" << endl;
                    cout << "Conteudo:" << endl;
                    cin >> (v + i)->conteudo;
                    cout << endl;

                    cout << "Id:" << endl;
                    cin >> (v + i)->id;
                    cout << endl;

                    v[i].idAutor = usuarios[n].id;

                    cout << "Curtidas:" << endl;
                    cin >> (v + i)->curtidas;
                    cout << endl;

                    cout << "Digite 1 para Sim e 0 para Nao" << endl <<     "Publico?";
                    cin >> (v + i)->publico;
                    cout << endl;
                }
    }
    
}
void exibirPosts(const Post *v, int p, const Usuario *usuarios, int n)
{
}
void curtir(Post *p)
{
}
Post *buscarPostPorId(Post *v, int p, int id)
{
}
int contarPostsDeUsuario(const Post *v, int p, int idUsuario)
{
}
void ocultarPost(Post *p)
{
}
void publicarPost(Post *p)
{
}

// Fim da Parte do Marcus e começo da parte do Kauan

void registrarCurtida(int **m, int idUsuario, const Usuario *usuarios, int n, int idPost, Post *posts, int p)
{
}
void exibirMatriz(int **m, int n, int p)
{
}
void liberarMatriz(int **m, int linhas)
{
}

// Fim da Parte do Kauan e começo da parte do Pedro

int main()
{
    int n;
    cout << "Quantos usuarios? " << endl;
    cin >> n;
    Usuario *usuarios = new Usuario[n];
    
    // Menu Esperado:

    //========================================
    //SocialCEFET -- Menu
    //========================================
    //1. Listar usuarios
    //2. Listar posts (feed completo)
    //3. Buscar usuario por ID
    //4. Suspender usuario
    //5. Reativar usuario
    //6. Buscar post por ID
    //7. Ocultar post
    //8. Publicar post
    //9. Exibir feed publico (filtrado)
    //10. Registrar curtida
    //11. Exibir matriz de curtidas
    //0. Sair
    //----------------------------------------
    //Opcao: _

    delete[] usuarios;
    usuarios=nullptr;
    return 0;
}