// See https://aka.ms/new-console-template for more information

public class Solution {
    public int AddDigits(int num)
    {
        string str = num.ToString();
        int ret = 0;
        start:
        foreach (var c in str)
        {
            ret += (c - 48);
        }

        if (ret > 9)
        {
            str = ret.ToString();
            ret = 0;
            goto start;
        }

        return ret;
    }
    static void Main()
    {
        Console.WriteLine(new Solution().AddDigits(38));
    }
}