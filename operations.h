#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "map.h"

void add_map(map_t m, char *key, value_t add);
void sub_map(map_t m, char *key, value_t sub);
void mul_map(map_t m, char *key, value_t mul);
void div_map(map_t m, char *key, value_t div);
void mod_map(map_t m, char *key, value_t mod);

void lsh_map(map_t m, char *key, value_t shift);
void rsh_map(map_t m, char *key, value_t shift);

#endif // OPERATIONS_H