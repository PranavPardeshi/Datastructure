class Node
{
    public int data;
    public Node next;
}

class SinglyCL
{
    private int size;
    private Node first;
    private Node last;

    public SinglyCL()
    {
        this.size = 0;
        this.first = null;
        this.last = null;
    }

    public int Count()
    {
        return size;
    }

    public void Display()
    {
        Node temp = first;
        do
        {
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        }while(temp != last.next);
        System.out.println();
    }

    public void InsertFirst(int no)
    {
        Node newn = new Node();
        newn.data = no;
        newn.next = null;
        
        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
            last.next = first;
        }
        this.size++;
    } 

    public void InsertLast(int no)
    {
        Node newn = new Node();
        newn.data = no;
        newn.next = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            last.next = newn;
            last = newn;
            
        }
        last.next = first;
        this.size++;    
    }

    public void InsertAtPos(int no,int ipos)
    {
        if((ipos < 1) || (ipos > size+1))
        {return;}

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
            newn.data = no;
            newn.next = null;

            Node temp = first;

            for(int i=1; i < ipos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            last.next = first;
            this.size++;
        }
    }
    public void DeleteFirst()
    {
        if((first == null) && (last == null))
        {
            return;
        }
        if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            Node temp = first;
            first = first.next;
            temp = null;   

        }
        last.next = first;
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
            Node temp = first;
            while(temp.next != last)
            {
                temp = temp.next;
            }
            last = null;
            last = temp;
            last.next = first;
        }
        this.size--;
    }
    public void DeleteAtPos(int ipos)
    {
        if((ipos < 1) || (ipos > size+1))
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

            for(int i=1; i < ipos-1;i++)
            {
                temp = temp.next;
            }
            Node targated = temp.next;
            temp.next = targated.next;
            targated = null;
            last.next = first;
            this.size--;
        }
    }

}

class SinglyCircularLinkedlist
{
    public static void main(String a[])
    {
        System.out.println("---------Singly Circular Linked List Using Java---------");
        
        SinglyCL obj = new SinglyCL();
        int iRet = 0;

        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.InsertAtPos(51,3);
        obj.InsertLast(101);
        obj.Display();

        //obj.DeleteFirst();
        //obj.Display();
        
        //obj.DeleteLast();
        obj.DeleteAtPos(3);
        obj.Display();

        iRet = obj.Count();
        System.out.println("Elements inside linkedlist are : "+iRet);
    }
}