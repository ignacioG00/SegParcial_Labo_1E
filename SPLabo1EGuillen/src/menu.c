/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Biblioteca.h"
#include "menu.h"

int menu(void){

	int option = 0;
	int firstFlag=0;
	int secFlag=0;


	    LinkedList* listaLibros = ll_newLinkedList();

	    do{
	    	puts("\t|**********INICIO**********|");
	    	if(subMenu(&option)){
	        switch(option)
	        {
	        case 1:
	        	if(firstFlag==0)
				{
	        		controller_loadFromText("Datos.csv",listaLibros);
	        		firstFlag=1;
				}
				else
				{
					printf("El archivo ya fue cargado");
				}
				break;

			case 2:
				controller_sortBook(listaLibros);

				if(validate_Exit_SN("Desea imprimir una lista ordenada?S/N","Error.Reingrese"))
				{
					controller_ListBook(listaLibros);
				}
				break;
	        case 3:
				if(firstFlag!=0)
				{
					controller_ListBook(listaLibros);
				}
				else
				{
					printf("Primero debe cargar un archivo\n");
				}
				break;
			case 4:
				controller_decreaseSalary(listaLibros);
				if(validate_Exit_SN("Desea imprimir una lista con los cambios?S/N","Error.Reingrese"))
				{
					controller_ListBook(listaLibros);
				}
				break;
			case 5:
				utn_getNumero(&secFlag, "Desea guardar en: \n1. Datos.csv \n2. Mapeado.csv", "Error, opcion incorrecta", 1, 2, 1);
				switch(secFlag)
				{
				case 1:
					controller_saveAsText("Datos.csv",listaLibros);
					secFlag=0;
					break;
				case 2:
					controller_saveAsText("Mapeado.csv",listaLibros);
					secFlag=0;
					break;
				}
				break;
	        	}
	    	}
	    }while(option != 6);
	    puts("\n PROYECTO FINALIZADO! MUCHAS GRACIAS POR UTILIZARLO!");
	    return 0;
}


//				case 3:
//					controller_addBook(listaLibros);
//					break;
//				case 3:
//					if((utn_getArchivo(path, "Ingrese nombre de archivo","Error, no es valido caracter especial, no olvide el .csv o .txt", 2, 30))==0)
//					{
//					controller_saveAsText(path,listaLibros);
//					}
//					else
//					{
//						secFlag=0;
//					}
//					break;

//			case 10:
//				utn_getNumero(&secFlag, "Desea guardar en: \n1. Datos.bin \n2. Chequeo.bin \n3. Nuevo archivo", "Error, opcion incorrecta", 1, 3, 1);
//				switch(secFlag)
//				{
//				case 1:
//
//					firstFlag=0;
//					break;
//				case 2:
//
//					firstFlag=0;
//					break;
//				case 3:
//					if((utn_getArchivo(path, "Ingrese nombre de archivo","Error, no es valido caracter especial, no olvide el .bin", 2, 30))==0)
//					{
//
//						firstFlag=0;
//					}
//					else
//					{
//						secFlag=0;
//					}
//					break;
//				}
//				break;
