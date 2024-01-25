#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <unistd.h>
#include <fstream>
#include <set>

using namespace std;

int main() {
    int escolha;
    int qtdSair = 0;

    do {
    cout << "Escolha a opcao:\n";
    cout << "1: Sorteio Manual!\n";
    cout << "2: Sorteio Automatico\n";
    cout << "3: Gerar Cartoes\n";
    cout << "4: Sair\n";
    cin >> escolha;

    // Criando um motor de geração de números aleatórios
    mt19937 gerador(random_device{}());



    if (escolha == 1) {
        int maximo;

        do {
        cout << "Escolha o numero maximo (75, 90 ou 100): ";
        cin >> maximo;

        if (maximo != 75 && maximo != 90 && maximo != 100) {
            cout << "Opcao invalida. Escolha 75, 90 ou 100.\n";
        }
            } while (maximo != 75 && maximo != 90 && maximo != 100);

        vector<int> numeros;
        for (int i = 1; i <= maximo; ++i) {
            numeros.push_back(i);
        }

        vector<int> numerosLancados;
        int numeroAnterior = 0;

        if (maximo == 75) {
            qtdSair = 4;
        } else if (maximo == 100) {
            qtdSair = 25;
        } else if (maximo == 90) {
            qtdSair = 14;
        }

        cin.ignore();

        uniform_int_distribution<> distribuicao(0, maximo - 1);

        for (int i = 0; i < qtdSair; ++i) {
            int larguraDoConsole = 80;
            int espacosAntes = (larguraDoConsole - ("SORTEIO COM " + to_string(maximo) + " BOLAS").length()) / 2;
            int indiceSorteado;
            do {
                indiceSorteado = distribuicao(gerador);
            } while (find(numerosLancados.begin(), numerosLancados.end(), numeros[indiceSorteado]) != numerosLancados.end());

            int numeroSorteado = numeros[indiceSorteado];
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            cout << "\033[1;34m"; //Cor Azul
            cout << setw(espacosAntes) << "" << "PAINEL - BINGO" << endl;
            cout << setw(espacosAntes) << "" << "SORTEIO COM " << maximo << " BOLAS" << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\033[0m"; //Cor Azul

             for (int j = 0; j < maximo; ++j) {
                if (find(numerosLancados.begin(), numerosLancados.end(), numeros[j]) != numerosLancados.end()) {
                        cout << "\033[1;31m";
                    cout << setw(4) << numeros[j];
                } else {
                    cout << "\033[1;34m"; //Cor Azul
                    cout << setw(4) << numeros[j];
                }

                if ((j + 1) % 20 == 0) {
                    cout << "\n";
                } else {
                    cout << " ";
                }
            }

            cout << "\033[1;34m"; //Cor Azul
            cout << " " << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\033[0m";
            cout << endl << endl;
            cout << "\033[1;34m"; //Cor Azul
            cout << "Sorteado anterior: ";
            cout << "\033[1;31m" << numeroAnterior << "\033[0m";
            cout << endl;
            cout << "\033[1;34m"; //Cor Azul
            cout << "Sorteado " << i + 1 << ": ";
            cout << "\033[1;31m" << numeroSorteado << "\033[0m";
            cout << endl;

            numeroAnterior = numeroSorteado;

            cout << "\033[1;34m"; //Cor Azul
            cout << "Pressione Enter para sortear o proximo numero...\n";
            cout << "\033[0m";
            cin.ignore();

            numerosLancados.push_back(numeroSorteado);
        }

        cout << "Pressione Enter para encerrar o programa...\n";
        cin.ignore();
    } else if (escolha == 2) {
        int maximo;

        do {
        cout << "Escolha o numero maximo (75, 90 ou 100): ";
        cin >> maximo;

        if (maximo != 75 && maximo != 90 && maximo != 100) {
            cout << "Opcao invalida. Escolha 75, 90 ou 100.\n";
        }
            } while (maximo != 75 && maximo != 90 && maximo != 100);

        uniform_int_distribution<> distribuicao(1, maximo);

        vector<int> numeros;
        while (numeros.size() < maximo) {
            int numeroAleatorio = distribuicao(gerador);
            if (find(numeros.begin(), numeros.end(), numeroAleatorio) == numeros.end()) {
                numeros.push_back(numeroAleatorio);
            }
        }

        sort(numeros.begin(), numeros.end());

        vector<int> numerosLancados;
        int numeroAnterior = 0;

        if (maximo == 75) {
            qtdSair = 4;
        } else if (maximo == 100) {
            qtdSair = 25;
        } else if (maximo == 90) {
            qtdSair = 14;
        }

        for (int i = 0; i < qtdSair; ++i) {
            int numeroSorteado = distribuicao(gerador);
            int larguraDoConsole = 80;
            int espacosAntes = (larguraDoConsole - ("SORTEIO COM " + to_string(maximo) + " BOLAS").length()) / 2;

            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            numerosLancados.push_back(numeroSorteado);
            cout << "\033[1;34m";
            cout << setw(espacosAntes) << "" << "PAINEL - BINGO" << endl;
            cout << setw(espacosAntes) << "" << "SORTEIO COM " << maximo << " BOLAS" << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\033[0m";
            for (int j = 0; j < maximo; ++j) {
                if (find(numerosLancados.begin(), numerosLancados.end(), numeros[j]) != numerosLancados.end()) {
                        cout << "\033[1;31m";
                    cout << setw(4) << numeros[j];
                } else {
                    cout << "\033[1;34m"; //Cor Azul
                    cout << setw(4) << numeros[j];
                }

                if ((j + 1) % 20 == 0) {
                    cout << "\n";
                } else {
                    cout << " ";
                }
            }

            cout << " " << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << endl << endl;
            cout << "\033[1;34m"; //Cor Azul
            cout << "Sorteado anterior: ";
            cout << "\033[1;31m" << numeroAnterior << "\033[0m";
            cout << endl;
            cout << "\033[1;34m"; //Cor Azul
            cout << "Sorteado " << i + 1 << ": ";
            cout << "\033[1;31m" << numeroSorteado << "\033[0m";
            cout << endl;

            numeroAnterior = numeroSorteado;
            #ifdef _WIN32
            Sleep(1000);
            #else
            sleep(1);
            #endif
        }
    } else if (escolha == 3) {
    int quantidadeDeArquivos = 0;
    int maximo = 0;
    int qtdSair = 0;
    int maxNumerosPorLinha = 4;

    do {
        cout << "Escolha o numero maximo (75, 90 ou 100): ";
        cin >> maximo;

        if (maximo != 75 && maximo != 90 && maximo != 100) {
            cout << "Opcao invalida. Escolha 75, 90 ou 100.\n";
        }
    } while (maximo != 75 && maximo != 90 && maximo != 100);

    cout << "Quantos cartoes pretende gerar?" << endl;
    cin >> quantidadeDeArquivos;

    if (maximo == 75) {
        qtdSair = 4;
    } else if (maximo == 100) {
        qtdSair = 25;
    } else if (maximo == 90) {
        qtdSair = 14;
    }

    for (int i = 0; i < quantidadeDeArquivos; ++i) {
        stringstream nomeArquivoStream;
        nomeArquivoStream << i << ".txt";
        string nomeArquivo = nomeArquivoStream.str();

        ofstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
            return 1;
        }

        srand(static_cast<unsigned int>(time(nullptr)));

        set<int> numerosUnicos;
        vector<int> numerosPorLinha;

        while (numerosUnicos.size() < maxNumerosPorLinha * 4) {
            int numeroAleatorio = rand() % maximo + 1;
            if (numerosUnicos.insert(numeroAleatorio).second) {
                numerosPorLinha.push_back(numeroAleatorio);
                if (numerosPorLinha.size() == maxNumerosPorLinha) {
                    for (int numero : numerosPorLinha) {
                        arquivo << setw(3) << numero << ' ';
                    }
                    arquivo << endl;
                    numerosPorLinha.clear();
                }
            }
        }

        arquivo.close();

        cout << "Arquivo " << nomeArquivo << " gerado com sucesso!" << endl;
    }

    return 0;

    } else if (escolha == 4) {
        return 0;
    } else {
        cout << "Opcao invalida. Escolha 1, 2, 3 ou 4.\n";
    }

    }  while (escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4);

    return 0;
}
