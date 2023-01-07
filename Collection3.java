import java.util.*;
class Collection3
{
    public static void main(String arr[])
    {
        Vector <Float> vobj = new Vector <Float>();
           
            vobj.add(11f);
            vobj.add(21f);
            vobj.add(51f);
            vobj.add(101f);

            ListIterator iobj = vobj.listIterator();
            
            while(iobj.hasNext())
            {
                System.out.println(iobj.next());
            }
            vobj.clear();

        
    }
}