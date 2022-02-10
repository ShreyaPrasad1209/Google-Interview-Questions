class SnapshotArray {
private:
    map<int, map<int, int>> snaps;
    int snapId = 0;
public:
    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) {
            map<int, int> mp; mp[0] = 0;
            snaps[i] = mp;
        }
    }
    
    void set(int index, int val) {
        snaps[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id); it--;
        return it->second;
    }
};