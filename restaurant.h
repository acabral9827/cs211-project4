#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* GLOABLS */
int debugMode;
typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;
typedef enum {IN_RESTAURANT, CALL_AHEAD} STATUS;

/* stack struct */
typedef struct Node
{
  char *name;
  int numGroup;
  STATUS status;
  struct Node *next;   /* pointer to next position in the stack */
}Node;

/* Function prottypes */
/* USER INTERFACE */
void clearToEoln();
int getNextNWSChar();
int getPosInt ();
char *getName();
void printCommands();
/* LINKED LIST FUNCTION */
void addToList( Node **head, char* name, int groupSize, STATUS status );
boolean doesNameExist( Node **head, char* name );
boolean updateStatus( Node **head, char *name, int debugMode );
void retrieveAndRemove( Node **head, int table, int debugMode );
int countGroupsAhead( Node **head, char* name, int debugMode );
int displayGroupSizeAhead( Node **head, char* name );
void displayListInformation( Node **head );
/* LINKED LIST HELPER FUNCTIONS */
void doAdd ( Node **head, int debugMode );
void doCallAhead ( Node **head, int debugMode );
void doWaiting ( Node **head, int debugMode );
void doRetrieve ( Node **head, int debugMode );
void doList ( Node **head, int debugMode );
void doDisplay ( Node **head, int debugMode );
int main (int argc, char **argv);