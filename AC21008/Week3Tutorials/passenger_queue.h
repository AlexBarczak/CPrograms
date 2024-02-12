/**
 * FILE: PASSENGER_QUEUE.H
 *
 * Contains definitions of data structures and error codes required for the
 * Passenger Queue Program. It also provides declarations of the functions 
 * that require to be implemented. The function implementations should be
 * placed in the separate 'passenger_queue.c' file.
 *
 * NOTE: YOU DO NOT NEED TO MODIFY THIS FILE. IT SHOULD WORK AS-IS.
 * HOWEVER, FEEL FREE TO ADD ANYTHING ELSE THAT YOU WANT FOR YOUR OWN PROGRAM.
 * THE CODE THAT YOU IMPLEMENT WILL BE IN THE PASSENGER_QUEUE.C FILE.
 */

#ifndef __PASSENGER_QUEUE_HEADER__ // this is a 'guard' on the header file, to prevent it's contents from
#define __PASSENGER_QUEUE_HEADER__ // being redefined more than once during the build process

/**
 * ### ERROR codes / SUCCESS codes ###
 * PLEASE USE THESE AS THE RETURN VALUES FOR YOUR FUNCTIONS. 
 * Example:
 * return INVALID_INPUT_PARAMETER;
 *
 */
#define SUCCESS                  100   // Value to be returned if a function is completed successfully
#define INVALID_INPUT_PARAMETER  101   // Value to be returned if you detect that one of the input parameters 
                                       // into your function is invalid, e.g. it is NULL or an unexpected value
#define MEMORY_ALLOCATION_ERROR  102   // Value to be returned if a memory allocation error occurs during your function
#define INVALID_QUEUE_OPERATION  103   // Value to be returned if your function detects an operation that is being
                                       // attempted on your queue data structure that isn't valid or your queue
                                       // isn't in a ready state to receive. For example, an attempt is made to remove
                                       // an item from an empty queue

// OTHER CONSTANTS
#define MAX_PASSENGER_NAME_LENGTH 89  // The maximum length of a passenger's name (including the null terminator)
#define MIN_PASSENGER_ID_VALUE 1
#define MAX_PASSENGER_ID_VALUE 88801

/** ### DATA STRUCTURES ### */

/* typedef for passengers boarding a plane */
typedef struct passenger {
    int ID;                 // the passenger's ID
	char name[MAX_PASSENGER_NAME_LENGTH];			// a string representing the passenger's name
    struct passenger *next;	// a pointer to the next passenger in the queue after this one
} Passenger;


/* typedef for a queue of passengers boarding a plane */
typedef struct passenger_queue {
	Passenger *head; // points to the passenger at the front/head of the queue
	Passenger *tail; // points to the passenger at the end/tail of the queue
} PassengerQueue;


/** ### FUNCTION PROTOTYPES / ADVANCE DECLARATIONS ### */
/** YOU WILL IMPLEMENT THESE FUNCTIONS IN THE SEPARATE PASSENGER_QUEUE.C FILE. */

/**
 * Create a new, empty queue, returning a pointer to the newly allocated
 * queue OR a value of NULL in the event of error.
 */
PassengerQueue *createQueue();


/**
 * Add a new passenger to the front or end of the queue using the input values
 * provided and return SUCCESS or otherwise to signify success or an error.
 */
int addPassenger(PassengerQueue *qPtr, int passengerID, char *passengerName, int isPriority);


/** 
 * Get the count of / number of passengers in the queue
 */
int getPassengerCount(PassengerQueue *qPtr);


/**
 * Remove the next passenger from the HEAD of the  queue, copying the removed passenger's
 * information into the fields of the input variable provided (*p)
 */
int removePassengerAtHead(PassengerQueue *qPtr, Passenger *p);


/**
 * Peek at the HEAD passenger in the queue.
 */
int peekAtHeadPassenger(PassengerQueue *qPtr, Passenger *p);


/**
 * Remove the next passenger from the TAIL of the  queue, copying the removed passenger's
 * information into the fields of the input variable provided (*p)
 * NOTE: THIS ISN'T AS STRAIGHT FORWARD AS REMOVING FROM THE HEAD!
 */
int removePassengerAtTail(PassengerQueue *qPtr, Passenger *p);


/**
 * Clear the content of the queue, freeing the memory for each passenger in the queue and
 * the queue itself. 
 */
int clearQueue(PassengerQueue *qPtr);


/** 
 * ADDED EXTRAS. If you want something extra to do, try implementing a function which
 * will re-order the passengers in the queue based on their ID value, making sure they
 * occur in order from lowest to highest.
 */
int sortQueue(PassengerQueue *qPtr);


/** 
 * Add any other functions you want too, e.g., a function to add an item into the middle of the queue, 
 * in between two passengers, or even remove a passenger from the middle of the queue. Implement a function 
 * to find / locate a specific passenger in the queue based on their ID value. 
 */

#endif
