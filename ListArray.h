#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
	private:
		T *arr; // Puntero al inicio del array que almacenará los elementos de la lista 
		int max; // Tamaño máximo de la lista
		int size; // Tamaño actual de la lista
		static const int MINSIZE = 2; // Tamaño mínimo de la lista
	
	public:
		// Constructor 
		ListArray() {
			arr = new T[MINSIZE];
			max = MINSIZE;
			size = 0;
		}

		// Destructor
		~ListArray() {
			delete[] arr;
		}

		virtual T operator[](int pos) {
			// Si la posición está fuera de rango lanzo una excepción
			if (pos < 0 || pos > size-1) {
				throw std::out_of_range("Índice fuera de rango");
			}
			return arr[pos];
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
			// ostream representa un flujo de salida (output stream)
			// Actúa como unn intermediario que formatea y envia datos 
			// Es como un cout
			// Recibe datos con << 
			out << "[";
			for(int i = 0; i < list.size(); i++) {
				out << list[i];
				if ( i < list.size()-1) {
					out << ", ";
				}
			}
			out << "]";
			return out; // Como si devolvería un string
		}

	private:
		void resize(int new_size) {
			// Creo un nuevo array dinámico con el nuevo tamaño
			T *aux = new T[new_size];
			// Copio los elementos del viejo array al nuevo
			for(int i = 0; i < size; i++) {
				aux[i] = arr[i];
			}
			//Libero los recursos de memoria
			delete[] arr;
			// Actualizo max
			max = new_size;
			// Actualizo arr para que apunte a la dirección de memoria 
			// en la que se encuentra el nuevo array
			arr = aux;
		}
	public:	
		// Funciones de list
		// override significa que se está sobrescribiendo una función virtual
		void insert(int pos, T e) override {
			// Lanzo una excepción si la posición no es válida
			if(pos < 0 || pos > size) {
				throw std::out_of_range("Posición no valida");
			}

			// Creo un array auxiliar del mismo máximo que arr
			T* aux = new T[max];

			// Si al meter e en auxiliar el tamaño va a superar
			// al máximo, hacemos el auxiliar más grande
			if(size + 1 > max) {
				aux.resize(max+1);
				max++;
			}

			// Copio en aux los numeros que van antes de la posición
			// en donde quiero meter e
			for(int i = 0; i < pos; i++) {
				aux[i] = arr[i];
			}

			// Coloco el elemento e
			aux[pos] = e;

			// Coloco el resto de elementos en aux
			for(int j = pos; j < size; j++) {
				aux[pos+1] = arr[j];	
			}
			
			// Elimino arr para liberar memoria 
			delete[] arr;

			// Actualizo arr para que apunte a la misma
			// dirección de memoria que aux
			arr = aux;

			// Aumento size
			size++;	
		}

		void append(T e) override {
			insert(size,e);
		}

		void preppend(T e) override {
			insert(0,e);
		}

		T remove(int pos) override {
			// Creo un auxiliar
			T *aux = new T[size];
			// Le copio todos los elementos antes y despues 
			// del elemento (sin incluirlo)
			for(int i = 0; i < pos; i++) {
				aux[i] = arr[i];
			}

			for(int j = pos+1; j < size; j++) {
				aux[j-1] = arr[j];
			}	

			// Elimino arr para liberar memoria
			delete[] arr;

			// Actualizo arr para que apunte a la dirección 
			// que apunta aux
			arr = aux;

			// Actualizo size
			size--;
		}
};

#endif 
