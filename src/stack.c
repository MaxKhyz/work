/**
 * @file    stack.c
 * @version 1.3.0
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    14/10/2022
 */

/****************************** Included files ********************************/
#include "common.h"
#include <stdlib.h>
/****************************** Private  variables ****************************/
static data_t stack[STACK_LENGTH];
static volatile uint8_t top;
static volatile uint8_t count;
static uint8_t _is_create;
/****************************** Private  functions ****************************/
static bool stack_check(void) {
	bool result = true;
	if (!_is_create) {
		printf("Memory access error\n");
		result = false;
	}
	return result;
}


/********************* Application Programming Interface **********************/
void create_stack(void) {
        count = 0u;
        top = 0u;
        _is_create = true;
}
/*----------------------------------------------------------------------------*/
bool push_stack(uint8_t item) {
    bool result = false;
    if (stack_check()) {
        if (top < (STACK_LENGTH - 1u)) {
            if (count++){
				stack[++top] = item;
			}
            else { 
				stack[top] = item;
			}
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
	_is_create = false;
}
/******************************************************************************/
