#include <iostream>
#include <string>
using namespace std;

struct Usuario
{
    string username;
    string email;
    int id;
    int seguidores;
    bool ativo = true; // true = conta ativa, false = conta suspensa
};
void lerUsuarios(Usuario *v, int n) //Lê nome, e-mail, id, número de seguidores e a atividade de cada usuário.
{
    if (v != nullptr)
    {
        cout << "--- Cadastro de usuarios ---" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Usuario " << i + 1 << ":" << endl;

            cout << "Username: ";
            cin >> (v + i)->username;
            cout << endl;

            cout << "Email: ";
            cin >> (v + i)->email;
            cout << endl;

            v[i].id = 1+i;
            cout << endl;

            cout << "Seguidores: ";
            cin >> (v + i)->seguidores;
            cout << endl;

        }
    }
}
void exibirUsuarios(const Usuario *v, int n) //Exibe todos os campos de cada usuário.
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
            cout << "|Status:" << Ativo<<endl;
        }
    }
}
Usuario *buscarUsuarioPorId(Usuario *v, int n, int id) //Busca por um usuário usando seu ID.
{
    Usuario *procurado = nullptr;
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
void suspenderUsuario(Usuario *u) //Suspende um usuário marcando seu campo ativo como false caso seja true, e emite um aviso caso contrário
{
    if (u != nullptr)
    {
        if (u->ativo == true)
        {
            u->ativo = false;
            cout<<"Usuario "<<u->username<<" suspenso com sucesso."<<endl;
        }
        else
        {
            cout << "Aviso: a conta "<< u->username<<" ja esta suspensa."<< endl;
        }
    }
}
void reativarUsuario(Usuario *u) //Reativa um usuário marcando seu campo ativo como true caso seja false, e emite um aviso caso contrário
{
    if(u!=nullptr){
        if(u->ativo==false){
            u->ativo=true;
            cout<<"Usuario "<<u->username<<" reativado com sucesso."<<endl;
        }
        else{
            cout<<"Aviso: a conta "<<u->username<<" ja esta ativa."<<endl;
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
void lerPosts(Post *v, int p, Usuario *usuarios, int n)
{
    if (v != nullptr){
        cout << "--- Cadastro de posts ---" << endl;

        for (size_t i = 0; i < p; i++){
            cout << "Post " << i + 1 << ":" << endl;

            int id;
            Usuario* usuarioPublicador = nullptr;

            //verifica o ID do autor antes da leitura do Post
            cout << "ID do autor: ";
            cin >> id;
            cout << endl;

            //Verifica se o Autor existe
            usuarioPublicador = buscarUsuarioPorId(usuarios,n,id);
                if(usuarioPublicador != nullptr){

                    //Verifica se ele está ativo
                    if (usuarioPublicador->ativo == true){
                        cout << "Autor encontrado:" << usuarioPublicador->username << endl;
                        v[i].idAutor = usuarioPublicador->id;

                        cout << "Conteudo:";
                        cin >> (v + i)->conteudo;
                        cout << endl;

                        v[i].curtidas = 0;

                        v[i].id = 1+i;

                        cout << "Visibilidade (1-Publico / 0-Apenas seguidores): ";
                        cin >> (v + i)->publico;
                        cout << endl;
                    }
                    cout << endl << "Usuario: " << usuarioPublicador->username << " Suspenso.";
                }
            //Caso id não for encontrado retrocede o codigo a i - 1(Volta ao cadastramento do mesmo post)
            cout << "Erro: usuario com ID " << id << " nao encontrado. Informe novamente.";
            i--;
        }
    }
}
void exibirPosts(const Post *v, int p, const Usuario *usuarios, int n)
{
}
void curtir(Post *p)
{
}
Post *buscarPostPorId(Post *v, int p, int id){
    
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