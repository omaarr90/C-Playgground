/* Figure 14.5  Program to Launch Another Program (parent.c) */
/* Create a new process, replace the new process image with a    */
/* different process image from an executable file, and,        */
/* communicate using a pipe                                     */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

/* Define the message to be sent using the pipe */
#define MESSAGE "Parent Message To Forked Process"

int
main(void)
{
     int filedes[2]; /* Array of file descriptors for the pipe */

     pid_t fpid; /* Forked process id */
     int status; /* Forked process status */

     /* Create the interprocess communications pipe */
     if (pipe (filedes) < 0)
          printf ("Error Creating The Interprocess Communications Pipe\n");

     /* Create a new process */
     fpid = fork();

     /* Both the parent and new processes continue running here */
     if (fpid < 0)
     {
          /* The new process was not created */
          printf ("Error Creating The New Process\n");

          /* Close the read and write file descriptors of the pipe */
          if (close (filedes[0]) != 0)
               printf ("Error Closing File Descriptor 0\n");
          if (close (filedes[1]) != 0)
               printf ("Error Closing File Descriptor 1\n");
     }
     else if (fpid == 0)
     {
          /* This is the new process */
          printf ("Forked Process ID %d\n", getpid());

          /* Close the write file descriptor of the pipe */
          if (close (filedes[1]) != 0)
               printf ("Error Closing File Descriptor 0\n");

          /* Duplicate & assign read file descriptor to standard input */
          if (dup2 (filedes[0], STDIN_FILENO) != STDIN_FILENO)
               printf ("Error Duplicating File Descriptor 0\n");

          /* Close read file descriptor of the pipe after duplication */
          if (close (filedes[0]) != 0)
               printf ("Error Closing File Descriptor 0\n");

          /* Replace this process image with the process */
          /* image from the executable file child.exe */
          if (execl("child.exe", "child.exe", NULL) < 0)
               printf ("Error Replacing This Process Image\n");
     }
     else
     {
          /* This is the parent process */
         printf ("Parent Process ID %d\n", getpid());

          /* Close the read file descriptor of the pipe */
          if (close (filedes[0]) != 0)
               printf ("Error Closing Pipe\n");

          /* Wait for the forked process to begin executing */
          sleep(1);

          printf ("Parent Process Writing '%s'\n", MESSAGE);

          /* Write the message to the write file descriptor and flush */
          /* the write file descriptor by writing a newline character */
          if (write (filedes[1], MESSAGE, sizeof (MESSAGE)) < 0)
               printf ("Error Writing To File Descriptor 1\n");
          if (write (filedes[1], "\n", 1 ) < 0)
               printf ("Error Writing To File Descriptor 1\n");

           printf ("Parent Process Waiting For Forked Process\n");

           /* Wait for the forked process to complete & display status */
           if (wait (&status) == fpid)
                printf ("Forked Process Status %d\n", WEXITSTATUS(status));
           else
                printf ("Error Waiting For The Forked Process\n");

           printf ("Parent Process Resuming\n");
      }

      printf ("Parent Process Stopping\n");

      return (0);
}