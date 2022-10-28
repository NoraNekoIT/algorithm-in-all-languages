import java.util.Arrays;

class InsertionSort{
    //method for insertion sort
    static void mergeSort(int arr[]){
        for(int i=1;i<arr.length;i++){
            int key = arr[i];
            int j = i-1;

            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
            }
            arr[j+1]=key;
        }
    }
    public static void main(String[] args) {
        int arr[] = {67,24,98,-1,0};

        System.out.println("Before sorting :"+Arrays.toString(arr));
        mergeSort(arr);
        System.out.println("After sorting :- "+Arrays.toString(arr));
    }
}