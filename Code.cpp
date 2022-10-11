#include <iostream>
using namespace std;

class Nodo {
	int dato;
	Nodo* sig;
public:
	Nodo(int dato)
	{
		this->dato = dato;
		sig = NULL;
	}
	int getDato()
	{
		return dato;
	}
	void setDato(int dato)
	{
		this->dato = dato;
	}
	Nodo* getsig()
	{
		return this->sig;
	}
	void setsig(Nodo* sig)
	{
		this->sig = sig;
	}
};

class Lista {
	Nodo* ini;
public:
	Lista()
	{
		this->ini = NULL;
	}
	Nodo* getini()
	{
		return this->ini;
	}
	void Insertar(int dato)
	{
		Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            ini = temp;
        }
        else
        {
            Nodo* recorrido = this->ini;
            this->ini = temp;
            this->ini->setsig(recorrido);
        }
	}
	void Imprimir()
	{
		Nodo* recorrido = ini;
		cout << "Lista:" << endl;
		while (recorrido != NULL)
		{
			cout << recorrido->getDato() << endl;
			recorrido = recorrido->getsig();
		}
		cout << endl;
		cout << endl;
	}

	int Eliminar()
	{
		if (EstaVacia())
		{
			cout << "No hay elemento a eliminar" << endl;
		}
		else
		{
			ini = ini->getsig();
		}

	}

	void Vaciar()
	{
		ini = NULL;
	}
	bool EstaVacia()
	{
		if (ini == NULL)
			return true;
		else
			return false;
	}
};

class Pila
{
	Lista elementos;
public:
	Pila()
	{
		elementos = Lista();
		int indice = 0;
	}
	bool PilaVacia()
	{
		if (elementos.getini() == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Insertar(int elemento)
	{
		elementos.Insertar(elemento);
	}

	int Quitar()
	{
		if (PilaVacia())
		{
			return NULL;
		}
		else
		{
			elementos.Eliminar();
		}
	}

	void Imprimir()
	{
		elementos.Imprimir();
	}

	void Vaciar()
	{
		elementos.Vaciar();
	}
};


int main()
{
	Pila pila = Pila();

	pila.Insertar(1);
	pila.Insertar(2);
	pila.Insertar(3);
	pila.Insertar(4);
	pila.Insertar(5);
	pila.Insertar(6);
	pila.Imprimir();

	pila.Quitar();
	pila.Imprimir();
	pila.Quitar();
	pila.Imprimir();
}
