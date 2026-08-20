
public class numbersInArray {

    public int findNumber(int[] arr) {
        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            for (int num : arr) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }

            if (count % 3 != 0) {
                ans = ans | (1 << bit);
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        numbersInArray obj = new numbersInArray();

        int[] arr = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};

        int result = obj.findNumber(arr);

        System.out.println("The number that appears 4 times is: " + result);
    }
}