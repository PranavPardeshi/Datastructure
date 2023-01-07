import java.util.*;

class Collection1
{
    public static void main(String arr[])
    {
        LinkedList <Integer> lobj = new LinkedList<Integer>();

        lobj.add(11);
        lobj.add(21);
        lobj.add(51);
        lobj.add(101);
        System.out.println("Elements inside linkedlist are: "+lobj);

        lobj.addFirst(1);
        lobj.addLast(121);
        System.out.println("Elements inside linkedlist are: "+lobj);
        System.out.println("First element of linkedlist is: "+lobj.getFirst());

        Iterator iobj = lobj.iterator();
        while(iobj.hasNext())
        {
            System.out.println(iobj.next());
        }

        if(lobj.contains(51))
        {
            System.out.println("51 is present in linkedlist");
        }
        else
        {
            System.out.println("51 is not in there.");
        }

        lobj.remove();
        System.out.println("Elements inside linkedlist are: "+lobj);

        lobj.remove();
        System.out.println("Elements inside linkedlist are: "+lobj);

        lobj.removeLast();
        System.out.println("Elements inside linkedlist are: "+lobj);

        lobj.clear();
        System.out.println("Elements inside linkedlist are: "+lobj);
    }
}