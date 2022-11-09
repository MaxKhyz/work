/**
 * @file    fl_queue.c
 * @version 1.3.0
 * @authors 
 * @date    27/10/2022
 * @date    27/10/2022
 */

/****************************** Included files ********************************/
#include "common.h"
/****************************** Private  variables ****************************/
static uint8_t queue[QUEUE_LENGTH];
static volatile uint8_t head;
static volatile uint8_t tail;
static volatile uint8_t count;
static uint8_t _is_created;
/********************* Application Programming Interface **********************/
void create_queue(void) {
	_is_created = true;
	head  = 0u;
    tail  = 0u;
    count = 0u;
}
/*----------------------------------------------------------------------------*/
bool push_queue(uint8_t num) {
    if (count) {
        uint8_t tail_old = tail++;
        tail %= QUEUE_LENGTH;
        if (tail == head) {
            printf("Buffer overflow\n");
            tail = tail_old;
            return false;
        }
    }
    count++;
    *(queue + tail) = num;
    return true;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_queue(void) {
    uint8_t result = 0u;
    if (count) {
        result = *(queue + head);
        if (--count) {
            head++;
            head %= QUEUE_LENGTH;
        }
    }
    else { printf("QUEUE is empty\n"); }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t front_queue(void) {
    return (count) ? queue[head] : 0u;
}
/*----------------------------------------------------------------------------*/
bool is_empty_queue(void) {
    return (count == 0u);
}
void destroy_queue(void) {
	_is_created = false;
}


/******************************************************************************/
