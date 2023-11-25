// See https://aka.ms/new-console-template for more information

public class Solution {
    //88ms ?食大便啦
    public int[] CountBits(int n)
    {
        int low = 0b00000000000000000000000000000001;
        return Enumerable.Range(0, n + 1).ToList().Select(x =>
        {
            int intCounter = 0;
            int lowBit = low;
            for (int i = 0; i < 32; i++)
            {
                int intTemp = lowBit & x;
                if (intTemp > 0)
                { 
                    intCounter += 1; 
                }
                lowBit <<= 1;
                
                if (!(lowBit > x*2))
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            return intCounter;
        }).ToArray();
    }

    static void Main()
    {
        Console.WriteLine(string.Join(" ", new Solution().CountBits(2)));
    }
}