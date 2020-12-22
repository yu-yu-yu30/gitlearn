#include <iostream>;
#include <vector>;
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>element_result(0);
        int len = nums.size();
        if (len==0){
            return element_result;
        }
        if(len==1){
            element_result.push_back(nums[0]);
            return element_result;
        }
        int calculate_1 = 0;
        int calculate_2 = 0;
        int a=nums[0];int b = nums[0];
        for (int num:nums){
            if (num==a){
                calculate_1++;
                continue;
            }
            if(num==b){
                calculate_2++;
                continue;
            }
            if (calculate_1==0){
                a = num;
                calculate_1++;
                continue;
            }
            else if(calculate_2==0){
                b =num;
                calculate_2++;
                continue;
            }
            calculate_1--;
            calculate_2--;
        }
        calculate_1=calculate_2=0;
        for(int num:nums){
            if(num==a){
                calculate_1++;
            }
            else if(num==b){
                calculate_2++;
            }}
        if(calculate_1>nums.size()/3){
            element_result.push_back(a);
        }
        if(calculate_2>nums.size()/3){
            element_result.push_back(b);
        }
        return element_result;
    }
};

class zhongshu_2 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> cands,cnts;

        if (len==0){
            return vector<int>(0);
        }
        cands.assign(2,nums[0]);
        cnts.assign(2,0);
        for (auto num:nums){
            bool flag = false;
            for(int i = 0;i<cands.size();++i){
                if(num==cands[i]){
                    ++cnts[i];
                    flag = true;
                    break;
                }
            }
            if (!flag){
                bool flag_2 = false;
                for(int j=0;j<cands.size();++j) {
                    if (cnts[j] == 0) {
                        cands[j] = num;
                        cnts[j]++;
                        flag_2 = true;
                        break;
                    }
                }
                if(!flag_2){
                    for(int k =0;k<cnts.size();++k){
                        --cnts[k];
                    }
                }
            }



        }
//        if(cands[0]==cands[1]){
//            cands.pop_back();
//        }
        cnts.assign(2,0);
        for (auto num:nums){
            for(int i = 0;i<cands.size();++i){
                if (cands[i]==num){
                    ++cnts[i];
                    break;
                }

            }
        }
        vector<int>res;
        for(int i=0;i<cnts.size();++i){
            if(cnts[i]>len/3){
                res.push_back(cands[i]);
            }
        }
        return res;


    }


};







//int main(){
//    vector<int>test = {1,2};
//    zhongshu_2 a;
//    vector<int>b;
//    b = a.majorityElement(test);
//    for(int x:b){
//        cout<<x<<" ";
//    }
//}
//
