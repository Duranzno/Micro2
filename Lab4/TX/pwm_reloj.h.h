// 2.8.- Se debe activar y visualizar un reloj digital,
//usando el RTCC del DsPIC,
//con la opción de programar la fecha y
// hora inicial y una alarma repetitiva
//cada 30 , 60 , 90 o 120 segundos, y
// que una vez activada, encienda y apague un led externo.
// Nota: Estudiantes que logre activar el RTCC
//usando el cristal externo de 32 Khz obtendrá una nota extra.
#define RTCC_NONE        0
#define RTCC_30         1
#define RTCC_60         2
#define RTCC_90         3
#define RTCC_120         4
#define SEG 0
#define MIN 1
#define HOR 2
#define DIA 3
#define MES 4
#define ANO 5
#define SEM 6
#define SEGMIN         0
#define HORSEM         1
#define DIAMES         2
#define ANONAD 3
unsigned short rtcc_VAL=0,RTCBandera=0,CASO_ALARMA=RTCC_NONE;
unsigned short         u_hora        [7]={0,0,0,0,0,0,0};
char  buffer[30];


void config_Pwm_reloj() {
        PTPER = 458; /* Periodo del PWM en tiempo base primario */
        /* Desplazamiento de fase */
        PHASE1 = 0;
        /* Ciclo útil*/
        PDC1 = 227;
        /* Tiempo muerto*/
        DTR1 = 10;
        ALTDTR1 = 10;
        /* Modo Push-Pull */
        IOCON1 =  0xC800;
        /* Tiempo base primario, Modo Flanco Alineado y ciclo útil independiente */
        PWMCON1 =  0x0000;
        /* prescaler 1:1 */
        PTCON2 = 0x0000;
        /* habilitación de módulo PWM*/
        PTCON = 0x8000;
}


//hid