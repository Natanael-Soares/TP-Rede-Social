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
void lerUsuarios(Usuario *v, int n) // Lê nome, e-mail, id, número de seguidores e a atividade de cada usuário.
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

            v[i].id = 1 + i;
            cout << endl;

            cout << "Seguidores: ";
            cin >> (v + i)->seguidores;
            cout << endl;
        }
    }
}
void exibirUsuarios(const Usuario *v, int n) // Exibe todos os campos de cada usuário.
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
            cout << "|Status:" << Ativo << endl;
        }
    }
}
Usuario *buscarUsuarioPorId(Usuario *v, int n, int id) // Busca por um usuário usando seu ID.
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
        }
    }
    return nullptr;
}
void suspenderUsuario(Usuario *u) // Suspende um usuário marcando seu campo ativo como false caso seja true, e emite um aviso caso contrário
{
    if (u != nullptr)
    {
        if (u->ativo == true)
        {
            u->ativo = false;
            cout << "Usuario " << u->username << " suspenso com sucesso." << endl;
        }
        else
        {
            cout << "Aviso: a conta " << u->username << " ja esta suspensa." << endl;
        }
    }
}
void reativarUsuario(Usuario *u) // Reativa um usuário marcando seu campo ativo como true caso seja false, e emite um aviso caso contrário
{
    if (u != nullptr)
    {
        if (u->ativo == false)
        {
            u->ativo = true;
            cout << "Usuario " << u->username << " reativado com sucesso." << endl;
        }
        else
        {
            cout << "Aviso: a conta " << u->username << " ja esta ativa." << endl;
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
    if (v != nullptr)
    {
        cout << "--- Cadastro de posts ---" << endl;

        for (int i = 0; i < p; i++)
        {
            cout << "Post " << i + 1 << ":" << endl;

            int id;
            Usuario *usuarioPublicador = nullptr;

            // verifica o ID do autor antes da leitura do Post
            cout << "ID do autor: ";
            cin >> id;
            cout << endl;

            // Verifica se o Autor existe
            usuarioPublicador = buscarUsuarioPorId(usuarios, n, id);
            if (usuarioPublicador != nullptr)
            {

                // Verifica se ele está ativo
                if (usuarioPublicador->ativo == true)
                {
                    cout << "Autor encontrado:" << usuarioPublicador->username << endl;
                    v[i].idAutor = usuarioPublicador->id;

                    cout << "Conteudo:";
                    cin >> (v + i)->conteudo;
                    cout << endl;

                    v[i].curtidas = 0;

                    v[i].id = 1 + i;

                    cout << "Visibilidade (1-Publico / 0-Apenas seguidores): ";
                    cin >> (v + i)->publico;
                    cout << endl;
                }
                cout << endl
                     << "Usuario: " << usuarioPublicador->username << " Suspenso.";
            }
            // Caso id não for encontrado retrocede o codigo a i - 1(Volta ao cadastramento do mesmo post)
            cout << "Erro: usuario com ID " << id << " nao encontrado. Informe novamente.";
            i--;
        }
    }
}
void exibirPosts(const Post *v, int p, Usuario *usuarios, int n)
{
    if (v != nullptr)
    {
        cout << "--- Feed completo ---" << endl;

        for (int i = 0; i < p; i++)
        {
            // busca o Usuario publicador
            Usuario *usuarioPublicador = buscarUsuarioPorId(usuarios, n, v[i].idAutor);
            // exibindo post
            cout << "[POST " << v[i].id << "] ";
            cout << "@" << usuarioPublicador->username << ": ";
            cout << "\"" << v[i].conteudo << "\"";
            cout << "   |   Curtidas: " << v[i].curtidas << endl;
            cout << "Visibilidade: " << (v[i].publico ? "Publico" : "Apenas seguidores");
            cout << endl;
        }
    }
}
void curtir(Post *p)
{
    p->curtidas++;
}
Post *buscarPostPorId(Post *v, int p, int id)
{
    Post *procurado = nullptr;
    if (v != nullptr)
    {
        for (int i = 0; i < p; i++)
        {
            if ((v + i)->id == id)
            {
                procurado = (v + i);
                return procurado;
            }
            cout << "Post nao encontrado." << endl;
        }
    }
    return nullptr;
}
int contarPostsDeUsuario(const Post *v, int p, int idUsuario)
{
    int acm = 0;
    for (int i = 0; i < p; i++)
    {
        if (idUsuario == v[i].idAutor)
            acm++;
    }
    return acm;
}
void ocultarPost(Post *p)
{
    p->publico = false;
}
void publicarPost(Post *p)
{
    p->publico = true;
}
Post *filtrarPublicos(const Post *v, int p, int *qtd)
{
    // contando publicos
    int total = 0;
    
    for (int i = 0; i < p; i++){
        if (v[i].publico){
            total++;
        }
    }

    // alterando o valor da referencia
    *qtd = total;

    if (total == 0){
        return nullptr;
    }

    // alocando os publicos
    Post *filtrados = new Post[total];

    for (int i = 0; i < p; i++){
        if (v[i].publico){
            filtrados[i] = v[i];
        }
    }

    return filtrados;
}

// Fim da Parte do Marcus e começo da parte do Kauan

int **criarMatriz(int linhas, int colunas)
{
    if (linhas <= 0 || colunas <= 0)
    {
        cout << "Erro: dimensoes invalidas." << endl;
        return nullptr;
    }

    int **m = new int *[linhas];

    for (int i = 0; i < linhas; i++)
    {
        m[i] = new int[colunas];

        for (int j = 0; j < colunas; j++)
        {
            m[i][j] = 0;
        }
    }

    return m;
}
void registrarCurtida(int **m, int idUsuario, Usuario *usuarios, int n, int idPost, Post *posts, int p)
{

    if (m == nullptr || usuarios == nullptr || posts == nullptr){
        cout << "Erro: ponteiro invalido." << endl;
        return;
    }

    Usuario *u = buscarUsuarioPorId(usuarios, n, idUsuario);
    if (u == nullptr){
        cout << "Erro: usuario com ID " << idUsuario << " nao encontrado." << endl;
        return;
    }

    Post *post = buscarPostPorId(posts, p, idPost);
    if (post == nullptr){
        cout << "Erro: post com ID " << idPost << " nao encontrado." << endl;
        return;
    }

    if (!u->ativo){
        cout << "Erro: usuario @" << u->username
             << " esta suspenso e nao pode curtir posts." << endl;
        return;
    }

    if (!post->publico){
        cout << "Erro: apenas posts publicos podem receber curtidas." << endl;
        return;
    }

    if (m[idUsuario - 1][idPost - 1] == 1){
        cout << "Aviso: o usuario @" << u->username
             << " ja curtiu o post [" << idPost << "]." << endl;
        return;
    }

    m[idUsuario - 1][idPost - 1] = 1;
    curtir(post);

    cout << "Curtida registrada com sucesso." << endl;
}
void exibirMatriz(int **m, int n, int p)
{
    if (m == nullptr)
    {
        cout << "Erro: matriz inexistente." << endl;
        return;
    }

    cout << "--- Matriz de curtidas (usuario x post) ---" << endl;

    // cabeçalho
    for (int j = 0; j < p; j++)
    {
        cout << "P" << j + 1 << " ";
    }
    cout << endl;

    // linhas
    for (int i = 0; i < n; i++)
    {
        cout << "U" << i + 1 << " [ ";

        for (int j = 0; j < p; j++)
        {
            cout << m[i][j] << " ";
        }

        cout << "]" << endl;
    }
}
void liberarMatriz(int **m, int linhas)
{
    if (m == nullptr)
        return;

    for (int i = 0; i < linhas; i++)
    {
        delete[] m[i];
    }

    delete[] m;
}

// Fim da Parte do Kauan e começo da parte do Pedro

int main()
{
    int n, p;

    cout << "Quantos usuarios? ";
    cin >> n;
    Usuario *usuarios = new Usuario[n];

    lerUsuarios(usuarios, n);

    cout << "\nQuantos posts? ";
    cin >> p;
    Post *posts = new Post[p];

    lerPosts(posts, p, usuarios, n);

    // cria matriz de curtidas (usuarios x posts)
    int **matrizCurtidas = criarMatriz(n, p);

    int opcao;

    do
    {
        cout << "\n========================================" << endl;
        cout << "SocialCEFET -- Menu" << endl;
        cout << "========================================" << endl;
        cout << "1. Listar usuarios" << endl;
        cout << "2. Listar posts (feed completo)" << endl;
        cout << "3. Buscar usuario por ID" << endl;
        cout << "4. Suspender usuario" << endl;
        cout << "5. Reativar usuario" << endl;
        cout << "6. Buscar post por ID" << endl;
        cout << "7. Ocultar post" << endl;
        cout << "8. Publicar post" << endl;
        cout << "9. Exibir feed publico (filtrado)" << endl;
        cout << "10. Registrar curtida" << endl;
        cout << "11. Exibir matriz de curtidas" << endl;
        cout << "0. Sair" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            exibirUsuarios(usuarios, n);
            break;

        case 2:
            exibirPosts(posts, p, usuarios, n);
            break;

        case 3:
        {
            int id;
            cout << "Digite o ID do usuario: ";
            cin >> id;

            Usuario *u = buscarUsuarioPorId(usuarios, n, id);

            if (u != nullptr)
            {
                cout << "Usuario encontrado: @" << u->username << endl;
            }
            else
            {
                cout << "Usuario nao encontrado." << endl;
            }
            break;
        }

        case 4:
        {
            int id;
            cout << "ID do usuario para suspender: ";
            cin >> id;

            Usuario *u = buscarUsuarioPorId(usuarios, n, id);
            suspenderUsuario(u);
            break;
        }

        case 5:
        {
            int id;
            cout << "ID do usuario para reativar: ";
            cin >> id;

            Usuario *u = buscarUsuarioPorId(usuarios, n, id);
            reativarUsuario(u);
            break;
        }

        case 6:
        {
            int id;
            cout << "Digite o ID do post: ";
            cin >> id;

            Post *post = buscarPostPorId(posts, p, id);

            if (post != nullptr)
            {
                cout << "Post encontrado: " << post->conteudo << endl;
            }
            else
            {
                cout << "Post nao encontrado." << endl;
            }
            break;
        }

        case 7:
        {
            int id;
            cout << "ID do post para ocultar: ";
            cin >> id;

            Post *post = buscarPostPorId(posts, p, id);
            if (post != nullptr)
            {
                ocultarPost(post);
                cout << "Post ocultado com sucesso." << endl;
            }
            break;
        }

        case 8:
        {
            int id;
            cout << "ID do post para publicar: ";
            cin >> id;

            Post *post = buscarPostPorId(posts, p, id);
            if (post != nullptr)
            {
                publicarPost(post);
                cout << "Post publicado com sucesso." << endl;
            }
            break;
        }

        case 9:
        {
            int qtdPublicos;
            Post *publicos = filtrarPublicos(posts, p, &qtdPublicos);

            if (publicos == nullptr)
            {
                cout << "Nao ha posts publicos." << endl;
            }
            else
            {
                exibirPosts(publicos, qtdPublicos, usuarios, n);
                delete[] publicos;
            }
            break;
        }

        case 10:
        {
            int idUsuario, idPost;

            cout << "ID do usuario: ";
            cin >> idUsuario;

            cout << "ID do post: ";
            cin >> idPost;

            registrarCurtida(matrizCurtidas, idUsuario, usuarios, n, idPost, posts, p);
            break;
        }

        case 11:
            exibirMatriz(matrizCurtidas, n, p);
            break;

        case 0:
            cout << "Encerrando programa..." << endl;
            break;

        default:
            cout << "Opcao invalida." << endl;
        }

    } while (opcao != 0);

    liberarMatriz(matrizCurtidas, n);
    delete[] posts;
    delete[] usuarios;

    posts = nullptr;
    usuarios = nullptr;

    return 0;
}