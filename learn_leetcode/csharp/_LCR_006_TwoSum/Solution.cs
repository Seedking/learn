// See https://aka.ms/new-console-template for more information

public class Solution {
    public int[] TwoSum(int[] numbers, int target)
    {
        int len = numbers.Length, low = 0, high = len - 1;
        while(low < high)
        {
            int intTemp = numbers[low] + numbers[high];
            if (intTemp == target)
            {
                break;
            }
            if (intTemp < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return new[] { low, high };
    }
}