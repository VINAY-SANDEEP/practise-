import java.util.*;
public class G {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(0);
        list.add(2);
        list.add(4);
        list.add(6);
        list.add(8);
        System.out.println(list);
        System.out.println(list.get(0));
        System.out.println(list.set(0, 5));
        System.out.println(list.remove(3));
        System.out.println(list.size());
        System.out.println("printing");
        for (int i = 0; i < list.size(); i++) {
          System.out.println(list.get(i));   
        }
       System.out.println();
       Collections.sort(list);
       System.out.println(list);
    }
}
