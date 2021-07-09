#include <iostream>
using namespace std;

class Persona {};
class Cliente : public Persona {
private:
	string fecha_registro;
	string codigo;

public:
	Cliente() {}
	~Cliente() {}
	//Setters
	void setFecha(string fecha) {
		this->fecha_registro = fecha;
	}
	void setCodigo(string codigo) {
		this->codigo = codigo;
	}
	//Getters 
	string getFecha() {
		return this->fecha_registro;
	}
	string getCodigo() {
		return this->codigo;
	}

	void generarCodigo() {
		this->codigo = "Cliente-" + this->getCodigo();
	}
};
