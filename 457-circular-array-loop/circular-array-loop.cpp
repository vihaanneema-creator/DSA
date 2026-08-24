class Solution {
public:
     int nextIndex(vector<int>&nums,int curr){
        int n = nums.size();
         return (curr + nums[curr]%n + n) % n;
     }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int slow = i;
            int fast = i;

            bool direction = nums[i]>0;
             while(true){
              int slowNext = nextIndex(nums,slow);

              if((nums[slowNext]>0) != direction){
                break;
              }
              if (slowNext == slow){
                break;
              }

                slow = slowNext;

                int fastNext = nextIndex(nums,fast);

                if((nums[fastNext]>0) != direction){
                    break;
                }
                if(fastNext == fast){
                    break;
                }
                int fastNext2 = nextIndex(nums,fastNext);

                if ((nums[fastNext2] > 0) != direction){
                    break;
                }
                if(fastNext2 == fastNext){
                    break;
                }         
                    fast = fastNext2;

                    if (slow==fast){
                        return true;
                    }

             

            }
        }
        return false;
        
    }
};