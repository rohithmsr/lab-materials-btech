// https://leetcode.com/problems/design-underground-system/ 

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInMap; // uid - station, time
    unordered_map<string, pair<double, int>> routeMap; // routename - totaltime, count
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [fromStation, startTime] = checkInMap[id];
        checkInMap.erase(id);
        
        string routeName = fromStation + "_" + stationName;
        
        routeMap[routeName].first += t - startTime;
        routeMap[routeName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        
        auto [totalTime, count] = routeMap[routeName];
        return (double) totalTime / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
