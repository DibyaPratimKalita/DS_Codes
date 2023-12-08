// Display the original doubly linked list
    printf("Original ");
    displayList(head);

    // Rotate the doubly linked list 'k' times
    int k = 3;
    rotateKTimes(&head, k);

    // Display the rotated doubly linked list
    printf("Doubly linked list after rotating %d times: ", k);
    displayList(head);

    // Free memory allocated for the doubly linked list
    freeList(&head);

    return 0;
}