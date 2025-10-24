#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T> *first; // Puntero al primero de la lista
		int sz; // Tamaño de la lista
	
	public:
		// Constructor
		ListLinked() { 
			first = nullptr; // No hay un primero al que apuntar
			sz = 0;
		}

		// Destructor
		~ListLinked() {
			 while(first != nullptr) {
        			Node<T> *aux = first;
        			first = first->next;
        			delete aux;	
    				}
		}

		// Utilización del []
		T operator[](int pos) {
			// Gestionar las posiciones
			if(pos < 0 || pos > sz-1) throw std::out_of_range("Posición inválida");
			// Creo un puntero que apunte a la misma dirección que first
			Node<T> *aux = first;
			// Bucle hasta llegar a la posición deseada
			for (int i = 0; i < pos; i++) {
				aux = aux->next; // Actualizamos aux para que sea el siguiente
			}
			
			return aux->data;
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
			out << "[";
			// Creo un auxiliar
			Node<T> *aux = list.first;
			// Creo un bucle que vaya pasando por todos los datos de la lista
			while(aux != nullptr) {
				out << aux->data;
				if(aux->next != nullptr) {
					out << ", ";
				}
				aux = aux->next;
			}
			out << "]";
			return out;
		}

		// Métodos heredados
		
		void insert(int pos, T e) override {
			// Manejo de posiciones
                        if(pos < 0 || pos > sz-1) throw std::out_of_range("Posición inválida");
			// Si lo quiero colocar primero
			if(pos == 0) {
				first = new Node<T>(e,first);
			} else {
				// Creo un auxiliar que apunte donde el primero
				Node<T> *aux = first;
				// Lo llevo a la posición
				for(int i = 0; i < pos-1; i++) {
					aux = aux->next;
				}
				// Aux->next apuntará al nuevo nodo que
				// apunta a su vez a donde marcaba antes aux->next
				aux->next = new Node<T>(e,aux->next);
				// Aumento el tamaño
				sz++;
			}
		}

		void append(T e) override {
			return insert(sz,e);
		}

		void prepend(T e) override {
			return insert(0,e);
		}

		T remove(int pos) override {
			// Manejo de posiciones
			if(pos < 0 || pos > sz-1) throw std::out_of_range("Posición inválida");
			// Creo dos auxiliares para hacer un bypass
			Node<T> *prev = nullptr;
			Node<T> *aux = first;
			// Variable en la que se guarda el dato
			T d;
			// Primera posición excepción
			if(pos == 0) {
				first = first->next;
				d = aux->data;
			} else {
				// Llego hasta la posición
				for(int i = 0; i < pos-1; i++) {
					prev = aux;
					aux = aux->next;	
				}
				// Hago el bypass
				prev->next = aux->next;
				// Guardo la variable
				d = aux->data;
			}
			//Libero memoria
			delete aux;
			// Actualizo sz
			sz--;
			return d;

		}

		T get(int pos) override {
			Node<T> *aux = first;
			return aux[pos];
		}

		int search(T e) override {
			// Creo un auxiliar
			Node<T> *aux = first;
			int pos = 0;
			// Bucle para encontrar el elemento
			while(aux != nullptr) {
				if( e == aux->data) return pos; // Se encontró con el elemento
				aux = aux->next;
				pos++;
			}
			// No se encontró el elemento
			return -1;
		}

		bool empty() override {
			return (sz==0);
		}

		int getSize() override {
			return sz;
		}
};
