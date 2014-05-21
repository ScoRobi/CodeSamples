The following code will merge two ordered linked lists containing integers into a single ordered linked list using only pointer manipulation. No new nodes and no copying.

The function accepts the head of two linked lists and returns a pointer to the new, combined linked list.

Logic:
*Determine the smallest element between the two linked lists. Set head of new list to this node.
*Find the next smallest element through recursion and set the next node to this. Continue until one of the lists reaches an end (NULL).
*Return pointer to new list