// https://leetcode.com/problems/design-twitter/

class Twitter {
    unordered_map<int, unordered_set<int>> friends;
    int curr = 0;
    vector<vector<int>> timeline;
    
public:
    Twitter() {
        friends.clear();
        curr = 0;
        timeline = vector<vector<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push_back({curr++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        
        int n = timeline.size() - 1;
        int count = 0;
        
        while(n > -1 && count < 10) {
            auto topTweet = timeline[n--];
            
            if(topTweet[2] == userId || friends[userId].count(topTweet[2])){
                ans.push_back(topTweet[1]);
                count++;
            }
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
