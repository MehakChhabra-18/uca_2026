public class reverseLLUsingRecursion {
    static class Node
    {
        int data;
        Node next;
        Node(int d)
        {
            data=d;
            next=null;
        }
    }

    public Node reverse(Node head)
    {
        if(head==null || head.next==null)
            return head;

        Node newHead=reverse(head.next);
        head.next.next=head;
        head.next=null;

        return newHead;
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
        reverseLLUsingRecursion r=new reverseLLUsingRecursion();
        Node a=new Node(1);
        a.next=new Node(2);
        a.next.next=new Node(3);
        a.next.next.next=new Node(4);
        Node newHead=r.reverse(a);
        print(newHead);
    }
}
