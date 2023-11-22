// See https://aka.ms/new-console-template for more information

class Solution
{
    static int[] intArray = new[] { 2, 3, 5 };
    public bool IsUgly(int n)
    {
        if (n <= 0) return false;
        foreach (var i in intArray)
        {
            while (n % i == 0)
            {
                n/= i;
            }
        }

        return n == 1;
    }
}