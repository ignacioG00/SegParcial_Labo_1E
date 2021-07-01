/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#ifndef book_H_INCLUDED
#define book_H_INCLUDED
#define TITULO_LEN 128
#define AUTOR_LEN 128


typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    int precio;
    int editorialId;
}eLibro;

eLibro* book_new(void);

eLibro* book_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr);

void book_delete();

//SETTERS AND GETTERS
int book_setId(eLibro* this,int id);
int book_getId(eLibro* this,int* id);

int book_setTitulo(eLibro* this,char* titulo);
int book_getTitulo(eLibro* this,char* titulo);

int book_setAutor(eLibro* this,char* autor);
int book_getAutor(eLibro* this,char* autor);

int book_setPrecio(eLibro* this,int precio);
int book_getPrecio(eLibro* this,int* precio);


//EDITORIAL ID FUNCTIONS
int book_setEditorialId(eLibro* this,int sueldo);
int book_getEditorialId(eLibro* this,int* sueldo);
//PASSING ID TO STRING/STRING TO ID
int book_IdToEditorial(int id, char* editorialIdStr);
int book_EditorialToId(int* id, char* editorialId);

//SORT
int book_sortPrecio(void* thisOne, void* thisTwo);
int book_sortEditId(void* thisOne, void* thisTwo);
int book_sortTitulo(void* thisOne, void* thisTwo);
int book_sortAutor(void* thisOne, void* thisTwo);
int book_sortId(void* thisOne, void* thisTwo);

void book_print(eLibro* this);

//EXTRA tp4

int book_decreaseSalary(void *empleadoRecibido);

#endif // book_H_INCLUDED
