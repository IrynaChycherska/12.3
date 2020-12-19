#include <iostream>
#include <cstring>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* next,
		* prev;
	Info info;
};
void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
int kilkist(char* str)
{
	if (strlen(str) < 2)
		return 0;
	int k = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == str[i + 1] )
			k++;
	return k;
}
int main()
{
	char str[101];
	
	Elem* first = NULL,
		* last = NULL;
	for (int i = 1; i <= 10; i++)
		enqueue(first, last, i);
	while (first != NULL)
		cout << dequeue(first, last) << " ";
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << kilkist(str) << endl;
	cout << endl;
	return 0;

}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; 
	tmp->info = value; 
	tmp->next = NULL; 
	if (last != NULL)
		last->next = tmp; 
	tmp->prev = last; 
	last = tmp; 
	if (first == NULL)
		first = tmp; 
}
Info dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->next; 
	Info value = first->info; 
	delete first; 
	first = tmp; 
	if (first == NULL)
		last = NULL; 
	else
		first->prev = NULL; 
	return value; 
}