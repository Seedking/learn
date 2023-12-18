// See https://aka.ms/new-console-template for more information

using System.Collections;

public class Solution {
    public int Fib(int n)
    {
        if (n < 2)
        {
            return n;
        }
        
        int[] array = {0,1};

        for (int i = 2; i <= n; i++)
        {
            var int_temp = array[0] + array[1];
            array[0] = array[1];
            array[1] = int_temp % 1000000007;
        }

        return array[1];
    }
}