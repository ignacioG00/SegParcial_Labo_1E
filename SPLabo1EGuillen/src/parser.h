/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_bookFromText(FILE* pFile , LinkedList* pArrayListBook);
int parser_bookFromBinary(FILE* pFile , LinkedList* pArrayListBook);
int parser_bookToBinary(FILE* pFile , LinkedList* pArrayListBook);
int parser_bookToText(FILE* pFile , LinkedList* pArrayListBook);

#endif /* PARSER_H_ */
