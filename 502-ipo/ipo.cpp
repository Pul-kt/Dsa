class Solution {
public:
    int findMaximizedCapital(int k,int w,vector<int>& profits,
    vector<int>& capital) { 
        
    priority_queue<vector<int>,vector<vector<int>>,
    greater<vector<int>>> minHeap;
    for(int i = 0;i<profits.size();i++){
        minHeap.push({capital[i],i});
    }

    priority_queue<vector<int>> maxHeap;
    while(k > 0){

        while(!minHeap.empty() && minHeap.top()[0] <= w){
            auto top = minHeap.top();
            maxHeap.push({profits[top[1]],top[1],top[0]});
            minHeap.pop();
        }
        if (maxHeap.empty()) break;
        int profitTaken = maxHeap.top()[0];
        w += profitTaken;
        k--;
        maxHeap.pop();
    }
    return w;
    }
};