#include<iostream>
using namespace std;
int funcion();
int tipoenfermedad(int tipo,int dias);
int serviad(float numserad,  float i, float res, int servicioelegido);
int edadlimite(float cargoad,int enfermedad,int res2, float total2,int toto,int total1);
int main() 
{
	funcion();
}
int funcion()
{
	float cargoad, enfermedad, i, numserad,	res, res2, total1, total2,total3,ed,toto;
	int dias, edad , tipo, servicioelegido; 
	string serad;
	res = 0;
	
	cout << "-------------------------------------------" << endl;
	cout << "Existen 3 tipos de enfermedades. " << endl;
	cout << "Tipo 1. " << " $2500" << endl;
	cout << "Tipo 2." << " $1600" << endl;
	cout << "Tipo 3. " << " $1000" << endl;
	cout << "-------------------------------------------" << endl;
	do {
		cout << "Ingrese el numero de dias que estuvo internado: " << endl;
		cin >> dias;
		cout << "Ingrese su edad: " << endl;
		cin >> edad;
		cout << "Ingrese su tipo de enfermedad: " << endl;
		cin >> tipo;
	} while (!((dias>0 && dias<366) && (edad>=0 && edad<=90) && (tipo==1 || tipo==2 || tipo==3)));
	do {
		cout << "Desea agregar un servicio adicional?" << endl;
		cout << "Escriba: si , para agregar algun servicio adicional a su total." << endl;
		cout << "Escriba: no , para imprimir el total hasta ahora." << endl;
		cin >> serad;
	} while (!(serad=="si" || serad=="no"));
	if (serad=="si") {
		res2 =serviad(numserad, i, res, servicioelegido);
	}
	if (edad>=0 && edad<=12) {
	ed=edadlimite(cargoad,enfermedad,res2, total2, toto,total1);
	} else 
	{
		total3=edadlimite( cargoad, enfermedad, res2, total2, toto,total1);
	
	}
}
int serviad(float numserad, float i,  float res, int servicioelegido)
{
	do {
			cout << "Solo puede agregar 3 servicios adicionales como maximo." << endl;
			cout << "Cuantos servicios adicionales quiere?" << endl;
			cin >> numserad;
		} while (!(numserad==1 || numserad==2 || numserad==3));
		cout << "Existen 3 tipos de servicios adicionales." << endl;
		cout << "1-Consulta medica extra. " << " $600" << endl;
		cout << "2-Otros medicamentos." << " $800" << endl;
		cout << "3-Laboratorio." << " $1000" << endl;
		cout << "-------------------------------------------" << endl;
		for (i=1;i<=numserad;i++) {
			cout << "Seleccione su servicio: " << i << endl;
			cin >> servicioelegido;
			switch (servicioelegido) {
			case 1:
				res = res+600;
				break;
			case 2:
				res = res+800;
				break;
			case 3:
				res = res+1000;
				break;
			default:
				cout << "Error" << endl;
			}
		}
		return res;
}

int edadlimite(float cargoad,int enfermedad,int res2, float total2,int toto,int total1)
{
	int tipo,dias;
	tipoenfermedad( tipo,dias);
		cargoad = total1*0.10;
		total2 = total1+res2+cargoad;
		cout << "-Se le aplico un cargo adicional del 10% total por ser menor a los 13 anos-" << endl;
		cout << "*\\\\\\Su total a pagar es de: $" << total2 << "///*" << endl;
	
}

int tipoenfermedad(int tipo,int dias)
{
	int enfermedad=0;
	int total1;
	switch (tipo) {
	case 1:
		enfermedad = enfermedad+2500;
		break;
	case 2:
		enfermedad = enfermedad+1600;
		break;
	case 3:
		enfermedad = enfermedad+1000;
		break;
	default:
		cout << "Error" << endl;
	}
		total1 = enfermedad*dias;
		cout << "Su total a pagar es de: $" << total1 << endl;	
		return enfermedad;
}
