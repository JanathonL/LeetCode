731. My Calendar II
class MyCalendarTwo {
public:
    
    vector<pair<int, int>> first;
    vector<pair<int, int>> second;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto item: second){
            if(item.first<end&&start<item.second){
                return false;
            }
        }
        for(auto item: first){
            if(item.first<end&&start<item.second){
                second.push_back({max(item.first, start), min(item.second, end)});
            }
        }
        first.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */