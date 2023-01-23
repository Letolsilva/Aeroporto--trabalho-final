#ifndef PISTAS_HPP
#define PISTAS_HPP
#include <queue>  
#include "Viao.hpp"
using namespace std;

/*struct comparacao
{
    bool operator()(Viao &v1, Viao&v2)
    {
        return v1.getCombustivel()>v2.getCombustivel();
    }
};*/
struct comparacao
{
    bool operator()(Viao &v1, Viao&v2)
    {
        if(v1.getEmergencia()&& !v2.getEmergencia())
            return false;
        else
            return true;
    }
};

class Pistas
{
    private:
    priority_queue <Viao, vector<Viao>, comparacao> fila_aterrisagem1;
    priority_queue <Viao, vector<Viao>, comparacao> fila_aterrisagem2;
    queue <Viao> filadecolagem;
    int minutos, minutos2, qtd, qtd2, numemergencia=0;

    public:
    Pistas();
    void inserir(Viao v);
    void inserir_deco(Viao v);
    int size_aterrisagem();
    int size_decolagem();
    void imprimir1();
    void imprimir2();
    float media1();
    float media2();
    float mediadeco();
    void remover();
    void decrementardeco();
    void decremnetaate1();
    void decrementaate2();
    int emergencia2();
    void getFila1();
    void getFila2();
    void getFilaD();
    void removeraterrisagem();
    int retornanumemergencia();
};
#endif