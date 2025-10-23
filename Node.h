#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
	public: 
		T data; // Elemento almacenado de tipo T (cualquier tipo)
		Node<T> *next; // Puntero al siguiente nodo de la secuencia 
			       // Si no fuera puntero, habría un bucle infinito de Nodes
			       // Tengo una referencia a un objeto de la misma clase
	public:
		//Constructor
		Node(T data, Node<T> *next = nullptr) {
			this->data = data;
			this->next = next;
		}
		
		// Imprimo el data de ese nodo
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
			out << node->data;
			return out;
		}
	
};

#endif 
