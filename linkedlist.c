#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct node
{
    int info;          // Data part
    struct node *link; // Link part
};

// Declare a global pointer for the head of the list
struct node *head = NULL;

// Function to create a new node and return its pointer
struct node *create_node(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node)); // Allocate memory
    newnode->info = data;                                              // Assign data
    newnode->link = NULL;                                              // Initialize link as NULL
    return newnode;                                                    // Return the new node
}

// Function to insert a node at the front of the list
void insert_front(int data)
{
    struct node *newnode = create_node(data); // Create a new node
    newnode->link = head;                     // Link the new node to the head
    head = newnode;                           // Make the new node as the head
}

// Function to insert a node at the end of the list
void insert_end(int data)
{
    struct node *newnode = create_node(data); // Create a new node
    if (head == NULL)
    {                   // If the list is empty
        head = newnode; // Make the new node as the head
    }
    else
    {
        struct node *temp = head; // Create a temporary pointer
        while (temp->link != NULL)
        {                      // Traverse the list until the last node
            temp = temp->link; // Move the pointer to the next node
        }
        temp->link = newnode; // Link the last node to the new node
    }
}

// Function to insert a node such that the list is in ascending order
void insert_order(int data)
{
    struct node *newnode = create_node(data); // Create a new node
    if (head == NULL || head->info >= data)
    {                         // If the list is empty or the new node is smaller than the head
        newnode->link = head; // Link the new node to the head
        head = newnode;       // Make the new node as the head
    }
    else
    {
        struct node *temp = head; // Create a temporary pointer
        while (temp->link != NULL && temp->link->info < data)
        {                      // Traverse the list until the end or the next node is larger than the new node
            temp = temp->link; // Move the pointer to the next node
        }
        newnode->link = temp->link; // Link the new node to the next node
        temp->link = newnode;       // Link the current node to the new node
    }
}

// Function to delete the first node of the list
void delete_first()
{
    if (head == NULL)
    {                               // If the list is empty
        printf("List is empty.\n"); // Print an error message
    }
    else
    {
        struct node *temp = head; // Create a temporary pointer
        head = head->link;        // Make the head point to the next node
        free(temp);               // Free the memory of the first node
    }
}

// Function to delete a node before a specified position
void delete_before(int pos)
{
    if (head == NULL || pos <= 1)
    {                                       // If the list is empty or the position is invalid
        printf("Deletion not possible.\n"); // Print an error message
    }
    else
    {
        struct node *temp = head; // Create a temporary pointer
        struct node *prev = NULL; // Create a pointer to store the previous node
        int count = 1;            // Create a variable to count the nodes
        while (temp->link != NULL && count < pos - 1)
        {                      // Traverse the list until the end or the node before the specified position
            prev = temp;       // Store the current node as the previous node
            temp = temp->link; // Move the pointer to the next node
            count++;           // Increment the count
        }
        if (count == pos - 1)
        { // If the node before the specified position is found
            if (prev == NULL)
            {                      // If the node to be deleted is the head
                head = temp->link; // Make the head point to the next node
            }
            else
            {
                prev->link = temp->link; // Link the previous node to the next node
            }
            free(temp); // Free the memory of the node to be deleted
        }
        else
        {
            printf("Deletion not possible.\n"); // Print an error message
        }
    }
}

// Function to delete a node after a specified position
void delete_after(int pos)
{
    if (head == NULL)
    {                               // If the list is empty
        printf("List is empty.\n"); // Print an error message
    }
    else
    {
        struct node *temp = head; // Create a temporary pointer
        int count = 1;            // Create a variable to count the nodes
        while (temp->link != NULL && count < pos)
        {                      // Traverse the list until the end or the specified position
            temp = temp->link; // Move the pointer to the next node
            count++;           // Increment the count
        }
        if (count == pos && temp->link != NULL)
        {                                  // If the node after the specified position is found
            struct node *del = temp->link; // Create a pointer to store the node to be deleted
            temp->link = del->link;        // Link the current node to the next node
            free(del);                     // Free the memory of the node to be deleted
        }
        else
        {
            printf("Deletion not possible.\n"); // Print an error message
        }
    }
}

// Function to display the list
void display()
{
    if (head == NULL)
    {                               // If the list is empty
        printf("List is empty.\n"); // Print an error message
    }
    else
    {
        struct node *temp = head; // Create a temporary pointer
        while (temp != NULL)
        {                              // Traverse the list until the end
            printf("%d ", temp->info); // Print the data of the current node
            temp = temp->link;         // Move the pointer to the next node
        }
        printf("\n"); // Print a new line
    }
}

// Function to display the menu and return the user's choice
int menu()
{
    int choice;        // Create a variable to store the user's choice
    printf("Menu:\n"); // Print the menu
    printf("1. Insert a node at the front of the list.\n");
    printf("2. Insert a node at the end of the list.\n");
    printf("3. Insert a node such that the list is in ascending order.\n");
    printf("4. Delete the first node of the list.\n");
    printf("5. Delete a node before a specified position.\n");
    printf("6. Delete a node after a specified position.\n");
    printf("7. Display the list.\n");
    printf("8. Exit.\n");
    printf("Enter your choice: "); // Prompt the user to enter the choice
    scanf("%d", &choice);          // Read the choice
    return choice;                 // Return the choice
}

// Main function
int main()
{
    int choice, data, pos; // Create variables to store the choice, data and position
    do
    {
        choice = menu(); // Call the menu function and store the choice
        switch (choice)
        {                                              // Execute the appropriate case based on the choice
        case 1:                                        // Insert a node at the front of the list
            printf("Enter the data to be inserted: "); // Prompt the user to enter the data
            scanf("%d", &data);                        // Read the data
            insert_front(data);                        // Call the insert_front function with the data
            break;
        case 2:                                        // Insert a node at the end of the list
            printf("Enter the data to be inserted: "); // Prompt the user to enter the data
            scanf("%d", &data);                        // Read the data
            insert_end(data);                          // Call the insert_end function with the data
            break;
        case 3:                                        // Insert a node such that the list is in ascending order
            printf("Enter the data to be inserted: "); // Prompt the user to enter the data
            scanf("%d", &data);                        // Read the data
            insert_order(data);                        // Call the insert_order function with the data
            break;
        case 4:             // Delete the first node of the list
            delete_first(); // Call the delete_first function
            break;
        case 5:                             // Delete a node before a specified position
            printf("Enter the position: "); // Prompt the user to enter the position
            scanf("%d", &pos);              // Read the position
            delete_before(pos);             // Call the delete_before function with the position
            break;
        case 6:                             // Delete a node after a specified position
            printf("Enter the position: "); // Prompt the user to enter the position
            scanf("%d", &pos);              // Read the position
            delete_after(pos);              // Call the delete_after function with the position
            break;
        case 7:        // Display the list
            display(); // Call the display function
            break;
        case 8:      // Exit
            exit(0); // Print a message
            break;
        }
    } while (1);
}