


# include "init.h"
# include "uart.h"

char g_A = 'A'; 

int a = 0;
int b;
short int c = 0;
long d = 0;

int main(void)
{
	
	uart_init();
	
	puts("a = ");
		hex_print(a); 
		puts("c = ");
		hex_print(c);
		puts("d = ");
		hex_print(d);    
	while (1)
	{
		putchar(g_A);
		g_A++; 
		delay(1000000);
	}

	return 0;
}







/*
运行结果：


*/





