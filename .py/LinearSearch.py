def Linear(arr,value):
    for i in arr:
        if i==value:
            return True 
    return False 


arr=[1,2,3,4,5,6]
value=2
print(Linear(arr,value))