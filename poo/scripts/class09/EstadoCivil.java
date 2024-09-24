package class09;

public enum EstadoCivil {
	SOLTEIRO(0, "Solteiro"),
	CASADO(1, "Casado"),
	DIVORCIADO(2, "Divorciado"),
	VIUVO(3, "Viúvo");
	
	private int num;
	private String status;
	
	
	private EstadoCivil(int num, String status) {
		this.num = num;
		this.status = status;
	}
	
	public String getStatus() {
		return this.status;
	}
}
