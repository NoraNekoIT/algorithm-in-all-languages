import java.util.*;

class Merge_Sort
{
    //method to print the elements of the array
	static void printArray(int arr[])
    {
        StringBuffer sb=new StringBuffer("");
        int n = arr.length;
        for (int i=0; i<n; ++i)
            sb.append(arr[i]+" ");
        System.out.println(sb.toString());
    }

    

	public static void main(String args[])
	{
	    //taking input using Scanner class
		Scanner sc = new Scanner(System.in);
		
		//taking testcases
		int T = sc.nextInt();
		while(T>0)
		{
		    //taking elements count
			int n = sc.nextInt();
			
			//creating an object of class Merge_Sort
			Merge_Sort ms = new Merge_Sort();
			
			//creating an array of size n
			int arr[] = new int[n];
			
			//adding elements to the array
			for(int i=0;i<n;i++)
				arr[i] = sc.nextInt();

            
			Solution g = new Solution();
			
			//calling the method mergeSort
			g.mergeSort(arr,0,arr.length-1);

            //calling the method printArray
			ms.printArray(arr);
		T--;
		}
	}
}



// } Driver Code Ends


class Solution
{
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         
         
             int left[]=Arrays.copyOfRange(arr,l,mid+1);
             int right[]=Arrays.copyOfRange(arr,mid+1,r+1);
             int k=l;
             int n=left.length;
             int m=right.length;
             int i=0;
             int j=0;
          while(i<n && j<m)
          {
              if(left[i]<=right[j])
              {
                  arr[k++]=left[i];
                  i++;
                  
              }else{
                  arr[k++]=right[j];
                  j++;
              }
          }
          while(i<n)
          {
               arr[k++]=left[i];
                  i++; 
          }
          while(j<m)
          {
              arr[k++]=right[j];
                  j++;
          }
             
         
    }
    void mergeSort(int arr[], int l, int r)
    {
        // System.out.println(r);
        //code her
        
         if(l<r)
         {
                      int mid=(l+r)/2;
                      mergeSort(arr,l,mid);
                      mergeSort(arr,mid+1,r);
                      merge(arr,l,mid,r);
         }
    }
}
