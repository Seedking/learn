// See https://aka.ms/new-console-template for more information

using System.Collections;

public class Solution {
    public int[] CountNumbers(int cnt)
    {
        int num = 1;
        int max = 1;
        for (int i = 0; i < cnt; i++)
        {
            max *= 10;
        }

        int[] ret = new int[max-1];

        for (int i = 0; i < max-1; i++)
        {
            ret[i] = num;
            num += 1;
        }

        return ret;
    }

    static void Main()
    {
        Console.WriteLine(new Solution().CountNumbers(1).ToString());
    }
}