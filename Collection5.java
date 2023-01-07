import java.util.*;

class Collection5
{
    public static void main(String arr[])
    {
        Hashtable <String,Integer> hobj = new Hashtable<String , Integer>();
        hobj.put("PPA",16500);
        hobj.put("LB",15000);
        hobj.put("Python",18000);
        hobj.put("Angular",14000);

        System.out.println(hobj.get("Python"));
        hobj.remove("LB");
        Enumeration eobj = hobj.keys();
        while(eobj.hasMoreElements())
        {
            System.out.println("Data is: "+eobj.nextElement());
        }
    }
}