#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"

template <typename T>
class ListArray : public List<T> {
	private:
		T *arr; // Puntero al inicio del array que almacenará los elementos de la lista 
		int max; // Tamaño máximo de la lista
		int size; // Tamño actual de la lista
		static const int MINSIZE = 2; // Tamaño mínimo de la lista
	
	public:
		// Constructor 
		ListArray() {
			arr = nullptr;
			max = MINSIZE;
			size = 0;
		}

		// Destructor
		~ListArray() {
			delete[] arr;
		}

		

};

#endif 
