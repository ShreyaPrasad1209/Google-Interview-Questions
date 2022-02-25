class SnapshotArray {
private:
    vector<map<int, int>> snaps;
    int snapId = 0;
public:
    SnapshotArray(int length) {
        for(int index = 0; index < length ; index++) {
            map<int, int> mp;
            mp[snapId] = 0;
            snaps.push_back(mp);
        }
    }
    
    void set(int index, int val) {
        snaps[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};