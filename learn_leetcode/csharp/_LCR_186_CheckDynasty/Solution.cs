// See https://aka.ms/new-console-template for more information

public class Solution {
    public bool CheckDynasty(int[] places) {
        Array.Sort(places);
        int len = places.Length;
        int num = 0, zero = 0;
        for (int i = 0; i < len; i++)
        {
            if (places[i] == 0)
            {
                zero += 1;
            }
            else
            {
                num = i;
                break;
            }
        }

        for (int i = num + 1; i < len; i++)
        {
            if (places[i] == places[i-1])
            {
                return false;
            }

            if (places[i] == places[i-1] + 1)
            {
                continue;
            }
            else
            {
                int int_temp = places[i] - places[i - 1] -1;
                if (zero > 0 && zero - int_temp >= 0)
                {
                    zero -= int_temp;
                    continue;
                }
                return false;
            }
        }

        return true;
    }

    static void Main()
    {
        int[] places = { 0,0,8,5,4 };
        Console.WriteLine(new Solution().CheckDynasty(places));
    }
}