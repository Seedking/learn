// See https://aka.ms/new-console-template for more information

public class Solution {
    public int[] TwoSum(int[] price, int target)
    {
        int[] ret = {};
        int low = 0, high = price.Length - 1;
        while (low < high)
        {
            int int_temp = price[low] + price[high];
            if (int_temp == target)
            {
                ret = new[] { price[low] , price[high] };
                break;
            }
            else
            {
                if (int_temp > target)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        return ret;
    }
}