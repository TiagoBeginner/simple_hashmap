#include "hash.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

keysize_t getHashKey(char *string) {
	char *ptr;
	keysize_t hash;
	keysize_t i;
	
	// Piccola hack per velocizzare il loop dei caratteri
	ptr = string;
	for (i = 0;
		*ptr && i < MAX_KEY_LENGHT;
		++ptr) {
		hash += *ptr * i;
		++i;
	}
	if (i >= MAX_KEY_LENGHT)
		return 0;
	return hash;
}

void newMap(map *m) {
	*m = (map) {
		.ptr = malloc(sizeof(*m->ptr) * UINT16_MAX),
	};
}

void closeMap(map *m) {
	free(m->ptr);
	*m = (map) {
		.ptr = NULL,
	};
}

void modifyMapElement(map *m, char *key, int32_t element) {
	if (m->ptr)
		m->ptr[getHashKey(key)] = element;
}

int32_t getMapElement(map m, char *key) {
	return (m.ptr) ? m.ptr[getHashKey(key)] : 0;

}
