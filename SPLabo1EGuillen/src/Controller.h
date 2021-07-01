/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBook);
int controller_loadFromBinary(char* path , LinkedList* pArrayListBook);
int controller_addBook(LinkedList* pArrayListBook);
int controller_editBook(LinkedList* pArrayListBook);
int controller_removeBook(LinkedList* pArrayListBook);
int controller_ListBook(LinkedList* pArrayListBook);
int controller_sortBook(LinkedList* pArrayListBook);
int controller_saveAsText(char* path , LinkedList* pArrayListBook);
int controller_saveAsBinary(char* path , LinkedList* pArrayListBook);
int book_EditorialToId(int* id, char* editorialId);
int book_IdToEditorial(int id, char* editorialIdStr);

void controller_chooseLoadText(int flagChoose,LinkedList* list);
void controller_chooseLoadBin(int flagChoose,LinkedList* list);

int controller_getMaxId(LinkedList* pArrayListBook);

int controller_decreaseSalary(LinkedList* pArrayListBook);

