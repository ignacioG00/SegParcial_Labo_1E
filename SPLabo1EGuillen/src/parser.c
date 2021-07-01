/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Biblioteca.h"
#include "parser.h"
#include "eLibro.h"

/**
 *
 * \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int -1 error, 0 si esta ok
 *
 */

int parser_bookFromText(FILE* pFile , LinkedList* pArrayListBook)
{
		int retorno = -1;
		int retornoLeido;
		char buffer[5][128];
		eLibro* pAuxLibro=NULL;

		if(pFile!=NULL && pArrayListBook!=NULL)
		{
//		    printf("entro al parser");
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
			do
			{
				retornoLeido = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3], buffer[4]);
				//printf("Id: %s - Titulo: %s  - Autor: %s - Precio: %s - Editorial: %s\n",buffer[0],buffer[1],buffer[2],buffer[3], buffer[4]);
				if(retornoLeido<5)
				{
					book_delete(pAuxLibro);
					retorno=-1;
					break;
				}
				else
				{
					pAuxLibro = book_newParametros(buffer[0],buffer[1],buffer[2],buffer[3], buffer[4]);
					//printf("Id: %d - Titulo: %s  - Autor: %s - Precio: %d - Editorial: %d\n",pAuxLibro->id,pAuxLibro->titulo,pAuxLibro->autor,pAuxLibro->precio,pAuxLibro->editorialId);
					if(pAuxLibro!=NULL)
					{

						ll_add(pArrayListBook,pAuxLibro);
						retorno=0;
					}
				}
			}while(!feof(pFile));
		}

    return retorno;
}

/**
 *
 * \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int -1 error, 0 si esta ok
 *
 */

int parser_bookFromBinary(FILE* pFile , LinkedList* pArrayListBook)
{
	int retorno = -1;
	int retornoLeido;
	eLibro* pAuxLibro=NULL;

		if(pFile!=NULL && pArrayListBook!=NULL)
		{
		do{
			pAuxLibro=book_new();
			if(pAuxLibro!=NULL)
			{
				retornoLeido = fread(pAuxLibro,sizeof(eLibro),1,pFile);
				if(retornoLeido!=1)
				{
					book_delete(pAuxLibro);
					break;
				}
				else
				{
					ll_add(pArrayListBook,pAuxLibro);
					retorno=0;
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}
//
///**
// *
// * \brief pasa los datos del archivo a modo binario.
// * \param path char*
// * \param pArrayListBook LinkedList*
// * \return int -1 error, 0 si esta ok, 1 borra el empleado existente
// *
// */
//
//int parser_bookToBinary(FILE* pFile , LinkedList* pArrayListBook)
//{
//	int retorno = -1;
//	int retornoLeido;
//	int auxCantLink;
//	eLibro* pAuxLibro=NULL;
//	if(pFile!=NULL && pArrayListBook!=NULL)
//	{
//		auxCantLink=ll_len(pArrayListBook);
//		for(int i=0; i<auxCantLink; i++)
//		{
//			pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
//			retornoLeido=fwrite(pAuxLibro, sizeof(eLibro),1,pFile);
//			if(retornoLeido!=1)
//			{
//				book_delete(pAuxLibro);
//				break;
//				retorno=-1;
//			}
//			else
//			{
//				retorno=0;
//			}
//		}
//	}
//	return retorno;
//}
//
///**
// *
// * \brief pasa los datos del archivo a modo texto.
// * \param path char*
// * \param pArrayListBook LinkedList*
// * \return int 0 error, 1 si esta ok
// *
// */
//int parser_bookToText(FILE* pFile , LinkedList* pArrayListBook)
//{
//	int retorno=0;
//	int auxCantLink;
//	eLibro* pAuxLibro=NULL;
//	int auxId, auxPrecio, auxEditId;
//	char auxTitulo[128];
//	char auxAutor[51];
//
//	if(pFile!=NULL && pArrayListBook!=NULL)
//	{
//		auxCantLink=ll_len(pArrayListBook);
//		fprintf(pFile,"id,titulo,autor,precio,editorialId\n");
//		for(int i=0; i<auxCantLink; i++)
//		{
//			pAuxLibro = (eLibro*)ll_get(pArrayListBook, i);
//
//			if(book_getId(pAuxLibro, &auxId)==0 &&
//			   book_getTitulo(pAuxLibro, auxTitulo)==0 &&
//			   book_getAutor(pAuxLibro, auxAutor)==0 &&
//			   book_getPrecio(pAuxLibro, &auxPrecio)==0 &&
//			   book_getEditorialId(pAuxLibro, &auxEditId)==0)
//			{
//				fprintf(pFile,"%d, %s, %s, %d, %d\n",auxId, auxTitulo, auxAutor, auxPrecio,auxEditId);
//			}
//			retorno=1;
//		}
//
//	}
//	return retorno;
//}
