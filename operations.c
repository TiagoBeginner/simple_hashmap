#include "operations.h"
#include "map.h"

void add_map(map_t m, char *key, value_t add) {
	change_map(m, key, get_map(m, key) + add);
}

void sub_map(map_t m, char *key, value_t sub) {
	change_map(m, key, get_map(m, key) - sub);
}

void mul_map(map_t m, char *key, value_t mul) {
	change_map(m, key, get_map(m, key) * mul);
}

void div_map(map_t m, char *key, value_t div) {
	change_map(m, key, get_map(m, key) / div);
}

void mod_map(map_t m, char *key, value_t mod) {
	change_map(m, key, get_map(m, key) % mod);
}

void lsh_map(map_t m, char *key, value_t shift) {
	change_map(m, key, get_map(m, key) << shift);
}

void rsh_map(map_t m, char *key, value_t shift) {
	change_map(m, key, get_map(m, key) >> shift);
}