#ifndef HASH_H
#define HASH_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGHT		256

typedef uint16_t keysize_t;

typedef struct Map {
	int32_t *ptr;
} map;

/* Funzione Hash
 * Inizia tutto da qui
 * Se la stringa sorpassa il limite ritorna 0
 *
 */
keysize_t getHashKey(char *string);

// Gestione della mappa

/* Creatore per mappa hash
 * Per evitare allocazione manuale della memoria,
 * generatore del seme per la mappa.
 * Se la usi è consigliato chiamare la funzione closeMap()
 * quando non serve più
 *
 */
void newMap(map *map);
/* Distruttore per mappa hash
 * Dealloca risorse usate per la mappa
 *
 */
void closeMap(map *map);

// Elaborazione dei dati della mappa

/* Cambia elemento nella mappa in base alla chiave
 * Se la chiave non è valida il valore verrà scritto
 * all'indirizzo di ptr (quello default)
 *
 */
void modifyMapElement(map *m, char *key, int32_t element);
/* Ottieni elemento in base alla chiave
 * Se la chiave non è valida ottieni comportamento non definito (ti sta bene)
 * Se il puntatore, per qualche ragione, è NULL ritorna 0
 *
 */
int32_t getMapElement(map m, char *key);

#endif // HASH_H