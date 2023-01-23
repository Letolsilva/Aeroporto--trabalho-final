#include "Aeroporto.hpp"
Aeroporto::Aeroporto()
{
    pista1 = new Pistas();
    pista2 =new Pistas();
    pista3 = new Pista3();

}

void Aeroporto:: inserir(Viao aviao)
{
    if(aviao.getTipo())
    {
        if(aviao.getEmergencia())
        {
            if(!pista3->verificaemerge())
            {
                cout<<"\n\tAVIAO ATERRISAGEM NA PISTA 3"<<endl;
                pista3->inserir(aviao);
                
                return;
            } 
        }
        if(pista1->size_aterrisagem()<pista2->size_aterrisagem())
        {
            cout<<"\n\tAVIAO ATERRISAGEM NA PISTA 1"<<endl;

            pista1->inserir(aviao);
        }
        else
        {
            cout<<"\n\tAVIAO ATERRISAGEM NA PISTA 2"<<endl;

            pista2->inserir(aviao);
        }
    }
    else
    {
        int menor=pista1->size_decolagem();

        if(menor>pista2->size_decolagem())
        {
            menor=pista2->size_decolagem();
        }
        if(menor>pista3->size())
        {
            menor=pista3->size();
        }


        if(pista1->size_decolagem()==menor)
        {
            cout<<"\n\tAVIAO DECOLAGEM NA PISTA 1"<<endl;
            pista1->inserir_deco(aviao);
        }
        else if(pista2->size_decolagem()==menor)
        {
            cout<<"\n\tAVIAO DECOLAGEM NA PISTA 2"<<endl;
            pista2->inserir_deco(aviao);
        }
        else
        { 
            cout<<"\n\tAVIAO DECOLAGEM NA PISTA 3"<<endl;
            pista3->inserir(aviao);
        }
    }
}

void Aeroporto:: decrementar(){
    pista1->decrementardeco();
    pista1->decrementaate2();
    pista2->decrementardeco();
    pista2->decremnetaate1();
    pista3->decrementar();
    pista1->decremnetaate1();
    pista2->decrementaate2();
}

void Aeroporto :: imprimir()
{
    cout<<"-------------------------------------------------"<<endl;
    cout<<"\tPISTA 1"<<endl;
    pista1->getFila1();
    pista1->getFila2();
    pista1->getFilaD();
    cout<<"\tPISTA 2"<<endl;
    pista2->getFila1();
    pista2->getFila2();
    pista2->getFilaD();
    cout<<"\tPISTA 3"<<endl;
    pista3->getFila3();
    cout <<"Número de aviões com emergências que aterrisaram: "<< pista1->retornanumemergencia()+pista2->retornanumemergencia() << endl;
    cout<<"-------------------------------------------------"<<endl;
}
void Aeroporto:: remover(){
    cout<<"---------------------------------------"<<endl;
    cout<<"\tPISTA 1:"<<endl;
    pista1->remover();
    cout<<"---------------------------------------"<<endl;
    cout<<"\tPISTA 2:"<<endl;
    pista2->remover();
    cout<<"---------------------------------------"<<endl;
    cout<<"\tPISTA 3:"<<endl;
    pista3->remover();
    cout<<"---------------------------------------"<<endl;
}
void Aeroporto::media(){
    cout<<"Média da pista 1 fila 1: "<<pista1->media1()<<endl;
    cout<<"Média da pista 1 fila 2: "<<pista1->media2()<<endl;
    cout<<"Média da pista 1 fila decolagem: "<<pista1->mediadeco()<<endl;
    cout<<"Média da pista 2 fila 1: "<<pista2->media1()<<endl;
    cout<<"Média da pista 2 fila 2: "<<pista2->media2()<<endl;
    cout<<"Média da pista 2 fila decolagem: "<<pista2->mediadeco()<<endl;
    cout<<"Média da pista 3: "<<pista3->mediafila3()<<endl;
    cout<<"Média global aterrisagem: "<<pista1->media1()+pista1->media2()+pista2->media1()+pista2->media2()<<endl;
    cout<<"Média global de decolagem: "<<pista1->mediadeco()+pista2->mediadeco()+pista3->mediafila3()<<endl;
}