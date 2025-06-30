#ifndef CONTACTOS_H
#define CONTACTOS_H

#include <string>
using namespace std;

struct contactoEmail{
	string nombre;
	string sexo;
	int edad;
	int telefono;
	string email;
	string nacionalidad;
};

void Agregar_Contacto(contactoEmail Contactos[], int &cont);
void Eliminar_Contacto(contactoEmail Contactos[], int &cont);
void Mostrar_Listado_General(contactoEmail Contacto[], int cont);
void Lista_Servidor(contactoEmail Contacto[], int cont);
void menu();

#endif