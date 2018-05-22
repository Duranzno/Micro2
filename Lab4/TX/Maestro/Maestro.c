#include "hid.h"

void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
void Error_SPI() org 0x26{
        IFS0bits.SPI1EIF=0;
          write("Error");
                 delay_ms(3000);

}
void SPI() org 0x28{
        IFS0bits.SPI1IF=0;
            write("ALGUN DATO SE TRANSMITIO");
                 delay_ms(3000);

}
char writebuff[64],readbuff[64];                
int cnt=0;
void main() {
    // cambio_led();
    config_INT();//config_timer8();
    InitMCU();
    config_timer3();
    config_adc();
   // config_vref();
   config_pin();
   config_spi();
    HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usb hid
    while(1){
            menu2();
            while(!HID_Read());
            for(cnt=0;cnt<64;cnt++) {
                    writebuff[cnt]=readbuff[cnt];
            }
            if(strcmp(readbuff,caso_1)==0){//CASE 1
                 write("Bienvenido al Caso 1");
                 SPI1BUF = 0x0001; // Write data to be transmitted
                 delay_ms(4000);
                  //  caso1();
            }
            else if(strcmp(readbuff,caso_2)==0){//CASE 2
                        write("Bienvenido al Caso 2");
                        SPI1BUF = 0x0002; // Write data to be transmitted
                 delay_ms(4000);
                  // caso2();
            }
            else if(strcmp(readbuff,caso_3)==0){//CASE 3
                      write("Bienvenido al Caso 3");
                      SPI1BUF = 0x0003; // Write data to be transmitted
                 delay_ms(4000);
                  //  caso3();
            }
    Delay_ms(1000);
    escape=0;
    }
}