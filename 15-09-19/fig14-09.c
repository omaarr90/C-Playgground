/* Figure 14.9  Program for Modeling the Delivery and Dispensing of Gasoline (caseused.c) */
#include <pthread.h>
#include <stdio.h>
#include <wait.h>

int get_number(); /* Pump number function prototype */
int get_amount(); /* Pump amount function prototype */

void startup (int* number, pthread_t* ptid); /* Startup function prototype */
void cleanup (     pthread_t ptid); /* Cleanup function prototype */

/* Producer and consumer thread function prototypes */
void* producer (void* argument);
void* consumer (void* argument);

#define CAPACITY 1000 /* Storage tank refill capacity */
#define QUANTITY 50 /* Storage tank refill quantity */

#define FILL_RATE 50 /* Storage tank fill rate */
#define FLOW_RATE 5 /* Station pump flow rate */

#define PUMPS 10 /* Number of pumps available */

#define VERBOSE 0 /* Verbose display on (1) or off (0) */

int terminate; /* Storage fill terminate */
int inventory; /* Storage tank inventory */
int pump[PUMPS]; /* Pump quantity requests */

pthread_mutex_t lock; /* Mutual exclusion id */

int
main(void)
{
     int number; /* Pump number */

     pthread_t ptid; /* Producer thread id */
     pthread_t ctid; /* Consumer thread id */

     /* Startup the application */
     startup (&number, &ptid);

     /* Loop until the user sets the pump number to -1 */
     while (number != -1)
     {
          /* Get the pump number */
          number = get_number();

          if (number != -1)
          {
               /* Assign the amount to the pump */
               if (pthread_mutex_lock (&lock) != 0)
                    printf ("Error Locking Mutex\n");

               pump[number-1] = get_amount();

               if (pthread_mutex_unlock (&lock) != 0)
                    printf ("Error Unlocking Mutex\n");

               /* Create a new consumer thread passing in pump number */
               if (pthread_create (&ctid, NULL, consumer, &number) != 0)
                    printf ("Error Creating The Consumer Thread\n");
          }
     }

     /* Cleanup the application */
     cleanup (ptid);

     return (0);
}

void startup (int* number, pthread_t* ptid)
{
     int count; /* Loop counter */

     /* Initialize the storage fill terminate to FALSE */
     terminate = 0;

     /* Initialize the storage tank inventory to the CAPACITY */
     inventory = CAPACITY;

     /* Initialize the pump amounts to 0 */
     for (count = 0; count < PUMPS; count++)
          pump[count] = 0;

     /* Initialize the pump number */
     *number = 0;

     /* Initialize the mutex lock and create the producer thread */
     if (pthread_mutex_init (&lock, NULL) != 0)
     {
          printf ("Error Initializing The Mutex Lock\n");
          *number = -1;
     }
     else if (pthread_create (ptid, NULL, producer, NULL) != 0)
     {
          printf ("Error Creating The Producer Thread\n");
          *number = -1;
     }
}

void cleanup (pthread_t ptid)

{
     int checks; /* Pump checks */
     int number; /* Pump number */
     int active; /* Pump active */

     /* Initialize the pump checks counter */
     checks = 0;

     do
     {
          /* Initialize the pump number and active flag */
          number = 0;
          active = 0;

          /* Look for pumps that are active */
          while (number < PUMPS && !active)
          {
               if (pthread_mutex_lock (&lock) != 0)
                    printf ("Error Locking Mutex\n");

               if (pump[number] > 0)
                    active = 1;
               else
                    number++;

               if (pthread_mutex_unlock (&lock) != 0)
                    printf ("Error Unlocking Mutex\n");
          }

          if (active)
          {
               /* Increment the checks counter */
               checks++;

          /* Display the active pumps message on the first check */
          if (checks == 1)
               printf ("Wait For Active Pump(s) To Finish\n");

          /* Sleep for one second before checking again */
          sleep (1);
      }
   }
   while (active);

   /* Set the terminate flag to cancel the producer thread */
   if (pthread_mutex_lock (&lock) != 0)
        printf ("Error Locking Mutex\n");

   terminate = 1;

   if (pthread_mutex_unlock (&lock) != 0)
        printf ("Error Unlocking Mutex\n");

   /* Wait for the producer thread to complete */
   if (pthread_join (ptid, NULL) != 0)
        printf ("Error Joining The Producer Thread\n");
}

int get_number()
{
    int number; /* Pump number */

    do
    {
              /* Get the pump number */
              printf ("Enter A Pump Number From 1 To %d or ñ1 To Quit\n",
                   PUMPS);
              scanf (" %d", &number);

              /* Skip processing if the pump number is ñ1 */
              if (number != -1)

                   /* Validate the pump number */
              if (number < 1 || number > PUMPS)
              {
                   printf ("The Pump Number Must Be From 1 To %d\n",
                        PUMPS);
                   number = 0;
              }
              else
              {
                   /* Check to see if the pump is available */
                   if (pthread_mutex_lock (&lock) != 0)
                        printf ("Error Locking Mutex\n");

                   if (pump[number-1] > 0)
                   {
                        printf ("Pump Number %d Is Already In Use\n",
                             number);
                        number = 0;
                   }

                   if (pthread_mutex_unlock (&lock) != 0)
                        printf ("Error Unlocking Mutex\n");
                   }
     }
     while (number == 0);

     return (number);
}

int get_amount()
{
     int amount; /* Pump amount */

     do
     {
          /* Get the amount of gasoline to pump */
          printf ("Enter The Amount Of Gasoline To Pump\n");
          scanf (" %d", &amount);

          /* Validate the amount of gasoline */
          if (amount <= 0)
       {
          printf (
               "The Amount Of Gasoline Must Be Greater Than 0\n");
          amount = 0;
       }
    }
    while (amount == 0);

    return (amount);
}

void* producer (void* argument)
{
     int cancel; /* Cancel deliveries */
     int number; /* Pump number count */
     int remain; /* Pump remain count */

     /* Loop until the terminate flag is set to TRUE */
     do
     {
          if (pthread_mutex_lock (&lock) != 0)
               printf ("Error Locking Mutex\n");

          /* Refill storage tank if inventory falls below QUANTITY */
          if (inventory < QUANTITY)
          {
               printf ("Taking Pump(s) Off Line\n");

               /* Consumer threads are blocked when mutex is locked */
               for (number = 1; number <= PUMPS; number++)
                    if (pump[number-1] > 0)
                         printf ("Pump Number %d Off Line\n", number);

               printf ("Storage Tank Refill Started Inventory %d\n",
                    inventory);

               /* Refill storage tank at FILL_RATE gallons per second */
               while (inventory < CAPACITY)
               {
               /* Do not refill storage tank beyond its CAPACITY */
               if (inventory + FILL_RATE <= CAPACITY)
                    inventory += FILL_RATE;
               else
                    inventory = CAPACITY;

               if (VERBOSE)
                    printf ("Storage Tank Inventory %d\n", inventory);

               sleep (1);
          }

          printf ("Storage Tank Refill Finished Inventory %d\n",
                    inventory);
          printf ("Putting Pump(s) Back On Line\n");

          /* Unblock consumer threads when mutex is unlocked */
          for (number = 1; number <= PUMPS; number++)
          {
                remain = pump[number-1];

                if (remain > 0)
                     printf ("Pump Number %d On Line %d Remain\n",
                          number, remain);
          }
       }

       /* Assign the terminate flag to the local cancel flag */
       /* used in the while condition outside the mutex lock */
       cancel = terminate;

       if (pthread_mutex_unlock (&lock) != 0)
            printf ("Error Unlocking Mutex\n");

       /* Sleep for one second before checking again */
       sleep (1);
     }
     while (!cancel);

     printf ("Storage Tank Deliveries Canceled\n");

     return (NULL);
}

void* consumer (void* argument)
{
     int number; /* Pump number */
     int output; /* Pump output */
     int amount; /* Pump amount */

     /* Cast argument as an int* and assign the contents to number */
     number = *(int*) argument;

     /* Initialize the output */
     output = 0;

     printf ("Pump Number %d Started\n", number);

     do
     {
          if (pthread_mutex_lock (&lock) != 0)
          printf ("Error Locking Mutex\n");

          /* Do not dispense more gasoline than requested */
          if (pump[number-1] < FLOW_RATE)
               amount = pump[number-1];
          else
               amount = FLOW_RATE;

          /* Do not dispense more gasoline than available */
          if (amount > inventory)
               amount = inventory;

          /* Reduce the storage tank inventory and */
          /* pump amount by the gallons per second amount */
          inventory -= amount;
          pump[number-1] -= amount;

          /* Increment the output by the amount */
          output += amount;

          /* Store the remaining pump amount in the local variable */
          /* amount for use in the while condition after the mutex */
          /* has been unlocked                                     */
          amount = pump[number-1];

          if (VERBOSE)
               printf ("Pump Number %d Output %d\n", number, output);
          if (pthread_mutex_unlock (&lock) != 0)
               printf ("Error Unlocking Mutex\n");

          sleep (1);
    }
    while (amount > 0);

    printf ("Pump Number %d Finished Output %d\n", number, output);

    return (NULL);
}
