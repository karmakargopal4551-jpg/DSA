class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        map<int, int> mp;
        for (int &handNumber : hand) {
            mp[handNumber]++;
        }

        while (!mp.empty()) {
            int current = mp.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                int card = current + i;

                if (mp[card] == 0) {
                    return false;
                }

                mp[card]--;
                if (mp[card] == 0) {
                    mp.erase(card);
                }
            }
        }
        
        return true;
    }
};