bool isPalindrome(int x) {
    if ( x < 0 )
        return false;

    int digito = 0 , temp = x;
    double inverso = 0;
    while ( x != 0 ){
        digito = x % 10;
        inverso = inverso * 10 + digito;
        x /= 10;
    }
    return temp == inverso;
}
