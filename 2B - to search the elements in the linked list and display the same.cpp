#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void searchAndDisplay(struct Node* head, int target) {
    struct Node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == target) {
            printf("Element %d found at position %d.\n", target, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Element %d not found in the linked list.\n", target);
}

int main() {
    struct Node* head = NULL;
    int numNodes, data, searchElement;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    searchAndDisplay(head, searchElement);

    return 0;
}


/*Enter the number of nodes: 5
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Enter data for node 4: 40
Enter data for node 5: 50
Enter the element to search: 30
Element 30 found at position 2.
*/
