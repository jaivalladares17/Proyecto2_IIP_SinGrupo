#include <iostream>
using namespace std;

class Persona {};
class Medico : public Persona {
private:
	string fecha_ingreso;
	string codigo;

public:
	Medico() {}
	~Medico() {}
	//Setters
	void setFecha(string fecha) {
		this->fecha_ingreso = fecha;
	}
	void setCodigo(string codigo) {
		this->codigo = codigo;
	}
	//Getters
	string getFecha() {
		return this->fecha_ingreso;
	}
	string getCodigo() {
		return this->codigo;
	}

	void generarCodigo() {
		this->codigo = "Medico-" + this->getCodigo();
	}
};
