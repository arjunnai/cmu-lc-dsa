class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1 ; i <= ratings.size()-1 ; i++){
            if (ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }else{
                candies[i] = 1;
            }
        }
        for (int i = ratings.size()-2 ; i >= 0 ; i--){
            if (ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

//1 3 2 1
//rating[i]> rating[i-1]
//candy[i] = candy[i-1]+1
//else 1
// 1 2 1 1 


//pass 2 
//rating[i]> rating[i+1]
//candy[i] = candy[i+1] + 1
//candy[i] = max(candy[i], candy[i+1])+1
// 1 3 2 1