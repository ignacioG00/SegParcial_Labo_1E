/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include "LinkedList.h"
#include "parser.h"
#include "menu.h"
#include "Biblioteca.h"
#include "eLibro.h"

/** \brief Carga los datos de los Libros desde el archivo Datos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int -1 error 0 esta ok
 *
 */
// RETORNO -1 error 0 esta ok

int controller_loadFromText(char* path , LinkedList* pArrayListLibro)
{
	int retorno=-1;
		if(path!=NULL && pArrayListLibro!=NULL && ll_isEmpty(pArrayListLibro)==1)
		{
			retorno=0;
			FILE *pFile=fopen(path,"r");
//			printf("%p",pFile);
			if(parser_bookFromText(pFile,pArrayListLibro)==-1)
			{
				printf("No se pudo leer el archivo\n");
				retorno=-1;
			}
			else
			{
				printf("Archivo leido y cerrado correctamente\n");
			}
			fclose(pFile);
		}else{
			if(validate_Exit_SN("Existen datos en la LinkedList. Desea borrarlos? S/N",
					"Error.Reingrese S/N") && ll_clear(pArrayListLibro)==0)
			{
				FILE *pFile=fopen(path,"r");
				if(parser_bookFromText(pFile,pArrayListLibro)==-1)
				{
					printf("No se pudo leer el archivo\n");
					retorno=-1;
				}
				else
				{
					printf("Archivo leido y cerrado correctamente\n");
				}
				fclose(pFile);
			}
		}
		return retorno;
}

/** \brief Carga los datos de los Libros desde el archivo Datos.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListBook)
{
	int retorno=0;
		if(path!=NULL && pArrayListBook!=NULL && ll_isEmpty(pArrayListBook)==1)
		{
			retorno=1;
			FILE *pFile=fopen(path,"rb");
			if(parser_bookFromBinary(pFile,pArrayListBook)!=0)
			{
				printf("No se pudo leer el archivo\n");
			}
			else
			{
				printf("Archivo bien leido. Cerrado correctamente\n");
				fclose(pFile);
			}
		}else{
			if(validate_Exit_SN("Existen datos en la LinkedList. Desea borrarlos? S/N",
					"Error.Reingrese S/N") && ll_clear(pArrayListBook)==0)
			{
				FILE *pFile=fopen(path,"rb");
				if(parser_bookFromBinary(pFile,pArrayListBook)!=0 && pFile!=NULL)
				{
					printf("No se pudo leer el archivo\n");
				}
				else
				{
					printf("Archivo leido y cerrado correctamente\n");
				}
				fclose(pFile);
			}
		}
	return retorno;
}

/** \brief Listar Libros
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_ListBook(LinkedList* pArrayListBook)
{
	int retorno = 1;
		eLibro* pAuxLibro=NULL;
		int auxId;
		int auxEditId;
		int auxPrecio;
		char auxAutor[128];
		char auxTitulo[128];
		char auxEditorialStr[128];
		int cantLinkedList;

		if(pArrayListBook != NULL && ll_isEmpty(pArrayListBook)==0)
		{
			cantLinkedList=ll_len(pArrayListBook);
			printf("| ID   |			TITULO				|	AUTOR	|	ID EDITORIAL	|    PRECIO	|\n");
			for(int i=0; i<cantLinkedList ; i++)
			{
				pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
				if(book_getId(pAuxLibro, &auxId)==0 ||
				   book_getTitulo(pAuxLibro, auxTitulo)==0 ||
				   book_getAutor(pAuxLibro, auxAutor)==0 ||
				   book_getPrecio(pAuxLibro, &auxPrecio)==0 ||
				   book_getEditorialId(pAuxLibro, &auxEditId)==0 ||
				   book_IdToEditorial(auxEditId, auxEditorialStr)==0)
				{
					retorno=-1;
					printf("Error, al imprimir lista");
					break;
				}else{
					printf("|%5d |%48s	|%15s|%15s	|%10d	|\n",auxId ,auxTitulo ,auxAutor ,auxEditorialStr ,auxPrecio);
					retorno = 0;
				}
			}

		}else{
			printf("No hay lista para imprimir\n");
		}
	return retorno;
}

/** \brief Ordenar Libros
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_sortBook(LinkedList* pArrayListBook)
{
	int retorno=0;
		int option;
		int(*pCritOrden)(void*,void*);

		if(pArrayListBook!=NULL)
		{
			utn_getNumero(&option, "\t|***ORDENAMIENTO***|"
					"\n1. Id"
					"\n2. Titulo "
					"\n3. Autor "
					"\n4. Precio"
					"\n5. Id Editorial",
					"Error, opcion incorrecta\n", 1, 4, 2);
			switch(option)
			{
				case 1:
					pCritOrden=book_sortId;
					utn_getNumero(&option, "\t|***INGRESE CRITERIO***|\n"
										"1. Descendente(30-1)\n"
										"0. Ascendente(1-30) \n",
										"Error, opcion incorrecta", 0, 1, 2);
					break;
				case 2:
					pCritOrden=book_sortTitulo;
					utn_getNumero(&option, "\t|***INGRESE CRITERIO***|\n"
										"0. Descendente(Z-A)\n"
										"1. Ascendente(A-Z) \n",
										"Error, opcion incorrecta", 0, 1, 2);
					break;
				case 3:
					pCritOrden=book_sortAutor;
					utn_getNumero(&option, "\t|***INGRESE CRITERIO***|\n"
										"0. Descendente(Z-A)\n"
										"1. Ascendente(A-Z) \n",
										"Error, opcion incorrecta", 0, 1, 2);
					break;
				case 4:
					pCritOrden=book_sortPrecio;
					utn_getNumero(&option, "\t|***INGRESE CRITERIO***|\n"
											"1. Descendente(Mayor a Menor)\n"
											"0. Ascendente(Menor a Mayor) \n",
											"Error, opcion incorrecta", 0, 1, 2);
					break;
				case 5:
					pCritOrden=book_sortEditId;
					utn_getNumero(&option, "\t|***INGRESE CRITERIO***|\n"
											"1. Descendente(6-1)\n"
											"0. Ascendente(1-6) \n",
											"Error, opcion incorrecta", 0, 1, 2);
					break;
			}

			ll_sort(pArrayListBook, pCritOrden, option);
			retorno=1;
		}
	    return retorno;
}


/** \brief Guarda los datos de los Libros en el archivo Datos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBook)
{
	int retorno = 0;
	int cantLinkedList;
	char auxTitulo[128];
	char auxAutor[128];
	char auxEditIdStr[128];
	int auxEditId;
	int auxId;
	int auxPrecio;
	FILE* pFile;

	eLibro* pAuxLibro=NULL;
	if(path!=NULL && pArrayListBook!=NULL)
		{
			if((pFile=fopen(path,"w"))==NULL)
			{
				printf("No se pudo escribir el archivo\n");
			}
			else
			{
				cantLinkedList=ll_len(pArrayListBook);
				fprintf(pFile,"id,titulo,autor,precio,editorialId\n");
				for(int i=0; i<cantLinkedList; i++)
				{
					pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
					if(book_getId(pAuxLibro, &auxId) &&
					   book_getTitulo(pAuxLibro, auxTitulo) &&
					   book_getAutor(pAuxLibro, auxAutor) &&
					   book_getPrecio(pAuxLibro, &auxPrecio) &&
					   book_getEditorialId(pAuxLibro, &auxEditId) &&
					   book_IdToEditorial(auxEditId, auxEditIdStr))
					{
					   fprintf(pFile,"%d,%s,%s,%d,%s\n",auxId, auxTitulo,auxAutor,auxPrecio, auxEditIdStr);
					   retorno=1;
					}
				}
				printf("Archivo escrito y guardado correctamente\n");
			}
			fclose(pFile);
		}
	return retorno;
}

/** \brief Guarda los datos de los Libros en el archivo Datos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */

int controller_decreaseSalary(LinkedList* pArrayListBook)
{
	int retorno=0;

	if(pArrayListBook!=NULL)
	{
		ll_map(pArrayListBook,book_decreaseSalary);
		retorno=1;
	}
	return retorno;
}

//
///** \brief Alta de Libros
// *
// * \param path char*
// * \param pArrayListBook LinkedList*
// * \return int
// *
// */
//int controller_addBook(LinkedList* pArrayListBook)
//{
//	int retorno=0;
//		eLibro* pAuxLibro=NULL;
//		int auxId;
//		char auxTitulo[128];
//		int auxEditId;
//		int auxPrecio;
//		int respuesta;
//		if(pArrayListBook!=NULL && ll_isEmpty(pArrayListBook))
//		{
//
//				if(validate_Exit_SN("\t CARGA DE DATOS!\n"
//						"Desea inicializar un Id o generar un Id propio ? S/N \n","Error.Reingrese S/N"))
//				{
//					utn_getNumero(&respuesta, "Elegir una opcion: \n"
//							"1. Crear una nueva lista inicializando el ID en 1.\n"
//							"2. Inicializar el ID en otro numero.\n","Error, reingrese opcion. \n", 1, 2, 1);
//						switch(respuesta)
//						{
//							case 1:
//								auxId=1;
//								break;
//							case 2:
//								utn_getNumero(&auxId, "En que numero quiere inicializar el ID?\n", "Error, ingrese valor numerico\n", 1, 100000000, 2);
//								break;
//						}
//						pAuxLibro=book_new();
//						if(pAuxLibro!=NULL)
//						{
//							if(utn_getNombre(auxTitulo, "Ingrese Titulo del Libro", "Error ingrese Titulo valido\n", 2, 128)==0 &&
//							   utn_getNumero(&auxEditId, "Ingrese ID EDITORIAL", "Error ingrese numero valido, maximo 745\n", 0, 745, 2)==0 &&
//							   utn_getNumero(&auxPrecio, "Ingrese Precio", "Error ingrese numero valido, maximo 999999\n", 0, 999999, 2)==0)
//							{
//								if(book_setId(pAuxLibro, auxId)==0 &&
//								   book_setTitulo(pAuxLibro, auxTitulo)==0 &&
//								   book_setEditorialId(pAuxLibro, auxEditId)==0 &&
//								   book_setPrecio(pAuxLibro, auxPrecio)==0)
//								{
//									ll_add(pArrayListBook, pAuxLibro);
//									book_print(pAuxLibro);
//									printf("Carga exitosa\n");
//									retorno=0;
//								}
//								else
//								{
//									printf("Error al cargar Libro\n");
//								}
//							}
//						}
//					}else{
//						auxId=controller_getMaxId(pArrayListBook);
//						pAuxLibro=book_new();
//
//						if(pAuxLibro!=NULL)
//						{
//							if(utn_getNombre(auxTitulo, "Ingrese Titulo del Libro", "Error, ingrese Titulo valido\n", 2, 128)==0 &&
//							   utn_getNumero(&auxEditId, "Ingrese ID EDITORIAL", "Error ingrese numero valido, maximo 745\n", 0, 745, 2)==0 &&
//							   utn_getNumero(&auxPrecio, "Ingrese Precio", "Error numero valido, maximo 999999", 0, 999999, 2)==0)
//							{
//							if(book_setId(pAuxLibro, (auxId+1))==0 &&
//							   book_setTitulo(pAuxLibro, auxTitulo)==0 &&
//							   book_setEditorialId(pAuxLibro, auxEditId)==0 &&
//							   book_setPrecio(pAuxLibro, auxPrecio)==0)
//							{
//								ll_add(pArrayListBook, pAuxLibro);
//								book_print(pAuxLibro);
//								printf("Carga exitosa\n");
//								retorno=0;
//							}else{
//								printf("Error al cargar Libro\n");
//							}
//						}
//					}
//				}
//			}
//		return retorno;
//}
//
///** \brief Busca Id Maximo
// *
// * \param path char*
// * \param pArrayListBook LinkedList*
// * \return int
// *
// */
//int controller_getMaxId(LinkedList* pArrayListBook)
//{
//	int retorno=-1;
//	int cantidadLinkedList;
//	int id;
//
//	eLibro* pAuxLibro=NULL;
//	if(pArrayListBook!=NULL && ll_isEmpty(pArrayListBook)==0)
//	{
//		cantidadLinkedList=ll_len(pArrayListBook);
//		for(int i=0; i<cantidadLinkedList ; i++)
//		{
//			pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
//			book_getId(pAuxLibro, &id);
//			if(id>retorno)
//			{
//				retorno=id;
//			}
//		}
//	}
//	return retorno;
//}
//
///** \brief Modificar datos de Libro
// *
// * \param path char*
// * \param pArrayListBook LinkedList*
// * \return int
// *
// */
//
//int controller_editBook(LinkedList* pArrayListBook)
//{
//
//		eLibro* pAuxLibro=NULL;
//		int cantLinkedList;
//		int auxId;
//		int auxEditId;
//		int auxPrecio;
//		int id;
//		int auxInt;
//		char auxTitulo[128];
//		int numMax=0;
//		int retorno=0;
//
//		if(pArrayListBook!=NULL && ll_isEmpty(pArrayListBook)==0)
//		{
//			cantLinkedList=ll_len(pArrayListBook);
//			for(int i=0; i<cantLinkedList ; i++)
//			{
//				pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
//				book_getId(pAuxLibro, &auxId);
//				if(auxId>numMax)
//				{
//					numMax=auxId;
//				}
//			}
//			utn_getNumero(&id, "Ingrese Id de persona a modificar", "Error, reingrese valor numerico", 0, auxId, 2);
//			for(int i=0; i<cantLinkedList ; i++)
//			{
//				pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
//				book_getId(pAuxLibro, &auxId);
//				if(auxId==id)
//				{
//					puts("|***Libro***|\n");
//					book_print(pAuxLibro);
//					if(validate_Exit_SN("\n Desea modificar este Libro?\n","Error, reingrese."))
//					{
//						utn_getNumero(&auxInt, "|***MODIFICAR***|\n1. Titulo \n2. ID EDITORIAL \n3. Precio", "Error, opcion incorrecta", 1, 3, 2);
//						switch(auxInt)
//						{
//							case 1:
//								if((utn_getNombre(auxTitulo, "Ingrese Titulo del Libro\n", "Error, muy largo", 2, 128)==0) &&
//								  (book_setTitulo(pAuxLibro, auxTitulo)==0))
//								{
//									printf("Datos modificados correctamente\n");
//									book_print(pAuxLibro);
//								}
//								break;
//							case 2:
//								if((utn_getNumero(&auxEditId, "Ingrese ID EDITORIAL\n", "Error, maximo 100000", 0, 100000, 2)==0) &&
//								   (book_setEditorialId(pAuxLibro, auxEditId)==0))
//								{
//									printf("Datos modificados correctamente\n");
//									book_print(pAuxLibro);
//								}
//								break;
//							case 3:
//								if((utn_getNumero(&auxPrecio, "Ingrese Precio\n", "Error, maximo 999999", 0, 999999, 2)==0) &&
//								   (book_setPrecio(pAuxLibro, auxPrecio)==0))
//								{
//									printf("Datos modificados correctamente\n");
//									book_print(pAuxLibro);
//								}
//								break;
//						}
//						retorno=1;
//					}
//				}
//			}
//		}
//		return retorno;
//}
//
///** \brief Baja de Libro
// *
// * \param path char*
// * \param pArrayListBook LinkedList*
// * \return int
// *
// */
//int controller_removeBook(LinkedList* pArrayListBook)
//{
//	int retorno=0;
//		eLibro* pAuxLibro=NULL;
//		int cantLinkedList;
//		int auxId;
//		int id;
//		int i;
//		int numMax=0;
//
//		if(pArrayListBook!=NULL && ll_isEmpty(pArrayListBook)==0)
//		{
//			cantLinkedList=ll_len(pArrayListBook);
//			for(int i=0; i<cantLinkedList ; i++)
//			{
//				pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
//				book_getId(pAuxLibro, &auxId);
//				if(auxId>numMax)
//				{
//					numMax=auxId;
//				}
//			}
//			utn_getNumero(&id, "Ingrese Id de persona a borrar", "Error, ingrese valor numerico", 0, auxId, 2);
//			for(i=0; i<cantLinkedList ; i++)
//			{
//				pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
//				book_getId(pAuxLibro, &auxId);
//				if(auxId==id)
//				{
//					printf("Desea borrar este Libro?\n");
//					book_print(pAuxLibro);
//					if(validate_Exit_SN("Desea modificar este Libro?\n","ERROR REINGRESE."))
//					{
//						if(ll_remove(pArrayListBook, i)==0)
//						{
//							printf("Operación exitosa!\n");
//							retorno=1;
//							break;
//						}
//					}
//				}
//			}
//		}
//	    return retorno;
//}
///** \brief Guarda los datos de los Libros en el archivo Datos.csv (modo binario).
// *
// * \param path char*
// * \param pArrayListBook LinkedList*
// * \return int
// *
// */
//int controller_saveAsBinary(char* path , LinkedList* pArrayListBook)
//{
//	int retorno = 0;
//	int auxCantLink, retornoLeido;
//	FILE* pFile=NULL;
//	eLibro* pAuxLibro=NULL;
//
//		if(path!=NULL && pArrayListBook!=NULL)
//		{
//			if((pFile=fopen(path,"wb"))==NULL)
//			{
//				printf("No se pudo escribir el archivo\n");
//			}
//			else
//			{
//				auxCantLink=ll_len(pArrayListBook);
//				for(int i=0; i<auxCantLink; i++)
//				{
//					pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
//					retornoLeido=fwrite(pAuxLibro, sizeof(eLibro),1,pFile);
//					if(retornoLeido!=1)
//					{
//						book_delete(pAuxLibro);
//						break;
//						retorno=-1;
//					}
//					else
//					{
//						retorno=1;
//						printf("Archivo escrito y guardado correctamente\n");
//					}
//				}
//			}
//			fclose(pFile);
//		}
//	    return retorno;
//}
//
//void controller_chooseLoadText(int flagChoose,LinkedList* list)
//{
//	utn_getNumero(&flagChoose, "Elija opcion a abrir: \n"
//			"1. data.csv \n"
//			"2. Chequeo.csv\n",
//			"Error, opcion incorrecta", 1, 2, 1);
//		switch(flagChoose)
//		{
//		case 1:
//			controller_loadFromText("data.csv",list);
//			break;
//		case 2:
//			controller_loadFromText("Chequeo.csv",list);
//			break;
//		}
//}
//
//void controller_chooseLoadBin(int flagChoose,LinkedList* list)
//{
//	utn_getNumero(&flagChoose, "Elija opcion a abrir: \n"
//			"1. Datos.bin \n"
//			"2. Chequeo.bin \n",
//			"Error, opcion incorrecta", 1, 2, 1);
//		switch(flagChoose)
//		{
//		case 1:
//			controller_loadFromBinary("data.bin",list);
//			break;
//		case 2:
//			controller_loadFromBinary("Chequeo.bin",list);
//			break;
//		}
//}
//
//EXTRA TP4


