#include <iostream>
#include <string>
#include <math.h>

using namespace std;

char* binario (unsigned long long a, unsigned long long n){
	
	unsigned long long i = 0;
	unsigned long long acum = 0;
	

	char *bin = new char[n+1];
			
	if(a == 0){
		bin[0] = '0';	
	}else if(a==1){
		bin[0] = '1';
	}
	
	else{
		
		bin[0] = '1';	
		
		while (a != 1){ // obtains the string of the binary number // obtiene el string del numero binario
		
			acum = a % 2;
			
			if(acum == 0)			
				bin[n-i-1] = '0';

				
			else bin[n-i-1] = '1';
	
			a = a  / 2;
			i++;
		
		}
		
	}
	
	
	return bin;
	
	
}

unsigned long long expRapida(unsigned long long base, unsigned long long exponente, unsigned long long modulo){
	
	
	cout<<endl;  
	char* p = NULL;
	unsigned long long n = 1;
	
	while ((pow(2,n)-1) < exponente) // loop to obtain the size of the binary numer//  bucle para obtener el tamaño del numero binario
		n++;
		
	
	p = binario(exponente, n);
	
	cout<<endl;

	unsigned long long x = 1;
	
	for(unsigned long long i=0; i < n; i++){ 
		
		if(p[i] == '1'){
			x = pow(x, 2);
			x = (x*base) % modulo;
		}
			
		else if(p[i] == '0'){
			x = pow(x,2);
			x = x % modulo;
		}
	}
	

	delete[] p;
	
	return x;
}

int main(){
	
	unsigned long long b, ex, mod = 0;
	
	do{
	
		cout<<"Base: "; //18446744073709551615 is the maximun number for unsigned long long
		cin>>b;
		cout<<"Exponent: ";
		cin>>ex;
		cout<<"Modulo: ";
		cin>>mod;
	}while(b < 0 || ex < 0 || mod <= 0);
	
	cout<<"Result: "<<expRapida(b,ex,mod);
	
	return 0;
}
