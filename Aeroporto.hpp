#ifndef AEROPORTO_HPP
#define AEROPORTO_HPP
#include <iostream>
#include <string> 
#include "Pistas.hpp"
#include "Pista3.hpp" 
using namespace std;

class Aeroporto
{
    private:
     Pistas* pista1;
     Pistas* pista2;
     Pista3* pista3;
     
     public:
     Aeroporto();
     void inserir(Viao aviao);
     void decrementar();
     void imprimir();
     void remover();
     void media();
};
#endif

