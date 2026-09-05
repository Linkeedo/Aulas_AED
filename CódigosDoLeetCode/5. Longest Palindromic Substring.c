char* longestPalindrome(char* s) {
    char *c,*palindromo;
    int absoluto_tamanho=0,absoluto_ini=0;
    for(c=s; *c != '\0' ;c = c+1 ){
    int i=strlen(c), maior_palin = 0, tamanho_palin=0,ini=0,fim=0,ini_final = 0;
        for(ini=c-s,fim=c-s+1; ini>=0 && fim<strlen(s); ini--,fim++){
            if(s[ini] == s[fim]){
                tamanho_palin = fim - ini + 1;
                if(tamanho_palin > maior_palin){
                    maior_palin = tamanho_palin;
                    ini_final= ini;
                }
            }else
                break;
        }
        tamanho_palin=0;
        for(ini=c-s,fim=c-s; ini>=0 && fim<strlen(s); ini--,fim++){
            if(s[ini] == s[fim]){
                tamanho_palin = fim - ini + 1;
                if(tamanho_palin > maior_palin){
                    maior_palin = tamanho_palin;
                    ini_final= ini;
                }
            }else
                break;
        }
        if(maior_palin > absoluto_tamanho){
            absoluto_tamanho = maior_palin;
            absoluto_ini = ini_final;
        }
    }
    if (absoluto_tamanho == 0 && strlen(s) > 0) {
        absoluto_tamanho = 1;
        absoluto_ini = 0;
    }
    if(strlen(s) == 0)
        return "";
    palindromo = malloc(((absoluto_tamanho)+1) * sizeof(char));
    strncpy(palindromo,&s[absoluto_ini],absoluto_tamanho);
    palindromo[absoluto_tamanho] = '\0';
    return palindromo;
}
