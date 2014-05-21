// Scott Robinson - scorobi@umd.edu - 2013

Node *findLCA(Node *root, Node *p, Node *q)
{
	if (!root || !p || !q)
		return NULL;

	if (p == root || q == root)
		return root;

	if (p->value < root->value && q->value < root->value)
	{
		return findLCA(root->left, p, q);
	}
	else if (p->value > root->value && q->value > root->value)
	{
		return findLCA(root->right, p, q);
	}
	else
	{
		return root;
	}
}