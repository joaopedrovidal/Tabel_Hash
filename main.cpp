#include <iostream>
#include "Hash.h"
#include "Aluno.h"

using namespace std;

int main() {
    // Criando uma tabela hash pequena para facilitar colisões
    Hash tabelaHash(5); // Tamanho menor para forçar colisões

    // Inserindo alunos com colisões
    tabelaHash.insertItem(Aluno(10, "Joao Pedro")); // 10 % 5 = 0
    tabelaHash.insertItem(Aluno(15, "Ana Clara"));  // 15 % 5 = 0 (colisão)
    tabelaHash.insertItem(Aluno(20, "Carlos Silva")); // 20 % 5 = 0 (colisão)
    tabelaHash.insertItem(Aluno(25, "Beatriz Santos")); // 25 % 5 = 0 (colisão)

    // Imprimindo a tabela hash
    cout << "Tabela Hash após insercoes (com colisoes):" << endl;
    tabelaHash.print();

    // Buscando um aluno que sofreu colisão
    Aluno alunoBusca(15, ""); // RA do aluno a ser buscado
    bool encontrado;
    tabelaHash.retrieveItem(alunoBusca, encontrado);
    if (encontrado) {
        cout << "Aluno encontrado: RA = " << alunoBusca.getRa()
             << ", Nome = " << alunoBusca.getNome() << endl;
    } else {
        cout << "Aluno com RA 15 nao encontrado." << endl;
    }

    // Removendo um aluno que sofreu colisão
    cout << "Removendo aluno com RA 15..." << endl;
    tabelaHash.deleteItem(Aluno(15, ""));

    // Imprimindo a tabela hash após remoção
    cout << "Tabela Hash apos remocao:" << endl;
    tabelaHash.print();

    return 0;
}
