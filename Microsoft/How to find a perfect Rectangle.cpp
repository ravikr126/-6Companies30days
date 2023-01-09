class Solution {
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    if (rectangles.size() == 0 || rectangles[0].size() == 0)
    {
        {
            return false;
        }
    
        int x1 = INT_MAX;
        int x2 = INT_MIN;
        int y1 = INT_MAX;
        int y2 = INT_MIN;
    
        unordered_set<string> set;
        long long area = 0;
    
        for (auto rect : rectangles)
        {
            x1 = min(rect[0], x1);
            y1 = min(rect[1], y1);
            x2 = max(rect[2], x2);
            y2 = max(rect[3], y2);
    
            area += ((long long)(rect[2] - rect[0])) * ((long long)(rect[3] - rect[1]));
    
            string s1 = to_string(rect[0]) + " " + to_string(rect[1]);
            string s2 = to_string(rect[0]) + " " + to_string(rect[3]);
            string s3 = to_string(rect[2]) + " " + to_string(rect[3]);
            string s4 = to_string(rect[2]) + " " + to_string(rect[1]);
    
            if (set.find(s1) != set.end())
            {
                set.erase(s1);
            }
            else
            {
                set.insert(s1);
            }
            if (set.find(s2) != set.end())
            {
                set.erase(s2);
            }
            else
            {
                set.insert(s2);
            }
            if (set.find(s3) != set.end())
            {
                set.erase(s3);
            }
            else
            {
                set.insert(s3);
            }
            if (set.find(s4) != set.end())
            {
                set.erase(s4);
            }
            else
            {
                set.insert(s4);
            }
        }
    
        if (set.find(to_string(x1) + " " + to_string(y1)) == set.end() || set.find(to_string(x1) + " " + to_string(y2)) == set.end() || set.find(to_string(x2) + " " + to_string(y1)) == set.end() || set.find(to_string(x2) + " " + to_string(y2)) == set.end() || set.size() != 4)
        {
            return false;
        }
    
        return area == ((long long)(x2 - x1)) * ((long long)(y2 - y1));
     }
};
    ```
