#include <stdio.h>
#include "IntVector.h"
#include <stdlib.h>
#define next printf("\n\n");

//[название тестируемой функции]

int main()
{
//int_vector_new && int_vector_copy && int_vector_push_back 
//int_vector_get_size && int_vector_get_capacity && int_vector_get_item
	IntVector *v = int_vector_new(10);
	for (int i = 0; i < 5; i++){
		int_vector_push_back(v, i + 1);
	}

	IntVector *copy_v = int_vector_copy(v);
    printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(copy_v), (int) int_vector_get_size(copy_v));
	for (int i = 0; i < int_vector_get_size(copy_v); i++){
		printf("%d ", int_vector_get_item(copy_v, i));
	}

    next

//int_vector_free
	int_vector_free(copy_v);
    printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(copy_v), (int) int_vector_get_size(copy_v));
    for (int i = 0; i < int_vector_get_size(copy_v); i++){
		printf("%d ", int_vector_get_item(copy_v, i));
	}

    next

//int_vector_set_item
	int_vector_set_item(v, 2, 13);
    printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));
    for (int i = 0; i < int_vector_get_size(v); i++){
		printf("%d ", int_vector_get_item(v, i));
	}

    next

//int_vector_pop_back
	int_vector_pop_back(v);
    printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));
    for (int i = 0; i < int_vector_get_size(v); i++){
		printf("%d ", int_vector_get_item(v, i));
	}

    next

//int vector shrinck to fit
	int_vector_shrink_to_fit(v);
	printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));

    next

//int_vector_reserve
	int_vector_reserve(v, 10);
	printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));

    next

//int_vector_resize
    int_vector_resize(v, 7);
	printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));
    for (int i = 0; i < int_vector_get_size(v); i++){
		printf("%d ", int_vector_get_item(v, i));
	}

    next

    int_vector_resize(v, 0);
    printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));
    for (int i = 0; i < int_vector_get_size(v); i++){
		printf("%d ", int_vector_get_item(v, i));
	}
    int_vector_push_back(v, 13);
    printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));
    for (int i = 0; i < int_vector_get_size(v); i++){
		printf("%d ", int_vector_get_item(v, i));
	}

	int_vector_free(v);
    printf("\n");

	return 0;
}