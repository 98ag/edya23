#ifndef __SLISTS_H__
#define __SLISTS_H__

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

struct _SListS {
  SNodo *primero;
  SNodo *ultimo;
};

typedef struct _SListS *SListS;

/**
 *
 */
SListS slists_crear();

/**
 * 
 */
void slists_agregar_inicio(SListS lista, int dato);

/**
 * 
 */
void slists_agregar_final(SListS lista, int dato);

/**
 * 
 */
void slists_imprimir(SListS lista);

/**
 * 
 */
void slists_destruir(SListS lista);
#endif