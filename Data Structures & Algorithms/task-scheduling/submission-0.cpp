class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        unordered_map<int,int> mp;
        for(char c:tasks) mp[c]++;
        for(auto &p: mp){
            pq.push(p.second);
        }
        int time = 0;
        while(!q.empty() || !pq.empty()){
            time++;
            if(!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;
                if(cnt>0){
                    q.push({cnt, time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }

        }
        return time;
    }
};
