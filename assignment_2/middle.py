# print middle value
nums = [10,5,18,3]


middle = len(nums) // 2
if len(nums) % 2 == 0:
    middle_num = nums[middle -1: middle + 1]
else:
    middle_num = nums[middle]
       
print(middle_num)