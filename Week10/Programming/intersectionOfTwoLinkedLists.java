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
        HashSet<Integer> set=new HashSet<>();
        while(headA!=null)
        {
            set.add(headA.data);
            headA=headA.next;
        }

        HashSet<Integer> set1=new HashSet<>();
        while(headB!=null)
        {
            set1.add(headB.data);
            headB=headB.next;
        }

        Node dummy=new Node(0);
        Node temp=dummy;
        for(int i:set)
        {
            if(set1.contains(i))
            {
                temp.next=new Node(i);
                temp=temp.next;
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