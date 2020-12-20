#include<iostream>
#include<string>
using namespace std;

namespace collection
{

		class Exception
		{
		private:
			string message;
		public:
			Exception(string message = "")
			{
				this->message = message;
			}
			string getMessage(void) const throw()
			{
			   return this->message;
			}
		};
		class LinkedList;
		class Node
		{
		private:
			int data;
			Node *next;
		public:
			Node(int data = 0)
			{
				this->data = data;
				this->next = NULL;
			}
			friend class LinkedList;
		};
		class LinkedList
		{
		private:
			Node *head;
			Node *tail;
		public:
			LinkedList()
			{
				this->head = NULL;
				this->tail = NULL;
			}
			bool isEmpty()
			{
				return this->head == NULL;
			}
			void AddFirst(int data)
			{
				Node *newNode = new Node(10);
				if(this->isEmpty())
					this->tail = newNode;
				else
					newNode->next = this->head;
				this->head = newNode;
			}
			void AddLast(int data)
				{
					Node *newNode = new Node(10);
					if(this->isEmpty())
						this->head = newNode;
					else
						tail->next = newNode;
					this->tail = newNode;
				}
		};
}

int menu_list(void)
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Add At First"<<endl;
	cout<<"2.Add At Last"<<endl;
	cout<<"Enter Choice:";
	cin>>choice;

	return choice;
}

void accept_record(string message,int& data)
{
   cout<<message;
   cin>>data;
}

int main(void)
{
   int choice,data,position;
   collection::LinkedList list;

   while(choice = ::menu_list() != 0) // @suppress("Assignment in condition")
   {
	   switch(choice)
	   {
	       case 1:
	          accept_record("Enter data : ",data);
	          list.AddFirst(data);
	          break;
	       case 2:
	       	  accept_record("Enter data : ",data);
	       	  list.AddLast(data);
	       	  break;
	   }
   }

   return 0;
}
