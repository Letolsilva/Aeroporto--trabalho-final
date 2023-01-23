#ifndef PISTA3_HPP
#define PISTA3_HPP
#include <queue>  
#include "Viao.hpp"
using namespace std;

struct prioridade
{
    bool operator()(Viao &v1, Viao&v2)
    {
    if(v1.getEmergencia()&& !v2.getEmergencia())
        return false;
    else
        return true;
    }
};

class Pista3
{
    private:
    priority_queue<Viao, vector<Viao>, prioridade >fila3priori;
    
    public:
    Pista3();
    void inserir(Viao v);
    void decrementar();
    int size();
    void imprimir();
    float mediafila3();
    void remover();
    int emergencia();
    bool verificaemerge();
    void getFila3();
  

};
#endif
