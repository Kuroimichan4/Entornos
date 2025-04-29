//static es que solo se puede acceder dentro de la clase y no de forma externa

#include <iostream> //  Permite el uso de funciones como cout y cin para imprimir en consola y recibir entrada del usuario.
#include <cstdlib>  // Para rand() (generar números aleatorios) y srand() (semilla para la generación de números aleatorios)
#include <ctime>    // Para time(), que devuelve el tiempo actual en segundos. Se usa como semilla para que los números aleatorios de rand()

using namespace std; //si no quieres escribir std:: cada vez que uses un elemento de la biblioteca estándar se debe de poner esto 
//si no se deberia poner a cada momento std::cout o std::string

struct personaje { //Esto representará tanto al heroe como al enemigo. Los valores de cada uno pueden ser diferenrtes ya que se determinan en el main
    int vida; 
    int hit;
}; // Un struct es una manera de agrupar varios datos relacionados bajo un solo nombre. Cada elemento dentro del struct se llama miembro

void intro() {
    cout << "Eres el Heroe de esta tierra y el enemigo ha venido a destruirte\n";
    cout << "Tendras que luchar con el\n";
    cout << "Elige sabiamente tus ataques\n";
}
// El "&" si tenemos int ataque se puede poner: int& ataque o int &ataque
int heroAttack(personaje &hero, personaje &enemy) { // al ponerle & delante de la variable se pasa el "parametro por referencia" y se modifica la variable original
    // hit la ponemos sin & porque no nos interesa cambiar la variable original ya que en cada ronda tendrá un valor (esto se llama parametro por valor) 
    //ademas en vez de VOID pongo INT heroAttack  porque ahora sí que nos tiene que devolver un valor

    cout << "Elige tu ataque\n";
    cout << "1 - Patada\n";
    cout << "2 - Mandoble (Ataque poderoso pero facil de esquivar)\n";

    int ataque;
    cin >> ataque;
    

    if (ataque == 1) { 
        double random = (rand() % 20 + 1);  //con el % limito el rango del numero aleatorio en este caso del 0 al 9 por eso le sumo el +1 para que sea hasta el 10
        hero.hit = random;
        if (hero.hit < 5) {
            hero.hit = 10; //daño mínmo
        }   
    }
    else if (ataque == 2) {
        double random = (rand() % 30 + 1);  
        hero.hit = random;
        if (hero.hit < 15) {
            hero.hit = 15;
        }
        else if (hero.hit > 25) { //aquí pongo una variable dado que determina si el ataque poderoso acierta o no
            double dado = (rand() % 10 + 1);  
            int dice = (int)dado;
            if (dice >= 6) {
                hero.hit = 0;
            }
        } 
    }
    else {
        hero.hit = 0;
        cout << "No elegiste bien tu ataque, te tropiezas y pierdes un turno\n";
    }
    enemy.vida -= hero.hit; // modifico la vida del enemigo
    return hero.hit;  // Devuelvo el valor de hit
}

int enemyAttack( personaje &hero, personaje &enemy) { //Turno Enemigo (paso parametros)

    double random = (rand() % 40 + 1);  
    enemy.hit = random;
    if (enemy.hit < 10) {
        enemy.hit = 10;
    }
    
    if (enemy.hit > 25) { //aquí tambien pongo una variable dado que determina si el ataque acierta o no
        double dado = (rand() % 10 + 1);  
        int dice = (int)dado;
        if (dice >= 4) {
            enemy.hit = 0;
        } 
    }
    
    hero.vida -= enemy.hit; // modifico la vida del heroe
    return enemy.hit;  // Devuelvo el valor de hitV
}

void status(personaje hero, personaje enemy, int &rondas) { //El estado de la batalla

    cout << "\n";
    cout << "---------- Ronda " << rondas++ << " ----------\n";
    cout << "* Heroe *\n";
    cout << "VIT Hero: " << hero.vida << "\n";
    cout << "Le hiciste un ataque de " << hero.hit << "\n"; //puedo poner un if de si hace daño 0 que salge el enemigo esquivó el ataque****
    if (enemy.hit == 0) {
        cout << "Esquivaste el ataque!!!\n";
    }
    else if (hero.hit >= 25) {
        cout << "Golpe critico del Heroe!!!\n";
    }
    cout << "*****************************\n";
    cout << "* Villano *\n";
    cout << "VIT Enemy: " << enemy.vida << "\n";
    cout << "Te hizo un ataque de " << enemy.hit << "\n";
    if (hero.hit == 0) {
        cout << "El enemigo esquivo el ataque\n";
    }
    else if (enemy.hit >= 25) {
        cout << "Golpe critico del Enemigo!!!\n";
    }
    cout << "*****************************\n";
    cout << "\n";
}

int main() { 

    srand(time(NULL));  // Al usar srand() junto con time(NULL), le das al generador de números aleatorios una semilla basada en la hora actual del sistema
    // time(NULL)  Es una función que devuelve el tiempo actual en segundos concretamente
    // srand() establece la semilla en el generador de números aleatorios "rand()"
    // También podría hacer esto para tener un mínimo y un máximo en el rand(). En c++ se puede establecer un min y un max 
    //  int min = 25; // Límite inferior
    //  int max = 75; // Límite superior
    //  int random = min + rand() % (max - min + 1); esto es así porque rand genera 0, le sumamos el min EJ: 5, pero eso afecta al max, así que se le tiene que restar el min
    // Es decir, si el max es 10 y el min es 5, si no le restamos despues el min a max, max acabaría siendo 15


    personaje hero = { 100, 0 }; // el primer int indica la vida y el segundo su ataque (variables locales)
    personaje enemy = { 100, 0 };
    //int heroV = 100; es lo mismo ahora que hero.vida; como tenía anteriormente
    int rondas = 1;

    intro();

    while (hero.vida > 0 && enemy.vida > 0) {

        heroAttack(hero, enemy);  
        enemyAttack(hero, enemy);
        status(hero, enemy, rondas);

        if (hero.vida <= 0 && enemy.vida <= 0) { //este se podría quitar si estructiramos la vida del hero y enemigo despues de cada uno de sus turnos******
            cout << "Has caido en combate derrotando al enemigo, pero tu gesta sera recordada por la eternidad\n"; 
            break;
        }
        else if (enemy.vida <= 0) {  //esto podría ir justo después del ataque del heroe************
            cout << "Ganaste!! La humanidad se ha salvado y te rendiran homenaje por la eternidad\n";
            break;
        }
        else if (hero.vida <= 0) { // y este después del atque enemigo********************
            cout << "Perdiste y condenaste a la humanidad\n"; //
            break;
        }
    }
}


//C++11 o versiones más recientes, puedes utilizar la biblioteca <random> que ofrece una mejor manera de generar números aleatorios de manera más segura y flexible.
//Con <random>, puedes utilizar generadores de números aleatorios más avanzados, como std::mt19937 (un generador de números pseudoaleatorios de Mersenne Twister), y obtener un rango 
// específico de números de manera más directa.
