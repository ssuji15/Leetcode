class UndergroundSystem {
public:
    unordered_map<int,string> passengerCheckIn;
    unordered_map<int,int> passengerCheckInTime;
    unordered_map<string,unordered_map<string,int>> totalTime;
    unordered_map<string,unordered_map<string,int>> numberOfPassengers;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        passengerCheckIn[id] = stationName;
        passengerCheckInTime[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        totalTime[passengerCheckIn[id]][stationName] += (t - passengerCheckInTime[id]);
        numberOfPassengers[passengerCheckIn[id]][stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)totalTime[startStation][endStation] / numberOfPassengers[startStation][endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */