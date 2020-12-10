#include <iostream>
using namespace std;
template <class T> class Lista{
    private:
        template <class G> class Celula{
            public:
            Celula<G> *Prox;
            T Valor;
            Celula(const G &v)
            {
                this->Valor=v;
                Prox = nullptr;
            }
        };
        int Tamanho;
        Celula<T> *Fim;
        Celula<T> *Inicio;
    public: 
        Lista()
        {
            Inicio = Fim = nullptr;
            Tamanho = 0;
        }
        ~Lista()
        {
            Celula<T> *x;
            while(Inicio!=nullptr){
                x = Inicio;
                Inicio = Inicio->Prox;
                delete x;
            }
        }
        bool Inserir_No_Fim(const T &Valor)
        {
            if(Fim == nullptr)
            {
                Inicio = Fim = new Celula<T>(Valor);
                Tamanho++;
            }else
                {
                this->Fim->Prox = new Celula<T>(Valor);
                this->Fim = Fim->Prox;
                Tamanho++;
            }
            return 1;
        }
        bool Inserir_No_Inicio(const T &Valor)
        {
            if(Inicio == nullptr)
            {
                Inicio = Fim = new Celula<T>(Valor);
                Tamanho++;
            }else
                {
                Celula<T> *x = new Celula<T>(Valor);
                x->Prox = Inicio;
                Tamanho++;
                Inicio = x;
            }
            return true;
        }
        bool Inserir_No_Meio(const T &item, const int &posicao)
        {
            Celula<T> *nValor, *x;
            x = this->Inicio;
            for(int i = 0; i < posicao-1; i++)
            {
                x = x->Prox;
            }
            nValor =new Celula<T>(item);
            nValor->Prox = x->Prox;
            x->Prox = nValor;
            this->Tamanho++;
            return true;
        }
        bool pop(){
        if(this->Inicio == nullptr)
        { 
            return false; 
        }else
            { 
            if(this->Inicio->Prox == nullptr)
            { 
                delete this->Inicio; 
                this->Inicio = this->Fim = nullptr; 
            } else
                { 
                Celula<T> *x=this->Inicio, *x1; 
                while(x->Prox->Prox!= nullptr)
                {  
                    x=x->Prox; 
                }
                x1 = x;
                delete Fim;
                this->Fim = x1;
                x->Prox = nullptr;
            } 
            this->Tamanho--; 
            return true; 
        }
        }
        bool Remover_Do_Inicio(){
            if(this->Inicio==nullptr)
            {
                return false;
            }else
                {
                Celula<T> *x;
                x = this->Inicio;
                this->Inicio = this->Inicio->Prox;
                delete x;
                Tamanho--;
                return true;
            }
            
        }
        bool Remover_Do_Meio(int const &pos)
            {
            if(pos<=Tamanho)
            {
                Celula<T> *x = this->Inicio, *proc;
                for(int i = 0; i < pos-1; i++)
                {
                    x = x->Prox;
                    cout<<x->Prox<<endl;
                }
                proc = x->Prox;
                x->Prox = x->Prox->Prox; 
                if(x->Prox == nullptr)
                {
                    this->Fim = x;
                    delete proc;
                    this->Tamanho--;  
                }
                return true;
            }else
                {
                return false;
            }
        }        
        void Mostrar()
        {
            Celula<T> *x = this->Inicio;
            cout<<"[ ";
            while(x != nullptr)
            {
                cout<<x->Valor<<" ";
                x=x->Prox;
            }
            cout<<"]"<<endl;
        }
        T Mostrar_No_Meio(int const &pos)
        {
            if(pos<=Tamanho && pos >= 0)
            {
                Celula<T> *x;
                x = this->Inicio;
                for(int i = 0; i < pos; i++)
                {
                    x=x->Prox;
                }
                return x->Valor;
            }else{
                cout<<"Essa posição não existe na lista"<<endl;
                return 0;
            }
            
        }
        int Retornar_Tamanho()
        {
            return Tamanho;
        }
};


int main(){
    Lista<int> L;
    for(int i = 0; i<20; i++){
        L.Inserir_No_Fim(i);
    }
    cout<<L.Retornar_tamanho()<<endl;
    L.Mostrar();
    L.Remover_Do_Meio(3);
    L.Remover_Do_Inicio();
    L.Mostrar_No_Meio(19);
    cout<<L.Retornar_Tamanho()<<endl;
    L.Mostrar();
    return 0;
}