#include <iostream>
//Importaciones de las clases
#include "Persona.cpp"
#include "Animal.cpp"

#include "Cliente.cpp"
#include "Medico.cpp"
#include "Paciente.cpp"
#include "Visita.cpp"
#include "Factura.cpp"
#include "Medicamento.cpp"
//--------------------------------
using namespace std;

Persona* personas[50]; // Arreglo que almacenara tanto medicos como clientes
Paciente* pacientes[25];
Visita* visitas[25];
Factura* facturas[25];
Medicamento* medicamentos[25];

int indicePersonas;
int indicePacientes;
int indiceVisitas;
int indiceFacturas;
int indiceMedicamentos;

void imprimirMenu();

void agregarPersona(string);//Ingresa clientes y medicos POLIFORMISMO
void agregarPacientes();
void agregarVisita();
void agregarFactura();
void agregarMedicamento();
void imprimirPersonas(string);
void imprimirPacientes();
void imprimirVisitas();
void imprimirFacturas();
void imprimirMedicamentos();

int main() {
	indicePersonas = 0;
	indicePacientes = 0;
	indiceVisitas = 0;
	indiceFacturas = 0;
	indiceMedicamentos = 0;
	int opc;
	do {
		imprimirMenu();
		cout << "Ingrese una opcion: ";
		cin >> opc;
		switch (opc) {
		case 1:
			agregarPersona("Cliente");
			break;
		case 2:
			agregarPersona("Medico");
			break;
		case 3:
			agregarPacientes();
			break;
		case 4:
			imprimirPersonas("Cliente");
			break;
		case 5:
			imprimirPersonas("Medico");
			break;
		case 6:
			imprimirPacientes();
			break;
		case 7:
			agregarVisita();
			break;
		case 8:
			agregarFactura();
			break;
		case 9:
			agregarMedicamento();
			break;
		case 10:
			imprimirVisitas();
			break;
		case 11:
			imprimirFacturas();
			break;
		case 12:
			imprimirMedicamentos();
			break;
		default:
			break;
		}
	} while (opc != 0);
	return 0;
}

void imprimirMenu() {
	cout << "Menu" << endl;
	cout << "1. Agregar Cliente" << endl;
	cout << "2. Agregar Medico" << endl;
	cout << "3. Agregar Paciente" << endl;
	cout << "4. Imprimir Clientes" << endl;
	cout << "5. Imprimir Medicos" << endl;
	cout << "6. Imprimir Pacientes" << endl;
	cout << "7. Agregar Visitas" << endl;
	cout << "8. Agregar Facturas" << endl;
	cout << "9. Agregar Medicamentos" << endl;
	cout << "10. Imprimir Visitas" << endl;
	cout << "11. Imprimir Facturas" << endl;
	cout << "12. Imprimir Medicamentos" << endl;
	cout << "0. Salir" << endl;
}

void agregarPersona(string tipo) {
	if (tipo == "Cliente") {
		personas[indicePersonas] = new Cliente();
	}
	else {
		personas[indicePersonas] = new Medico();
	}
	string auxiliar;
	personas[indicePersonas]->setTipo(tipo);
	while (true) {
		cout << "Ingrese Nombre: ";
		cin >> auxiliar;
		try {
			personas[indicePersonas]->setNombre(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Apellido: ";
		cin >> auxiliar;
		try {
			personas[indicePersonas]->setApellido(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Direccion: ";
		cin >> auxiliar;
		try {
			personas[indicePersonas]->setDireccion(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Telefono: ";
		cin >> auxiliar;
		try {
			personas[indicePersonas]->setTelefono(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Identidad: ";
		cin >> auxiliar;
		try {
			personas[indicePersonas]->setIdentidad(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Ciudad: ";
		cin >> auxiliar;
		try {
			personas[indicePersonas]->setCiudad(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Fecha Registro: ";
		cin >> auxiliar;
		try {
			personas[indicePersonas]->setFecha(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	personas[indicePersonas]->generarCodigo();
	indicePersonas++;
}

void imprimirPersonas(string tipo) {
	cout << "Listado de " << tipo << endl;
	for (int i = 0; i < indicePersonas; i++) {
		if (personas[i]->getTipo() == tipo) {
			personas[i]->imprimirNombre();
			personas[i]->imprimirContacto();
			personas[i]->imprimirDireccion();
		}
	}
}

void agregarPacientes() {
	pacientes[indicePacientes] = new Paciente();
	string auxiliar;
	char sexo;
	double peso;
	int edad;
	while (true) {
		cout << "Ingrese Especie: ";
		cin >> auxiliar;
		try {
			pacientes[indicePacientes]->setEspecie(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Raza: ";
		cin >> auxiliar;
		try {
			pacientes[indicePacientes]->setRaza(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Sexo(M o F): ";
		cin >> sexo;
		try {
			pacientes[indicePacientes]->setSexo(sexo);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Peso(KG): ";
		cin >> peso;
		try {
			pacientes[indicePacientes]->setPeso(peso);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Color: ";
		cin >> auxiliar;
		try {
			pacientes[indicePacientes]->setColor(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Nombre: ";
		cin >> auxiliar;
		try {
			pacientes[indicePacientes]->setNombre(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Alergias: ";
		cin >> auxiliar;
		try {
			pacientes[indicePacientes]->setAlergias(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Fecha Ultima Visita: ";
		cin >> auxiliar;
		try {
			pacientes[indicePacientes]->setUltimaVisita(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese edad: ";
		cin >> edad;
		try {
			pacientes[indicePacientes]->setEdad(edad);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Observaciones: ";
		cin >> auxiliar;
		try {
			pacientes[indicePacientes]->setObservaciones(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	pacientes[indicePacientes]->generarId();
	indicePacientes++;
}

void  imprimirPacientes() {
	cout << "Listado de Pacientes" << endl;
	for (int i = 0; i < indicePacientes; i++) {
		pacientes[i]->imprimirDatos();
		pacientes[i]->imprimirEspecieRaza();
	}
}

void agregarVisita() {
	visitas[indiceVisitas] = new Visita();
	string auxiliar;
	int factura;
	while (true) {
		cout << "Ingrese Fecha: ";
		cin >> auxiliar;
		try {
			visitas[indiceVisitas]->setFecha(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Tipo: ";
		cin >> auxiliar;
		try {
			visitas[indiceVisitas]->setTipo(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Nombre Paciente: ";
		cin >> auxiliar;
		try {
			visitas[indiceVisitas]->setPaciente(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Numero Factura: ";
		cin >> factura;
		try {
			visitas[indiceVisitas]->setFactura(factura);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese nombre Medico: ";
		cin >> auxiliar;
		try {
			visitas[indiceVisitas]->setMedico(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Observaciones: ";
		cin >> auxiliar;
		try {
			visitas[indiceVisitas]->setObservacion(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	indiceVisitas++;
}

void imprimirVisitas() {
	cout << "Listado de Visitas" << endl;
	for (int i = 0; i < indiceVisitas; i++) {
		visitas[i]->imprimirInfoBasica();
		visitas[i]->imprimirDetalle();
	}
}

void agregarFactura() {
	facturas[indiceFacturas] = new Factura();
	string auxiliar;
	double montos;
	while (true) {
		cout << "Ingrese Fecha: ";
		cin >> auxiliar;
		try {
			facturas[indiceFacturas]->setFecha(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Forma De Pago: ";
		cin >> auxiliar;
		try {
			facturas[indiceFacturas]->setFormaPago(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Total: ";
		cin >> montos;
		try {
			facturas[indiceFacturas]->setTotal(montos);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	facturas[indiceFacturas]->calcularISV();
	facturas[indiceFacturas]->calcularSubTotal();
	indiceFacturas++;
}

void imprimirFacturas() {
	cout << "Listado de Facturas" << endl;
	for (int i = 0; i < indiceFacturas; i++) {
		facturas[i]->imprimir();
	}
}

void agregarMedicamento() {
	medicamentos[indiceMedicamentos] = new Medicamento();
	string auxiliar;
	double montos;
	while (true) {
		cout << "Ingrese Fecha Fabricacion: ";
		cin >> auxiliar;
		try {
			medicamentos[indiceMedicamentos]->setFechaFabricaion(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Fecha Vencimiento: ";
		cin >> auxiliar;
		try {
			medicamentos[indiceMedicamentos]->setFechaVencimiento(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Nombre: ";
		cin >> auxiliar;
		try {
			medicamentos[indiceMedicamentos]->setNombre(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Farmaceutica: ";
		cin >> auxiliar;
		try {
			medicamentos[indiceMedicamentos]->setFarmaceutica(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Aplica Descuento (Si o No): ";
		cin >> auxiliar;
		try {
			medicamentos[indiceMedicamentos]->setAplicaDescuento(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Pais Fabricacion: ";
		cin >> auxiliar;
		try {
			medicamentos[indiceMedicamentos]->setPais(auxiliar);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (true) {
		cout << "Ingrese Precio: ";
		cin >> montos;
		try {
			medicamentos[indiceMedicamentos]->setPrecio(montos);
			if (cin.fail()) {
				throw "error";
			}
			break;
		}
		catch (...) {
			cout << "Verifique el tipo de dato ingresado..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	indiceMedicamentos++;
}

void imprimirMedicamentos() {
	cout << "Listado de Medicamentos" << endl;
	for (int i = 0; i < indiceMedicamentos; i++) {
		medicamentos[i]->imprimirInformacion();
		medicamentos[i]->imprimirInfoFarmaceutica();
	}
}