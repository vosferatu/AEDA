#include <iostream>
#include <vector>

using namespace std;

/**
 * Versão da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);

// excecao  NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

//-----------------------------------------------------------------------------------
//a partir daqui funções que fiz
//-----------------------------------------------------------------------------------

template <class N>
class ArestaRepetida {
public:
	N destiny;
	N start;
	ArestaRepetida(N dest, N inicio) {
		destiny = dest;
		start = inicio;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<N> &ar)
{ out << "Aresta repetida: " << ar.start << " , " << ar.destiny; return out; }

template <class N>
class ArestaInexistente {
public:
	N begin;
	N end;
	ArestaInexistente(N ini, N fim) {
		begin = ini;
		end = fim;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaInexistente<N> &ai)
{ out << "Aresta inexistente: " << ai.begin << " , " << ai.end; return out; }

template <class N, class A>
Grafo<N,A>::Grafo(){
	nos = {};
}

template <class N, class A>
Grafo<N,A>::~Grafo() {}

template <class N, class A>
int Grafo<N,A>::numNos(void) const{
	return nos.size();
}

template <class N, class A>
int Grafo<N,A>::numArestas(void) const{
	unsigned int numarestas = 0;

	for (size_t i = 0; i < nos.size(); i++)
	{
		numarestas += nos[i]->arestas.size();
	}
	return numarestas;
}

template <class N, class A>
Grafo<N,A> & Grafo<N,A>::inserirNo(const N &dados){

	No<N,A>* novo = new No<N,A>(dados);

	NoRepetido<N> error_except(dados);

	for (size_t i = 0; i < nos.size(); i++)
	{
		if (nos[i]->info == dados)
			throw error_except;
	}
	nos.push_back(novo);
	return *this;
}

template <class N, class A>
Grafo<N,A> & Grafo<N,A>::inserirAresta(const N &inicio, const N &fim, const A &val)
{
	bool found = false;

	size_t j = 0;

	for (size_t i = 0; i < nos.size(); i++)
	{
		if (nos[i]->info == fim)
			{
			j = i;
			break;
			}
	}

	Aresta<N,A> nova = Aresta<N,A>(nos[j],val);

	for (size_t i = 0; i < nos.size(); i++)
	{
		if (nos[i]->info == inicio)
		{
			for (size_t k = 0; k < nos[i]->arestas.size(); k++)
				{
					if(nos[i]->arestas[k].destino->info == fim)
						{
							throw ArestaRepetida<N>(fim, inicio);
							break;
						}
				}
			nos[i]->arestas.push_back(nova);
			found = true;
		}
	}

	if (found == false)
		throw NoInexistente<N>(inicio);

	return *this;
}

template<class N, class A>
A & Grafo<N,A>::valorAresta(const N &inicio, const N &fim){

	bool foundNo = false;

	for (size_t i = 0; i < nos.size(); i++)
		{
			if (nos[i]->info == inicio)
			{
				for (size_t k = 0; k < nos[i]->arestas.size(); k++)
					{
						if(nos[i]->arestas[k].destino->info == fim)
							{
								return nos[i]->arestas[k].valor;
							}
					}
				foundNo = true;
			}
		}

	if (!foundNo)
		throw NoInexistente<N>(inicio);

	throw ArestaInexistente<N>(inicio,fim);
}

template<class N, class A>
Grafo<N,A> & Grafo<N,A>::eliminarAresta(const N &inicio, const N &fim){

	bool foundNo = false;

	for (size_t i = 0; i < nos.size(); i++)
		{
			if (nos[i]->info == inicio)
			{
				for (size_t k = 0; k < nos[i]->arestas.size(); k++)
					{
						if(nos[i]->arestas[k].destino->info == fim)
							{
								nos[i]->arestas.erase(nos[i]->arestas.begin() + k);
								return *this;
							}
					}
				foundNo = true;
			}
		}

	if (!foundNo)
		throw NoInexistente<N>(inicio);

	throw ArestaInexistente<N>(inicio, fim);
}

template<class N, class A>
void Grafo<N,A>::imprimir(std::ostream &os) const{

	for (size_t i = 0; i < nos.size(); i++)
		{
		os << "( " << nos[i]->info;
			for (size_t k = 0; k < nos[i]->arestas.size(); k++)
				{
					os << "[ " << nos[i]->arestas[k].destino->info << " ";
					os << nos[i]->arestas[k].valor << "] ";
				}
		os << ") ";
		}
}

template <class N, class A>
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g){
	g.imprimir(out);
	return out;
}
