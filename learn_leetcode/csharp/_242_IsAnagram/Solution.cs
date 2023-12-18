// See https://aka.ms/new-console-template for more information

public class Solution {
    public bool IsAnagram(string s, string t)
    {
        if (s.Length != t.Length)
        {
            return false;
        }
        
        var len = s.Length;
        if (len == 1)
        {
            if (s == t)
            {
                return true;
            }
        
            if (s != t)
            {
                return false;
            }
        }
        
        var sA = s.ToArray();
        var tA = t.ToArray();
        Array.Sort(sA);
        Array.Sort(tA);

        for (int i = 0; i < len; i++)
        {
            if (sA[i] != tA[i])
            {
                return false;
            }
        }
        return true;
    }
    
    static void Main()
    {
        Console.WriteLine(new Solution().IsAnagram("ac","bb"));
    }
}

