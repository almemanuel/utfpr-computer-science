package class06;

public class Carro {
    String modelo;
    String marca;
    int ano;
    String placa;
    String cor;
    boolean estaLigado;
    int velocidade;

    public Carro(String modelo, String marca, int ano, String placa, String cor) {
        this.modelo = modelo;
        this.marca = marca;
        this.ano = ano;
        this.placa = placa;
        this.cor = cor;
        this.estaLigado = false;
        this.velocidade = 0;
    }


    public void ligar(){
        if(!(this.estaLigado)) {
            this.estaLigado = true;
        }
    }


    public void desligar() {
        if(this.estaLigado){
            this.estaLigado = false;
        }
    }


    public void acelerar() {
        if(this.velocidade <= 140) {
            this.velocidade += 10;
    }


    public void frear() {
        if(this.velocidade > 10) {
            this.velocidade -= 10;
        }
    }
}