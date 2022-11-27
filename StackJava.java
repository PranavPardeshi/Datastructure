class Node
{
    public int data;
    public Node next;
}

class Stack
{
    private int size;
    private Node first;

    public Stack()
    {
        size = 0;
        first = null;
    }

    public void Push(int no)        // InsertFirst(ino)
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

    public int Pop()        // DeleteFirst()
    {
        int ino = first.data;
        if(size == 0)
        {
            return -1;
        }
        else if(size == 1)
        {
            ino = first.data;
            first = null;
        }
        else
        {
            ino = first.data;
            Node temp = first;
            
            first = first.next;
            temp = null;
        }
        this.size--;
        return ino;
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

class StackJava
{
    public static void main(String arr[])
    {
        Stack obj = new Stack();
        obj.Push(51);
        obj.Push(21);
        obj.Push(11);

        obj.Display();

        int iret = 0;
        iret = obj.Count();
        System.out.println("Elements inside stack are : "+iret);
                
        int iPoped = obj.Pop();
        obj.Display();
        System.out.println("Poped element is : "+iPoped);
    }
}