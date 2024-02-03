#include<stdio.h>
#include<stdlib.h>

int main(){
	//se crea un archivo
	FILE *pf;
	//se crea una variable para nuestro menu
	int r;
	//se crea una matriz o array para almacenar nuestros datos
	char inventario[50];
	//iniciamos nuestro menu con if-else
	if((pf = fopen("inventario.txt","w")) !=NULL)
	{
		//imprimimos nuestra primer instruccion al usuario para que ingrese al menu de opciones
		printf("\nDesea editar el inventario?\n\n1.-Si\n\n0.-No\n\n");
			scanf("%d",&r);
		
		//iniciamos nuestro sub menu para poder realizar los cambios que requerimos en nuestro archivo de inventario
		while(r)
		{
			//aqui limpiamos nuestro programa para que no se genere la llamada "basura"
			fflush(stdin);
			//aqui el usuario escribe en el inventario el nuevo producto
			printf("\nIngrese el inventario: ");
			//aqui le decimos que lo coloque en nuestro archivo inventario
			gets(inventario);
			fputs(inventario, pf);
			//aqui damos la opcion de dejar de escribir en nuestro inventario
			printf("\nDesea agregar mas elementos al inventario?\n\n1.-Si\n\n0.-No\n\n");
			scanf("%d",&r);
			if(r)
			{
				//aqui le decimos que coloque un salto de liena en nuestro archivo cada que se escriba de nuevo en el para organizar mejor el texto
				fputs("\n",pf);  
			}	
		}
		//aqui se cierra el archivo para que se guarde los cambios en el y se pueda cerrar el programa
		fclose(pf);
	}
	else{
		//en caso de que no se pueda crear el archivo nos soltara este error que nos indica que no se a podido crear el archvio de inventario
		printf("\nNO SE PUDO CREAR EL ARCHIVO");
	}return 0;
}
