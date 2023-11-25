// See https://aka.ms/new-console-template for more information
public class Solution {
    public IList<int> FindWordsContaining(string[] words, char x)
    {
        int len = words.Length;
        IList<int> ret = new List<int>();
        for (int i = 0; i < len; i++)
        {
            if (words[i].Contains(x))
            {
                ret.Add(i);
            }
        }

        return ret;
    }
}