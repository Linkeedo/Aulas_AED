/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
   int *soma=malloc(numsSize*sizeof(int)), somador = 0, i=0;
   do{
        somador += nums[i];
        soma[i] = somador;
        i++;
   }while(i < numsSize);
(*returnSize) = i;
return soma; 
}
