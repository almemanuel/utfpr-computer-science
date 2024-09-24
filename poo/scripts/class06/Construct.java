// inicializa o objeto
// executado no momento da instanciação do objeto
// deve possuir o mesmo nome da classe
// não possui retorno definido
// define ou permite que o objeto receba dados na instanciação

// this é um ponteiro de auto referência ao próprio objeto
// isto diferencia atributos de variáveis locais
// com this é possível passar o próprio objeto como argumento na chamada de um método construtor, invocar o método construtor da própria classe dentro de outra, etc

// sobrecarga de método consiste em criar o mesmo método com possibilidade de entradas diferentes
// isso acaba trazendo algumas repetições ao código, porém este problema pode ser reduzido fazendo um construtor invocar outro via this()

package class06;

public class Construct {
    String nome;
    int idade;

    public Construct() {
        this("João da Silva", 30);
    }

    public Construct(String nome) {
        this(nome, 30);
    }

    public Construct(int idade) {
        this("João da Silva", idade);
    }

    public Construct(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }
}