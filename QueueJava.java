class Node
{
    public int data;
    public Node next;
}

class Queue
{
    private int size;
    private Node first;

    public Queue()
    {
        this.size = 0;
        first = null;
    }

    public void Enqueue(int no)    // InsertLast(no)
    {
        Node newn = new Node();
        newn.data = no;
        newn.next = null;

        if(size == 0)
        {
            first = newn;
        }
        else if(size == 1)
        {
            first.next = newn;
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
        this.size++;
    }
    public int Dequeue()        // DeleteFirst()
    {
        int ino = 0;
        if(size == 0)
        {
            return -1;
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

    public int Count()
    {
        return this.size;
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
}

class QueueJava
{
    public static void main(String A[])
    {
        Queue obj = new Queue();
        obj.Enqueue(11);
        obj.Enqueue(21);
        obj.Enqueue(51);
        obj.Enqueue(101);

        obj.Display();

        int iret = 0;
        iret = obj.Count();
        System.out.println("Elements inside queue are : "+iret);

        int iValue = 0;
        iValue = obj.Dequeue();
        
        obj.Display();

        System.out.println("Dequeued element is : "+iValue);

    }
}