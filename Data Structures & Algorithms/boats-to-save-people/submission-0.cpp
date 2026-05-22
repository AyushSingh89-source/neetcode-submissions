class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(), people.end());
        
        int first = 0;
        int last = people.size() - 1; 

        while (first <= last) {
            if (people[first] + people[last] <= limit) {
                first++;
            }
            
            last--;  
            boats++; 
        }
        
        return boats;
    }
};