/*******************************************************************************
* File Name: main.c
*
* Version: 1.20
*
* Description: 
*   This is a source code for example project of Lock-in amplifier using Delta-Sigma ADC.
*   It is intended for water conductivity measurement
*
********************************************************************************
* NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include "project.h"

#define BlinkLED(); {Pin_LED_Write(1); CyDelayUs(30); Pin_LED_Write(0);} // blink LED indicator






//===========================================
// 
//===========================================

static volatile CYBIT isrADC_flag = 0; // semaphore between ISR and main()
static volatile uint32 ADC_1_result; //
//CY_ISR_PROTO(isrADC_InterruptHandler);//declaration
CY_ISR(isrADC_InterruptHandler)
{
    isrADC_flag = 1;
    ADC_1_result = ADC_1_GetResult32();
}


//===========================================
// Global variables
//===========================================
//int32 IIRout;
int32 Med_filter;
int32 ADC_Offset = 0;




//===========================================
// Function prototypes
//===========================================
void DMA_Config(void);
int32 LowPassFilter(int32 input);


void Init()
{
    CyGlobalIntEnable; //enable global interrupts
    
    UART_1_Start();
    CyDelay(100);
    
    Button_1_Start();               // Start Button switch      

    //ADC_1_IRQ_Start();//not required
    ADC_1_Start();
    //ADC_1_IRQ_StartEx(ADC_1_IRQ_myInterrupt);//MUST be placed AFTER ADC1_Start()
    isrADC_StartEx(isrADC_InterruptHandler);//MUST be placed AFTER ADC1_Start()
    ADC_1_StartConvert();//only for free-running ADC
}

int main(void)
{
    Init();


    for(;;)
    {
        if(isrADC_flag != 0) // monitor for ADC1 interrupt
        {
            isrADC_flag = 0;
            //BlinkLED();
            
            ADC_1_result -= ADC_Offset;
            
            int32 IIR_filter = LowPassFilter(ADC_1_result);
            Med_filter = Filter_1_AddValue(ADC_1_result);
//            Vadc = ADC1_CountsTo_uVolts( ADC1_result );
//            sprintf(strMsg1,"ADC:%d, Vadc:%d\r\n",  ADC1_result, Vadc);
//            sprintf(strMsg1,"ADC:%d, V:%.3f\r\n",  ADC1_result,(float) 0.000001*VTherm);
//            sprintf(strMsg1,"ADC:%d\r\n",  ADC1_result);
//          BT_Receiver_PutString(strMsg1);
            Chart_1_Plot(ADC_1_result, IIR_filter, Med_filter);
        }
       
        // tare option
        if (Button_1_Pressed!=0)                            // some buttons were pressed
        {
            uint32 status = Button_1_Pressed;               // capture state
            Button_1_Pressed = 0;                           // clear flag
            
            if (status & BTN_0)                             // Button 0 pressed
            {
                BlinkLED();                                 // debug..
                ADC_Offset += Med_filter; // tare: update offset to zero output 
            }    
        }
        
    }
    
}


//=============================================================================
// Exponential averaging
// it is provided for comparisen with the median filter
//=============================================================================

int32 LowPassFilter(int32 input)
{
    static int32 Filter_Acc; // IIR accumulator
    
    int32 k;
    input <<= 8;
    Filter_Acc = Filter_Acc + (((input-Filter_Acc) >> 8) * 8);// factor 8/256
//    Filter_Acc = Filter_Acc + ((input-Filter_Acc) >> 8);// factor 1/256
    k = (Filter_Acc>>8) + ((Filter_Acc & 0x00000080) >> 7);
    return k;
}




/* [] END OF FILE */
