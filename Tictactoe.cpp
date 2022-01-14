#include <iostream>
#include <ctime>
#include <random>
using namespace std;

char tablero[9] = {' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' };
void mostrar_tablero();
void conseguir_eleccion_jugador_X();
void conseguir_eleccion_jugador_O();
void conseguir_eleccion_computadora();
int contar_tablero(char simbolo);
char revisar_ganador();
void computadora_vs_jugador();
void jugador_vs_jugador();

int main()
{
    //Seleccion de modos del juego
    int modo;
    cout << "1. Computadora vs Jugador" << "\n" << "2. Player 1 vs PLayer 2 \n";
    cout << "Seleccione modo de juego: " << endl;

    cin >> modo;

    switch(modo)
    {
        case 1:
        computadora_vs_jugador();
        break;

        case 2: 
        jugador_vs_jugador();
        break;

        default:
        cout << "Porfavor seleccione un modo de juego: " << endl;
        break;

    }
    return 0;
}

void computadora_vs_jugador()
{
    string nombre_jugador;
    cout << "Ingrese su nombre: "; cin >> nombre_jugador;
    while(true)
    {
        system("cls");
        mostrar_tablero();
        if(contar_tablero('X') == contar_tablero('O'))
        {
            cout << "Turno de "<< nombre_jugador << endl;
            conseguir_eleccion_jugador_X();
        }
        else // Si no es una eleccion del usuario, entonces conseguira una opcion de la computadora
        {
            conseguir_eleccion_computadora();
        }
        
        char ganador = revisar_ganador();
        if(ganador == 'X')
        {
            system("cls");
            mostrar_tablero();
            cout << nombre_jugador << " Gano el juego. " << endl;
            break;
        }
        else if (ganador == 'O')
        {
            system("cls");
            mostrar_tablero();
            cout << "La Computadora gano el juego. " << endl;
            break;
        }
        else if (ganador == 'D')
        {
            cout << "El juego termino en un empate. " << endl;
            break;
        }
    }
}

void conseguir_eleccion_computadora()
{
    srand(time(0)); //Guarda el random, asegura que cada vez sea un numero completamente arbitrario
    int eleccion;
    do //Loop para que la computadora haga su eleccion en un cuadro que yo no este previamente lleno
    {
        eleccion = rand () % 10;
    } while (tablero[eleccion] != ' ');
    tablero[eleccion] = 'O';
}

void conseguir_eleccion_jugador_X()
{
    while(true)
    {
        cout << "Seleccione su posicion (1 - 9): ";
        int eleccion;
        cin >> eleccion;
        eleccion--;// "--" porque si el usuario quiere marcar la posicion 9, el programa la ve realmente como la 8 como empieza desde posicion 0 en vez de posicion 1.
        if(eleccion < 0 || eleccion > 8)
        {
            cout << "Porfavor seleccione su eleccion desde (1 - 9). " << endl;
        }
        else if(tablero[eleccion] != ' ')
        {
            cout << "Porfavor eliga una posicion vacia. " << endl;
        }
        else
        {
            tablero[eleccion] = 'X';
            break;
        }
    }
}

void conseguir_eleccion_jugador_O()
{
    while(true)
    {
        cout << "Seleccione su posicion (1 - 9): ";
        int eleccion;
        cin >> eleccion;
        eleccion--;// "--" porque si el usuario quiere marcar la posicion 9, el programa la ve realmente como la 8 como empieza desde posicion 0 en vez de posicion 1.
        if(eleccion < 0 || eleccion > 8)
        {
            cout << "Porfavor seleccione su eleccion desde (1 - 9). " << endl;
        }
        else if(tablero[eleccion] != ' ')
        {
            cout << "Porfavor eliga una posicion vacia. " << endl;
        }
        else
        {
            tablero[eleccion] = 'O';
            break;
        }
    }
}

void jugador_vs_jugador()
{
    string player1x, player2o;
    cout << "Ingrese el nombre del jugador 1 (X): ";
    cin >> player1x;

    cout << "Ingrese el nombre del jugador 2 (O): ";
    cin >> player2o;

    while(true)
    {
        system("cls");
        mostrar_tablero();

        //si simbolo que se ingresa de ambos jugadores es igual es el turno de player 1 (X) sino es de player 2 (O)
        if(contar_tablero('X') == contar_tablero('O'))
        {
            cout << "Turno de: " << player1x << endl;
            conseguir_eleccion_jugador_X();
        }
        else
        {
            cout << "Turno de: " << player2o << endl;
            conseguir_eleccion_jugador_O();
        }
        char ganador = revisar_ganador();

        if(ganador == 'X')
        {
            system("cls");
            mostrar_tablero();
            cout << player1x << " ha ganado"<< endl;
            break;
        }
        else if (ganador == 'O')
        {
            system("cls");
            mostrar_tablero();
            cout << player2o << " ha ganado"<< endl;
            break;
        }
        else if (ganador == 'D')
        {
            cout << "Empate" << endl;
            break;

        }
    }

}

int contar_tablero(char simbolo) //Verificara el simbolo que se ingrese y contara cuantas veces aparece ese simbolo en el tablero
{
    int total = 0;
    for(int i = 0; i < 9; i++)
    {
        if(tablero[i] == simbolo)
        {
            total += 1;
        }
    }
    return total;
}

char revisar_ganador() //Verificara el ganador del juego
{
    //Verificando ganador, horizontal/fila
    if(tablero[0] == tablero[1] && tablero[1] == tablero[2] && tablero[0] != ' ')
    {
        return tablero[0];
    }
    if(tablero[3] == tablero[4] && tablero[4] == tablero[5] && tablero[3] != ' ')
    {
        return tablero[3];
    }
    if(tablero[6] == tablero[7] && tablero[7] == tablero[8] && tablero[6] != ' ')
    {
        return tablero[6];
    }
    
    //Verificando ganador, vertical/columna
    if(tablero[0] == tablero[3] && tablero[3] == tablero[6] && tablero[0] != ' ')
    {
        return tablero[0];
    }
    if(tablero[1] == tablero[4] && tablero[4] == tablero[7] && tablero[1] != ' ')
    {
        return tablero[1];
    }
    if(tablero[2] == tablero[5] && tablero[5] == tablero[8] && tablero[2] != ' ')
    {
        return tablero[2];
    }
    
    //Verificando ganador, diagonal
    if(tablero[0] == tablero[4] && tablero[4] == tablero[8] && tablero[0] != ' ')
    {
        return tablero[0];
    }
    if(tablero[2] == tablero[4] && tablero[4] == tablero[6] && tablero[2] != ' ')
    {
        return tablero[2];
    }
    
    if(contar_tablero('X') + contar_tablero('O') < 9)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}

void mostrar_tablero() //Funcion para mostrar el tablero
{
    // Imprime la 1ra fila, "|" para division horizontal, "-" para division vertical
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << tablero[0] << "   |   " << tablero[1] << "   |   " << tablero[2] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << " ---------------------" << endl;
    
    //Imprime la 2da fila
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << tablero[3] << "   |   " << tablero[4] << "   |   " << tablero[5] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << " ---------------------" << endl;
    
    //Imprime la 3ra fila, division vertical no es necesaria
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << tablero[6] << "   |   " << tablero[7] << "   |   " << tablero[8] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
}