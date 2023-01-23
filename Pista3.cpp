#include "Pista3.hpp"

Pista3:: Pista3()
{

}

void Pista3::inserir(Viao v)
{
    cout<<"\n\tO Avião " << v.getId()<< " entrou na pista 3 \n"<<endl;
    v.imprimir();
    fila3priori.push(v);
}

int Pista3::size()
{
    
    return fila3priori.size();
}

void:: Pista3::decrementar(){
    priority_queue<Viao, vector<Viao>, prioridade >aux=fila3priori;
    priority_queue<Viao, vector<Viao>, prioridade >aux2;
    while(!aux.empty())
    {
        Viao auxiliar=aux.top();
        auxiliar.setCombustivel(auxiliar.getCombustivel()-1);
        auxiliar.setTempo_espera(auxiliar.getTempo_espera()+1);
        aux2.push(auxiliar);
        aux.pop();
    }
    fila3priori=aux2;
}

void Pista3:: imprimir()
{
    priority_queue<Viao, vector<Viao>, prioridade >aux=fila3priori;
    while(!aux.empty())
    {
        Viao auxiliar=aux.top();
        auxiliar.imprimir();
        aux.pop();
    }
}

float Pista3 :: mediafila3()
{
    priority_queue<Viao, vector<Viao>, prioridade > aux = fila3priori;
    float media=0;
    while(!aux.empty())
    {
        Viao auxiliar=aux.top();
        media+=auxiliar.getTempo_espera();
        aux.pop();
    }
    media=media/fila3priori.size();
    if(fila3priori.size()==0)
        media=0;
    return media;
}

void Pista3 :: remover()
{
    
    if(!fila3priori.empty()){
        Viao aux;
        aux=fila3priori.top();
        cout<<"\n\tO Avião " << aux.getId()<< " pousou na pista 3 \n"<<endl;
        fila3priori.pop();
    }
    
}

int Pista3 :: emergencia()
{
    int cont=0;
    priority_queue<Viao, vector<Viao>, prioridade > aux = fila3priori;
    Viao auxuliar=aux.top();
    while(!aux.empty())
    {
        if(auxuliar.getEmergencia()==true)
            cont++;
        aux.pop();
        if(cont==3)
            cout << "\nALERTA!!!, 3 AVIÕES EM ESTADO DE EMERGÊNCIA" << endl;
    }
    return cont;
}

bool Pista3:: verificaemerge()
{
    if(fila3priori.empty())
        return false;
    Viao auxiliar=fila3priori.top();
    if(auxiliar.getEmergencia())
        return true;
    else 
        return false;
}

void Pista3 :: getFila3()
{
    priority_queue <Viao, vector<Viao>, prioridade> aux=fila3priori;
    cout << "\n\nImprimindo aviões que estão na Fila 3: \n" << endl;
    while(!aux.empty())
    {
        Viao auxiliar =aux.top();
        cout<<"O id : "<<auxiliar.getId()<<endl;
        cout<<"Tempo de espera: "<<auxiliar.getTempo_espera()<<endl;
        cout<<"\n";
        aux.pop();
    }
    if(aux.empty())
        cout<<"A fila 3 está vazia"<<endl;
        cout<<"\n";
}