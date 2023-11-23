// See https://aka.ms/new-console-template for more information

using System.Collections;
using System.Data;

public class Solution {
    public bool WordPattern(string pattern, string s)
    {
        var strArray = s.Split();
        if (strArray.Length != pattern.Length)
        {
            return false;
        }
        Dictionary<char, string> dict = new Dictionary<char, string>();
        ICollection<string> values = dict.Values;
        for (int i = 0; i < pattern.Length; i++)
        {
            string? temp;
            if (!dict.TryGetValue(pattern[i], out temp))
            {
                foreach (var str in values)
                {
                    if (str == strArray[i])
                    {
                        return false;
                    }
                }
                dict[pattern[i]] = strArray[i];
            }
            else
            {
                if (dict[pattern[i]] != strArray[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    static void Main()
    {
        var pattern = "abba";
        var s = "dog dog dog dog";
        bool b = new Solution().WordPattern(pattern, s);
        Console.WriteLine(b);
    }
}