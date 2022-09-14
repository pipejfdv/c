#include <stdio.h>
//declarar las funciones antes del main//
void depositar();
void Retirar();
void Consulta();
int validacion(int cuenta_temp, int password_temp);
int i,x;
int cuenta_temp;
int password_temp;
int monto_temp;

int main()
{	
	//crear el menu//
	while(1)//ciclo infinito, se le agrega el 1//
	{
		int Op;
		printf("\n------Cajero Nequi-----\n");
		printf("1. Depositar\n2. Retirar\n3. Constultar Balance\n4. Exit\nPresionar enter para seleccionar.");
		scanf("%d", &Op);
		switch(Op) //tomar el valor y asignar al caso que corresponda//
		{
			case 1:
			{
				depositar();//activar la funcion//
				break;//que termine la funcion que se acabo de seleccionar//
					//para que no se genere un ciclo//
			}
			case 2:
			{
				Retirar();
				break;
			}
			case 3:
			{
				Consulta();
				break;
			}
			case 4:
			{
				Exit(1);
				break;
			}
			default://respuesta en caso de ser diferente la seleccion//
				printf("No definido, vuelve a intentar\n");
		}	
	}
}

struct cuenta_detalles 
{	//Estructura
	int no_cuenta;
	int password;
	int saldo;
};

struct cuenta_detalles s[3]{{123451,1234, 100},{123452,1234, 0},{123453,1234, 1000}};
void Retirar()
{
	
	printf("\nIngresar número de la cuenta:\t");
	scanf("%d", &cuenta_temp);
	printf("\nContraseña:\t");
	scanf("%d", &password_temp);
	printf("\nCantidad a retirar:\t");
	scanf("%d", &monto_temp);
	x=validacion(cuenta_temp, password_temp);
	
	if(s[x].saldo<monto_temp)
	{
		printf("\nNo cuenta con el dinero suficiente");
	}
	
}

int validacion(cuenta_temp, password_temp)
{
	for (i=0; i<3; i++)
	{
		if(s[i].no_cuenta==cuenta_temp)
		{
			if(s[i].password==password_temp)
			{
				return i;
				break;
			}
			else{
				printf("La contraseña no es correcta");
				exit(1);
			}	
		}
		else{
			printf("Número de cuenta incorrecto")
			exit(1);
		}
	}
}