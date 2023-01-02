class Solution {
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0;
        int cows = 0;
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;//charater : freq

        for(int index = 0; index < secret.size(); index++)
        {
            if(secret[index] == guess[index]) // digit of guess is presnt in secret & is at correct pos
                bulls++;
            
            else
            {
                map1[secret[index]]++;
                map2[guess[index]]++;
            }
        }

        for(auto current : map2)
        {
            if(map1.find(current.first) != map1.end())
                cows += min(map1[current.first],map2[current.first]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};