// See https://aka.ms/new-console-template for more information

public class Solution {
    public int SearchInsert(int[] nums, int target)
    {
        int low = 0, high = nums.Length - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
            {
                low++;
            }
            else if (nums[mid] > target)
            {
                high--;
            }
            else
            {
                return mid;
            }
        }

        return low;
    }
}