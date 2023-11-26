// See https://aka.ms/new-console-template for more information

public class Solution {
    public bool checkBranch(ref string s, int low, int high)
    {
        while (low <= high)
        {
            if (s[low] == s[high])
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
    public bool ValidPalindrome(string s)
    {
        int low = 0, high = s.Length - 1;
        while (low <= high)
        {
            if (s[low] == s[high])
            {
                low++;
                high--;
            }
            else
            {
                break;
            }
        }

        return checkBranch(ref s, low + 1, high) || checkBranch(ref s, low, high - 1);
    }
}