class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        /** we can insert at both front and tail to avoid special judging **/
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        /** Note the boundary of for loop **/
        for(int i = 0; i < s && n > 0; ++i) {
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }   
        return n <= 0;
    }
};