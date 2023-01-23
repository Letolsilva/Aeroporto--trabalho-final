#ifndef VIAO_HPP
#define VIAO_HPP
#include <iostream>
#include <string>
#include <time.h>   
using namespace std;

class Viao
{
    private:
        int combustivel;
        string companhia;
        bool emergencia;
        int id;
        int passageiros;
        bool tipo; //false=decolar e true=aterrissar
        int tempo_espera;

    public:
    Viao(int combustivel, string companhia, int id,bool tipo, int passageiros);
    Viao();
    void setId(int id);
    int getId();
    void setCompanhia(string companhia);
    string getCompanhia();
    void setCombustivel(int combustivel);
    int getCombustivel();
    void setEmergencia(bool emergencia);
    void setTempo_espera(int tempo_espera);
    int getTempo_espera();
    bool getEmergencia();
    bool getTipo();
    void numeroaleatorio();
    void combustivelaleatorio();
    void imprimir();
};
#endif