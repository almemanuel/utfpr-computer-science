package lista1;

public class PessoaTeste {
	public static void main(String[] args) {
		Pessoa pessoa1 = new Pessoa();
		pessoa1.nome = "João";
		pessoa1.sexo = "M";
		pessoa1.cpf = 1234567890;
		pessoa1.idade = 21;
		pessoa1.altura = 1.8;
		pessoa1.peso = 75;
		
		Pessoa pessoa2 = new Pessoa();
		pessoa2.nome = "Pedro";
		pessoa2.sexo = "M";
		pessoa2.cpf = 1234567890;
		pessoa2.idade = 21;
		pessoa2.altura = 1.8;
		pessoa2.peso = 75;

		Pessoa pessoa3 = new Pessoa();
		pessoa3.nome = "Maria";
		pessoa3.sexo = "F";
		pessoa3.cpf = 1234567890;
		pessoa3.idade = 21;
		pessoa3.altura = 1.8;
		pessoa3.peso = 75;

		System.out.println(pessoa1.nome);
		System.out.println(pessoa1.sexo);
		System.out.println(pessoa1.cpf);
		System.out.println(pessoa1.idade);
		System.out.println(pessoa1.altura);
		System.out.println(pessoa1.peso);
		System.out.println("====================");
	
		System.out.println(pessoa2.nome);
		System.out.println(pessoa2.sexo);
		System.out.println(pessoa2.cpf);
		System.out.println(pessoa2.idade);
		System.out.println(pessoa2.altura);
		System.out.println(pessoa2.peso);
		System.out.println("====================");
		
		System.out.println(pessoa3.nome);
		System.out.println(pessoa3.sexo);
		System.out.println(pessoa3.cpf);
		System.out.println(pessoa3.idade);
		System.out.println(pessoa3.altura);
		System.out.println(pessoa3.peso);
		System.out.println("====================");
	}
}
