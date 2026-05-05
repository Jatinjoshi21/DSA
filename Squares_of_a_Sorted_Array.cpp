class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<nums.size()){
            if(nums[i]<0){
                neg.push_back(nums[i]*nums[i]);
            }
            else{
                pos.push_back(nums[i]*nums[i]);
            }
            i++;
        }

        reverse(neg.begin(),neg.end());

        i=0;

        while(j<pos.size() && k<neg.size()){
            if(pos[j]<=neg[k]){
                nums[i]=pos[j];
                i++;
                j++;
            }
            else{
                nums[i]=neg[k];
                i++;
                k++;
            }
        }

        while(j<pos.size()){
            nums[i]=pos[j];
            i++;
            j++;
        }

        while(k<neg.size()){
            nums[i]=neg[k];
            i++;
            k++;
        }
        return nums;

    }
};