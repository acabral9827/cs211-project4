#include "restaurant.h"

////////////////////////////////////////////////////////////////////////////////
/* OPERATION FUNCTIONS */
void addToList( Node **head, char* name, int groupSize, STATUS status )
{
  /* allocate space for new data */
  Node *newNode = (Node*) malloc (sizeof(Node));
  /* set the values of the new node */
  newNode->name = name;
  newNode->numGroup = groupSize;
  if ( status == IN_RESTAURANT )
  {
    newNode->status = IN_RESTAURANT;
  }
  else
  {
    newNode->status = CALL_AHEAD;
  }

  newNode->next = NULL;

  Node *tmp = *head;

  /* check if list is empty */
  if ( *head == NULL )
  {
    *head = newNode;
    return;
  }
  else
  {
    while ( tmp->next != NULL )
    {
      tmp = tmp->next;
    }
    tmp->next = newNode;
    return;
  }

  return;
}

boolean doesNameExist( Node **head, char* name )
{
  /* create a temp to traverse */
  Node *tmp = *head;
  
  /* traverse through until name is found */
  while ( tmp != NULL )
  {
    if ( strcmp(tmp->name, name) == 0 )
    {
      return TRUE;
    }
    tmp = tmp->next;
  }

  return FALSE;
}

boolean updateStatus( Node **head, char *name, int debugMode )
{
  /* create temp to traverse */
  Node *tmp = *head;
  char *stat;

  while ( tmp != NULL )
  {
    if ( strcmp( tmp->name, name ) == 0 )
    {
      if ( tmp->status == CALL_AHEAD )
      {
        tmp->status = IN_RESTAURANT;
        return FALSE;
      }
      else
      {
        return TRUE;
      }
    }
    tmp = tmp->next;
  }
  /* not found */
  return FALSE;
}

void displayListInformation( Node **head )
{
  Node *tmp = *head;
  char *stat;

  printf("List:\n");
  while( tmp != NULL )
  {
    if ( tmp->status == IN_RESTAURANT )
    {
      stat = "In restaurant";
    }
    else
    {
      stat = "Called ahead";
    }

    /* display information */
    printf("Name: %s,  Size of group: %d,   Status: %s\n", tmp->name, tmp->numGroup, stat);

    /* move to next node */
    tmp = tmp->next;
  }
}

/* try returning name (CHAR) */
void retrieveAndRemove( Node **head, int table, int debugMode )
{
  Node *tmp = *head;
  Node *ptr;
  char *stat;
  
  /* list is empty */
  if ( tmp == NULL )
  {
    printf("*** ERROR: LIST IS EMPTY ***\n");
    return;
  }

  /* check first node in linked list */
  if ( tmp->numGroup <= table && tmp->status == IN_RESTAURANT )
    {
      *head = (*head)->next;
      free(tmp);

      /* debugging */
      // if ( debugMode == TRUE )
      // {
      //   displayListInformation( head );
      //   return;
      // }
    }

  /* check the rest of the list */
  while ( tmp->next != NULL )
  {
    /* check if table available */

    /* Debug info */
    if ( debugMode == TRUE )
    {
      /* get value of status */
      if ( tmp->status == IN_RESTAURANT )
      {
        stat = "In restaurant";
      }
      else
      {
        stat = "Call ahead";
      }
      //printf("Name: %s,  Size of group: %d,   Status: %s\n", tmp->name, tmp->numGroup, stat);
    }

    if ( tmp->next->numGroup <= table && tmp->next->status == IN_RESTAURANT )
    {
      /* use tail pointer to reconnect lists */
      ptr = tmp->next;
      tmp->next = ptr->next;

      free(ptr);
      return;
    }    

    tmp = tmp->next;
    if ( debugMode == TRUE )
    {
      displayListInformation( head );
    }
  }

  printf("No available tables for current groups' sizes");
  return;
}

int countGroupsAhead( Node **head, char* name, int debugMode )
{
  /* temp node used to traverse through node */
  Node *tmp = *head;
  /* counter to increment until group is found */
  int counter= 0;

  /* check if empty */
  if ( tmp == NULL )
  {
    return 0;
  }
  /* no one is ahead */
  if ( tmp->name == name )
  {
    return 0;
  }
  while ( tmp != NULL )
  {
    /* until name is found increment counter */
    if ( tmp->name != name )
    {
      counter++;
    }
    tmp = tmp->next;
  }

  return counter;
}

int displayGroupSizeAhead( Node **head, char* name )
{
  Node *tmp = *head;
  char* stat;

printf("Groups ahead:\n");
  while ( tmp != NULL )
  {
    if ( tmp->status == IN_RESTAURANT )
    {
      stat = "In restaurant";
    }
    else
    {
      stat = "Called ahead";
    }
    if ( tmp->name != name )
    {
      printf("Name: %s,  Size of group: %d,   Status: %s\n", tmp->name, tmp->numGroup, stat);
    }
    /* move to next node */
    tmp = tmp->next;
  }
}

////////////////////////////////////////////////////////////////////////////////