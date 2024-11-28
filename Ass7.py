def find_subset(nums, target):
    # Sort the input list to make it easier to handle duplicates and 
    # optimize by stopping the search when the sum exceeds the target.
    nums.sort()
    
    # Initialize an empty list to store the current subset.
    possible_ans = []
    
    # Start the recursive helper function with initial values:
    # index = 0, current_sum = 0, and the empty possible_ans list.
    helper(nums, target, 0, 0, possible_ans)

def helper(nums, target, index, current_sum, possible_ans):
    # Base case: if current_sum matches the target, print the current subset (possible_ans).
    if current_sum == target:
        print(possible_ans)
        return

    # Initialize prev_element to track duplicate elements and avoid duplicate subsets.
    prev_element = -1

    # Iterate through the list starting from the given index.
    for i in range(index, len(nums)):
        # Only proceed if the current element is different from the previous one.
        if prev_element != nums[i]:
            # If adding the current element exceeds the target, exit the loop early.
            if nums[i] + current_sum > target:
                break
            # Add the current element to the possible_ans list.
            possible_ans.append(nums[i])
            # Update prev_element to the current element to avoid duplicates in further recursion.
            prev_element = nums[i]
            # Recursively call the helper function with updated index and sum.
            helper(nums, target, i + 1, current_sum + nums[i], possible_ans)
            # Backtrack by removing the last element to explore other subsets.
            possible_ans.pop()

if __name__ == "__main__":
    # Test case: find subsets of nums that add up to 9.
    nums = [1, 2, 5, 6, 8]
    find_subset(nums, 9)
