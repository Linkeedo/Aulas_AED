bool canConstruct(char* ransomNote, char* magazine) {
    for(int i=0; i<strlen(magazine);i++){
        char *pente=strchr(ransomNote,magazine[i]);
        if(pente != NULL){
            *pente = '0';
        }
    }
    for(int i=0; i<strlen(ransomNote);i++){
        if(ransomNote[i] != '0')
            return false;
    }
    return true;
}
