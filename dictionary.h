#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAIN_ENTITY_POINTER 0
#define EMPTY_POINTER -1
#define DATA_BLOCK_SIZE 50

typedef struct Entity{
    char name[DATA_BLOCK_SIZE]; 
    long dataPointer; 
    long attributesPointer; 
    long nextEntity; 
} ENTITY; 

typedef struct Attribute {
    char name[DATA_BLOCK_SIZE]; 
    bool isPrimary; 
    long type; 
    long size; 
    long nextAttribute;
} ATTRIBUTE;

//FILE* initializeDataDictionary(const char *dictionaryName);
FILE* initializeDataDictionary(const char *dictionaryName, const char *mode);//Inicializa un nuevo diccionario

int appendEntity(FILE* dataDicictionary, ENTITY newEntity); //Agrega una nueva entidad
void reorderEntities(FILE* dataDictionary, long currentEntityPointer, const char* newEntityName, long newEntityDirection); //Oredena las entidades alfabeticamente
void createEntity(FILE* dataDictionary);//Crea una entidad para agregar al diccionario

int appendAttribute(FILE* dataDictionary, ATTRIBUTE newAttribute); //Agrega el atributo a  la entidad a la que pertenece
void reorderAttributes(FILE* dataDictionary, long currentAttributePointer, const char* newAttributeName, long newAttributeDirection);//Ordena los atributos alfabeticamenete
void attributeSize(ATTRIBUTE newAtribute);//Calcula el tamaño de los atributos 
void createAttribute(FILE* dataDictionary, ENTITY currentEntity);//Crea un atributo para una entidad

ENTITY removeEntity(FILE* dataDictionary, long currentEntityPointer, const char* entityName); //Elimina una entidad
ATTRIBUTE removeAttribute(FILE *dataDictionary, long currentAttributePointer, const char* attributeName);//Elimina un atributo de la entidad seleccionada

void captureEntities(FILE* dataDictionary);//Capura una entidad mientras el ususario quiera 
ENTITY searchEntityByName(FILE* dataDictionary, const char* entityName);//Busca una entidad por el nombre
void showEntities(FILE* dataDictionary);//Muestra solo la lista de entidades 

void captureAttributes(FILE* dataDictionary, ENTITY currentEntity); //Captura un atributo para una entidad
void showAttributes(FILE* dataDictionary, long attributesPointer); //Muestra los atributos de una entidad
ATTRIBUTE searchAttributeByName(FILE* dataDictionary, long attributesPointer, const char* attributeName);//Busca un atributo por nombre

void deleteEntity(FILE* dataDictionary); //Funcion auxiliar para eliminar una entitdad
void deleteAttribute(FILE* dataDictionary); //Funcion auxiliar para eliminar un atributo


void mainMenu();//Menu principal del diccionario (Abrir/Iniciar/Salir)
void entityMenu(FILE* dataDictionary);//Menu para las entidades
void attributeMenu(FILE* dataDictionary);//Menu para los atributos de una entidad
void selectionEntitiesAttributes(FILE* dataDictionary);//Menu que muestra los menus de entidades y atributos 


#endif
