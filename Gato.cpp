#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//# Funciones
void tabla(string , string );
void jugadores();
void juego();
void identificarJugador(int);
int revisar();
bool soloNumeros();
void registro(string);
void consolaCambio(int);
//# Variables Globales
char posiciones[] = {'1','2','3','4','5','6','7','8','9'};
string jug1,jug2,jugador,nombreArchivo;
int cJugador = 1,revision;
//# Autor: Osmin Medrano Varela.
int main(int argc, char const *argv[])
{	
	system("mode con: cols=53 lines=19");
	jugadores();
	juego();
	system("PAUSE");
	return 0;
}

void tabla(string n1,string n2)
{
	system("CLS");
	cout << "\n\tBienvenido al juego \"Gato\"\n\n";
	cout << "\t"<<n1<<" = \"X\"\t"<<n2<<" = \"O\"\n";
	cout << "\t   "<<posiciones[0]<<"   |   "<<posiciones[1]<<"   |   "<<posiciones[2]<<"\n";
	cout << "\t-------|-------|-------\n";
	cout << "\t   "<<posiciones[3]<<"   |   "<<posiciones[4]<<"   |   "<<posiciones[5]<<"\n";
	cout << "\t-------|-------|-------\n";
	cout << "\t   "<<posiciones[6]<<"   |   "<<posiciones[7]<<"   |   "<<posiciones[8]<<"\n";
}

void jugadores()
{	
	cout << "\n\tBienvenido al juego \"Gato\"\n\n";
	cout << "\tNombre del Jugador 1: ";
	getline(cin,jug1);
	cout << "\tNombre del Jugador 2: ";
	getline(cin,jug2);
}

void juego()
{
	int soloNumeros;
	char tipo;
	string opc;
	//# Inicio del Juego
	do
	{
		tabla(jug1,jug2);

		cJugador = ( cJugador % 2)? 1 : 2;
		consolaCambio(cJugador);
		identificarJugador(cJugador);
		cout << "Ingrese numero segun la casilla\n";
		cout << "Turno de [ "<<jugador<<" ]: ";
		cin >> opc;
		soloNumeros = atoi(opc.c_str());
		tipo = (cJugador == 1 )? 'X' : 'O';
		  	if (soloNumeros == 1 && posiciones[0] == '1')
		  	{
	            posiciones[0] = tipo;
		  	}else if (soloNumeros == 2 && posiciones[1] == '2')
		  		{
		  			posiciones[1] = tipo;
		  		}else if (soloNumeros == 3 && posiciones[2] == '3')
		  			{
		  				posiciones[2] = tipo;
		  			}else if (soloNumeros == 4 && posiciones[3] == '4')
		  				{
		  					posiciones[3] = tipo;
		  				}else if (soloNumeros == 5 && posiciones[4] == '5')
		  					{
		  						posiciones[4] = tipo;
		  					}else if (soloNumeros == 6 && posiciones[5] == '6')
		  						{
		  							posiciones[5] = tipo;
		  						}else if (soloNumeros == 7 && posiciones[6] == '7')
		  							{
		  								posiciones[6] = tipo;
		  							}else if (soloNumeros == 8 && posiciones[7] == '8')
		  								{
		  									posiciones[7] = tipo;
		  								}else if (soloNumeros == 9 && posiciones[8] == '9')
		  									{
		  										posiciones[8] = tipo;
		  									}else
									        {
									            cout<<"Opcion no disponible\nIngresar nuevamente\n";
									            cJugador--;
									            cin.ignore();
									            cin.get();
									        }									        
		revision=revisar();
		cJugador++;
	}while(revision==0);
	//# Fin del Juego
	cJugador--;
	identificarJugador(cJugador);
	tabla(jug1,jug2);
	if(revision == 1)
	{
		system("color 6f");
		cout << "El jugador ["<<jugador<<"] ha Ganado!\n";		
		registro(jugador);		
	}else
	{
		system("color 4f");
		cout << "Empate entre ["<<jug1<<"] y ["<<jug2<<"]\n";
		registro(jugador);		
	}
	cout << "\n\tJuego realizado por Osmin Medrano Varela\n\n";
}

void identificarJugador(int identificar)
{
	if(identificar == 1)
	{
		jugador = jug1;
	}else
	{
		jugador = jug2;
	}
}

int revisar()
{	
	//# Lineas Horizontales
	if (posiciones[0] == posiciones[1] && posiciones[1] == posiciones[2]){return 1;}	 
    else if (posiciones[3] == posiciones[4] && posiciones[4] == posiciones[5]){return 1;}
    else if (posiciones[6] == posiciones[7] && posiciones[7] == posiciones[8]){return 1;}
    //# Lineas Verticales
    else if (posiciones[0] == posiciones[3] && posiciones[3] == posiciones[6]){return 1;}
    else if (posiciones[1] == posiciones[4] && posiciones[4] == posiciones[7]){return 1;}
    else if (posiciones[2] == posiciones[5] && posiciones[5] == posiciones[8]){return 1;}
    //# Diagonales
    else if (posiciones[0] == posiciones[4] && posiciones[4] == posiciones[8]){return 1;}
    else if (posiciones[2] == posiciones[4] && posiciones[4] == posiciones[6]){return 1;}
    //# Completa
    else if (posiciones[0] != '1' && posiciones[1] != '2' && posiciones[2] != '3' 
            && posiciones[3] != '4' && posiciones[4] != '5' && posiciones[5] != '6' 
            && posiciones[6] != '7' && posiciones[7] != '8' && posiciones[8] != '9'){return 2;}
    else{
        return 0;
    }
}

void registro(string regJug1)
{
	ofstream archivo;		
	nombreArchivo = "Registro_Gato.txt";

	archivo.open(nombreArchivo.c_str(), ios::out|ios::app); 

	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}

    if(revision == 1){
	    if(regJug1 == jug1)
	    {
	    	archivo << "El jugador ["<<jugador<<"[X]] ha Ganado!\n";
	    }else if(regJug1 == jug2)
	    {
	    	archivo << "El jugador ["<<jugador<<"[O]] ha Ganado!\n";
	    }
	}else    
    {
    	archivo << "Empate entre ["<<jug1<<"] y ["<<jug2<<"]\n";
    }
	archivo.close();
}

void consolaCambio(int colores)
{
	if(colores == 1)
	{
		system("color 3f");
	}else
	{
		system("color 2f");
	}	
}
