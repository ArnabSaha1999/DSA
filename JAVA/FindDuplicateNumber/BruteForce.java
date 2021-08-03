package Arnab.com;

class BruteForce {
    public int findDuplicate(int[] nums) {
        for(int i = 0 ; i < nums.length ; i++) {
            for(int j = 0 ; j < nums.length ; j++) {
                if(i != j) {
                    if(nums[i] == nums[j]){
                        return nums[i];
                    }
                }
            }
        }
        return 0;
    }
}
