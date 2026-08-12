import java.util.*;

class runningMedianInDataStream
{
    static PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    static PriorityQueue<Integer> maxHeap=new PriorityQueue<>(Collections.reverseOrder());
    public static void insert(int num)
    {
        if(maxHeap.isEmpty() || num<=maxHeap.peek())
        {
            maxHeap.offer(num);
        }

        else
        {
            minHeap.offer(num);
        }

        if(minHeap.size()>maxHeap.size()+1)
        {
            maxHeap.offer(minHeap.poll());
        }

        else if(maxHeap.size()>minHeap.size()+1)
        {
            minHeap.offer(maxHeap.poll());
        }

    }

    public static double getMedian()
    {
        if(maxHeap.size()==minHeap.size())
        {
            return (maxHeap.peek()+minHeap.peek())/2.0;
        }

        else if(maxHeap.size()>minHeap.size())
        {
            return maxHeap.peek();
        }
        return minHeap.peek();
    }
    public static void main(String[] args) {
        insert(0);
        insert(2);
        insert(3);
        insert(4);
        System.out.println(getMedian());
    }
}