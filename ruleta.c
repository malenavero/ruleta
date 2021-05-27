#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


long funcion_color(long billetera);
long funcion_par(long billetera);
long funcion_falta(long billetera);
long funcion_docena(long billetera);
long funcion_columna(long billetera);
long funcion_seisena(long billetera);
long funcion_cuadro(long billetera);
long funcion_transversal(long billetera);
long funcion_caballo(long billetera);
long funcion_pleno(long billetera);
int  funcion_numero_random();
long funcion_apuesta(long billetera);
void funcion_salida(long billetera);


int main()
{	
	int jugada = 0;
	
	long saldo;
    printf("\nIngrese cual va a ser su saldo incial: ");
	scanf("%li", &saldo);
	printf("\nPerfecto! Usted arranca con un saldo inicial de $%li \n", saldo);
	
    long billetera=saldo;
  
    do 
	{
		printf("\nHola, las jugadas posibles son:\n\n\t1- Rojo/Negro\n\t2- Par/Impar\n\t3- Pasa/Falta\n\t4- Docena\n\t5- Columna\n\t6- Seisena\n\t7- Cuadro\n\t8- Transversal\n\t9- Caballo\n\t10- Pleno\n");
		printf("\nPor favor indique que tipo de jugada quiere hacer: \n");
		scanf("%i",&jugada);
		fflush (stdin);
		switch (jugada)
		{
			case 1: {printf("\nUsted va a jugar a Color\n");billetera=funcion_color(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 2: {printf("\nUsted va a jugar a Par/Impar\n");billetera= funcion_par(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 3: {printf("\nUsted va a jugar a Pasa/Falta\n");billetera=funcion_falta(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 4: {printf("\nUsted va a jugar a Docena\n"); billetera=funcion_docena(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 5: {printf("\nUsted va a jugar a Columna\n"); billetera=funcion_columna(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 6: {printf("\nUsted va a jugar a Seisena\n"); billetera=funcion_seisena(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 7: {printf("\nUsted va a jugar a Cuadro\n"); billetera=funcion_cuadro(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 8: {printf("\nUsted va a jugar a Transversal\n"); billetera=funcion_transversal(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 9: {printf("\nUsted va a jugar a Caballo\n"); billetera=funcion_caballo(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			case 10: {printf("\nUsted va a jugar a Pleno\n"); billetera=funcion_pleno(billetera);printf("\nSu billetera ahora es de $%li\n",billetera); funcion_salida(billetera);break;}
			default : {printf("\nUsted no ingreso una opcion correcta\n");break;}
		}
		
    }
    while ( jugada > 0 || jugada < 10);
    
	return 0;
}

long funcion_apuesta(long billetera)
{ 	
	int i=0;
	char apuesta_string[10];
	long apuesta=0;
	int error=0;
		
		do	
		 {	
			printf("\nCuanto quiere apostar?\n");
			scanf("%s", apuesta_string);
			fflush (stdin);
				for(i=0; i<strlen(apuesta_string); i++)
				{		if((apuesta_string[i]!='.') && (isdigit(apuesta_string[i])==0))
						{
							printf("\nEl monto ingresado no es correcto. Por favor ingrese un numero entero sin signos.\n");error=0;break;
						}
						else {error=1;}
				}
		 }
		
		while (error==0);	
			
		apuesta=atol(apuesta_string);
			
		
	while (apuesta > billetera)
	{
		printf("\nNo tiene tanto dinero. Por favor ingrese cuanto desea apostar.\n");
		printf("\nSu billetera contiene $%li.\n", billetera);
		
		do	
		 {	
			printf("\nCuanto quiere apostar?\n");
			scanf("%s", apuesta_string);
			fflush (stdin);
				for(i=0; i<strlen(apuesta_string); i++)
				{		if((apuesta_string[i]!='.') && (isdigit(apuesta_string[i])==0))
						{
							printf("\nEl monto ingresado no es correcto. Por favor ingrese un numero entero sin signos.\n");error=0;break;
						}
						else {error=1;}
				}
		 }
		
		while (error==0);	
			
		apuesta=atol(apuesta_string);
		
	}
	

return (apuesta);	
			
}

int funcion_numero_random()
{
  
   time_t t;
   int numero =0;   
    
   srand((unsigned) time(&t));
   numero= rand() % 38;
   
   
   return(numero);
}

void funcion_salida (long billetera)
{
	char salida=0;
	if (billetera>0)
	{
		while(salida!='N' && salida != 'S')
		{
			printf("\nQuiere continuar jugando? Si(s) o No(n)\n");
			salida= toupper(getchar());fflush (stdin);
			switch(salida)
			{
				case 'N': {exit(0);break;}
				case 'S': {printf("\n\t\t\t\tBUENA SUERTE!\n\n\n");break;}
				default: {printf("\nIngreso una opcion no valida\n");}
				
			}
		}
	}
	else {printf("\n\n\t\tUSTED SE QUEDO SIN PLATA, NOS VEMOS LA PROXIMA\n\n\n\n");exit(0);}
	return;
}

long funcion_color(long billetera)
{   
	char color;
	int numero=0;
	int i=0;
	int temp=0;
	int rojos[]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	
	long apuesta=funcion_apuesta(billetera);
	long ganancia=apuesta;
		
	while (color!='N' && color!= 'R')
	{
		printf("\nSeleccione su apuesta:\n\tR- Rojo\n\tN- Negro\n");
		color = toupper(getchar());
		fflush (stdin);
		
			switch(color)
			{
				case 'R': {printf("\nUsted aposto $%li al Rojo.\n",apuesta);break;}
				case 'N': {printf("\nUsted aposto $%li al Negro.\n",apuesta);break;}
				default:  {printf("\nPor favor ingrese 'R' o 'N' para realizar su apuesta\n");}
			}	
	}
	printf("\nVamos a girar la ruleta...\n\n");
	//system("pause");
	
	numero = funcion_numero_random();	
	
	if (numero != 0)
	{
		for (i=0;i<18;i++)
		{ 	if (rojos [i] == numero)
			{temp=1;break;}
			
			else {temp=2;}
		};
	}
		
	if (temp == 1 && color == 'R')
	{   printf("\nEl numero ganador es %i y es color Rojo por lo tanto usted gano $%li\n", numero, ganancia);
		billetera=billetera+ganancia;}
	
	else if (temp == 2 && color == 'N')
	{   printf("\nEl numero ganador es %i y es color Negro por lo tanto usted gano $%li\n", numero, ganancia);
		billetera=billetera+ganancia;}
	
	else if  (temp == 1 && color == 'N')
	{ printf("\nEl numero ganador es %i y es color Rojo por lo tanto usted perdio\n", numero);
		billetera=billetera-apuesta;}
	
	else if  (temp == 2 && color == 'R')
	{ printf("\nEl numero ganador es %i y es color Negro por lo tanto usted perdio\n", numero);
		billetera=billetera-apuesta;}
	
	else { printf("\nEl numero ganador es %i y no lleva color por lo tanto usted perdio\n", numero);
		billetera=billetera-apuesta;}
	
	
	return (billetera);
		
		
}

long funcion_par(long billetera)
{
	char par_impar;
	int numero=0;
	long apuesta=funcion_apuesta(billetera);	
	long ganancia=apuesta;
		
	while (par_impar!='P' && par_impar!= 'I')
	{
		printf("\nSeleccione su apuesta:\n\n\tP- Par\n\tI- Impar\n");
		par_impar = toupper(getchar());
		fflush (stdin);
		
			switch(par_impar)
			{
				case 'P': {printf("\nUsted aposto $%li a Par.\n",apuesta);break;}
				case 'I': {printf("\nUsted aposto $%li a Impar.\n",apuesta);break;}
				default:  {printf("\nPor favor ingrese 'P' o 'I' para realizar su apuesta\n");}
			}	
	}
	
	numero = funcion_numero_random();	
		
	if (numero==0)
		{	printf("\nEl numero ganador es %i y no es par ni impar por lo tanto usted perdio\n", numero);billetera=billetera-apuesta;
		}
		
	else if (numero %2 == 0)
		{	switch(par_impar)
			{ 	case 'P': {printf("\nEl numero ganador es %i y es Par por lo tanto por lo tanto gano $%li\n", numero,ganancia);billetera=billetera+ganancia;break;}
				case 'I': {printf("\nEl numero ganador es %i y es Par por lo tanto usted perdio\n", numero);billetera=billetera-apuesta;break;}
			}
		}
		
	else
		{	switch(par_impar)
			{ 	case 'I': {printf("\nEl numero ganador es %i y es Impar por lo tanto usted gano $%li\n", numero, ganancia);billetera=billetera+ganancia;break;}
				case 'P': {printf("\nEl numero ganador es %i y es Impar por lo tanto usted perdio\n", numero);billetera=billetera-apuesta;break;}
			}
		}
	
	return(billetera);		
	
}

long funcion_falta(long billetera)
{
	
	char pasa_falta;
	int numero=0;
	long apuesta=funcion_apuesta(billetera);	
	long ganancia=apuesta*2;
	
	while (pasa_falta!='P' && pasa_falta!= 'F')
	{
		printf("\nSeleccione su apuesta:\n\n\tP- Pasa\n\tF- Falta\n");
		pasa_falta = toupper(getchar());
		fflush (stdin);
		
			switch(pasa_falta)
			{
				case 'P': {printf("\nUsted aposto $%li a Pasa.\n",apuesta);break;}
				case 'F': {printf("\nUsted aposto $%li a Falta.\n",apuesta);break;}
				default:  {printf("\nPor favor ingrese 'P' o 'F' para realizar su apuesta\n");}
			}	
	}
	
	numero = funcion_numero_random();	
		
	if (numero==0)
		{	printf("\nEl numero ganador es %i por lo tanto usted perdio\n", numero);
		}
		
	else if (numero < 19 )
		{	switch(pasa_falta)
			{ 	case 'F': {printf("\nEl numero ganador es %i, por lo tanto usted gano $%li\n", numero, ganancia);billetera=billetera+ganancia;break;}
				case 'P': {printf("\nEl numero ganador es %i, por lo tanto usted perdio\n", numero);billetera=billetera-apuesta;break;}
			}
		}
		
	else
		{	switch(pasa_falta)
			{ 	case 'P': {printf("\nEl numero ganador es %i, por lo tanto usted  gano $%li\n", numero,ganancia);billetera=billetera+ganancia;break;}
				case 'F': {printf("\nEl numero ganador es %i , por lo tanto usted perdio\n", numero);billetera=billetera-apuesta;break;}
			}
		}
	
	return(billetera);
	
	
}

long funcion_docena(long billetera)
{
	
	long apuesta=funcion_apuesta(billetera);
	long ganancia_1= apuesta*2;
	long ganancia_2= apuesta/2;
	int docena=0;
	int numero=0;
	int docena_ganadora=0;
	
	
	while (docena<1 || docena >5)
	{
		printf("\n Seleccione su apuesta:\n\n\t1- Docena 1\n\t2- Docena 2\n\t3- Docena 3\n\t4- Docenas 1 y 2\n\t5- Docenas 2 y 3\n");
		scanf("%i",&docena);fflush (stdin);
		if (docena<0 && docena >5)
		{printf("\nIngreso una opcion no valida\n");}
		
	}
	
	numero=funcion_numero_random();
	
		
	if(numero>0 && numero <13)
	{ docena_ganadora=1	;}
	else if (numero>12 && numero <=24)
	{ docena_ganadora=2;}
	else
	{docena_ganadora=3;}
	
	
	if (docena_ganadora==1)
	{
		switch (docena)
		{
			case 1: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted gano %li  \n", numero, docena_ganadora,ganancia_1);billetera=billetera+ganancia_1;break;}
			case 2: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted perdio\n",numero,docena_ganadora);billetera=billetera-apuesta;break;}
			case 3: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted perdio\n", numero,docena_ganadora);billetera=billetera-apuesta;break;}
			case 4: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted gano %li  \n", numero, docena_ganadora,ganancia_2);billetera=billetera+ganancia_2;break;}
			case 5: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted perdio\n",numero,docena_ganadora);billetera=billetera-apuesta;break;}
			
		}
	}
	
	else if (docena_ganadora==2)
	{
		switch (docena)
		{
			case 2: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted gano %li  \n", numero, docena_ganadora, ganancia_1);billetera=billetera+ganancia_1;break;}
			case 1: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted perdio\n",numero,docena_ganadora);billetera=billetera-apuesta;break;}
			case 3: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted perdio\n",numero,docena_ganadora);billetera=billetera-apuesta;break;}
			case 4: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted gano %li  \n", numero, docena_ganadora,ganancia_2);billetera=billetera+ganancia_2;break;}
			case 5: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted gano %li  \n", numero, docena_ganadora,ganancia_2);billetera=billetera+ganancia_2;break;}
		}
	}
	
	else 
	{
		switch (docena)
		{
			case 3: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted gano %li  \n", numero, docena_ganadora,ganancia_1);billetera=billetera+ganancia_1;break;}
			case 1: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted perdio\n",numero,docena_ganadora);billetera=billetera-apuesta;break;}
			case 2: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted perdio\n",numero,docena_ganadora);billetera=billetera-apuesta;break;}
			case 4: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted perdio\n",numero,docena_ganadora);billetera=billetera-apuesta;break;}
			case 5: {printf("\nEl numero ganador es %i y corresponde a la docena Nro %i, por lo tanto usted gano %li  \n", numero, docena_ganadora,ganancia_2);billetera=billetera+ganancia_2;break;}
		}
	}
	
	return(billetera);
	
}

long funcion_columna(long billetera)
{  
	long apuesta=funcion_apuesta(billetera);
	long ganancia_1= apuesta*2;
	long ganancia_2= apuesta/2;
	int columna_1[]={1,4,7,10,13,16,19,22,25,28,31,34};
	int columna_2[]={2,5,8,11,14,17,20,23,26,29,32,35};
	int columna=0;
	int columna_ganadora=0;
	int numero=0;
	int i=0;
		
	while (columna<1 || columna >5)
	{
		printf("\n Seleccione su apuesta:\n\n\t1- Columna 1\n\t2- Columna 2\n\t3- Columna 3\n\t4- Columnas 1 y 2\n\t5- Columnas 2 y 3\n");
		scanf("%i",&columna);fflush (stdin);
		if (columna<0 && columna >5)
		{printf("\nIngreso una opcion no valida\n");}
		
	}
		
	numero=funcion_numero_random();
	
	for (i=0;i<12;i++)
		{ 	if (columna_1[i] == numero)
			{columna_ganadora=1;break;}
			
			else if (columna_2[i] == numero)
			{columna_ganadora=2;break;}
			
			else {columna_ganadora=3;}
		}
	
	if (numero==0)
		{	printf("\nEl numero ganador es %i por lo tanto usted perdio\n", numero);
		}
		
	else if (columna_ganadora == 1)
		{	switch(columna)
			{ 	case 1: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted aposto %li y gano $%li\n", numero, columna_ganadora, apuesta,ganancia_1);billetera=billetera+ganancia_1;break;}
				case 2: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted perdio\n", numero,columna_ganadora);billetera=billetera-apuesta;break;}
				case 3: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted perdio\n", numero,columna_ganadora);billetera=billetera-apuesta;break;}
				case 4: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted aposto %li y gano $%li\n", numero, columna_ganadora, apuesta,ganancia_2);billetera=billetera+ganancia_2;break;}
				case 5: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted perdio\n", numero,columna_ganadora);billetera=billetera-apuesta;break;}
			}
		}
	
	else if (columna_ganadora == 2)
		{	switch(columna)
			{ 	case 2: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted aposto %li y gano $%li\n", numero, columna_ganadora, apuesta,ganancia_1);billetera=billetera+ganancia_1;break;}
				case 1: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted perdio\n", numero,columna_ganadora);billetera=billetera-apuesta;break;}
				case 3: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted perdio\n", numero,columna_ganadora);billetera=billetera-apuesta;break;}
				case 4: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted aposto %li y gano $%li\n", numero, columna_ganadora, apuesta,ganancia_2);billetera=billetera+ganancia_2;break;}
				case 5: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted aposto %li y gano $%li\n", numero, columna_ganadora, apuesta,ganancia_2);billetera=billetera+ganancia_2;break;}
			}
		}
		
	
	else if (columna_ganadora == 3)
		{	switch(columna)
			{ 	case 3: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted aposto %li y gano $%li\n", numero, columna_ganadora, apuesta,ganancia_1);billetera=billetera+ganancia_1;break;}
				case 1: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted perdio\n", numero,columna_ganadora);billetera=billetera-apuesta;break;}
				case 2: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted perdio\n", numero,columna_ganadora);billetera=billetera-apuesta;break;}
				case 4: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted perdio\n", numero,columna_ganadora);billetera=billetera-apuesta;break;}
				case 5: {printf("\nEl numero ganador es %i, y esta en la columna %i por lo tanto usted aposto %li y gano $%li\n", numero, columna_ganadora, apuesta,ganancia_2);billetera=billetera+ganancia_2;break;}
			}
		}
	
	return(billetera);
		
}

long funcion_seisena(long billetera)
{	
	long apuesta=funcion_apuesta(billetera);
	long ganancia=apuesta*5;
	int seisena=0;
	int numero=0;
	int i=0;
	int i_2=-2;
	int i_3=4;
		
		while (seisena <1|| seisena > 11)
		{
			printf("\nSeleccione a que seisena quiere apostar:\n\n\t  1 = 1,2,3,4,5,6\n\t  2 = 4,5,6,7,8,9\n\t  3 = 7,8,9,10,11,12\n\t  4 = 10,11,12,13,14,15\n\t  5 = 13,14,15,16,17,18\n\t  6 = 16,17,18,19,20,21\n\t  7 = 19,20,21,22,23,24\n\t  8 = 22,23,24,25,26,27\n\t  9 = 25,26,27,28,29,30\n\t 10 = 28,29,30,31,32,33\n\t 11 = 31,32,33,34,35,36\n");
			scanf("%i",&seisena);
			fflush (stdin);
		}

		numero=funcion_numero_random();
	
		for (i=1;i<12;i++)
		{
			i_2=i_2+3;
			i_3=i_3+3;
			
			if (seisena==i)
			{	
				if ( numero>=i_2  && numero <i_3)
				{printf ("\nEl numero ganador es %i por lo tanto usted gano %li\n", numero, ganancia);billetera=billetera+ganancia;}
				else 
				{printf ("\nEl numero ganador es %i por lo tanto usted perdio\n", numero);billetera=billetera-apuesta;}	
			}
		}
		
		return(billetera);
}

long funcion_cuadro(long billetera)
{
	long apuesta=funcion_apuesta(billetera);
	long ganancia=apuesta*8;
	int  seleccion;
	int i=0;
	int temp=0;
	int numero=0;
	int cuadro_seleccionado[4]={};
	
	
	while (seleccion<1||seleccion>22)
	{
	printf("\n Seleccione el cuadro al que desea apostar:\n\n");
	printf("1-  |01,02,04,05|\t\t2-  |02,03,05,06|\t\t3-  |04,05,07,08|\n4-  |05,06,08,09|\t\t5-  |07,08,10,11|\t\t6-  |08,09,11,12|\n7-  |10,11,13,14|\t\t8-  |11,12,14,15|\t\t9-  |13,14,16,17|\n10- |14,15,17,18|\t\t11- |16,17,19,20|\t\t12- |17,18,21,21|\n13- |19,20,22,23|\t\t14- |20,21,23,24|\t\t15- |22,23,25,26|\n16- |23,24,26,27|\t\t17- |25,26,28,29|\t\t18- |26,27,29,30|\n19- |28,29,31,32|\t\t20- |29,30,32,33|\t\t21- |31,32,34,35|\n22- |32,33,35,36|\n\n");
	scanf("%i",&seleccion);fflush (stdin);
	}

	if (seleccion==1)
	{	int cuadro[]= {1,2,4,5};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==2)
	{	int cuadro[]= {2,3,5,6};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==3)
	{	int cuadro[]= {4,5,7,8};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==4)
	{	int cuadro[]= {5,6,8,9};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==5)
	{	int cuadro[]= {5,6,8,9};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==6)
	{	int cuadro[]= {8,9,11,12};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==7)
	{	int cuadro[]= {10,11,13,14};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==8)
	{	int cuadro[]= {11,12,14,15};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==9)
	{	int cuadro[]= {13,14,16,17};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==10)
	{	int cuadro[]= {14,15,17,18};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==11)
	{	int cuadro[]= {16,17,19,20};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==12)
	{	int cuadro[]= {17,18,21,21};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==13)
	{	int cuadro[]= {19,20,22,23};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==14)
	{	int cuadro[]= {20,21,23,24};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==15)
	{	int cuadro[]= {22,23,25,26};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}
	else if (seleccion==16)
	{	int cuadro[]= {23,24,26,27};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}	
	else if (seleccion==17)
	{	int cuadro[]= {25,26,28,29};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}	
	else if (seleccion==18)
	{	int cuadro[]= {26,27,29,30};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}	
	else if (seleccion==19)
	{	int cuadro[]= {28,29,31,32};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}	
	else if (seleccion==20)
	{	int cuadro[]= {29,30,32,33};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}	
	else if (seleccion==21)
	{	int cuadro[]= {31,32,34,35};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}	
	else
	{	int cuadro[]= {32,33,35,36};
		for(i=0;i<4;i++)
		{cuadro_seleccionado[i] = cuadro[i];}
	}	
	
	   
    numero=funcion_numero_random();
    
    for (i=0;i<4;i++)
    {	if  (cuadro_seleccionado[i]==numero)
			{temp=1;break;}
		
	}
	switch (temp)
		{
			case 1:  {printf("El numero ganador es %i por lo tanto usted gano$%li",numero,ganancia);billetera=billetera+ganancia;break;}
			default: {printf("El numero ganador es %i por lo tanto usted perdio.\n\n",numero);billetera=billetera-apuesta;break;}
		}
    
	return(billetera);
}

long funcion_transversal(long billetera)
{
	int fila_array []= {1,2,3};
	int fila_seleccionada[3]={};
	int seleccion=0;
	int fila;
	int numero;
	long apuesta=funcion_apuesta(billetera);
	long ganancia=apuesta*11;
	int i=0;
	int temp=0;
	
	
		while (seleccion <1 || seleccion >3 )
		{
		printf("\n\tSeleccione una opcion: \n\t 1- Variante '0,1,2' \n\t 2- Variante '0,2,3' \n\t 3- Fila\n");
		scanf("%i",&seleccion);
		fflush (stdin);
		}
		
		if (seleccion == 1)
		
		{	fila_seleccionada[0]=0;
			fila_seleccionada[1]=1;
			fila_seleccionada[2]=2;
		}
		
		else if (seleccion == 2)
		
		{	fila_seleccionada[0]=0;
			fila_seleccionada[1]=2;
			fila_seleccionada[2]=3;
		}
			
		else 
		{	
			while (fila<1 ||fila>12)
			{
			printf("\n\tA que fila desea apostar?\n");
			scanf("%i",&fila); fflush (stdin);
			}
			for(i=0;i<3;i++)
			{
				fila_seleccionada[i]=fila_array[i]+(3*(fila-1));
				fila_seleccionada[i]=fila_array[i]+(3*(fila-1));
				fila_seleccionada[i]=fila_array[i]+(3*(fila-1));
			}
		}
				
		numero=funcion_numero_random();
		//printf("\nla fila seleccionada es %i, %i, %i\n", fila_seleccionada[0],fila_seleccionada[1],fila_seleccionada[2]);
		
	
		for (i=0;i<3;i++)
		{
			if (numero==fila_seleccionada[i])
			{temp=1;break;}
		}
		
		switch (temp)
		{
			case 1:  {printf("El numero ganador es %i por lo tanto usted gano$%li\n\n",numero,ganancia);billetera=billetera+ganancia;break;}
			default: {printf("El numero ganador es %i por lo tanto usted perdio\n\n",numero);billetera=billetera-apuesta;break;}
		}
		
	
	return(billetera);
	
	
}

long funcion_caballo(long billetera)
{
	
	int caballo1[] = {0,1};
	int caballo2[] = {0,2};
	int caballo3[] = {0,3};
	int caballo4[] = {1,2};
	int caballo5[] = {1,4};
	int caballo6[] = {2,3};
	int caballo7[] = {2,5};
	int caballo8[] = {3,6};
	int caballo9[] = {4,5};
	int caballo10[] = {4,7};
	int caballo11[] = {5,6};
	int caballo12[] = {5,8};
	int caballo13[] = {6,9};
	int caballo14[] = {7,8};
	int caballo15[] = {7,10};
	int caballo16[] = {8,9};
	int caballo17[] = {9,11};
	int caballo18[] = {9,12};
	int caballo19[] = {10,11};
	int caballo20[] = {10,13};
	int caballo21[] = {11,12};
	int caballo22[] = {11,14};
	int caballo23[] = {12,15};
	int caballo24[] = {13,14};
	int caballo25[] = {13,16};
	int caballo26[] = {14,15};
	int caballo27[] = {14,17};
	int caballo28[] = {15,18};
	int caballo29[] = {16,17};
	int caballo30[] = {16,19};
	int caballo31[] = {17,18};
	int caballo32[] = {17,20};
	int caballo33[] = {18,21};
	int caballo34[] = {19,20};
	int caballo35[] = {19,22};
	int caballo36[] = {20,21};
	int caballo37[] = {20,23};
	int caballo38[] = {21,24};
	int caballo39[] = {22,23};
	int caballo40[] = {22,25};
	int caballo41[] = {23,24};
	int caballo42[] = {23,26};
	int caballo43[] = {24,27};
	int caballo44[] = {25,26};
	int caballo45[] = {25,28};
	int caballo46[] = {26,27};
	int caballo47[] = {26,29};
	int caballo48[] = {27,30};
	int caballo49[] = {28,29};
	int caballo50[] = {28,31};
	int caballo51[] = {29,30};
	int caballo52[] = {29,32};
	int caballo53[] = {30,33};
	int caballo54[] = {31,32};
	int caballo55[] = {31,34};
	int caballo56[] = {32,33};
	int caballo57[] = {32,35};
	int caballo58[] = {33,36};
	int caballo59[] = {34,35};
	int caballo60[] = {35,36};
	
	
	long apuesta=funcion_apuesta(billetera);
	long ganancia=apuesta*17;	
	int caballo_jugador[2]={};
	int correcto=0;
		
		do
		{	
			printf("\nIngrese los numeros a los que quiere jugar, recuerde que deben ser consecutivos en el tablero (por favor ingreselos de menor a mayor o no funcionara):\n\n\t1- ");
			scanf("%i",&caballo_jugador[0]);fflush (stdin);
			printf("\n\t2- ");
			scanf("%i",&caballo_jugador[1]);fflush (stdin);
					
		
			
			if (
					(caballo_jugador[0]==caballo1[0] && caballo_jugador[1]==caballo1[1]) 
					|| ( caballo_jugador[0] == caballo2[0] && caballo_jugador[1] == caballo2[1])
					|| ( caballo_jugador[0] == caballo3[0] && caballo_jugador[1] == caballo3[1])
					|| ( caballo_jugador[0] == caballo4[0] && caballo_jugador[1] == caballo4[1])
					|| ( caballo_jugador[0] == caballo5[0] && caballo_jugador[1] == caballo5[1])
					|| ( caballo_jugador[0] == caballo6[0] && caballo_jugador[1] == caballo6[1])
					|| ( caballo_jugador[0] == caballo7[0] && caballo_jugador[1] == caballo7[1])
					|| ( caballo_jugador[0] == caballo8[0] && caballo_jugador[1] == caballo8[1])
					|| ( caballo_jugador[0] == caballo9[0] && caballo_jugador[1] == caballo9[1])
					|| ( caballo_jugador[0] == caballo10[0] && caballo_jugador[1] == caballo10[1])
					|| ( caballo_jugador[0] == caballo11[0] && caballo_jugador[1] == caballo11[1]) 
					|| ( caballo_jugador[0] == caballo12[0] && caballo_jugador[1] == caballo12[1]) 
					|| ( caballo_jugador[0] == caballo13[0] && caballo_jugador[1] == caballo13[1]) 
					|| ( caballo_jugador[0] == caballo14[0] && caballo_jugador[1] == caballo14[1]) 
					|| ( caballo_jugador[0] == caballo15[0] && caballo_jugador[1] == caballo15[1]) 
					|| ( caballo_jugador[0] == caballo16[0] && caballo_jugador[1] == caballo16[1]) 
					|| ( caballo_jugador[0] == caballo17[0] && caballo_jugador[1] == caballo17[1]) 
					|| ( caballo_jugador[0] == caballo18[0] && caballo_jugador[1] == caballo18[1]) 
					|| ( caballo_jugador[0] == caballo19[0] && caballo_jugador[1] == caballo19[1]) 
					|| ( caballo_jugador[0] == caballo20[0] && caballo_jugador[1] == caballo20[1]) 
					|| ( caballo_jugador[0] == caballo21[0] && caballo_jugador[1] == caballo21[1]) 
					|| ( caballo_jugador[0] == caballo22[0] && caballo_jugador[1] == caballo22[1]) 
					|| ( caballo_jugador[0] == caballo23[0] && caballo_jugador[1] == caballo23[1]) 
					|| ( caballo_jugador[0] == caballo24[0] && caballo_jugador[1] == caballo24[1]) 
					|| ( caballo_jugador[0] == caballo25[0] && caballo_jugador[1] == caballo25[1]) 
					|| ( caballo_jugador[0] == caballo26[0] && caballo_jugador[1] == caballo26[1]) 
					|| ( caballo_jugador[0] == caballo27[0] && caballo_jugador[1] == caballo27[1]) 
					|| ( caballo_jugador[0] == caballo28[0] && caballo_jugador[1] == caballo28[1]) 
					|| ( caballo_jugador[0] == caballo29[0] && caballo_jugador[1] == caballo29[1]) 
					|| ( caballo_jugador[0] == caballo30[0] && caballo_jugador[1] == caballo30[1]) 
					|| ( caballo_jugador[0] == caballo31[0] && caballo_jugador[1] == caballo31[1]) 
					|| ( caballo_jugador[0] == caballo32[0] && caballo_jugador[1] == caballo32[1]) 
					|| ( caballo_jugador[0] == caballo33[0] && caballo_jugador[1] == caballo33[1]) 
					|| ( caballo_jugador[0] == caballo34[0] && caballo_jugador[1] == caballo34[1]) 
					|| ( caballo_jugador[0] == caballo35[0] && caballo_jugador[1] == caballo35[1]) 
					|| ( caballo_jugador[0] == caballo36[0] && caballo_jugador[1] == caballo36[1]) 
					|| ( caballo_jugador[0] == caballo37[0] && caballo_jugador[1] == caballo37[1]) 
					|| ( caballo_jugador[0] == caballo38[0] && caballo_jugador[1] == caballo38[1]) 
					|| ( caballo_jugador[0] == caballo39[0] && caballo_jugador[1] == caballo39[1]) 
					|| ( caballo_jugador[0] == caballo40[0] && caballo_jugador[1] == caballo40[1]) 
					|| ( caballo_jugador[0] == caballo41[0] && caballo_jugador[1] == caballo41[1]) 
					|| ( caballo_jugador[0] == caballo42[0] && caballo_jugador[1] == caballo42[1]) 
					|| ( caballo_jugador[0] == caballo43[0] && caballo_jugador[1] == caballo43[1]) 
					|| ( caballo_jugador[0] == caballo44[0] && caballo_jugador[1] == caballo44[1]) 
					|| ( caballo_jugador[0] == caballo45[0] && caballo_jugador[1] == caballo45[1]) 
					|| ( caballo_jugador[0] == caballo46[0] && caballo_jugador[1] == caballo46[1]) 
					|| ( caballo_jugador[0] == caballo47[0] && caballo_jugador[1] == caballo47[1]) 
					|| ( caballo_jugador[0] == caballo48[0] && caballo_jugador[1] == caballo48[1]) 
					|| ( caballo_jugador[0] == caballo49[0] && caballo_jugador[1] == caballo49[1]) 
					|| ( caballo_jugador[0] == caballo50[0] && caballo_jugador[1] == caballo50[1]) 
					|| ( caballo_jugador[0] == caballo51[0] && caballo_jugador[1] == caballo51[1]) 
					|| ( caballo_jugador[0] == caballo52[0] && caballo_jugador[1] == caballo52[1]) 
					|| ( caballo_jugador[0] == caballo53[0] && caballo_jugador[1] == caballo53[1]) 
					|| ( caballo_jugador[0] == caballo54[0] && caballo_jugador[1] == caballo54[1]) 
					|| ( caballo_jugador[0] == caballo55[0] && caballo_jugador[1] == caballo55[1]) 
					|| ( caballo_jugador[0] == caballo56[0] && caballo_jugador[1] == caballo56[1]) 
					|| ( caballo_jugador[0] == caballo57[0] && caballo_jugador[1] == caballo57[1]) 
					|| ( caballo_jugador[0] == caballo58[0] && caballo_jugador[1] == caballo58[1]) 
					|| ( caballo_jugador[0] == caballo59[0] && caballo_jugador[1] == caballo59[1]) 
					|| ( caballo_jugador[0] == caballo60[0] && caballo_jugador[1] == caballo60[1]) 

			)

	
			
			{	correcto=1;
				printf("\nUsted esta apostando $%li a semipleno %i,%i\n",apuesta, caballo_jugador[0],caballo_jugador[1]);}
		}
		while (correcto!=1);	
			
		int numero=funcion_numero_random();
		
		if (caballo_jugador[0]== numero || caballo_jugador[1]== numero)
		{printf("\nEl numero ganador es %i, por lo tanto usted gano $%li!\n",numero,ganancia);billetera=billetera+ganancia;}
		else	
		{printf("\nEl numero ganador es %i, por lo tanto usted perdio!\n",numero);billetera=billetera-apuesta;}					
		
	
	
	
	
	return(billetera);
	
	
}

long funcion_pleno(long billetera)
{
	
	long apuesta=funcion_apuesta(billetera);
	long ganancia=apuesta*35;
	int numero=0;
	int pleno=-1;
	
	while(pleno<0 || pleno>36 )
	{
		printf("\nA que numero queres apostar?\n");
		scanf("%i",&pleno);
		fflush (stdin);
			
	}	
	printf("\nApostaste $%li al numero %i\n",apuesta,pleno);
	 
	numero=funcion_numero_random();
	
	if(numero==pleno)
	{printf("\nEl numero ganador es %i, ganaste $%li\n",numero, ganancia);billetera=billetera+ganancia;}
	else
	{printf("\nEl numero ganador es %i, perdiste\n",numero);billetera=billetera-apuesta;}
	
		
	return(billetera);
	
		
	
}
