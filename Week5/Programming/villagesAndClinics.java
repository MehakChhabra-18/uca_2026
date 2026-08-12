import java.util.*;

class villagesAndClinics{

    public int findLoad(int arr[], int clinic[], int clinics) {

        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a, b) -> (arr[b] / clinic[b]) - (arr[a] / clinic[a])
        );

        int n = arr.length;

        for(int i = 0; i < n; i++) {
            pq.add(i);
        }

        int remainingClinics = clinics - n;

        while(remainingClinics > 0) {

            int i = pq.poll();

            clinic[i]++;

            pq.add(i);

            remainingClinics--;
        }

        int i = pq.poll();

        return arr[i] / clinic[i];
    }

    public static void main(String[] args) {

        int clinics = 5;
        int arr[] = {200, 20, 50};
        int clinic[] = {1, 1, 1};

        int ans = new villagesAndClinics().findLoad(arr, clinic, clinics);

        System.out.println(ans);
    }
}