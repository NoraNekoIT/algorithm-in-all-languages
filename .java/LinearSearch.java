public class LinearSearch {
    public static int linearSearch(int [] arr, int element) {
        for (int i = 0; i < arr.length; i++) {
            if (element == arr[i]) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int [] arr = {1,8,6,53,156,416,54161,841,8416,16,846,41,68416,5};
        System.out.println(linearSearch(arr,68416));
    }
}
