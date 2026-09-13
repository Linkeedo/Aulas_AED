/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *x = malloc ( 2 * sizeof ( int ) );
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++){
        for(int cont = 0; cont < numsSize; cont++){
            if( cont != i ){
                if( (nums[i] + nums[cont]) == target){
                x[0] = i;
                x[1] = cont;
                return x;
                }
            }
        }
    }
    return 0;
}
