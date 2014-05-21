// Scott Robinson - scorobi@umd.edu - 2013

Node *merge_correct(Node *uno, Node *dos)
{
	Node *merged;
	
	if (uno == NULL)
	{
		return dos;
	}
	else if (dos == NULL)
	{
		return uno;
	}
	
	if (uno->data <= dos->data)
	{
		merged = uno;
		merged->next = merge_correct(uno->next, dos);
	}
	else
	{
		merged = dos;
		merged->next = merge_correct(uno, dos->next);
	}
	
	return merged;
}