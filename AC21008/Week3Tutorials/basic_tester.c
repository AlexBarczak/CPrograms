/**
 * FILE: BASIC_TESTER.C
 *
 * Can be used to run some tests for the Passenger Queue program.
 * This file can be compiled alongside your own file (passenger_queue.c)
 * and it will automatically call and make use of the functions that 
 * you have implemented and which are contained within your
 * passenger_queue.c file.
 *
 * YOU CAN MODIFY THIS FILE IF YOU WISH, E.G. CHANGE OUTPUT MESSAGES
 * OR TO ADD NEW TESTS, ETC. 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "passenger_queue.h"


/**
 * A helper function, to display the contents of the queue
 * for debugging purposes. The implementation for this is further 
 * below, under main()
 */
void displayQueue(PassengerQueue *qPtr);

/**
 * The main function. Run some basic tests on the queue.
 */
int main()
{
	printf("## BASIC TESTER PROGRAM\n\n");

	// a variable to store (a pointer to) our queue
	PassengerQueue *pQueue= NULL;

	// try to create the queue
	printf("Attempting to create queue..");
	pQueue = createQueue(); // This calls your implementation of createQueue().
							// It will be found within your passenger_queue.c file.
							// When you compile your passenger_queue.c file with this file 
							// (basic_tester.c), it will link everything together.

	// if queue wasn't created
	if (pQueue == NULL)
	{
		// display error msg
		printf("ERROR: Unable to create queue. Exiting...\n");

		// exit / return from the main function - no point in going further
		return 0;
	}
	else
	{
		printf("..success!\n");
	}

	// (attempt to) add a passenger to the end of the queue
	printf("\nAttempting to add Passenger 1 to the end of the queue, with name 'passenger1'..");
	char passengerName1[] = "passenger1";
	int passengerID1 = 43;
	int result = addPassenger(pQueue, passengerID1, passengerName1, 0); // this calls your implementation of addPassenger()

	// if passenger wasn't added successfully
	if (result != SUCCESS)
	{
		// display error msg
		printf("ERROR: Unable to add passenger. Exiting...\n");

		// Before exiting, free memory for the queue that was created already
		free(pQueue);

		// exit / return from the main function - no point in going further
		// if we can't get at least one passenger onto the queue
		return 0;
	}
	else
	{
		// display success msg
		printf("..passenger added successfully!\n");

		// display queue for confirmation
		displayQueue(pQueue);
	}

	// (attempt to) add a second passenger to the queue
	// add it to the FRONT of the queue as a priority passenger
	printf("\nAttempting to add Passenger 2 to the FRONT of the queue, with name 'passenger2'..");
	char passengerName2[] = "passenger2";
	int passengerID2 = 22;
	result = addPassenger(pQueue, passengerID2, passengerName2, 1); // this calls your implementation of addPassenger()

	// if passenger wasn't added successfully
	if (result != SUCCESS)
	{
		// display error msg
		printf("ERROR: Unable to add passenger 2. Exiting...\n");

		// Before exiting, free memory for the queue that was created already
		free(pQueue);

		// exit / return from the main function 
		return 0;
	}
	else
	{
		// display success msg
		printf("..passenger 2 added successfully!\n");

		// display queue for confirmation
		displayQueue(pQueue);
	}

	// (attempt to) add a third passenger to the END of the queue
	printf("\nAttempting to add Passenger 3 to the END of the queue, with name 'passenger3'..");
	char passengerName3[] = "passenger3";
	int passengerID3 = 12;
	result = addPassenger(pQueue, passengerID3, passengerName3, 0); // this calls your implementation of addPassenger()

	// if passenger wasn't added successfully
	if (result != SUCCESS)
	{
		// display error msg
		printf("ERROR: Unable to add passenger 3. Exiting...\n");

		// Before exiting, free memory for the queue that was created already
		free(pQueue);

		// exit / return from the main function 
		return 0;
	}
	else
	{
		// display success msg
		printf("..passenger 3 added successfully!\n");

		// display queue for confirmation
		displayQueue(pQueue);
	}

	// so far, we have added three passengers and they queue should be as follows:
	// head -> passenger2 (ID22) -> passenger1 (ID43) -> passenger3 (ID12)

	// get count of passengers in queue
	int count = getPassengerCount(pQueue); // this calls your implementation of getPassengerCount()
	printf("\nThere are %d passengers in the queue.\n\n", count);

	// peek at the head passenger in the queue
	Passenger p;
	result = peekAtHeadPassenger(pQueue, &p); // this calls your implementation of peekAtHeadPassenger()
	if (result != SUCCESS)
	{
		// display error msg
		printf("ERROR: Failed to peek at head passenger in queue.\n");
	}
	else
	{
		// display success msg
		printf("Successfully peeked at head passenger in queue.\n");
		printf("Passenger is %s with ID %d.\n", p.name, p.ID);
	}

	// (attempt to) remove / pop a passenger from the HEAD of the queue
	printf("\nAttempting to remove passenger from HEAD of queue..");
	Passenger passengerRemoved; // a variable to receive a copy of the information pertaining to the passenger removed from the front of the queue
	result = removePassengerAtHead(pQueue, &passengerRemoved); // this calls your implementation of removePassengerAtHead()

	// if packet wasn't removed successfully
	if (result != SUCCESS)
	{
		// display error msg
		printf("ERROR: Unable to remove passenger from HEAD of queue.\n");
	}
	else
	{
		// display success msg
		printf("..passenger removed successfully!\n");

		// Display details of passenger that was removed from the queue.
		// (it should be 'passenger2')		
		printf("Successfully removed head passenger in queue.\n");
		printf("Passenger is %s with ID %d.\n", passengerRemoved.name, passengerRemoved.ID);

		// Display remainder of queue for confirmation of passengers remaining. 
		// Queue should now be: head -> passenger1 (ID43) -> passenger3 (ID12)
		displayQueue(pQueue);
	}

	// (attempt to) remove / pop a passenger from the TAIL of the queue
	printf("\nAttempting to remove passenger from TAIL of queue..");
	result = removePassengerAtTail(pQueue, &passengerRemoved); // this calls your implementation of removePassengerAtTail()

	// if packet wasn't removed successfully
	if (result != SUCCESS)
	{
		// display error msg
		printf("ERROR: Unable to remove passenger from TAIL of queue.\n");
	}
	else
	{
		// display success msg
		printf("..passenger removed successfully!\n");

		// Display details of passenger that was removed from the queue.
		// (it should be 'passenger3')		
		printf("Successfully removed TAIL passenger in queue.\n");
		printf("Passenger is %s with ID %d.\n", passengerRemoved.name, passengerRemoved.ID);

		// Display remainder of queue for confirmation of passengers remaining. 
		// Queue should now be: head -> passenger1 (ID43)
		displayQueue(pQueue);
	}

	// clear the queue when finished.
	printf("\nAttempting to clear the queue..");
	if (clearQueue(pQueue) != SUCCESS) // this calls your implementation of clearQueue()
	{
		// display error msg
		printf("ERROR: Unable to clear the queue when finished.\n");
	}
	else
	{
		printf("..queue cleared successfully!\n\n");		
	}

	
	 //If you have implemented the sort() function, you could try a separate test for that
	 PassengerQueue *pQueue2 = createQueue();
	 addPassenger(pQueue2, 22, "passenger22", 0);
	 addPassenger(pQueue2, 12, "passenger12", 0);
	 addPassenger(pQueue2, 56, "passenger56", 0);
	 addPassenger(pQueue2, 2, "passenger2", 0);
	 addPassenger(pQueue2, 9, "passenger9", 0);
	 sortQueue(pQueue2);
	 displayQueue(pQueue);
	

	/**
	 * Try adding some INPUT VALIDATION / error-checking tests if you want, 
	 * e.g., create a second queue:
	 * PassengerQueue *pQueue2 = createQueue();
	 * 
	 * try adding a passenger to the queue, but with an invalid ID, e.g. -1
	 * int result = addPassenger(pQueue2, -1, "passengerName", 0);
	 * if (result != INVALID_INPUT_PARAMETER)
	 *    input validation failed
	 * 
	 * try adding a passenger to an invalid / NULL queue
	 * int result = addPassenger(NULL, 23, "passengerName", 0);
	 * if (result != INVALID_INPUT_PARAMETER)
	 *    input validation failed
	 * 
	 * try adding a passenger where their name is too long
	 * int result = addPassenger(pQueue2, 23, "passengerNameIsTooLong_ItHasMoreThanMAX_PASSENGER_NAME_LENGTHCharactersInIt_IfWeAreNotCareful, ThisCouldResultInAMemoryLeak!", 0);
	 * if (result != INVALID_INPUT_PARAMETER)
	 *    input validation failed
	 * 
	 * try peeking at the head of the queue, but with an empty queue
	 * Passenger p;
	 * int result = peekAtHeadPassenger(pQueue2, &p);
	 * if ((result != INVALID_INPUT_PARAMETER) || (result != INVALID_QUEUE_OPERATION))
	 *    input validation failed
	 * 
	 * try removing from the head of any empty queue
	 * Passenger p;
	 * int result = removePassengerAtHead(pQueue2, &p);
	 * if ((result != INVALID_INPUT_PARAMETER) || (result != INVALID_QUEUE_OPERATION))
	 *    input validation failed
	*/

	/**
	 * Try some queue validity checks. E.g., you create a queue
	 * PassengerQueue *pQueue2 = createQueue();
	 * 
	 * check it has been initialised properly
	 * if ((pQueue2->head == NULL) && (pQueue2->tail == NULL))
	 *    // correct
	 * 
	 * add a passenger to the queue
	 * addPassenger(pQueue2, 23, "passenger23", 0);
	 * 
	 * // check queue is in a valid state afterwards
	 * if ((pQueue2->head != NULL) && (pQueue2->head->ID == 23) && (pQueue2->head->next == NULL) && (pQueue2->tail == pQueue2->head))
	 *     queue in valid state, new passenger at head, ID matches what we added, no next node in the queue yet, both tail and head pointing to same
	*/
}

/**
 * Helper function:a function to display the contents of the queue, 
 * for debugging purposes.
 */
void displayQueue(PassengerQueue *qPtr)
{
	printf("Displaying current status of queue()...");

	if (qPtr == NULL)
	{
		printf("ERROR: NULL queue.\n.");
		return; // break out of function
	}
	else
	{
		printf("\n");
	}

	// start at the head of the queue
	Passenger *pNextPassenger = qPtr->head;

	// while there is a passenger to display
	while (pNextPassenger != NULL)
	{
		// display passenger details
		printf("Next passenger has a name of %s, and an ID of %d.\n", pNextPassenger->name, pNextPassenger->ID);

		// move to next passenger after this one, if there is one there
		pNextPassenger = pNextPassenger->next;
	}

	// done
}
