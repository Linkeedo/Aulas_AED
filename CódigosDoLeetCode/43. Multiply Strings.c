char *multiply( char *num1, char *num2 ) {
	int tamanhoPrimeiro = strlen(num1),tamanhoSegundo = strlen(num2);
	int tamanhoTotal = tamanhoPrimeiro + tamanhoSegundo, i = 0;
	unsigned char *resposta = malloc ( ( tamanhoTotal + 1 ) * sizeof(char) );
    resposta[tamanhoTotal] = '\0';
	do{
		resposta[i] = '0';
		i++;
	}while(i < tamanhoTotal );

	for(int segundo = tamanhoSegundo - 1, casas = 0 ; segundo >= 0 ; segundo-- , casas++){
		for(int primeiro = tamanhoPrimeiro - 1, casasTotais = casas ; primeiro >= 0; primeiro-- , casasTotais++){
			resposta [ tamanhoTotal - 1 - casasTotais ] += ( ( num2 [ segundo ] - 48 ) * ( ( num1 [ primeiro ] ) - 48 ) ); 
			int contadorTemp = 0;
			if ( ( resposta [ tamanhoTotal - 1 - casasTotais - contadorTemp ] - 48 ) >= 10 ){
				do{
                    char restoPequeno = '0' , restoGrande = '0' ;
                    restoGrande = ( ( resposta [ tamanhoTotal - 1 - casasTotais - contadorTemp ] - 48 ) / 10 ) + 48;
                    restoPequeno = ( resposta [ tamanhoTotal - 1 - casasTotais - contadorTemp ] - ( 10 * ( restoGrande-48 ) ) );
                    resposta [ tamanhoTotal - 1 - casasTotais - contadorTemp ] = (restoPequeno);
                    contadorTemp++;
                    resposta [ tamanhoTotal - 1 - casasTotais - contadorTemp ] += ( restoGrande - 48 );
                }while( ( resposta [ tamanhoTotal - 1 - casasTotais - contadorTemp ] - 48 ) >= 10 );
			}
		}
	}
    char *res = NULL,*temp = resposta;
	while ( temp[0] == '0' && strlen( temp ) > 1 ){
		temp++;
	}
	res = malloc( ( strlen( temp ) + 1 ) * sizeof( char ) );
	strcpy( res, temp );
    res[ strlen( temp ) ] = '\0';
    free(resposta);
	return res;
}
