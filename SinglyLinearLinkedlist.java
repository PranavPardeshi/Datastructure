class Node
{
	public int data;
	public Node next;
}

class SinglyLL
{
	private int size;
	private Node first;
	
	public SinglyLL()
	{
		this.size = 0;
		this.first = null;
	}
	
	public void InsertFirst(int no)
	{
		Node newn = new Node();
		
		newn.data = no;
		newn.next = null;
		
		if(first == null)
		{
			first = newn;
		}
		else
		{
			newn.next = first;
			first = newn;
		}
		this.size++;
	}
	
	public void InsertLast(int no)
	{
		Node newn = new Node();
		newn.data = no;
		newn.next = null;
		
		if(first == null)
		{
			first = newn;
		}
		else
		{
			Node temp = first;
			
			while(temp.next != null)
			{
				temp = temp.next;
			}
			temp.next = newn;
		}
		size++;
	}
	
	public void InsertAtPos(int no,int ipos)
	{
		if((ipos < 1) || (ipos > size+1))
		{
			return;
		}
		if(ipos == 1)
		{
			InsertFirst(no);
		}
		else if(ipos == (size+1))
		{
			InsertLast(no);
		}
		else
		{
			Node newn = new Node();
			newn.data = no;
			newn.next = null;
			
			Node temp = first;
			for(int i = 1;i < ipos-1;i++)
			{
				temp = temp.next;
			}
			newn.next = temp.next;
			temp.next = newn;
			
			this.size++;
		}
	}
	public void DeleteFirst()
	{
		if(size == 0)
		{
			return;
		}
		else if(size == 1)
		{
			first = null;
		}
		else
		{
			first = first.next;
		}
		this.size--;
	}
	public void DeleteLast()
	{
		if(size == 0)
		{
			return;
		}
		else if(size == 1)
		{
			first = first.next;
		}
		else
		{
			Node temp = first;
			while(temp.next.next != null)
			{
				temp = temp.next;
			}
			temp.next = null;
		}
		this.size--;
	}
	public void DeleteAtPos(int ipos)
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
			Node temp = first;

			for(int i = 1; i < ipos-1;i++)
			{
				temp = temp.next;
			}
			temp.next = temp.next.next;
			
			this.size--;
		}
	}
	
	public void Display()
	{
		Node temp = first;
		
		while(temp != null)
		{
			System.out.print("|"+temp.data+"|->");
			temp = temp.next;
		}
		System.out.println();		
	}
	public int Count()
	{
		return this.size;
	}
}

class SinglyLinearLinkedlist
{
	public static void main(String arr[])
	{
		System.out.println("---------Singly Linear Linked List Using Java---------");
		
		SinglyLL obj = new SinglyLL();
		int iRet = 0;
		obj.InsertFirst(21);
		obj.InsertFirst(1);
		obj.InsertLast(101);
		obj.InsertLast(151);
		obj.InsertLast(251);
		obj.InsertAtPos(51,3);
		obj.Display();
		obj.DeleteAtPos(3);
		obj.Display();

		obj.DeleteFirst();
		obj.DeleteLast();
		obj.Display();

		iRet = obj.Count();
		System.out.println("Elements in linkedlist are : "+iRet);
		
	}
}