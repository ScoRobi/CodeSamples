The following code will merge determine the lowest common ancestor (LCA) between two given nodes in a balanced tree.

The function requires a pointer to the head of the tree as well as pointers to two nodes. A pointer to the LCA is returned.

Logic:
* Ensure all pointers are valid and the nodes do not equal the head.
* Determine if the nodes' values are both greater than or less than the current head. Call function recursively until nodes are equal to or on opposite side of head.
* Return the current head.