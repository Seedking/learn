// See https://aka.ms/new-console-template for more information

public class Solution {
    public bool IsPalindrome(string s)
    {
        var strTemp = s.ToLower().Replace(" ", "").Where(c => char.IsLetterOrDigit(c)).ToArray();
        int low = 0, high = strTemp.Length - 1;
        while (low < high)
        {
            if (strTemp[low] == strTemp[high])
            {
                low++;
                high--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    static void Main()
    {
        Console.WriteLine(new Solution().IsPalindrome("0P"));
    }
}