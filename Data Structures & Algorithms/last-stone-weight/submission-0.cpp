class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(),stones.end());

        while(maxHeap.size()>1){
            int y = maxHeap.top();
            maxHeap.pop();

            int x = maxHeap.top();
            maxHeap.pop();

            if(y!=x){
                maxHeap.push(y-x);
            }
        }

        if(maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};
