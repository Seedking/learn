// See https://aka.ms/new-console-template for more information

using System.Text;

public class Solution {
    public char FindTheDifference(string s, string t)
    {
        uint ret = 0;

        foreach (var c in s)
        {
            ret += c;
        }
        
        foreach (var c in t)
        {
            ret -= c;
        }

        return (char)Math.Abs(ret);
    }
}