class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high; 
        while (l <= high) {
            int mid = l + (high - l) / 2;
            if (canEatAll(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canEatAll(const vector<int>& piles, int h, int k) {
        long long hours=0;
        for (int pile : piles) {
            hours += (pile+k-1)/k;
            if (hours>h) {
                return false;
            }
        }
        return true;
    }
};