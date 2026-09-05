int numberOfSteps(int num) {
    int passos=0;
    for(;num != 0;){
        if( num % 2 == 0){
            num = num/2;
            passos++;
        }
        else{
            num = num-1;
            passos++;
        }
    }
    return passos;
}
