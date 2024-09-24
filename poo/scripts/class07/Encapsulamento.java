// técnica de esconder a estrutura de um objeto atrás de um conjunto de operações sobre ele, sendo acessível somente por meio destas operações

// modificadores de acesso
// Default (sem declaração)
//      atributos e metodos acessiveis de todos os metodos de todas as classes do mesmo pacote
// public
//      atributos e métodos são sempre acessíveis em todos os métodos de todas as classes
//      nível menos rígido de encapsulamento
//      identificado por + no UML
// protected
//      atributos e métodos são acessíveis nos métodos da própria classe e suas subclasses e dentro do mesmo pacote
//      identificados por #
// private
//      atributos e métodos são acessíveis somente nos métodos da própria classe
//      nível mais rígido de encapsulamento
//      identificado por -

// os atributos de um objeto só podem ser acessados por métodos da mesma classe através dos métodos Getters e Setters

package class07;

public class ContaBancaria {
    int numero;
    String titular;
    double saldo;

    public ContaBancaria(int numero, String titular) {
        this.numero = numero;
        this.titular = titular;
        this.saldo = 0.00;
    }

    public void depositar(double valor) {
        this.saldo += valor;
    }

    // get - utilizado para obter um valor
    public int getNumero() {
        return numero;
    }

    public String getTitular() {
        return titular;
    }

    // set - utilizado para atribuir um valor
    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setTitular(String titular) {
        this.titular = titular;
    }
}