import java.util.*;

class Node
{
    public int data;
    public Node lchild;
    public Node rchild;
}
// 51   21  101  105  55  20 
class BinaryTree
{
    private Node Head;

    public BinaryTree()
    {
        Head = null;
    } 
    
    public void Insert(int no)
    {
        Node newn = new Node();
        newn.data = no;
        newn.lchild = null;
        newn.rchild = null;

        if(Head == null)
        {
            Head = newn;
        }
        else
        {
            Node temp = Head;
            while(true)     // unconditional loop
            {
                if(temp.data == no)
                {
                    temp = null;
                    break;
                }
                else if(no > temp.data)
                {
                    if(temp.rchild == null)
                    {
                        temp.rchild = newn;
                        break;
                    }
                    temp = temp.rchild;
                }
                else if(no < temp.data)
                {
                    if(temp.lchild == null)
                    {
                        temp.lchild = newn;
                        break;
                    }
                    temp = temp.lchild;
                }
            }
        }
    }

    public boolean Search(int no)
    {
        boolean flag = false;
        if(Head == null)
        {
            return flag;
        }
        else
        {
            while(Head != null)
            {
                if(Head.data == no)
                {
                    flag = true;
                    break;
                }
                else if(no > Head.data)
                {
                    Head = Head.rchild;
                }
                else if(no < Head.data)
                {
                    Head = Head.lchild;
                }
            }
        }
        return flag;
    }
}

class BST
{
    public static void main(String arr[])
    {
        boolean bret = false;
        int ino = 0,iret = 0;
        
        Scanner sobj = new Scanner(System.in);
        
        BinaryTree bobj = new BinaryTree();
        bobj.Insert(51);
        bobj.Insert(101);
        bobj.Insert(21);

        System.out.println("Enter number to search");
        ino = sobj.nextInt();
        bret = bobj.Search(ino);
        
        if(bret == true)
        {
            System.out.println("Number is there");
        }
        else
        {
            System.out.println("Number is not there");
        }
        iret = sobj.Count();
        System.out.println("Elements inside binary tree are "+iret);
    }
}