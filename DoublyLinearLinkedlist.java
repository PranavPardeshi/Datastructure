class Node
{
    public int data;
    public Node next;
    public Node prev;
}

class DoublyLL
{
    private int size;
    private Node first;
    private Node last;

    public DoublyLL()
    {
        this.size = 0;
        first = null;
        last = null;
    }
    
    public int Count()
    {
        return size;
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

    public void InsertFirst(int no)
    {
        Node newn = new Node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        first.prev = null;
        last.next = null;
        this.size++;
    }
    public void InsertLast(int no)
    {
        Node newn = new Node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.prev = last;
            last.next = newn;
            last = newn;
        }
        first.prev = null;
        last.next = null;
        this.size++;
    }

    public void InsertAtPos(int no,int ipos)
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
            Node newn = new Node();
            newn.next = null;
            newn.prev = null;
            newn.data = no;

            Node temp = first;
            for(int i = 1; i < ipos-1;i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            first.prev = null;
            last.next = null;

            this.size++;
        }
    }
    public void DeleteFirst()
    {
        if((first == null) && (last == null))
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            Node temp = first;
            first = first.next;
            first.prev = null;
            temp = null;
        }
        first.prev = null;
        last.next = null;
        this.size--;
    }

    public void DeleteLast()
    {
        if((first == null) && (last == null))
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            Node temp = last;
            last = last.prev;
            last.next = null;
            temp = null;
        }
        first.prev = null;
        last.next = null;
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
            Node targated = temp.next;
            targated.next.prev = temp;
            temp.next = targated.next;
            targated = null;

            first.prev = null;
            last.next = null;
            this.size--;
        }
    }
}
class DoublyLinearLinkedlist
{
    public static void main(String arr[])
    {
        System.out.println("----------Doubly Linear linked list using Java----------");

        DoublyLL obj = new DoublyLL();
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.InsertLast(101);
        obj.InsertAtPos(51,3);
        obj.Display();
        
       /* obj.DeleteFirst();
        obj.Display();

        obj.DeleteLast();*/
        obj.DeleteAtPos(3);
        obj.Display();
        int iRet = 0;
        iRet = obj.Count();
        System.out.println("Elements inside linkedlist are : "+iRet);

    }
}