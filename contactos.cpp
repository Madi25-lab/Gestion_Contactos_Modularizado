#include <iostream>
#include <string>
#include "contactos.h"

using namespace std;

void Agregar_Contacto(contactoEmail Contactos[], int &cont){
	
	cout<<"==========================================================" << endl;
    cout<<"                   Agregar Contacto" << endl;
    cout<<"==========================================================" << endl;
	cout<<"Ingrese el nombre completo"<<endl;
	cout<<cont+1<<".-: ";
	cin.ignore();
	getline(cin,Contactos[cont].nombre);
	
	cout<<endl;
	cout<<"*f*-> Femenino; *m*-> Masculino"<<endl;
	cout<<"Ingrese el sexo: ";
	getline(cin,Contactos[cont].sexo);
	cout<<endl;
	
	cout<<"Ingrese la edad: ";
	cin>>Contactos[cont].edad;
	cout<<endl;
	
	cout<<"Ingrese el numero de telefono : ";
	cin>>Contactos[cont].telefono;
	cout<<endl;
	
	cout<<"Ingrese el Email (cuenta@servidor.com): ";
	cin.ignore();
	getline(cin,Contactos[cont].email);
	cout<<endl;
	
	cout<<"Ingrese la nacionalidad: ";
	getline(cin,Contactos[cont].nacionalidad);
	cout<<endl;
	
	cont++;
	cout<<"--------------------Contacto agregado-----------------------"<<endl;
	cout<<endl;
	}
	
	
	void Eliminar_Contacto(contactoEmail Contactos[], int &cont){
		
	if(cont!=0){
		
	int orden;
	cout<<"==========================================================" << endl;
    cout<<"                   Eliminar Contacto" << endl;
    cout<<"==========================================================" << endl;	
    cout<<"Ingrese el numero de orden del contacto: ";
    cin>>orden;
	
	orden=orden-1;	
	if(orden>=0 && orden<cont){
		for(int i=orden;i<cont-1;i++){
			Contactos[i]=Contactos[i+1];
		}
		cont --;
		cout<<endl;
	    cout<<"-------------------Contacto eliminado---------------------"<<endl;
	    cout<<endl;
	}else{
		cout<<"No hay registro de este numero orden "<<endl;
		cout<<endl;
	}
	}else { 
	cout<<endl;
    cout<<"No hay contactos para eliminar!!"<<endl;
	cout<<endl;
    }
}

void Mostrar_Listado_General(contactoEmail Contacto[], int cont){
	
    if (cont != 0){
    cout<<"==========================================================" << endl;
    cout<<"                   Registro de contactos" << endl;
    cout<<"==========================================================" << endl;	
        for (int i = 0; i < cont; i++){
            cout << i + 1 << ") -------------------Contacto---------------------"<< endl;
            cout << "Nombre: " << Contacto[i].nombre << endl;
            cout << "Sexo: " << Contacto[i].sexo << endl;
            cout << "Edad: " << Contacto[i].edad << endl;
            cout << "Telefono: " << Contacto[i].telefono << endl;
            cout << "Email: " << Contacto[i].email << endl;
            cout << "Nacionalidad: " << Contacto[i].nacionalidad << endl;
        }
    }else {
    	cout<<endl;
        cout << "No hay registro de contactos!!" << endl;
        cout<<endl;
    }
}

string Servidor(string email) {
    string servidor = "";
    bool arroba = false;
    
	int i = 0;
    while (email[i] != '\0') {
        if (arroba) {
            servidor=servidor+email[i];
        }
        if (email[i] == '@') {
            arroba = true;
        }
        i++;
    }
    return servidor;
}

void Lista_Servidor(contactoEmail Contacto[], int cont){
	const int Max=100;
	contactoEmail Valor[Max];
	if(cont!=0){
	int aux;	
    for(int i=0;i<cont;i++){
        Valor[i]=Contacto[i];
    }
    for(int i=0;i<cont-1;i++){
        for (int j=0;j<cont-i-1;j++){
        	string dom1, dom2;
            dom1=Servidor(Valor[j].email);
            dom2=Servidor(Valor[j+1].email);
            if (dom1>dom2){
                contactoEmail aux=Valor[j];
                Valor[j]=Valor[j+1];
                Valor[j+1]=aux;
            }
        }
    }  
    cout<<"==========================================================" << endl;
    cout<<"                   REGISTRO DE CONTACTOS" << endl;
    cout<<"==========================================================" << endl;	
    for(int i=0;i<cont;i++){
        cout<<i+1<<"Nombre: "<<Valor[i].nombre<<endl;
        cout<<"Email: "<<Valor[i].email<<" (Servidor(@): "<<Servidor(Valor[i].email)<<")"<<endl; 
		cout<<endl;  
    }
}else{cout<<endl;
        cout << "No hay registro de contactos!!" << endl;
        cout<<endl;
    }
}      
    
void menu(){
		
	char eleccion;
	int cont=0;
    const int Max=100;
	contactoEmail Contactos[Max];
		
	
	cout << "==========================================================" << endl;
    cout << "                 GESTOR DE CONTACTOS (MD)" << endl;
    cout << "==========================================================" << endl;
    
	do{
		cout<<endl;
    	cout<<"------------------------OPCIONES-------------------------"<<endl;
    	cout<<endl;
		cout<<"a) Agregar un contacto" <<endl;
		cout<<"b) Eliminar un contacto" <<endl;
		cout<<"c) Mostrar listado general de contactos registrados" <<endl;
		cout<<"d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas" <<endl;
		cout<<"e) Salir" <<endl;
		cout<<"Seleccione una alternativa: ";
		cin>> eleccion;
		cout<<endl;
		system("cls");
		
		switch (eleccion) {
			case 'a':{
				Agregar_Contacto(Contactos, cont);
				break;
			}
				
			case 'b':{
				Eliminar_Contacto(Contactos, cont);
				break;
			}
			
			case 'c':{
				Mostrar_Listado_General(Contactos, cont);
				break;
			}
				
			case 'd':{
				Lista_Servidor(Contactos, cont);
				break;
			}
				
			case 'e':{
				cout<<endl;
				cout<<"Saliendo del programa ... ";
				cout<<endl;
				break;
			}
				
			default:{
				cout<<endl;
				cout<<"-------Alternativa invalida--------"<<endl;
				cout<<endl;
				break;
			}
					
		}
	}while (eleccion !='e');
}