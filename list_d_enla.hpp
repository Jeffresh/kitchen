#ifndef LISTA_D_ENLA_HPP
#define LISTA_D_ENLA_HPP

#include<cassert>

template<typename T>
class Lista
{
	struct nodo ;
public:

	typedef nodo* posicion;

	Lista();
	Lista(const Lista<T>& L);
	Lista<T>& operator =(const Lista<T>& L);

	posicion siguiente(posicion p)const;
	posicion anterior(posicion p)const;
	posicion primera()const;
	posicion fin()const;
	posicion buscar(const T& x);

	const T& elemento(posicion p)const;
	T& elemento(posicion p);
	void insertar(const T& x, posicion p);
	void eliminar(posicion x);

	~Lista();

private:

	struct nodo
	{
		T elto;
		nodo *ant, *sig;

		nodo(const T& x, nodo* a = 0, nodo* s = 0) :
		elto{x},
		ant{a},
		sig{s}{}
	};

	nodo* L;

	void copiar(const Lista<T>& L);
};

template<typename T>
void Lista<T>::copiar(const Lista<T>& l)
{
	nodo* p = (l.L)->sig;
	L= new nodo(T());

	L->ant = L->sig = L;

	while(p!=l.L)
	{
		L->ant=L->ant->sig = new nodo(p->elto,L->ant,L);
		p= p->sig;
	}		
}
	
template<typename T>
Lista<T>::Lista():
L{new nodo(T())}
{L->ant=L->sig=L;}

template<typename T>
inline Lista<T>::Lista(const Lista<T>& l)
{
	copiar(l);
}

template<typename T>
inline  Lista<T>& Lista<T>::operator =(const Lista<T>& l)
{
	if(this!= &l)
	{
		this->~Lista();
		copiar(l);
	}

	return *this;
}





template<typename T>
inline typename Lista<T>::posicion Lista<T>::primera()const
{
	return L;
}

template<typename T>
inline typename Lista<T>::posicion Lista<T>::fin()const
{
	return L->ant;
}

template<typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(typename Lista<T>::posicion p)const
{
	return p->sig;
}


template<typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(typename Lista<T>::posicion p)const
{
	return p->ant;
}

template<typename T>
typename Lista<T>::posicion Lista<T>::buscar(const T& x)
{

	nodo* p = L; // nos saltamos la cabecera? no

	while(p->sig!=L && (p->sig)->elto!=x)
		p = p->sig;


	return p;
}




template<typename T>
void Lista<T>::insertar(const T& x, typename Lista<T>::posicion p)
{
	p->sig = p->sig->ant= new nodo(x,p,p->sig);
}




template<typename T>
void Lista<T>::eliminar(typename Lista<T>::posicion p)
{

	assert(p->sig!=L); // no borrar la cabecera

	nodo *q = p->sig;

	p->sig = q->sig;
	q->sig->ant = p;

	delete q;
}


template<typename T>
inline const T& Lista<T>::elemento(typename Lista<T>::posicion p)const
{
	assert(p->sig != L);
	return p->sig->elto;
}

template<typename T>
inline T& Lista<T>::elemento(typename Lista<T>::posicion p)
{
	assert(p->sig != L);
	return p->sig->elto;
}


template<typename T>
Lista<T>::~Lista()
{
	nodo* q;

	while(L->sig != L)
	{
		q= L->sig;
		L->sig = q->sig;
		delete q;
	}

	delete L;

}

#endif // LISTA_DOBLE_H

