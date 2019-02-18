



# include "init.h"
# include "uart.h"
# include "s3c2440_soc.h"
# include "nand_flash.h"


int main(void)
{

	  key_init();
	  led_init();
	  //timer0_init();

	//nor_flash_test();
	//nand_flash_test();
      lcd_test();

      //adc_test();
	  touchscreen_test();

      while(1);

	return 0;
}








