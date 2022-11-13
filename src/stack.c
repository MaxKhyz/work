/**
 * @file    stack.c
 * @version 
 * @authors 
 * @date    12/11/2022
 * @date    12/11/2022
 */


/****************************** Included files ********************************/
#include "common.h"
#include <stdlib.h>
#include <malloc.h>
/****************************** Private  variables ****************************/
static data_t * stack;
static uint8_t s_size;
static volatile uint8_t top;
static volatile uint8_t count;
/****************************** Private  functions ****************************/
static bool stack_check(void) {
	bool result = true;
	if (!stack) {
		printf("Memory access error\n");
		result = false;
	}
	return result;
}
/********************* Application Programming Interface **********************/
bool create_stack(uint8_t buf_size) {
	bool result = false;
	stack = (data_t*)calloc(buf_size, sizeof(data_t));
	if (stack_check()) {
		s_size = buf_size;
		count = 0u;
		top = 0u;
		result = true;
	}
	return result;
}
/*----------------------------------------------------------------------------*/
bool push_stack(uint8_t item) {
	bool result = false;
	if (stack_check()) {
		if (top < s_size - 1u) {
			if (count++) { stack[++top] = item; }
			else { stack[top] = item; }
			result = true;
		}
		else { printf("Buffer overflow\n"); }
	}
	return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_stack(void) {
	uint8_t result = 0u;
	if (stack_check()) {
		if (count) {
			if (!top) { result = stack[top]; }
			else { result = stack[top--]; }
			count--;
		}
		else { printf("Stack is empty\n"); }
	}
	return result;
}
/*----------------------------------------------------------------------------*/
uint8_t top_stack(void) {
	uint8_t result = 0u;
	if (stack_check()) {
		if (count) {
			result = stack[top];
		}
	}
	return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_stack(void) {
	bool result = 0u;
	if (stack_check()) {
		result = (count == 0u);
	}
	return result;
}
/*----------------------------------------------------------------------------*/
void destroy_stack(void) {
	free(stack);
	stack = NULL;
}
/******************************************************************************/
