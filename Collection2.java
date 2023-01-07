import java.util.*;

class Collection2
{
    public static void main(String arr[])
    {
        ArrayList <Integer> aobj = new ArrayList <Integer>();

        aobj.add(11);
        aobj.add(21);
        aobj.add(51);
        aobj.add(101);

        System.out.println("Elements inside Arraylist are : "+aobj);

        Iterator iobj = aobj.iterator();

        while(iobj.hasNext())
        {
            System.out.println(iobj.next());
        }
        if(aobj.contains(51))
        {
            System.out.println("51 is inside arraylilst");
        }
        else
        {
            System.out.println("51 is not present in arraylist");
        }
        aobj.set(2,101);
        System.out.println(aobj);
        aobj.clear();
        System.out.println(aobj);

    }
}