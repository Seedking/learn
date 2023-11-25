// See https://aka.ms/new-console-template for more information

public class Solution {
    public string ReverseMessage(string message)
    {
        if (message == "")
        {
            return "";
        }
        
        return string.Join(" ", message.Split().Where(x => x != "").Reverse().ToArray());
    }

    static void Main()
    {
        Console.WriteLine(new Solution().ReverseMessage("        114 514 1919 810 "));
    }
}