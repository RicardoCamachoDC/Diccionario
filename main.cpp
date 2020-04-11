/* Ejercicio 4. Implementar un 'Diccionario'. 
El diccionario debe contener palabras en castellano y una lista de posibles significados
de cada palabra.

Notas:
- Implementar una clase dicionario, con métodos de inserción y búsqueda.
- Para palabras y significados use la clase string. */

//Autor: Ricardo Camacho Diaz-Cano

//Librerias.
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

/*Se define un contenedor que contendrá al diccionario y es una variable global para 
acceder a ella en todo momento: */
map<string, string> dicionario;

//Estructuras.
/*Se define una clase diccionario donde se define la palabra y el significado. */
class Diccionario{
	private: // Atributos.
		string palabra;
		string significado;
	public: //Metodos.
		Diccionario (string, string); //Constructor 1.
		Diccionario (string); //Constructor 2
		void insertarPalabra();
		void buscarPalabra();
};

//Constructor para insertar la palabra.
Diccionario::Diccionario(string _palabra, string _significado){
	palabra=_palabra;
	significado=_significado;
}

//Constructor para buscar la palabra.
Diccionario::Diccionario(string _palabra){
	palabra=_palabra;
}

//InsertarPalabra añaden la palabra y su significado en el contenedor.
 void Diccionario::insertarPalabra(){
 	dicionario.insert(make_pair(palabra, significado));
 	
 	return;
 }
 
 /*buscarPalabra busca la palabra en el contenedor y representa su significado
 en el caso de no encontrarla devuelve un mensaje por pantalla. */
 void Diccionario::buscarPalabra(){
 	map<string, string>::iterator it=dicionario.begin();
 	bool encontrado=false;
 	
 	while(it!=dicionario.end() && encontrado==false){
 		if (it->first == palabra){
 			cout << it->first << " : " << it->second << endl;
 			encontrado=true;
		}
		it++;
	 }
	 
	 if (encontrado==false){
	 	cout << "La palabra no se encuentra en el diccionario. " << endl;
	 }
	 
	 return;
 }
 
 //Cabeceras de las funciones.
 void menuDiccionario();
 string cadenaMayusculas(string );
 
 //Main.
int main() {
	menuDiccionario();
	
	return 0;
}

//Rutinas.
/*Se crea una funcion para el menu del diccionario, donde por cada operacion se 
limpia la pantalla para mayor claridad y se limpia el buffer cada vez que se pide
datos para evitar posibles problemas. */
void menuDiccionario(){
	int opc;
	string palabra, significado;
	
	do{
		system("cls");
		cout << "\t-. Menu Diccionario .-" << endl;
		cout << "Opciones:" << endl;
		cout << "1. Introducir una palabra. " << endl;
		cout << "2. Buscar una palabra. " << endl;
		cout << "3. Salir. " << endl;
		cout << "Que desea hacer? "; cin >> opc;
		
		switch(opc){
			case 1:{
					system("cls");
					fflush(stdin);
					cout << "Introduce la palabra: "; getline(cin, palabra);
					palabra=cadenaMayusculas(palabra);
					fflush(stdin);
					cout << "Introduce su significado: "; getline(cin, significado);
					Diccionario concepto (palabra, significado);
					concepto.insertarPalabra();
				
					cout << "\n\n";
					system("pause");
				}
				break;
				
			case 2:{
					system("cls");
					fflush(stdin);
					cout << "Introduce la palabra: "; getline(cin, palabra);
					palabra=cadenaMayusculas(palabra);
					Diccionario concepto (palabra);
					concepto.buscarPalabra();
		
					cout << "\n\n";
					system("pause");
				}	
				break;
			case 3:{
					system("cls");
					cout << "Gracias. ";
				
					cout << "\n\n";
				}
				break;
			default:{
					cout << "Introduzca una opcion valida: ";
					cout << "\n\n";
					system("pause");
				}
				break;
		}
	}while(opc!=3);
}

/*Se crea una funcion para pasar la palabra a mayusculas, debido a que cuando
se busca perro y Perro, el significado es el mismo, pero son palabras distintas
para evitar esto palabra siempre estará en mayusculas y al utilizar string y no 
cadenas de caracteres no se puede aplicar la funcion strupr. */
string cadenaMayusculas(string palabra){
	for (int i=0; i<palabra.length(); i++){
		palabra[i]=toupper(palabra[i]);
	}
	return palabra;
}


/*OBSERVACIONES: al igual que en el ejercicio 2, al estructurar el ejercicio,
las cabeceras y las rutinas en diferentes codigos fuentes, el mismo codigo aparece 
error en la linea 25 de makefile ($(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)), pero al 
juntarlo todo en el main.cpp funciona perfectamenete. */
