#include <stdlib.h> // required for some memory allocation functions such as 'malloc()' and 'free()'
#include <string.h> // you will need this if you use the string helper functions in C
#include <stdio.h> // for displaying items in the queue

#include "passenger_queue.h" // required, to include the Passenger Queue data structures, #defines, and function declarations


/*** ### FUNCTION IMPLEMENTATIONS ### ***/

/**
 * Create a new, empty queue, returning a pointer to the newly allocated
 * queue OR a value of NULL in the event of error.
 */
PassengerQueue *createQueue()
{
   // initialise local pointer to store memory address of the queue and set it to null
   PassengerQueue* pPassengerQueue = NULL;
   // attempt to allocate memory for the queue and cast the memory into type pointer to a passenger queue struct
   pPassengerQueue = (PassengerQueue*)malloc(sizeof(PassengerQueue));
   // if no memory is available for alloction, return an error indicating so
   if (pPassengerQueue == NULL){
      return NULL;
   }

   // initialise the head and tail of the queue to be null
   pPassengerQueue->head = NULL;
   pPassengerQueue->tail = NULL;
   
   //return the pointer to the now initialised queue
   return pPassengerQueue;
}

/**
 * add a new passenger to the front or end of queue if is or is not a priority passenger respectively
 * 
*/
int addPassenger(PassengerQueue* qPtr, int passengerID, char passengerName[], int isPriority)
{
   // check the arguments are not invalid
   if (qPtr == NULL || passengerID > MAX_PASSENGER_ID_VALUE || passengerID < MIN_PASSENGER_ID_VALUE || strlen(passengerName) > MAX_PASSENGER_NAME_LENGTH || !(isPriority == 0 || isPriority == 1)){
      return INVALID_INPUT_PARAMETER;
   }

   // create the passenger data structure
   Passenger* pPassenger = NULL;
   pPassenger = (Passenger*)malloc(sizeof(Passenger));
   if(pPassenger == NULL){
      return MEMORY_ALLOCATION_ERROR;
   }

   //initialise the passenger data structure
   pPassenger->ID = passengerID;
   strcpy(pPassenger->name, passengerName);
   pPassenger->next = NULL; 

   //check if queue is empty
   if(qPtr->head == NULL){
      qPtr->head = pPassenger;
      qPtr->tail = pPassenger;
      return SUCCESS;
   }

   if (isPriority == 1){
      //add to the head of the queue
      pPassenger->next = qPtr->head;
      qPtr->head = pPassenger;
      return SUCCESS;
   }

   //else add to the tail of the queue
   qPtr->tail->next = pPassenger;
   qPtr->tail = pPassenger;
   return SUCCESS;
}

int getPassengerCount(PassengerQueue *qPtr)
{
   //check the arguments are valid, except you cannot because this function returns values directly
   // if (qPtr == NULL){
   //    return INVALID_INPUT_PARAMETER;
   // }

   if (qPtr->head == NULL){
      return 0;
   }

   //starting from the head, add 1 to a running count each time you travel to the next person in the queue until a passenger has null as his next pointer
   Passenger* pPassenger = qPtr->head;
   int count = 1;

   while (pPassenger->next != NULL)
   {
      pPassenger = pPassenger->next;
      count += 1;
   }

   return count;
}

int peekAtHeadPassenger(PassengerQueue* qPtr, Passenger* p)
{
   //check the arguments are valid
   if (qPtr == NULL || p == NULL){
      return INVALID_INPUT_PARAMETER;
   }

   //queue must have at least one element to peek at
   if (qPtr->head == NULL){
      return INVALID_QUEUE_OPERATION;
   }
   
   //copy over the values to the passenger copy and return success
   p->ID = qPtr->head->ID;
   strcpy(p->name, qPtr->head->name);
   p->next = qPtr->head->next;

   return SUCCESS;
}

int removePassengerAtHead(PassengerQueue* qPtr, Passenger* p)
{
   //check the arguments to see if they are invalid
   if(qPtr == NULL, p == NULL){
      return INVALID_INPUT_PARAMETER;
   }

   //queue must have something in it to remove
   if (qPtr->head == NULL){
      return INVALID_QUEUE_OPERATION;
   }

   //copy the values over
   p->ID = qPtr->head->ID;
   strcpy(p->name, qPtr->head->name);
   p->next = qPtr->head->next;
   
   //if there is only one element, the tail will also become null
   if (qPtr->head == qPtr->tail){
      qPtr->tail = NULL;
   }

   //we can now free the oject at the head of the pointer and change the head value to the next object if there is one
   free(qPtr->head);
   qPtr->head = p->next;

   return SUCCESS;
}

int removePassengerAtTail(PassengerQueue* qPtr, Passenger* p)
{
   //check the arguments to see if they are invalid
   if(qPtr == NULL, p == NULL){
      return INVALID_INPUT_PARAMETER;
   }

   //queue must have something in it to remove
   if (qPtr->head == NULL){
      return INVALID_QUEUE_OPERATION;
   }

   p->ID = qPtr->head->ID;
   strcpy(p->name, qPtr->head->name);
   p->next = qPtr->tail->next;

   free(qPtr->tail);

   //check to see if queue only has one passenger
   if (qPtr->head == qPtr->tail)
   {
      qPtr->head = NULL;
      qPtr->tail = NULL;

      return SUCCESS;
   }

   Passenger* currentPassenger = qPtr->head;
   
   while (qPtr->tail != currentPassenger->next)
   {
      currentPassenger = currentPassenger->next;
   }

   qPtr->tail = currentPassenger;
   currentPassenger->next = NULL;

   return SUCCESS;
}

int clearQueue(PassengerQueue* qPtr){
   //check the arguments to see if they are invalid
   if(qPtr == NULL){
      return INVALID_INPUT_PARAMETER;
   }

   //run through the passengers front to back, freeing as we move along until there is no more 'next' reference
   Passenger* currentPassenger = qPtr->head;

   //while we're not at the tail
   while (currentPassenger->next != NULL)
   {
      //get a reference of the memory to free and move on
      Passenger* memAddress = currentPassenger;
      currentPassenger = currentPassenger->next;

      //free the passenger now that we don't need him
      free(memAddress);
   }

   //free the last passenger
   free(currentPassenger);

   //free the queue
   free(qPtr);

   //success!
   return SUCCESS;
}

int sortQueue(PassengerQueue* qPtr){
   if (qPtr == NULL)
   {
      return INVALID_INPUT_PARAMETER;
   }

   if (qPtr->head == NULL)
   {
      return INVALID_QUEUE_OPERATION;
   }   
   
   int sorted = 0;

   while(sorted != 1){
      int swaps = 0;
      Passenger* currentPassenger = qPtr->head;
      
      while (currentPassenger != NULL && currentPassenger->next != NULL){
         if (currentPassenger->ID > currentPassenger->next->ID)
         {
            Passenger* nextPassenger = currentPassenger->next;
            //swap the data
            int tempID = currentPassenger->ID;
            currentPassenger->ID = nextPassenger->ID;
            nextPassenger->ID = tempID;

            char tempName[88];
            strcpy(tempName, currentPassenger->name);
            strcpy(currentPassenger->name, nextPassenger->name);
            strcpy(nextPassenger->name, tempName);

            swaps += 1;
         }
         currentPassenger = currentPassenger->next;
      }

      if (swaps == 0)
      {
         sorted = 1;
      }
   }
}