T = int(input())
for t in range(T):
    n = int(input())
    nums = [int(x) for x in input().split(" ")]
    max_diff = 0

    y = 0
    for i in range(n-1): 
        y += max(0, nums[i] - nums[i+1])
        max_diff = max(max_diff, nums[i] - nums[i+1])
    z = 0
    for i in range(n-1): 
        z += min(max_diff, nums[i])
    print("Case #{0}: {1} {2}".format(t + 1, y, z))

        
    
