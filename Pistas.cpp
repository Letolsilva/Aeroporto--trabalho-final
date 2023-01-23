#include "Pistas.hpp"

Pistas:: Pistas()
{
    this->minutos=0;
    this->minutos2=0;
    this->qtd=0;
    this->qtd2=0;

}

void Pistas::inserir(Viao v)
{   
    v.imprimir();
        if(fila_aterrisagem1.size()<fila_aterrisagem2.size())
        {
            cout<<"\n\tO Avião com ID " << v.getId()<< " entrou na fila de espera 1\n"<<endl;
            fila_aterrisagem1.push(v);
        } 
        else
        {
            cout<<"\n\tO Avião com ID " << v.getId()<< " entrou na fila de espera 2\n"<<endl;
            fila_aterrisagem2.push(v);
        }

}

void Pistas::inserir_deco(Viao v)
{
    cout<<"\n\tO Avião com ID " << v.getId()<< " entrou na fila de decolagem\n"<<endl;
    v.imprimir();
    filadecolagem.push(v);
}   

int Pistas::size_aterrisagem()
{
    return fila_aterrisagem1.size()+fila_aterrisagem2.size();
}

int Pistas::size_decolagem()
{
    return filadecolagem.size();
}

void Pistas:: imprimir1()
{
    priority_queue<Viao, vector<Viao>, comparacao> aux = fila_aterrisagem1;
    cout<<"\nImprimindo a fila de aterrisagem 1...\n"<<endl;
    while(!aux.empty())
    {
        Viao auxiliar = aux.top();
        auxiliar.imprimir();
        aux.pop();
    }
}

void Pistas:: imprimir2()
{
    priority_queue<Viao, vector<Viao>, comparacao> aux = fila_aterrisagem2;
     cout<<"\nImprimindo a fila de aterrisagem 2...\n"<<endl;
    while(!aux.empty())
    {
        Viao auxiliar=aux.top();
        auxiliar.imprimir();
        aux.pop();
    }
}

float Pistas:: media1()
{
    priority_queue<Viao, vector<Viao>, comparacao> aux = fila_aterrisagem1;
    float media=0;
    if(qtd!=0)
        media=minutos/qtd;
    return media;
}

float Pistas:: media2()
{
    priority_queue<Viao, vector<Viao>, comparacao> aux = fila_aterrisagem2;
    float media=0;
    if(qtd2!=0)
        media=minutos2/qtd2;
    return media;
}

float Pistas:: mediadeco()
{
    queue <Viao> aux = filadecolagem;
    float media=0;
    while(!aux.empty())
    {
        Viao auxiliar=aux.front();
        media+=auxiliar.getTempo_espera();
        aux.pop();
    }
    media=media/filadecolagem.size();
    if(filadecolagem.size()==0)
        media=0;
    return media;
}

void Pistas:: remover()
{
   
    if(!fila_aterrisagem1.empty() || !fila_aterrisagem2.empty() || !filadecolagem.empty())
    {
        Viao aux;
        Viao aux2;
        Viao aux3;
        if(!fila_aterrisagem1.empty())
            aux=fila_aterrisagem1.top();

        if(!fila_aterrisagem2.empty())
            aux2=fila_aterrisagem2.top();

        if(!filadecolagem.empty())
            aux3=filadecolagem.front();

        if(aux.getEmergencia()==true || aux2.getEmergencia()==true)
        {
            if(aux.getEmergencia()==true && aux2.getEmergencia()==true)
            {
                if(aux.getCombustivel()<aux2.getCombustivel())
                {
                    cout<<"\n\tO aviao "<<aux.getId()<<" aterrissou na fila 1 em  estado de emergencia\n"<<endl;
                    aux.imprimir();
                    minutos+= aux.getTempo_espera();
                    qtd++;
                    numemergencia++;
                    fila_aterrisagem1.pop();
                    return;
                }
                else if(!fila_aterrisagem2.empty())
                {
                    cout<<"\n\tO aviao "<<aux2.getId()<<" aterrissou na fila 2 em estado de emergencia\n"<<endl;
                    aux2.imprimir();
                    minutos2+=aux2.getTempo_espera();
                    qtd2++;
                    numemergencia++;
                    fila_aterrisagem2.pop();
                    return;
                }
            }
            else
            {
                if(aux.getEmergencia()==true)
                {
                    cout<<"\n\tApenas o aviao "<<aux.getId()<<" estava em emergência, e ele aterrissou na fila 1\n"<<endl;
                    aux.imprimir();
                    minutos+= aux.getTempo_espera();
                    qtd++;
                    numemergencia++;
                    fila_aterrisagem1.pop();
                    return;
                }
                else if(!fila_aterrisagem2.empty())
                {
                    cout<<"\n\tApenas o aviao "<<aux2.getId()<<" estava em emergência, e ele aterrissou na fila 2\n"<<endl;
                    aux2.imprimir();
                    minutos2+=aux2.getTempo_espera();
                    qtd2++;
                    numemergencia++;
                    fila_aterrisagem2.pop();
                    return;
                }
            }
        }
        int maior= aux.getTempo_espera();
        int ate= aux2.getTempo_espera();
        int ate2= aux3.getTempo_espera();

        if(maior<ate)
            maior=ate;

        if(maior<ate2)
            maior=ate2;
        
        if(maior==ate && !fila_aterrisagem1.empty())
        {
            cout<<"\n\tNenhum avião em estado de emergência"<<endl;
            cout<<"\n\tO aviao "<<aux.getId()<<" aterrissou na fila 1 \n"<<endl;
            aux.imprimir();
            minutos+= aux.getTempo_espera();
            qtd++;
            fila_aterrisagem1.pop();
            
        }
        else if(maior==ate2 && !fila_aterrisagem2.empty())
        {
            cout<<"\n\tNenhum avião em estado de emergência"<<endl;
            cout<<"\n\tO aviao "<<aux2.getId()<<" aterrissou na fila 2 \n"<<endl;
            aux2.imprimir();
            minutos2+=aux2.getTempo_espera();
            qtd2++;
            fila_aterrisagem2.pop();
        }
        else if(!filadecolagem.empty())
        {
            cout<<"\n\tO aviao "<<aux3.getId()<<" decolou na pista 1 ou na pista 2\n"<<endl;
            aux3.imprimir();
            filadecolagem.pop();
        }
    }
}

void Pistas :: decrementardeco()
{
    queue<Viao> aux = filadecolagem;
    queue<Viao> aux2;
    
    while(!aux.empty())
    {
        Viao auxuliar = aux.front();
        auxuliar.setCombustivel(auxuliar.getCombustivel()-1);
        auxuliar.setTempo_espera(auxuliar.getTempo_espera()+1);
        aux2.push(auxuliar);
        aux.pop();
    }
    filadecolagem=aux2;
}

void Pistas:: decremnetaate1()
{
    priority_queue <Viao, vector<Viao>, comparacao> aux=fila_aterrisagem1;
    priority_queue <Viao, vector<Viao>, comparacao> aux2;
    while(!aux.empty())
    {
        Viao auxuliar = aux.top();
        auxuliar.setCombustivel(auxuliar.getCombustivel()-1);
        auxuliar.setTempo_espera(auxuliar.getTempo_espera()+1);
        if(auxuliar.getCombustivel()<=5)
            auxuliar.setEmergencia(true);
      
        aux2.push(auxuliar);
        aux.pop();
    }
    fila_aterrisagem1=aux2;
}

void Pistas:: decrementaate2()
{
    priority_queue <Viao, vector<Viao>, comparacao> aux=fila_aterrisagem2;
    priority_queue <Viao, vector<Viao>, comparacao> aux2;
    while(!aux.empty())
    {
        Viao auxuliar = aux.top();
        auxuliar.setCombustivel(auxuliar.getCombustivel()-1);
        auxuliar.setTempo_espera(auxuliar.getTempo_espera()+1);
        if(auxuliar.getCombustivel()<=5)
            auxuliar.setEmergencia(true);
      
        aux2.push(auxuliar);
        aux.pop();
    }
    fila_aterrisagem2=aux2;
}

void Pistas :: getFila1()
{
    priority_queue <Viao, vector<Viao>, comparacao> aux=fila_aterrisagem1;
    cout << "\n\nImprimindo aviões que estão na Fila 1:\n" << endl;
    while(!aux.empty())
    {
        Viao auxiliar =aux.top();
        cout<<"ID : "<<auxiliar.getId()<<endl;
        cout<<"Combustivel: "<<auxiliar.getCombustivel()<<" litros"<<endl;
        cout<<"\n";
        aux.pop();
    }
    if(aux.empty())
        cout << "A fila 1 está vazia\n"<<endl;
}

void Pistas :: getFila2()
{
    priority_queue <Viao, vector<Viao>, comparacao> aux2=fila_aterrisagem2;
    cout << "\n\nImprimindo aviões que estão na Fila 2:\n" << endl;
    while(!aux2.empty())
    {
        Viao auxiliar =aux2.top();
        cout<<"ID : "<<auxiliar.getId()<<endl;
        cout<<"Combustivel: "<<auxiliar.getCombustivel()<<" litros"<<endl;
        cout<<"\n";
        aux2.pop();
    }
    if(aux2.empty())
        cout << "A fila 2 está vazia\n"<<endl;
}

void Pistas :: getFilaD()
{
    queue <Viao> aux2=filadecolagem;
    cout << "\n\nImprimindo aviões que estão na Fila de Decolagem:\n" << endl;
    while(!aux2.empty())
    {
        Viao auxiliar =aux2.front();
        cout<<"ID : "<<auxiliar.getId()<<endl;
        cout<<"Tempo de espera: "<<auxiliar.getTempo_espera()<<" minutos"<<endl;
        cout<<"\n";
        aux2.pop();
    }
    if(aux2.empty())
        cout << "A fila de decolagem está vazia\n"<<endl;
}

int Pistas :: retornanumemergencia()
{
    return numemergencia;
}
