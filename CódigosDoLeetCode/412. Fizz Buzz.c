/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** resposta = (char**) malloc(n * sizeof(char*));
    for(int i=1; i<=n ;i++){
        int temp = i-1;
        if(i % 3 == 0 && i % 5 == 0){
           resposta[temp] = (char*)malloc(sizeof("FizzBuzz"));
           strcpy(resposta[temp],"FizzBuzz");
        }else
        if(i % 3 == 0){
            resposta[temp] = (char*)malloc(sizeof("Fizz"));
            strcpy(resposta[temp],"Fizz");
        }else
        if(i % 5 == 0){
            resposta[temp] = (char*)malloc(sizeof("Buzz"));
            strcpy(resposta[temp],"Buzz");
        }else{
            resposta[temp] = (char*)malloc(sizeof(char*));
            sprintf(resposta[temp],"%d",i);
        }
    }
    return resposta;
}
