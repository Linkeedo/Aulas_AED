int romanToInt(char* s) {
    int i = 0, total = 0, anterior = 0, atual = 0;
    for(i ; i < strlen ( s ) ; i++){
       if ( s[i] == 'I' ) 
           atual = 1;
           
       if ( s[i] == 'V' ) 
           atual = 5;
           
       if ( s[i] == 'X' ) 
           atual = 10;
           
       if ( s[i] == 'L' ) 
           atual = 50;
           
       if ( s[i] == 'C' ) 
           atual = 100;
           
       if ( s[i] == 'D' ) 
           atual = 500;
       
       if ( s[i] == 'M' ) 
           atual = 1000;
           
       if ( anterior < atual )
           total += atual - ( 2 * anterior);
       else
           total += atual;
           
       anterior = atual;
    }
    return total;
}