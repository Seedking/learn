// See https://aka.ms/new-console-template for more information

public class Solution {
    public char DismantlingAction(string arr)
    {
        Dictionary<char, int> dict = new Dictionary<char, int>();
        foreach (var c in arr)
        {
            int int_temp;
            if (!dict.TryGetValue(c, out int_temp))
            {
                dict[c] = 1;
            }
            else
            {
                dict[c] += 1;
            }
        }

        foreach (var kvp in dict)
        {
            if (kvp.Value != 1)
            {
                continue;
            }
            else
            {
                return kvp.Key;
            }
        }

        return ' ';
    }

    static void Main()
    {
        Console.WriteLine("Answer : " + new Solution().DismantlingAction("abbccdeff"));
    }
}