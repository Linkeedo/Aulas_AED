int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int mais_rico=0;
    for(int i=0; i<accountsSize;i++){
       int soma=0;
        for(int j=0; j<(*accountsColSize);j++)
            soma += accounts[i][j];
    if(soma >= mais_rico)
        mais_rico = soma;
    soma=0;
    }
    return mais_rico;
}
