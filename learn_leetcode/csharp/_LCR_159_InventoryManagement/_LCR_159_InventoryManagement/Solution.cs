// See https://aka.ms/new-console-template for more information

public class Solution {
    public int[] InventoryManagement(int[] stock, int cnt)
    {
        Array.Sort(stock);
        int[] ret = new int[cnt];
        for (int i = 0; i < cnt; i++)
        {
            ret[i] = stock[i];
        }

        return ret;
    }
    
}