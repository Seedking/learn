// See https://aka.ms/new-console-template for more information

using System.Text;

public class Solution {
    public string MergeAlternately(string word1, string word2)
    {
        var e1 = word1.GetEnumerator();
        var e2 = word2.GetEnumerator();
        StringBuilder ret = new StringBuilder();
        bool e1b = true, e2b = true;
        while (e1b || e2b)
        {
            if (e1.MoveNext())
            {
                e1b = true;
                ret.Append(e1.Current);
            }
            else
            {
                e1b = false;
            }
            
            if (e2.MoveNext())
            {
                e2b = true;
                ret.Append(e2.Current);
            }
            else
            {
                e2b = false;
            }
        }

        return ret.ToString();
    }
}