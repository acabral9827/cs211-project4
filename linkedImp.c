#include "restaurant.h"

////////////////////////////////////////////////////////////////////////////////
/* LINKED LIST FUNCTIONS */ 
void doAdd ( Node **head, int debugMode )
{
  /* get group size from input */
  int size = getPosInt();
  if (size < 1)
    {
      printf ("Error: Add command requires an integer value of at least 1\n");
      printf ("Add command is of form: a <size> <name>\n");
      printf ("  where: <size> is the size of the group making the reservation\n");
      printf ("         <name> is the name of the group making the reservation\n");
      return;
    }
  
  /* get group name from input */
  char *name = getName();
  if (NULL == name)
    {
      printf ("Error: Add command requires a name to be given\n");
      printf ("Add command is of form: a <size> <name>\n");
      printf ("  where: <size> is the size of the group making the reservation\n");
      printf ("         <name> is the name of the group making the reservation\n");
      return;
    }
  
  printf ("Adding In-restaurant group \"%s\" of size %d\n", name, size);
  
  // add code to perform this operation here
  /* check if the group exists */
  if ( doesNameExist( head, name ) == TRUE )
  {
    printf("Group is already in the list\n");
    return;
  }
  else
  {
    /* debug */
    if ( debugMode == TRUE )
    {
      displayListInformation( head );
    }

    /* display new group added */
    printf("New group added:    Name: %s,   Size of group: %d\n", name, size);
    addToList( head, name, size, IN_RESTAURANT );
    return;
  }

}
 
 
void doCallAhead ( Node **head, int debugMode )
{
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 1\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }
 
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Call-ahead command requires a name to be given\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }
 
 printf ("Adding Call-ahead group \"%s\" of size %d\n", name, size);
 
 // add code to perform this operation here
 /* check if group exists already */
  if ( doesNameExist( head, name ) == TRUE )
  {
    printf("Group is already in the list\n");
    return;
  }
  else
  {
    /* debug */
    if ( debugMode == TRUE )
    {
      displayListInformation( head );
    }

    /* display new group added */
    printf("Group calling ahead:    Name: %s,   Size of group: %d\n", name, size);
    addToList( head, name, size, CALL_AHEAD );
    return;
  }

}
 
void doWaiting ( Node **head, int debugMode )
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Waiting command is of form: w <name>\n");
    printf ("  where: <name> is the name of the group that is now waiting\n");
    return;
   }
 
 printf ("Call-ahead group \"%s\" is now waiting in the restaurant\n", name);
 
 // add code to perform this operation here
 /* check if group exists */
 if ( doesNameExist( head, name ) == FALSE )
  {
    printf("This group is not in the list\n");
    return;
  }
  else
  {
    /* debug */
    if ( debugMode == TRUE )
    {
      displayListInformation( head );
    }
    /* they are in the restaurant */
    if ( updateStatus( head, name, debugMode ) == FALSE )
    {
      return;
    }
    /* not in restaurant */
    else
    {
      updateStatus( head, name, debugMode );
    }
  }
}
 
void doRetrieve ( Node **head, int debugMode )
{
 /* get table size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Retrieve command requires an integer value of at least 1\n");
    printf ("Retrieve command is of form: r <size>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    return;
   }
 clearToEoln();
 printf ("Retrieve (and remove) the first group that can fit at a table of size %d\n", size);
 
 // add code to perform this operation here
 retrieveAndRemove(head, size, debugMode);
 return;
}
 
void doList ( Node **head, int debugMode )
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: l <name>\n");
    printf ("  where: <name> is the name of the group to inquire about\n");
    return;
   }
 
 printf ("Group \"%s\" is behind the following groups\n", name);
 
 // add code to perform this operation here
 /* check if group is in list */
 if ( doesNameExist( head, name ) == FALSE )
 {
   printf("This group is not in the list");
   return;
 }
 else
 {
   printf("Groups ahead of %s group is: %d\n", name, countGroupsAhead( head, name, debugMode ));
   /* display the size of each group ahead */
   displayGroupSizeAhead( head, name );
   return;
 }
}
  
void doDisplay ( Node **head, int debugMode )
{
 clearToEoln();
 printf ("Display information about all groups\n");
 
 // add code to perform this operation here
 displayListInformation( head );
}
////////////////////////////////////////////////////////////////////////////////