package Searchingalgorithms;

import java.util.Scanner;

public class binarySearch {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter elements: ");
        for(int i=0; i<n; i++){
            arr[i] = sc. nextInt();
        }
        System.out.println("Enter target element: ");
        int target = sc.nextInt();
        //calling the function - Iterative
        binarysearch(arr, 0, arr.length - 1, target);

        //using recursion - calling the function
        int index = binarySearchUsingRecursion(arr, 0, arr.length -1, target);
        if (index != -1) {
            System.out.println("Element found at index " + index);
        }
        else {
            System.out.println("Element not found in the array");
        }
        
    }
    //creating a function to return the index of element - Iterative
    public static void binarysearch(int[] arr, int first, int last, int target) {
       
        //to avoid integer overflow
        //get index of mid element
        int mid = first + (last - first)/ 2;
        //repeat until this condition meet
        while( first <= last ){  

            if ( arr[mid] < target ){  
                //key to be searched is in the first half of array
              first = mid + 1;     
            }else if ( arr[mid] == target ){  
                //if element to be searched is the mid element
              System.out.println("Element is found at index: " + mid);  
              break;  
            }else{  
                //the key is to be searched in the second half of the array
               last = mid - 1;  
            }  
            mid = first + (last - first)/ 2; 
         }  
         //if first and last overlap, then key is not present
         if ( first > last ){  
            System.out.println("Element is not found!");  
         }
         
    }
     //creating another function to return the index of element - Recursion
    public static int binarySearchUsingRecursion(int[] arr, int start, int end, int target){
        while(start <= end){
        
            //to avoid integer overflow
            //get index of mid element
            int mid = start + (end - start)/2;

            //base condition
            if(target == arr[mid]){
                return mid;
            }
            else if(target>arr[mid]){
                //recursively search for key, key is in left half of the array
                return binarySearchUsingRecursion(arr, mid + 1, end, target);
            }
            else{
                //recursively search for key, key is in right half of the array
                return binarySearchUsingRecursion(arr, start, mid - 1, target);
            }
        }
        return -1;
    }
}
