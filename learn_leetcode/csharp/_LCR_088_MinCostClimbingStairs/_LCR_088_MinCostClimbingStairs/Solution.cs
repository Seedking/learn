// See https://aka.ms/new-console-template for more information

public class Solution {
    public int MinCostClimbingStairs(int[] cost)
    {
        int len = cost.Length;
        int low = 0, high = 0;
        for (int i = 2; i <= len; i++)
        {
            int next = Math.Min(low + cost[i - 1], high + cost[i - 2]);
            high = low;
            low = next;
        }

        return low;
    }

    static void Main()
    {
        Console.WriteLine(new Solution().MinCostClimbingStairs(new []{10,15,20}));
    }
}