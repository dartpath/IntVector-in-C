#include "IntVector.h"
#include <string.h>
#include <stdlib.h>

IntVector *int_vector_new(size_t initial_capacity)
{
    if (initial_capacity >= 0) {
        IntVector *v = malloc(sizeof(IntVector));
        if (!v) {
            return NULL;
        }
        v->data = malloc(sizeof(int) * initial_capacity);
        if (!v->data) {
            free(v);
            return NULL;
        }
        v->size = 0;
        v->capacity = initial_capacity;
        return v;
    } else {
        return NULL;
    }
}

IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *new_v = malloc(sizeof(IntVector));
	if (!new_v) {
		return NULL;
	}
	new_v->data = malloc(sizeof(int) * int_vector_get_capacity(v));
	if (!new_v->data) {
		free(new_v);
		return NULL;
	}
	memcpy(new_v->data, v->data, sizeof(int) * int_vector_get_capacity(v));
	new_v->size = int_vector_get_size(v);
	new_v->capacity = int_vector_get_capacity(v);
	return new_v;
}

void int_vector_free(IntVector *v)
{
	if (v) {
		free(v->data);
		free(v);
	}
}

int int_vector_get_item(const IntVector *v, size_t index)
{
	if ((index >= 0) && (index < int_vector_get_capacity(v))) {
		return v->data[index];
	}
    return 0;
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
	if ((index >= 0) && (index < int_vector_get_capacity(v))) {
		v->data[index] = item;
	}
}

size_t int_vector_get_size(const IntVector *v)
{
	return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
	return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
	if (int_vector_get_capacity(v) == 0){
		v->capacity = 1;
	}
	if (int_vector_get_capacity(v) == int_vector_get_size(v)) {
		int *new_v = realloc(v->data, sizeof(int) * int_vector_get_capacity(v) * 2);
		if (!new_v) {
			return -1;
		}
		v->capacity *= 2;
		v->data = new_v;
	}
	v->data[int_vector_get_size(v)] = item;
	v->size++;

	return 0;
}

void int_vector_pop_back(IntVector *v)
{
	if (int_vector_get_size(v) != 1) {
		v->size--;
	}
}

int int_vector_shrink_to_fit(IntVector *v)
{
	if (int_vector_get_capacity(v) > int_vector_get_size(v)) {
		int *new_v = realloc(v->data, sizeof(int) * int_vector_get_size(v));
		if (!new_v) {
			return -1;
		}
		v->data = new_v;
	}
	v->capacity = int_vector_get_size(v);
	return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if (new_size >= 0) {
        if (new_size > int_vector_get_size(v)) {
            for (int i = int_vector_get_size(v); i < new_size; i++) {
                if (int_vector_push_back(v, 0) == -1) {
                    return -1;
                }
            }
        }
        v->size = new_size;
        return 0;
    } else {
        return -1;
    }
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if (new_capacity >= 0) {
        if (new_capacity > v->capacity) {	
            v->capacity = new_capacity;
            int *new_v = realloc(v->data, sizeof(int) * v->capacity);
            if (!new_v) {
                return -1;
            }
            v->data = new_v;
        }
        return 0;
    } else {
        return -1;
    }
}
