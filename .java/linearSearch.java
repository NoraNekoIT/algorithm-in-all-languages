package Searchingalgorithms;

import java.util.Scanner;

public class linearSearch {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size: ");
        int N = sc.nextInt();
        int[] arr = new int[N];
        System.out.println("Enter array elements: ");
        for(int i=0; i<N; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter target element: ");
        int target = sc.nextInt();

        // iterative approach - calling the function
        int result = LinearSearch(arr, N, target);
        if(result == -1){
            System.out.println("Element not found");
        }else{
            System.out.println("Element is found at : "+result);
        }
        //using recursion - calling the function
        int result1 = LinearSearchUsingRecursion(arr, 0, arr.length -1, target);
        if(result1 == -1){
            System.out.println("Element not found");
        }else{
            System.out.println("Element is found at : "+result1);
        }

    }
    //creating a function to return the index of element - Iterative
    static int LinearSearch(int[] arr, int n, int target){
        
        for(int i=0; i<n; i++){
            //return index if found
            if(arr[i] == target){
                return i;
            }
        }
        //return -1 if not found
        return -1;

    }

    //creating another function - Recursion
    static int LinearSearchUsingRecursion(int[] arr, int start, int end, int target){

        if(start > end){
            return -1;
        }
        if(arr[start] == target){
            return start;
        }
        if(arr[end] == target){
            return end;
        }
        return LinearSearchUsingRecursion(arr, start+1, end, target);
        
    }
}
