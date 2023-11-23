// See https://aka.ms/new-console-template for more information

public class Solution {
    public int InventoryManagement(int[] stock)
    {
        int ret = 0;
        int i_temp = 0;
        int len = stock.Length;
        int num = stock.Length / 2;
        Dictionary<int, int> dict = new Dictionary<int, int>();
        for (int i = 0; i < len; i++)
        {
            int out_temp;
            if (!dict.TryGetValue(stock[i], out out_temp))
            {
                dict[stock[i]] = 1;
            }
            else
            {
                dict[stock[i]] += 1;
            }
        }

        foreach (var kvp in dict)
        {
            if (kvp.Value > num && kvp.Value > i_temp)
            {
                ret = kvp.Key;
                i_temp = kvp.Value;
            }
        }
        return ret;
    }

    static void Main()
    {
        int[] stock = {6,1,3,1,1,1};
        Console.WriteLine(new Solution().InventoryManagement(stock));
    }
}