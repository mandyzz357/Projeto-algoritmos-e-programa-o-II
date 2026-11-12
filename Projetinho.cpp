#include <iostream>
#define MAX 20
using namespace std;

/* Definir a struct para cadastro de cursos */
struct Curso {
int cod_curso;
string nome_curso;
int ch_total;
int qtd_vagas;
};

struct Alunos {
int num_matricula;
string nome_aluno;
int cod_curso;
int idade;
};

/* Procedimento que exibe o menu com as opções */
void mostrar_menu(){
    cout << "##################### BEM VIND@! #####################\n";
    cout << "1 - Para cadastrar um curso.\n";
    cout << "2 - Para cadastrar alunos.\n";
    cout << "3 - Listar cursos.\n";
    cout << "4 - Listar alunos.\n";
    cout << "5 - Buscar alunos por curso.\n";
    cout << "6 - Relatorio geral.\n";
    cout << "0 - Sair.\n";
    cout << "################################################\n\n";
    cout << "Digite sua opcao: ";
}

/* Procedimento para cadastrar curso e bloquear se for o mesmo codigo */
    void cadastrar_curso(Curso cursos[],int posicao, int quantidade) {
// Curso cursos[] é o vetor que guarda os cursos
// int quantidade é ncessário para procurar códigos repetidos, pois mostra quantos já existem
    cout << "Digite o codigo do curso: ";
    cin >> cursos[posicao].cod_curso;
// aqui há a implementação do código no curso que for cadastrado
    for (int i = 0; i < quantidade; i++) {
        if(cursos[i].cod_curso == cursos[posicao].cod_curso){
            cout << "Curso já cadastrado!" << endl;
            return;
        }
}

    cout << "Digite o nome do curso: ";
    cin.ignore(); // serve para ignorar o enter
    getline(cin, cursos[posicao].nome_curso); // pega a linha inteira digitada

    cout << "Digite a carga horaria total: ";
    cin >> cursos[posicao].ch_total;

    cout << "Digite a quantidade de vagas: ";
    cin >> cursos[posicao].qtd_vagas;

    cout << "Curso cadastrado com sucesso!" << endl;
}

/* Procedimento para cadastrar aluno */
     void cadastro_aluno(Alunos alunos[], int posicao, Curso cursos[], int qtd_cursos) {
// o aluno só é vinculado se o curso já estiver cadastrado
    cout << "Digite o numero da matricula: ";
    cin >> alunos[posicao].num_matricula;

    cout << "Digite o nome do aluno: ";
    cin.ignore();
    getline(cin, alunos[posicao].nome_aluno);

    cout << "Digite a idade: ";
    cin >> alunos[posicao].idade;
// acima cadastra os dados do aluno

    cout << "Digite o código do curso: ";
    cin >> alunos[posicao].cod_curso;

    bool curso_encontrado = false;

    for(int i = 0; i < qtd_cursos; i++) {
        if(cursos[i].cod_curso == alunos[posicao].cod_curso) {
            curso_encontrado = true;
        }
    }

    if(curso_encontrado == false) {
        cout << "Curso nao cadastrado!" << endl;
        return;
    }
}


/* Procedimento que lista os cursos */
    void listar_cursos(Curso cursos[], int quantidade) {
// esse procedimento puxa todas as informações do curso cadastrado
        for (int i = 0; i < quantidade; i++) {
            cout << "---------------------------------" << endl;
            cout << "Código: " << cursos[i].cod_curso << endl;
            cout << "Nome: " << cursos[i].nome_curso << endl;
            cout << "Carga Horaria: " << cursos[i].ch_total << endl;
            cout << "Quantidade de vagas: " << cursos[i].qtd_vagas << endl;
        }

    }

/* Procedimento que lista os alunos */
    void listar_alunos(Alunos alunos[], int quantidade) {

        for (int i = 0; i < quantidade; i++) {

            cout << "---------------------------------" << endl;
            cout << "Matricula: " << alunos[i].num_matricula << endl;
            cout << "Nome: " << alunos[i].nome_aluno << endl;
            cout << "Idade: " << alunos[i].idade << endl;
            cout << "Codigo do curso: " << alunos[i].cod_curso << endl;
        }
    }


/* Procedimento para buscar alunos por curso */
    void busca_alunos(Alunos alunos[], int qtd_alunos, Curso cursos[], int qtd_cursos) {

        int busca;
        cout << "Digite o codigo do curso: ";
        cin >> busca;
        bool curso_encontrado = false;

         for(int i = 0; i < qtd_cursos; i++) {
            if(cursos[i].cod_curso == busca) {

                curso_encontrado = true;
        }
    }

    if(curso_encontrado == false) {
        cout << "Curso nao cadastrado!" << endl;

        return;
    }
        bool aluno_encontrado = false;

        for(int i = 0; i < qtd_alunos; i++) {
            if(alunos[i].cod_curso == busca) {

                    aluno_encontrado = true;
                cout << "---------------------------------" << endl;
                cout << "Nome: " << alunos[i].nome_aluno << endl;
                cout << "Matricula: " << alunos[i].num_matricula << endl;
                cout << "Idade: " << alunos[i].idade << endl;

            }

        }

        if (aluno_encontrado == false) {
            cout << "Nenhum aluno matriculado neste curso." << endl;
        }
    }

/* Procedimento para emitir o relatório geral */
    void relatorio(Alunos alunos[], int qtd_alunos, Curso cursos[], int qtd_cursos) {

        for (int i = 0; i < qtd_cursos; i++) {

            int quantidade = 0;

            for(int j = 0; j < qtd_alunos; j++) {

                if (alunos[j].cod_curso == cursos[i].cod_curso) {
                    quantidade++;
                }
            }

            cout << "---------------------------------" << endl;
            cout << "Curso: " << cursos[i].nome_curso << endl;
            cout << "Codigo: " << cursos[i].cod_curso << endl;
            cout << "Quantidade de alunos: " << quantidade << endl;
        }
    }

int main() {

    Curso cursos[MAX];
    Alunos alunos[MAX];

    int qtd_cursos = 0;
    int qtd_alunos = 0;

    int opcao;

    while(true) {

        mostrar_menu();
        cin >> opcao;

        switch(opcao) {

        case 1:

            if(cadastrar_curso(cursos, qtd_cursos, qtd_cursos)) {
                qtd_cursos++;
            }

            break;


        case 2:

            if(cadastro_aluno(alunos, qtd_alunos, cursos, qtd_cursos)) {
                qtd_alunos++;
            }

            break;


        case 3:

            listar_cursos(cursos, qtd_cursos);

            break;


        case 4:

            listar_alunos(alunos, qtd_alunos);

            break;


        case 5:

            busca_alunos(alunos, qtd_alunos, cursos, qtd_cursos);

            break;


        case 6:

            relatorio(alunos, qtd_alunos, cursos, qtd_cursos);

            break;


        case 0:

            cout << "Saindo do sistema..." << endl;

            return 0;


        default:

            cout << "Opcao invalida!" << endl;
        }
    }
}
