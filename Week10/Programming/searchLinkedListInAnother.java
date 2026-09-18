public class searchLinkedListInAnother {
    static class Node
    {
        int data;
        Node next;
        Node(int d) {
            data = d;
            next = null;
        }
    }

    public boolean search(Node a,Node b)
    {
        if(a==null) return false;
        while(b!=null)
        {
            Node temp1=a;
            Node temp2=b;
            while(temp1!=null && temp2!=null && temp1.data==temp2.data)
            {
                temp1=temp1.next;
                temp2=temp2.next;
            }

            if(temp1==null) return true;
            b=b.next;
        }
        return false;
    }

    public static void main(String[] args)
    {
        searchLinkedListInAnother list=new searchLinkedListInAnother();
        Node a=new Node(10);
        a.next=new Node(20);
    
        Node b=new Node(5);
        b.next=new Node(10);
        b.next.next=new Node(20);

        if(list.search(a,b))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
