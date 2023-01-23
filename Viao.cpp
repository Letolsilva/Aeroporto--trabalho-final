#include "Viao.hpp"

Viao :: Viao(int combustivel, string companhia, int id, bool tipo, int passageiros)
{
    this->combustivel=combustivel;
    this->companhia=companhia;
    if(tipo)
    {
        if(combustivel<=5)
        {
            emergencia=true;
        }
        else
        {
            emergencia=false;
        }
    }
    else
    {
        emergencia=false;
    }
    this->tipo=tipo;
    this->id=id;
    this->passageiros=passageiros;
    this->tempo_espera=0;
}

Viao :: Viao()
{

}

void Viao :: setCompanhia(string companhia)
{
    this->companhia=companhia;
} 

void Viao :: setEmergencia(bool emergencia)
{
    this->emergencia=emergencia;
}

void Viao :: setCombustivel(int combustivel)
{
    this->combustivel=combustivel;
}

void Viao::setId(int id)
{
    this->id=id;
}

int Viao::getId(){
    return this->id;
}

string Viao :: getCompanhia()
{
    return this->companhia;
}

bool Viao :: getEmergencia()
{
    return this->emergencia;
}

int Viao :: getCombustivel()
{
    return this->combustivel;
}

bool Viao::getTipo()
{
    return this->tipo;
}

int Viao::getTempo_espera()
{
    return this->tempo_espera;
}

void Viao:: setTempo_espera(int tempo_espera)
{
    this->tempo_espera=tempo_espera;
}

void Viao :: numeroaleatorio()
{
    srand(time(NULL));
    if((rand()%100)%2!=0)
        setId(rand()%100);
}

void Viao :: combustivelaleatorio()
{
    srand(time(NULL));
    setCombustivel(1+rand()%60);
}

void Viao::imprimir()
{
    if(!tipo){
        cout<<"Tempo de espera: "<<tempo_espera<<" minutos"<<endl;
        cout<<"Companhia: "<<companhia<<endl;
        cout<<"Emergencia(0 - Avião sem emergência | 1 - Avião com emergência): "<<emergencia<<endl;
        cout<<"Número de passageiros: "<<passageiros<<" passageiros"<<endl;
        cout<<"Tipo(0 - Decolagem | 1 - Aterrisagem): "<<tipo<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"\n";
        
    }
    else{
        cout<<"Combustivel: "<<combustivel<<" litros"<<endl;
        cout<<"Companhia: "<<companhia<<endl;
        cout<<"Emergencia(0 - Avião sem emergência | 1 - Avião com emergência): "<<emergencia<<endl;
        cout<<"Número de passageiros: "<<passageiros<<" passageiros"<<endl;
        cout<<"Tipo(0 - Decolagem | 1 - Aterrisagem): "<<tipo<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"\n";
    }
   
}