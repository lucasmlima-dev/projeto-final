#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;
int main() {
    SetConsoleOutputCP(65001);

    string nomes[20];
    int qtdAlunos, qtdDisciplinas, opcaoInicial;
    float notas[20][5];
    float media[20];

    inicio_menu:

    cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;
    cout << "1 - Novo relatório" << endl;
    cout << "2 - Ver relatório salvo" << endl;
    cout << "3 - Sobre o sistema" << endl;
    cout << "Escolha uma opção: " << endl;
    cin >> opcaoInicial;

    if (opcaoInicial == 2) {
        ifstream leitura("relatorio.txt");
        if (leitura.is_open()) {
            string linha;
            cout << "\n";
            while (getline(leitura, linha)) {
                cout << linha << endl;
            }
            leitura.close();
       }else {
        cout << "Nenhum relatório encontrado." << endl;
       }
       return 0;
    }

    if (opcaoInicial == 3) {
        cout << "\n=== SOBRE ===" << endl;
        cout << "Desenvolvido por: Lucas Maciel" << endl;
        cout << "Turma: LOPAL 2026 - SENAI-SP" << "\n" << endl;
        goto inicio_menu;
    }

    do {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore();

    for (int i = 0; i < qtdAlunos; i++) {
        nome_invalido:
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);

        if (nomes[i] == "") {
            cout << "Nome inválido!" << endl;
            goto nome_invalido;
        }
    }

    do {
        cout << "\nQuantidade de disciplinas (1 a 5): " << endl;
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for(int i = 0; i < qtdAlunos; i++) {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for(int j = 0; j < qtdDisciplinas; j++) {
            do {
                cout << "Disciplina " << j + 1 << " (1 a 5): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplinas;
    }

    cout << "\nAlunos cadastrados: " << endl;
    for (int i = 0; i < qtdAlunos; i++) {
        cout << "   " << i + 1 << ". " << nomes[i] << endl;
    }

    cout << "\n=== RELATÓRIO ===" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;
    for (int i = 0; i < qtdAlunos; i++) {
        cout << nomes[i] << " - Média: " << media[i] << " - ";
        if (media[i] >= 7) {
            cout << "Aprovado!" << endl;
            aprovados++;
        } else if (media[i] >= 5) {
            cout << "Recuperação!" << endl;
            recuperacao++;
        } else {
            cout << "Reprovado!" << endl;
            reprovados++;
        }
    }

    cout << "\nResumo: " << aprovados << " aprovados, " << reprovados << " reprovados, " << recuperacao << " recuperação." << endl;

    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open()) {
        arquivo << "=== RELATÓRIO ===" << endl;
        time_t agora = time(0);
        char* dataHora = ctime(&agora);
        arquivo << "Data do relatorio: " << dataHora << endl;
        for(int i = 0; i < qtdAlunos; i++) {
            arquivo << nomes[i] << " - Média: " << media[i] << " - ";
            if (media[i] >= 7) {
                arquivo << "Aprovado! :)" << endl;
            } else if(media[i] >= 5) {
                arquivo << "Recuperação!" << endl;
            } else {
                arquivo << "Reprovado! :(" << endl;
            }
        }
        arquivo << "\nResumo: " << aprovados << " Aprovados, " << recuperacao << " Em recuperação, " << reprovados << " Reprovados." << endl;

        arquivo.close();
        cout << "\nRelatório criado com sucesso! Salvo como relatorio.txt" << endl;
    } else {
        cout << "Erro ao criar o arquivo.";
    }

    return 0;
}