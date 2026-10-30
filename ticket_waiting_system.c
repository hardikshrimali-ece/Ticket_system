#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = -1, rear = -1;

void addPassenger()
{
    char name[50];

    if (rear == MAX - 1)
    {
        printf("Waiting queue is full!\n");
        return;
    }

    printf("Enter passenger name: ");
    scanf(" %49[^\n]", name);

    if (front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear], name);
    printf("%s added to waiting list.\n", name);
}

void allocateTicket()
{
    if (front == -1)
    {
        printf("No passengers in waiting list!\n");
        return;
    }

    printf("Ticket allocated to: %s\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void displayQueue()
{
    int i;

    if (front == -1)
    {
        printf("Waiting list is empty!\n");
        return;
    }

    printf("\nWaiting List:\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Ticket Waiting System ---\n");
        printf("1. Add Passenger\n");
        printf("2. Allocate Ticket\n");
        printf("3. Display Waiting List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addPassenger();
                break;

            case 2:
                allocateTicket();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("Exiting system.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
