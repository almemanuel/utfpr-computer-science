#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Escreva um numero de entrada: ";
    cin >> n;

    cout << "valor lido: " << n << " incremento: " << n+1 << endl;

}

class Ponto {
public:
    float x;
    float y;

    Ponto() {}
    Ponto(float i, float j) {x=i; y=j;}
    ~Ponto(){}
};

class Quadrado {
    Ponto inicio;
    Ponto fim;

public:
    Quadrado(Ponto i, Ponto f){
        inicio = Ponto(i.x, i.y);
        fim = Ponto(f.x, f.y);
    }

    Quadrado(Ponto i, float altura, float largura):
        inicio(i.x, i.y), fim(i.x+largura, i.y+altura) {}

    void desenha(){}
    void desenha(int cor) {}
};

