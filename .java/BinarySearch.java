import java.util.Arrays;

public class BinarySearch {

    public static int binarySearch(int [] arr, int element){
        int high = arr.length - 1;
        int low = 0;
        int mid;
        Arrays.sort(arr);
        while (low <= high){
            mid = (low + high) / 2;
            if (element == arr[mid]) {
                return mid;
            } else if (element > arr[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int [] arr = {1,8,6,53,156,416,54161,841,8416,16,846,41,68416,5};
        System.out.println(binarySearch(arr,68416));
    }
}
