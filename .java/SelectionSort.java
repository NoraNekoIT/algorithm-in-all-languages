import java.util.Arrays;

class SelectionSort{

        //METHOD FOR SELECTION SORT
        static void selectioSort(int arr[]){
            for(int i=0;i<arr.length-1;i++){
                int minPos = i;
                for(int j=i+1;j<arr.length;j++){
                    if(arr[j]<arr[minPos])
                      minPos=j;
                }

                //now if minPos is not equal to i
                //then swap elements
                if(i!=minPos){
                    int temp = arr[minPos];
                    arr[minPos]= arr[i];
                    arr[i]=temp;
                }
            }

        }


    public static void main(String[] args){
        int arr[] ={23,2,3,-1,0};
        System.out.println("Before sorting :-"+Arrays.toString(arr));
        selectioSort(arr);
        System.out.println("After sorting :-"+Arrays.toString(arr));
    }
}