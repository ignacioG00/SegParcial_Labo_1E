/*
 * 	UTN.c
 *	TRABAJO PRACTICO N?4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#include "eLibro.h"
#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


eLibro* book_new(void)
{
	eLibro* auxiliarP = NULL;
	auxiliarP = (eLibro*) malloc(sizeof(eLibro));
	return auxiliarP;
}
/**
 * brief Nueva estructura de Libros ingresando los valores por parametros.
 * param idStr parametro que recibe el ID a cargar.
 * param tituloStr recibe el titulo del libro.
 * param autorStr  recibe el nombre del autor.
 * param precioStr  recibe el precio del libro.
 * param editorialIdStr recibe la editorial.
 * return this retorna el Libro auxiliar con los datos que se recibieron por parametro, caso contrario retorna NULL.
 *
 */
eLibro* book_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr)
{
	eLibro* pAuxLibro = book_new();
	int auxId;
	if(pAuxLibro!=NULL && idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && editorialIdStr!=NULL)
	{
		if((book_setId(pAuxLibro,atoi(idStr))!=1) ||
		(book_setTitulo(pAuxLibro,tituloStr)!=1) ||
		(book_setAutor(pAuxLibro,autorStr)!=1) ||
		(book_setPrecio(pAuxLibro,atoi(precioStr))!=1) ||
		(book_EditorialToId(&auxId, editorialIdStr)!=1) ||
		(book_setEditorialId(pAuxLibro, auxId)!=1))
		{
			free(pAuxLibro);
			pAuxLibro=NULL;
		}
	}
	return pAuxLibro;
}

void book_delete(eLibro* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
/**
 * brief Obtiene el titulo del Libro de la estructura eLibro.
 * param this puntero a eLibro.
 * param titulo puntero a la cadena titulo del eLibro
 * return retorna 1 Si pudo obtener el titulo y 0 si no pudo obtener
 *
 */

int book_setTitulo(eLibro* this,char* titulo)
{
	int retorno = 0;

	if(this != NULL && titulo != NULL)
	{
			retorno = 1;
			strcpy(this->titulo,titulo);
	}
	return retorno;
}
/** \brief Coloca el titulo del Libro en una estructura Libro.
 *
 * param this puntero a Libro.
 * param titulo cadena que se colocara el titulo del Libro
 * return retorna 1 si se pudo colocar el titulo, y 0 si no se coloco
 *
 */
int book_getTitulo(eLibro* this,char* titulo)
{
	int retorno = 0;

	if(this != NULL && titulo != NULL)
	{
		retorno = 1;
		strncpy(titulo,this->titulo,TITULO_LEN);
	}
	return retorno;
}
/**
 * brief Obtiene el autor del Libro de la estructura eLibro.
 * param this puntero a eLibro.
 * param autor puntero a la cadena autor del eLibro
 * return retorna 1 Si pudo obtener el autor y 0 si no pudo obtener
 *
 */
int book_setAutor(eLibro* this,char* autor)
{
	int retorno = 0;

	if(this != NULL && autor != NULL)
	{
			retorno = 1;
			strcpy(this->autor,autor);
	}
	return retorno;
}
/** \brief Coloca el autor del Libro en una estructura Libro.
 *
 * param this puntero a Libro.
 * param autor cadena que se colocara el autor del Libro
 * return retorna 1 si se pudo colocar el autor, y 0 si no se coloco
 *
 */
int book_getAutor(eLibro* this,char* autor)
{
	int retorno = 0;

	if(this != NULL && autor != NULL)
	{
		retorno = 1;
		strcpy(autor,this->autor);
	}
	return retorno;
}

/**
 * brief Obtiene el id del Libro de la estructura eLibro.
 * param this puntero a eLibro.
 * param id puntero a la cadena autor del eLibro
 * return retorna 1 Si pudo obtener el id y 0 si no pudo obtener
 *
 */
int book_setId(eLibro* this,int id)
{
	int retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		this->id = id;
	}
	return retorno;
}
/** \brief Coloca el id del Libro en una estructura Libro.
 *
 * param this puntero a Libro.
 * param id cadena que se colocara el id del Libro
 * return retorna 1 si se pudo colocar el id, y 0 si no se coloco
 *
 */
int book_getId(eLibro* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		retorno = 1;
		*id = this->id;
	}
	return retorno;
}

/**
 * brief Obtiene el precio del Libro de la estructura eLibro.
 * param this puntero a eLibro.
 * param precio puntero a la cadena autor del eLibro
 * return retorna 1 Si pudo obtener el precio y 0 si no pudo obtener
 *
 */

int book_setPrecio(eLibro* this,int precio)
{
	int retorno=0;

	if(this!=NULL && precio>-1)
	{
		this->precio=precio;
		retorno=1;
	}
	return retorno;
}
/** \brief Coloca el precio del Libro en una estructura Libro.
 *
 * param this puntero a Libro.
 * param precio cadena que se colocara el precio del Libro
 * return retorna 1 si se pudo colocar el precio, y 0 si no se coloco
 *
 */
int book_getPrecio(eLibro* this,int* precio)
{
	int retorno=0;

	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		retorno=1;
	}
	return retorno;
}

/**
 * brief Obtiene el editorialId del Libro de la estructura eLibro.
 * param this puntero a eLibro.
 * param editorialId puntero a la cadena editorialId del eLibro
 * return retorna 1 Si pudo obtener el editorialId y 0 si no pudo obtener
 *
 */
int book_setEditorialId(eLibro* this,int editorialId)
{
	int retorno=0;
	if(this!=NULL)
	{
		this->editorialId=editorialId;
		retorno=1;
	}
	return retorno;
}

/** \brief Coloca el id del editorial del Libro en una estructura Libro.
 *
 * param this puntero a Libro.
 * param editorialId cadena que se colocara el editorialId del Libro
 * return retorna 1 si se pudo colocar el editorialId, y 0 si no se coloco
 *
 */
int book_getEditorialId(eLibro* this,int* editorialId)
{
	int retorno=0;
	if(this!=NULL && editorialId!=NULL)
	{
		*editorialId=this->editorialId;
		retorno=1;
	}
	return retorno;
}

int book_EditorialToId(int* id, char* editorialId)
{
	int retorno=0;
	if(editorialId!=NULL && id!=NULL)
	{
		retorno=1;
		if(stricmp(editorialId,"planeta")==0)
		{
			*id=1;
		}
		if(stricmp(editorialId,"siglo xxi editores")==0)
		{
			*id=2;
		}
		if(stricmp(editorialId,"pearson")==0)
		{
			*id=3;
		}
		if(stricmp(editorialId,"minotauro")==0)
		{
			*id=4;
		}
		if(stricmp(editorialId,"salamandra")==0)
		{
			*id=5;
		}
		if(stricmp(editorialId,"penguin books")==0)
		{
			*id=6;
		}
	}
	return retorno;
}

int book_IdToEditorial(int id, char* editorialIdStr)
{
	int retorno=0;
	if(editorialIdStr!=NULL && id>0 && id<7)
	{
		retorno=1;
		switch(id)
		{
		case 1:
			strcpy(editorialIdStr,"planeta");
			break;
		case 2:
			strcpy(editorialIdStr,"siglo xxi editores");
			break;
		case 3:
			strcpy(editorialIdStr,"pearson");
			break;
		case 4:
			strcpy(editorialIdStr,"minotauro");
			break;
		case 5:
			strcpy(editorialIdStr,"salamandra");
			break;
		case 6:
			strcpy(editorialIdStr,"penguin books");
			break;
		}
	}
	return retorno;
}

int book_sortPrecio(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int auxPrecioOne;
	int auxPrecioTwo;

	if(thisOne!=NULL && thisTwo!=NULL && book_getPrecio((eLibro*)thisOne, &auxPrecioOne)
			&& book_getPrecio((eLibro*)thisTwo, &auxPrecioTwo))
	{
			if(auxPrecioOne < auxPrecioTwo)
			{
				retorno=1;
			}
			if(auxPrecioOne > auxPrecioTwo)
			{
				retorno=-1;
			}
	}
	return retorno;
}

int book_sortEditId(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int auxEditIDOne;
	int auxEditIDTwo;

	if(thisOne!=NULL && thisTwo!=NULL && book_getEditorialId((eLibro*)thisOne, &auxEditIDOne)
			&& book_getEditorialId((eLibro*)thisTwo, &auxEditIDTwo))
	{
			if(auxEditIDOne < auxEditIDTwo)
			{
				retorno=1;
			}
			if(auxEditIDOne > auxEditIDTwo)
			{
					retorno=-1;
			}
	}
	return retorno;
}

int book_sortTitulo(void* thisOne, void* thisTwo)
{
	int retorno=0;
	char auxTituloOne[128];
	char auxTituloTwo[128];

	if(thisOne!=NULL && thisTwo!=NULL && book_getTitulo((eLibro*)thisOne, auxTituloOne)
			&& book_getTitulo((eLibro*)thisTwo, auxTituloTwo))
	{
			if(strcmp(auxTituloOne,auxTituloTwo)>0)
			{
				retorno=1;
			}
			if(strcmp(auxTituloOne,auxTituloTwo)<0)
			{
				retorno=-1;
			}
	}
	return retorno;
}

int book_sortAutor(void* thisOne, void* thisTwo)
{
	int retorno=0;
	char auxAutorOne[128];
	char auxAutorTwo[128];

	if(thisOne!=NULL && thisTwo!=NULL && book_getTitulo((eLibro*)thisOne, auxAutorOne)
			&& book_getTitulo((eLibro*)thisTwo, auxAutorTwo))
	{
			if(strcmp(auxAutorOne,auxAutorTwo)>0)
			{
				retorno=1;
			}
			if(strcmp(auxAutorOne,auxAutorTwo)<0)
			{
				retorno=-1;
			}
	}
	return retorno;
}

int book_sortId(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int auxIdOne;
	int auxIdTwo;

	if(thisOne!=NULL && thisTwo!=NULL && book_getId((eLibro*)thisOne, &auxIdOne)
			&& book_getId((eLibro*)thisTwo, &auxIdTwo))
	{
			if(auxIdOne < auxIdTwo)
			{
				retorno=1;
			}
			if(auxIdOne > auxIdTwo)
			{
				retorno=-1;
			}
	}
	return retorno;
}

void book_print(eLibro* this)
{
	int auxEditID;
	int auxId;
	int auxPrecio;
	char auxTitulo[128];

		if(book_getId(this, &auxId) && book_getTitulo(this, auxTitulo) &&
		   book_getEditorialId(this, &auxEditID) && book_getPrecio(this, &auxPrecio))
		{
			printf("|ID|> %d - |TITULO|> %s - |ID DE EDITORIAL|> %d - |PRECIO|> %d\n",auxId, auxTitulo,auxEditID,auxPrecio);
		}
}


int book_decreaseSalary(void *empleadoRecibido)
{
	int retorno=0;
	int auxPrecio;
	char auxEditStr[128];
	 if(empleadoRecibido!=NULL)
	 {
		 auxPrecio=(*(eLibro*)(empleadoRecibido)).precio;
		 book_IdToEditorial((*(eLibro*)(empleadoRecibido)).editorialId,auxEditStr);
		 if(strcmp(auxEditStr,"planeta")==0 && auxPrecio>299)
		 {
			 auxPrecio=auxPrecio-(auxPrecio*20/100);
			 (*(eLibro*)(empleadoRecibido)).precio=auxPrecio;
		 }else{
			 if(strcmp(auxEditStr,"siglo xxi editores")==0 && auxPrecio<201)
			 {
				auxPrecio=auxPrecio-(auxPrecio*10/100);
				(*(eLibro*)(empleadoRecibido)).precio=auxPrecio;
			 }
		 }
		 retorno=1;
	 }
	 return retorno;
}
