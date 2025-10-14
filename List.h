#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
	public:
		// Solo se define los métodos (virtual) 
		// Estos serán implementados en las clases derivadas a esta

		// Inserta un elemento en la posición deseada
		virtual void insert(int pos, T e) = 0;

		// Inserta un elemento al final de la lista
		virtual void append(T e) = 0;

		// Inserta un elemeno al principio de la lista
		virtual void prepend(T e) = 0;

		// Elimina y devuelve el elemento de la posición deseada
		virtual T remove(int pos) = 0;

		// Devuelve el elemento situado en la posición pos
		virtual T get(int pos) = 0;

		// Busca un elemento, devuelve la posición o -1 si no lo encuentra
		virtual int search(T e) = 0;

		// Devuelve el tamaño de la lista
		virtual void size() = 0;
};

#endif

