#include "map.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

size_t hash(char *key) {
	size_t hash;
	int16_t i;

	hash = 0;
	while (*key || i < MAX_KEY_LENGHT) {
		hash += 5 * (*key + 14) % 0x345f;
		++key;
	}

	return hash;
}

size_t hash_val(map_t m, char *key) {
	return hash(key) % m.lenght;
}

// Copies from p2 to p1
static void copy_bytes(void *p1, void *p2, size_t bytes) {
	for (int i = 0; i < bytes; ++i) {
		((char*)p1)[i] = ((char*)p2)[i];
	}
}

map_t new_map() {
	return (map_t) {
		.ptr = NULL,
		.lenght = 0
	};
}

#define key (m->ptr[i].key)
void close_map(map_t *m) {
	if (m->ptr) {
		for (size_t i = 0; i < m->lenght; ++i)
			free(key);
		free(m->ptr);
	}

	*m = (map_t) {
		.ptr = NULL,
		.lenght = 0
	};
}
#undef key

void append_map(map_t *restrict m, char *restrict key, value_t value) {
	struct map_element *new_table;
	
	++m->lenght;
	new_table = malloc(m->lenght * sizeof(*new_table));
	
	#define OLD_KEY m->ptr[i].key
	#define NEW_KEY new_table[new_hash].key
	for (int i = 0; i < m->lenght; ++i) {
		size_t new_hash;
		
		do {
			new_hash = hash_val(*m, OLD_KEY);
			copy_bytes(OLD_KEY, new_hash, (strlen(OLD_KEY) + 1 > sizeof(new_hash)) ? sizeof(new_hash) : strlen(OLD_KEY));
		} while (NEW_KEY);
		
		NEW_KEY = OLD_KEY;
		new_table[new_hash].value = m->ptr[i].value;
	}
	#undef OLD_KEY
	#undef NEW_KEY
	
	free(m->ptr);
	m->ptr = new_table;
}

value_t pop_map(map_t *restrict m, char *key) {
	size_t hash_code;
	value_t retval;
	
	// Find the key
	do
		hash_code = hash_val(*m, key);
	while (!strncmp(key, m->ptr[hash_code].key, MAX_KEY_LENGHT));
	
	// Copy it
	retval = m->ptr[hash_code].value;
	
	// Shift it
	#define KEY			(m->ptr[i].key)
	#define VAL			(m->ptr[i].value)
	#define NXT_KEY		(m->ptr[i + 1].key)
	#define NXT_VAL		(m->ptr[i + 1].value)
	for (size_t i = hash_code; i < m->lenght - 1; ++i) {
		KEY = realloc(KEY, sizeof(*KEY) * strlen(NXT_KEY));
		strcpy(KEY, NXT_KEY);
		VAL = NXT_VAL;
	}
	#undef KEY
	#undef VAL
	#undef NXT_KEY
	#undef NXT_VAL
	
	// Free it
	free(m->ptr[m->lenght - 1].key);
	--m->lenght;
	
	// Resize it
	m->ptr = realloc(m->ptr, sizeof(*m->ptr) * m->lenght);
	
	return retval;
}

void change_map(map_t m, char *key, value_t new_value) {
	size_t code;
	
	do
		code = hash_val(m, key);
	while (!strncmp(key, m.ptr[code].key, MAX_KEY_LENGHT));
	
	m.ptr[code].value = new_value;
}

value_t get_map(map_t m, char *key) {
	size_t hash_code;
	
	do {
		hash_code = hash_val(m, key);
	} while (!strncmp(key, m.ptr[hash_code].key, MAX_KEY_LENGHT));
	
	return m.ptr[hash_code].value;
}
