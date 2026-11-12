#include <iostream>

using namespace std;

class Display {
    private:
        string tipo;
    public:
        Display(string);
        string getTipo();
};

Display :: Display(string t) {
    tipo = t;
};

string Display :: getTipo() {
    return tipo;
};

class Hora {
    private:
        int hora;
        int minutos;
        int segundos;
    public:
        Hora(int, int, int);
        int getHora();
        int getMinutos();
        int getSegundos();
};

Hora :: Hora(int h, int min, int s) {
    hora = h;
    minutos = min;
    segundos = s;
};

int Hora :: getHora(){
    return hora;
};

int Hora :: getMinutos(){
    return minutos;
};

int Hora :: getSegundos(){
    return segundos;
};

class Reloj {
    private:
        Display* pDisplay;
        Hora* pHora;
    public:
        Reloj(int, int, int);
        void asignarDisplay(Display*);
        void mostrarReloj();
};

Reloj :: Reloj(int h, int min, int s) {
    pHora = new Hora(h, min, s);
};

void Reloj :: asignarDisplay(Display *pD) {
    pDisplay = pD;
};

void Reloj :: mostrarReloj() {
    if (pDisplay->getTipo() == "digital"){
        cout << "[" << pHora->getHora() << ":" << pHora->getMinutos() << ":" << pHora->getSegundos() << "]" << endl;
    }
    else if(pDisplay->getTipo() == "analogico"){
        cout << "-->" << pHora->getHora() << ":" << pHora->getMinutos() << ":" << pHora->getSegundos() << "<--" << endl;
    }
};

int main() {
    Display dig("digital");
    Display log("analogico");
    
    Reloj reloj1(10, 15, 55);
    reloj1.asignarDisplay(&dig);
    reloj1.mostrarReloj();
    
    Reloj reloj2(10, 15, 55);
    reloj2.asignarDisplay(&log);
    reloj2.mostrarReloj();
    
    return 0;
}