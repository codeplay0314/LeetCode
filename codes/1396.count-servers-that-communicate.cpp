/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
    class Record {
    public:
        int n;
        double avg;
        Record() : n(0), avg(0) {}
        Record(double t) : n(1), avg(t) {}
    };
    class InStInfo {
    public:
        int time;
        string st;
    public:
        InStInfo() : time(0), st("") {}
        InStInfo(int t, string str) : time(t), st(str) {}
    };
    unordered_map<int, InStInfo> inStation;
    unordered_map<string, Record> Ttable;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        InStInfo info(t, stationName);
        inStation[id] = info;
    }
    
    void checkOut(int id, string stationName, int t) {
        InStInfo info = inStation[id];
        string route = info.st + "-" + stationName;
        if (Ttable.find(route) == Ttable.end()) {
            Ttable[route] = Record((double)(t - info.time));
        } else {
            Record rec = Ttable[route];
            rec.avg = (rec.avg * rec.n + t - info.time) / (rec.n + 1);
            rec.n++;
            Ttable[route] = rec;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;
        return Ttable[route].avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

