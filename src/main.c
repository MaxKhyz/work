/**
 * @file    main.c
 * @version 
 * @authors 
 * @date    22/10/2022
 * @date    22/10/2022
 */

 /****************************** Included files ********************************/
#include"stack.h"
#include"queue.h"

 /******************************** Definition **********************************/
#define FIX_LENGTH_STACK_TEST   (0)
#define FIX_LENGTH_QUEUE_TEST   (1)
#define ADDITIONAL_TEST         (1)

#define DISCARD_RETURN(f) ((void)f)
#define TEST_START(name)\
    printf("\n>>> Test start for a %s <<<\n\n", name)
#define TEST_FINISH \
    printf("***************************************************************\n")
/********************************* Entry point ********************************/
int main() {
#if FIX_LENGTH_STACK_TEST
    TEST_START("variable size stack");
    if (create_stack(STACK_LENGTH)) {
        printf("\nAdded symbols with ASCII codes from 48 to 58 into a stack\n");
        for (uint8_t i = 0; i < (STACK_LENGTH + 1); i++) {
            DISCARD_RETURN(push_stack(48 + i));
        }

#if ADDITIONAL_TEST
        printf("\nGet three characters from the stack:\n");
        for (uint8_t i = 0; i < 3; i++) {
            printf("%c\n", pop_stack());
        }
        printf("Added new symbols with ASCII codes from 65 to 67\n");
        DISCARD_RETURN(push_stack(65));
        DISCARD_RETURN(push_stack(66));
        DISCARD_RETURN(push_stack(67));

        printf("\nThe content of the variable-length stack:\n");
        for (uint8_t i = 0; i < STACK_LENGTH + 1; i++) {
            printf("%c\n", pop_stack());
        }
        printf("Added new symbols with ASCII codes from 68 to 70\n");
        DISCARD_RETURN(push_stack(68));
        DISCARD_RETURN(push_stack(69));
        DISCARD_RETURN(push_stack(70));
#endif

        printf("The top of variable-length stack: %c\n", top_stack());
        printf("The content of variable-length stack:\n");
        while (!is_empty_stack()) {
            printf("%c\n", pop_stack());
        }

        destroy_stack();
    }
    TEST_FINISH;
#endif
    /*----------------------------------------------------------------------------*/
#if FIX_LENGTH_QUEUE_TEST
    TEST_START("variable size queue");
    if (create_queue(QUEUE_LENGTH)) {
        printf("\nAdded symbols with ASCII codes from 48 to 58 into a queue\n");
        for (uint8_t i = 0; i < (QUEUE_LENGTH + 1); i++) {
            DISCARD_RETURN(push_queue(48 + i));
        }

#if ADDITIONAL_TEST
        printf("\nGet three characters from the queue:\n");
        for (uint8_t i = 0; i < 3; i++) {
            printf("%c\n", pop_queue());
        }
        printf("Added new symbols with ASCII codes from 65 to 67\n");
        DISCARD_RETURN(push_queue(65));
        DISCARD_RETURN(push_queue(66));
        DISCARD_RETURN(push_queue(67));

        printf("\nThe content of variable-length queue:\n");
        for (uint8_t i = 0; i < QUEUE_LENGTH + 1; i++) {
            printf("%c\n", pop_queue());
        }
        printf("Added new symbols with ASCII codes from 68 to 70\n");
        DISCARD_RETURN(push_queue(68));
        DISCARD_RETURN(push_queue(69));
        DISCARD_RETURN(push_queue(70));
#endif

        printf("The front of variable-length queue: %c\n", front_queue());
        printf("The content of variable-length queue:\n");
        while (!is_empty_queue()) {
            printf("%c\n", pop_queue());
        }
        destroy_queue();
    }
    TEST_FINISH;
#endif
    /*----------------------------------------------------------------------------*/
    getchar();
    return 0;
}
