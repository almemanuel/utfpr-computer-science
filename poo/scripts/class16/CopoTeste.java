package class16;

import java.util.Random;

public class CopoTeste {
	public static void main(String[] args) {
		int n = 24;
		Copo[] engradado = new Copo[n];
		
		for(int i = 0, tamanho = engradado.length; i < tamanho; i++) {
			Copo copo = new Copo(i);
			copo.setCapacidadeMaxima(300);
			copo.setCapacidadeAtual(new Random().nextInt(copo.getCapacidadeMaxima()));
			copo.setCor("Transparente");
			copo.setMaterial("Plástico");
			engradado[i] = copo;
		}
		
		for(int i = 0, tamanho = engradado.length; i < tamanho; i++) {
			System.out.println(engradado[i]);
		}
	}
}
