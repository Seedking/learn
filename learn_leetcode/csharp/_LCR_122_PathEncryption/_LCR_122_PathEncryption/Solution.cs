// See https://aka.ms/new-console-template for more information

public class Solution {
    public string PathEncryption(string path)
    {
        return new string(path.Select(x => x = (x == '.') ? ' ' : x).ToArray());
    }
}