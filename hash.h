#ifndef MAP_H
#define MAP_H

// To avoid problems I comment it
// #include "operations.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_KEY_LENGHT		(256)

typedef int32_t value_t;

struct map_element {
	char *key;
	value_t value;
};

typedef struct map {
	map_element *ptr;
	size_t lenght;
} map_t;

/* Creates a fixed sise representation of the given string (max lenght 256)
 * @param key: A string used to encript the data
 * @return: A fixed size number which is the result of the encription of the string
 *
 */
size_t hash(char *key);
/* Transforms the result of the hash function for the map_t
 * @param m: the map_t for which we have to accomodate the hash
 * @param key: String used to encript the data
 *
 */
size_t hash_val(map_t m, char *key);

/* Creates hashmap and allocates resources for it
 * @return: a fresh empty new map_t
 *
 */
map_t new_map();
/* Frees allocated memory and set everything to 0
 * @param m: a pointer to the map_t whose resources need to be freed
 *
 */
void close_map(map_t *m);

// Adds new element to the map_t and sets its value
void append_map(map_t *m, char *key, value_t value);
// Removes element from map_t and returns the value
value_t pop_map(map_t *m, char *key);
// Changes an existing element of the map_t
void change_map(map_t m, char *key, value_t new_value);
// Returns value of a map_t element
value_t get_map(map_t m, char *key);

#include "operations.h"

#endif // MAP_H
