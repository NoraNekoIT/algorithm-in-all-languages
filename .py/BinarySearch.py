def binarySearch(arr,start,end,target):
    while(start<=end):
        mid = start+ (end-start)//2
        if arr[mid] == target:
            return mid
        if target > arr[mid]:
            start = mid + 1
        else:
            end = mid - 1
    return -1

n = int(input("Enter size of array: "))
arr = []
print("Enter the numbers:")
for i in range(n):
    arr.append(int(input()))
target = int(input("Enter the number to be searched: "))
start = 0
end = len(arr) - 1
position = binarySearch(arr,start,end,target)

if position != -1:
    print(f"{target} is at index {position}")
else:
    print(f"{target} is not found.")