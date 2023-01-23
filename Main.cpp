#include <bits/stdc++.h>
#include <random>
#include <ctime>
#include <fstream>
#include "Aeroporto.hpp"

int numaleatorio()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> num(0, 3);
    return num(mt);
}

int main()
{
    string linha, companhia;
    int minutos, id, cont = 1, passageiros, num_avioes = 0, cont_emerge = 0, resp, min=0;
    bool tipo;
    Aeroporto *aero = new Aeroporto();
    vector<Viao> avioesP;
    vector<Viao>avioesI;
    srand(time(NULL));

    ifstream Arq;
    do
    {
        cout << "\n\t********************** SEJA BEM VINDO AO PROGRAMA DO AEOPORTO ****************************\t";
        cout << "\n\tDigite o numero do item que deseja realizar\n\n";
        cout << "\t 1- Execução do programa por arquivo" << endl;
        cout << "\t 2- Execução do programa por número aleatório" << endl;
        cout << "\t 0- Sair do programa\n\n";
        cout << "\t*******************************************************************************************\t\n";
        cin >> resp;

        switch (resp)
        {
        case 1:
            Arq.open("aeroporto.txt", ios::in);
            if (Arq.fail())
                cout << ("Problemas na abertura do arquivo\n");

            while (!Arq.eof())
            {
                while (getline(Arq, linha, '\n'))
                {
                    if (cont == 1)
                    {
                        minutos = atoi(linha.c_str());
                        cont++;
                        
                    }
                    else if (cont == 2)
                    {
                        companhia = linha;
                        cont++;
                    }
                    else if (cont == 3)
                    {
                        id = atoi(linha.c_str());
                        if (id % 2 == 0)
                            tipo = false;
                        else
                            tipo = true;

                        cont++;
                    }
                    else if (cont == 4)
                    {
                        passageiros = atoi(linha.c_str());
                        cont++;
                        Viao V(minutos, companhia, id, tipo, passageiros);
                        if(tipo){
                            avioesI.push_back(V);
                        }
                        else{
                            avioesP.push_back(V);

                        }
                        
                        num_avioes++;
                        cont = 1;
                    }
                  
                }
            }
            Arq.close();
          
           
            int decolagem, aterrissagem, aux;
            while (avioesI.size() + avioesP.size()> 0)
            {
                decolagem = rand() % 4;
                aterrissagem = rand() % 4;
                cout << "\n";
                cout << "Número de aviões que irão decolar: " << decolagem << endl;
                cout << "Número de aviões que irão aterrisar: " << aterrissagem << endl;
                cout << "\tPassou " << min << " minutos!\n" << endl;   
                cout << "\n";
                min++;

                for (int i = 0; i < avioesP.size(); i++)
                {
                    if (!avioesP[i].getTipo() && decolagem > 0)
                    {
                        aero->inserir(avioesP[i]);
                        avioesP.erase(avioesP.begin()+i);
                        i--;
                        decolagem--;
                    }
                }

                for (int i = 0; i < avioesI.size(); i++)
                {
                    if (avioesI[i].getTipo() && aterrissagem > 0)
                    {
                        aero->inserir(avioesI[i]);
                        if(avioesI[i].getCombustivel()<=5)
                            cont_emerge++;
                        avioesI.erase(avioesI.begin()+i);
                       
                        i--;
                        aterrissagem--;
                    }
                
                }

                if (cont_emerge == 3)
                {
                    cout << "\nALERTA!!!, 3 AVIÕES EM ESTADO DE EMERGÊNCIA" << endl;
                    cout<<"/n";
                    cont_emerge = 0;
                }
                aero->decrementar();
                aero->remover();
                cout <<"\n"<< min<<" MINUTOS SE PASSARAM, KOWALSKI, RELATÓRIO!\n";
                aero->imprimir();
                aero->media();
            }
            break;
        case 2:
            int resp;

            do
            {
                int aux1, aux2;
                int auxid;
                random_device rd;
                mt19937 mt(rd());
                uniform_int_distribution<int> Numaterrisagemale(0, 3);
                uniform_int_distribution<int> Numdecolagemale(0, 3);

                aux1 = Numaterrisagemale(mt);
                aux2 = Numdecolagemale(mt);
                cout << "Número de aviões que irão decolar: " << aux2 << endl;
                cout << "Número de aviões que irão aterrisar: " << aux1 << endl<< endl;
                min++;
                while (aux1 > 0)
                {
                    uniform_int_distribution<int> NumId(0, 100);
                    auxid = NumId(mt);
                    auxid = auxid * 2 + 1;
                    tipo = true;
                    uniform_int_distribution<int> Numpassageiros(0, 50);
                    uniform_int_distribution<int> NumCombustivel(0, 15);
                    string companhia[4] = {"TAM", "GOL", "LATAM", "AMERICAN AIRLINES"};
                    companhia[numaleatorio()];
                    Viao V(NumCombustivel(mt), companhia[numaleatorio()], auxid, tipo, Numpassageiros(mt));
                    aero->inserir(V);
                    aux1--;
                }

                while (aux2 > 0)
                {
                    uniform_int_distribution<int> NumId(0, 100);
                    auxid = NumId(mt);
                    auxid = auxid * 2;
                    tipo = false;
                    uniform_int_distribution<int> Numpassageiros(0, 50);
                    uniform_int_distribution<int> NumCombustivel(0, 15);
                    string companhia[4] = {"TAM", "GOL", "LATAM", "AMERICAN AIRLINES"};
                    companhia[numaleatorio()];
                    Viao V(NumCombustivel(mt), companhia[numaleatorio()], auxid, tipo, Numpassageiros(mt));
                    aero->inserir(V);
                    aux2--;
                }
                aero->decrementar();
                aero->remover();
                cout <<"\n"<< min<<" MINUTOS SE PASSARAM, KOWASKI, RELATÓRIO!\n";
                aero->imprimir();
                aero->media();
                cout << "Deseja gerar mais um minuto? \n1-Sim \n2-Não" << endl;
                cin >> resp;
            } while (resp == 1);
            break;

        case 0:
            cout << "\nSaindo do programa...\n";
            break;
        }

    } while (resp != 0);

    return 0;
}