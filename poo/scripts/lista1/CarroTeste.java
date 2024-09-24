package lista1;

public class CarroTeste {
	public static void main(String[] args) {
		Carro carro1 = new Carro();
		carro1.modelo = "Mustang";
		carro1.marca = "Ford";
		carro1.cor = "Vermelho";
		carro1.ano = 1979;
		carro1.renavam = 123;
		carro1.chassi = "ABC";
		carro1.placa = "XYZ-7890";
				
		Carro carro2 = new Carro();
		carro2.modelo = "Opala";
		carro2.marca = "Chevrolet";
		carro2.cor = "Azul";
		carro2.ano = 1965;
		carro2.renavam = 123;
		carro2.chassi = "ABC";
		carro2.placa = "XYZ-7890";
		
		Carro carro3 = new Carro();
		carro3.modelo = "Fusca";
		carro3.marca = "Volks Wagen";
		carro3.cor = "Azul";
		carro3.ano = 1982;
		carro3.renavam = 123;
		carro3.chassi = "ABC";
		carro3.placa = "XYZ-7890";

		System.out.println("====================");
		System.out.println(carro1.modelo);
		System.out.println(carro1.marca);
		System.out.println(carro1.cor);
		System.out.println(carro1.ano);
		System.out.println(carro1.renavam);
		System.out.println(carro1.chassi);
		System.out.println(carro1.placa);
		
		System.out.println("====================");
		System.out.println(carro2.modelo);
		System.out.println(carro2.marca);
		System.out.println(carro2.cor);
		System.out.println(carro2.ano);
		System.out.println(carro2.renavam);
		System.out.println(carro2.chassi);
		System.out.println(carro2.placa);
		
		System.out.println("====================");
		System.out.println(carro3.modelo);
		System.out.println(carro3.marca);
		System.out.println(carro3.cor);
		System.out.println(carro3.ano);
		System.out.println(carro3.renavam);
		System.out.println(carro3.chassi);
		System.out.println(carro3.placa);
	}
}
