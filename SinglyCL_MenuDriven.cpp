#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class SinglyCL
{
	private:
		PNODE first;
		PNODE last;
		int size;
	public:
		
		SinglyCL()
		{
			first = NULL;
			last = NULL;
			size = 0;
		}
		void Display()
		{
			PNODE temp = first;
			if((first == NULL) && (last == NULL))
			{
				return;
			}
			do
			{
				cout<<"|"<<temp->data<<"|->";
				temp = temp->next;
			}while(temp != last->next);
			cout<<"\n";
		}
		
		int Count()
		{
			return size;
		}
		
		void InsertFirst(int no)
		{
			PNODE newn = new NODE;		//	Dynamic memory allocation
			newn->next = NULL;
			newn->data = no;
			
			if((first == NULL) && (last == NULL))
			{
				first = newn;
				last = newn;
			}
			else
			{
				newn->next = first;
				first = newn;				
			}
			last->next = first;
			size++;
		}
		void InsertLast(int no)
		{
			PNODE newn = new NODE;
			newn->next = NULL;
			newn->data = no;
			
			if((first == NULL) && (last == NULL))
			{
				first = newn;
				last = first;
			}
			else
			{
				last->next = newn;
				last = newn;				
			}
			last->next = first;
			size++;
		}
		
		void InsertAtPos(int no, int ipos)
		{
			if((ipos < 1) || (ipos > size+1))
			{
				return;
			}
			else if(ipos == 1)
			{
				InsertFirst(no);
			}
			else if(ipos == size+1)
			{
				InsertLast(no);
			}
			else
			{
				PNODE newn = new NODE;
				newn->next = NULL;
				newn->data = no;
				
				PNODE temp = first;
				for(int i = 1;i < ipos-1;i++)
				{
					temp = temp -> next;
				}
				newn->next = temp->next;
				temp->next = newn;
			}
			last->next = first;
			size++;
		}
		void DeleteFirst()
		{
			if((first == NULL) && (last == NULL))
			{
				return ;
			}
			else if(first == last)
			{
				delete first;
				first = NULL;
				last = NULL;
			}
			else
			{
				first = first->next;
				delete last->next;
				last->next = first;
			}
			size--;
		}
		void DeleteLast()
		{
			if((first == NULL) && (last == NULL))
			{
				return;
			}
			else if(first == last)
			{
				delete first;
				first = NULL;
				last = NULL;
			}
			else
			{
				PNODE temp = first;
				while(temp->next != last)
				{
					temp = temp->next;
				}
				delete last;
				last = temp;
				last->next = first;
			}
			size--;
		}
		void DeleteAtPos(int ipos)
		{
			if((ipos < 1) || (ipos > size))
			{
				return;
			}
			else if(ipos == 1)
			{
				DeleteFirst();
			}
			else if(ipos == size)
			{
				DeleteLast();
			}
			else
			{
				PNODE temp = first;
				
				for(int i = 1; i < ipos - 1;i++)
				{
					temp = temp->next;
				}
				
				PNODE targated = NULL;
				targated = temp->next;
				temp->next = targated->next;	// temp->next = temp->next->next;
				delete targated;
				
				last->next = first;				
				size--;			
			}
		}
		
};
int main()
{
	int choice = 0,inum = 0,ipos = 0,iret = 0;
	SinglyCL sobj;
    
    cout<<"----------------------Welcome to Singly Circular Linked List Operation----------------------\n";
	cout<<"Enter 1 : InsertFirst\n";
	cout<<"Enter 2 : InsertLast\n";
	cout<<"Enter 3 : InsertAtPos\n";
	cout<<"Enter 4 : DeleteFirst\n";
	cout<<"Enter 5 : DeleteLast\n";
	cout<<"Enter 6 : DeleteAtPos\n";
	cout<<"Enter 7 : Display \n";
	cout<<"Enter 8 : Count \n";
    cout<<"Enter 9 : Exit\n";
    cout<<"-------------------------------------------------------------------------------------------\n";

	while(1)
    {   
        cout<<"Enter your choice : ";
	    cin>>choice;
        if((choice <= 0) || (choice >= 10))
		{
			return -1;
		}
		else
		{
			switch(choice)
		    {
			    case 1:
			        cout<<"Enter number that you want to add at first : "<<"\n";
		    	    cin>>inum;
			    	sobj.InsertFirst(inum);
                	cout<<"Number is successfully added in linkedlist\n";				
                	break;

            	case 2:
		        	cout<<"Enter number that you want to add at last : "<<"\n";
                	cin>>inum;
    		    	sobj.InsertLast(inum);
					cout<<"Number is successfully added in linkedlist\n";
                	break;

            	case 3:
		        	cout<<"Enter number that you want to add : "<<"\n";
    				cin>>inum;
                	cout<<"Enter the position of number : "<<"\n";
                	cin>>ipos;
			    	sobj.InsertAtPos(inum,ipos);
					cout<<"Number is successfully added in linkedlist\n";
                	break;

            	case 4:
			    	sobj.DeleteFirst();
                	cout<<"Number successfully removed from linkedlist\n";
                	break;

            	case 5:
	    			sobj.DeleteLast();
                	cout<<"Number is successfully removed from linkedlist\n";                
                	break;  

            	case 6:
                	cout<<"Enter the position : "<<"\n";
                	cin>>ipos;
                	sobj.DeleteAtPos(ipos);
                	cout<<"Number is successfully removed from linkedlist\n"; 
                	break;               

            	case 7:
                	sobj.Display();
                	break;

            	case 8:
                	iret = sobj.Count();
                	cout<<"Number of elements inside linkelist are : "<<iret<<"\n";
                	break;
            
            	case 9:
                	cout<<"Thank you!!";
                	exit(0);
					break;  

    			default:
                	cout<<"Enter valid number\n";
                	break;
	    	}
		}
        
    }
	
	return 0;
}