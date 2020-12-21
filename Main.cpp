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
				Node *newNode = new Node(data);

				if(this->isEmpty())
					this->tail = newNode;
				else
					newNode->next = this->head;
				this->head = newNode;
			}
			void AddLast(int data)
				{
					Node *newNode = new Node(data);
					if(this->isEmpty())
						this->head = newNode;
					else
						this->tail->next = newNode;
					this->tail = newNode;
				}
			void removeFirst() throw( Exception )
						{
			               if(this->isEmpty())
			            	   throw new Exception("List is empty");
			               else if(this->head == this->tail)
			               {
			            	   delete this->head;
			            	   this->head = this->tail = NULL;
			               }
			               else
			               {
                                Node *temp = this->head;
                                this->head = this->head->next;
                                delete temp;

			               }
						}
			void removeLast() throw( Exception )
			{
               if(this->isEmpty())
            	   throw new Exception("List is empty");
               else if(this->head == this->tail)
               {
            	   delete this->head;
            	   this->head = this->tail = NULL;
               }
               else
               {
                   Node *trav = this->head;
                   while(trav->next != this->tail)
                   {
                       trav = trav->next;
                   }

                   this->tail = trav;
                   this->tail->next = NULL;
                   delete this->tail->next;

               }
			}
			int nodeCount()
			{
				int count = 0;
				Node *trav = this->head;
				while(trav != NULL)
				{
					trav = trav->next;
					count ++;
				}
				return count;
			}


			void AddAtPosition(int position,int data)
			{
				if(position <= 0)
					throw new Exception("Invalid Position");
				else if(position ==1)
					this->AddFirst(data);
				else if(position > this->nodeCount())
					this->AddLast(data);
				else
				{
					Node *trav = this->head;
					for(int count = 1 ;count < position -1 ; count++)
					{
						trav = trav->next;
					}

					Node *newNode = new Node(data);
					newNode->next = trav->next;
					trav->next = newNode;

				}
			}
			void removeFromPosition(int position)
						{
							if(position <= 0)
								throw new Exception("Invalid Position");
							else if(position == 1)
								this->removeFirst();
							else if(position >= this->nodeCount())
							{
								cout<<this->nodeCount();
								this->removeLast();
							}
							else
							{
								Node *trav = this->head;

								for(int count = 1 ;count < position -1 ; count++)
								{
									trav = trav->next;
								}

								Node *temp = trav->next;
								trav->next = temp->next;
								delete temp;

							}
						}
			void print() throw(Exception)
		    {
				if(this->isEmpty())
					throw new Exception("List is empty");
				else
				{
				   Node *trav = this->head;
                   while(trav != NULL)
                   {
                	   cout<<trav->data<<" ";
                	   trav = trav->next;
                   }

                   cout<<endl;
				}
		    }

			void reverse()
			{
				if(this->isEmpty())
					throw new Exception("List is empty");
				else
				{
					Node *trav = this->head;
                    Node *current;
                    Node *previous = NULL;

                    while(trav != NULL)
                    {
                        current = trav;
                        trav = trav->next;
                        current->next = previous;
                        previous = current;
                    }

                    this->tail = this->head;
                    this->head = previous;
				}
			}

		};
}

int menu_list(void)
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Add At First"<<endl;
	cout<<"2.Add At Last"<<endl;
	cout<<"3.Add At a position"<<endl;
	cout<<"4.Remove First"<<endl;
	cout<<"5.Remove Last"<<endl;
	cout<<"6.Remove From Position"<<endl;
	cout<<"7.Print List"<<endl;
	cout<<"8.Reverse List"<<endl;
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
   using namespace collection;
   LinkedList list;

   while((choice = ::menu_list()) != 0)
   {
		try {
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
				case 3:
				   accept_record("Enter position : ",position);
				   accept_record("Enter data : ",data);
		           list.AddAtPosition(position,data);
				   break;
				case 4:
				   list.removeFirst();
				   break;
				case 5:
				   list.removeLast();
				   break;
				case 6:
				   accept_record("Enter position : ",position);
				   list.removeFromPosition(position);
				   break;
				case 7:
				   list.print();
				   break;
				case 8:
					list.reverse();
					break;
			}
		} catch (Exception &e)
		{
			cout<<e.getMessage()<<endl;
		}

	   cout<<"---------------------"<<endl;
   }

   return 0;
}
