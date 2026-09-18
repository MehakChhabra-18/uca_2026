import java.util.*;
class intersectionOfTwoLinkedLists {
    static class Node
    {
        int data;
        Node next;
        Node(int d) {
            data = d;
            next = null;
        }
    }
     
    public Node getIntersection(Node headA, Node headB) {

        HashMap<Integer, Integer> map = new HashMap<>();
        while (headA != null) {
            map.put(headA.data, map.getOrDefault(headA.data, 0) + 1);
            headA = headA.next;
        }

        HashMap<Integer, Integer> map1 = new HashMap<>();

        while (headB != null) {
            map1.put(headB.data, map1.getOrDefault(headB.data, 0) + 1);
            headB = headB.next;
        }

        Node dummy = new Node(0);
        Node temp = dummy;

        for (int i : map.keySet()) {

            if (map1.containsKey(i)) {
                int count = Math.min(map.get(i), map1.get(i));
                while (count > 0) {
                    temp.next = new Node(i);
                    temp = temp.next;
                    count--;
                }
            }
        }

        return dummy.next;
    }

    public static void print(Node head)
    {
        while(head.next!=null)
        {
            System.out.print(head.data+"->");
            head=head.next;
        }

        System.out.print(head.data);
    }
    public static void main(String[] args)
    {
        intersectionOfTwoLinkedLists list=new intersectionOfTwoLinkedLists();
        Node a=new Node(1);
        a.next=new Node(2);
        a.next.next=new Node(3);
        a.next.next.next=new Node(4);
        a.next.next.next.next=new Node(6);

        Node b=new Node(2);
        b.next=new Node(4);
        b.next.next=new Node(6);
        b.next.next.next=new Node(8);
        Node newHead=list.getIntersection(a,b);
        print(newHead);

    }
}