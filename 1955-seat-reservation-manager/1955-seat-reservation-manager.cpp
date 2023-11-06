class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int c = 0;
    SeatManager(int n) {    
        
    }
    
    int reserve() {
        if (pq.size() && pq.top() <= c) {
            int t = pq.top();
            pq.pop();
            return t;
        }
        c++;
        return c;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */