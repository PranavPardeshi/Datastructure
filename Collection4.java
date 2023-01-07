import java.util.*;

class Collection4
{
    public static void main(String arr[])
    {
        Stack <Character> sobj = new Stack<Character>();
        sobj.push('P');
        sobj.push('R');
        sobj.push('A');
        sobj.push('N');
        sobj.push('A');
        sobj.push('V');

        System.out.println("Elements inside stack : "+sobj);

        sobj.pop();
        
        System.out.println("Elements inside stack : "+sobj);
    }
}