nums = [10, 5, 18, 3]
lowest = nums[0]

for i in range(1, len(nums)):
    if nums[i] < lowest:
        lowest = nums[i]
        
print(lowest)
