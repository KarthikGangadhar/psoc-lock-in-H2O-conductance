/* ============================================================================
 * File Name: ButtonSw32.h
 *   ButtonSw32_v0.0
 *
 * Description:
 *   Implements vertical counters algorithm using polling technique.
 *   Detects button pressed and released events.
 *   Detects up to 32 buttons. 
 *
 * Credits:
 *   based on vertical counters algorithm
 *    https://www.compuphase.com/electronics/debouncing.htm
 *
 * Note:
 *
 * ============================================================================
 * PROVIDED AS-IS, NO WARRANTY OF ANY KIND, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * FREE TO SHARE, USE AND MODIFY UNDER TERMS: CREATIVE COMMONS - SHARE ALIKE
 * ============================================================================
*/



// todo: add unique prefix e.g. BSW32_... (?)
#ifndef Button_1_H
#define Button_1_H
 
    
#include <project.h>
#include <cytypes.h>
           
#define true  1
#define false 0

/***************************************
*        read-only parameters
***************************************/  

#define Button_1_InpWidth      1           // number of buttons  
#define Button_1_Events        1           // button events  
#define Button_1_IsrInternal   true  // internal / external timer interrupt to check pins state   


#define BTN_PRESSED   0x01u
#define BTN_RELEASED  0x02u   


// 32-bit     
#define BTN_0   (uint32)(0x01u << 0)
#define BTN_1   (uint32)(0x01u << 1)
#define BTN_2   (uint32)(0x01u << 2)
#define BTN_3   (uint32)(0x01u << 3)
#define BTN_4   (uint32)(0x01u << 4)
#define BTN_5   (uint32)(0x01u << 5)
#define BTN_6   (uint32)(0x01u << 6)
#define BTN_7   (uint32)(0x01u << 7)
#define BTN_8   (uint32)(0x01u << 8)
#define BTN_9   (uint32)(0x01u << 9)
#define BTN_10  (uint32)(0x01u << 10)
#define BTN_11  (uint32)(0x01u << 11)
#define BTN_12  (uint32)(0x01u << 12)
#define BTN_13  (uint32)(0x01u << 13)
#define BTN_14  (uint32)(0x01u << 14)
#define BTN_15  (uint32)(0x01u << 15)
#define BTN_16  (uint32)(0x01u << 16)
#define BTN_17  (uint32)(0x01u << 17)
#define BTN_18  (uint32)(0x01u << 18)
#define BTN_19  (uint32)(0x01u << 19)
#define BTN_20  (uint32)(0x01u << 20)
#define BTN_21  (uint32)(0x01u << 21)
#define BTN_22  (uint32)(0x01u << 22)
#define BTN_23  (uint32)(0x01u << 23)
#define BTN_24  (uint32)(0x01u << 24)
#define BTN_25  (uint32)(0x01u << 25)
#define BTN_26  (uint32)(0x01u << 26)
#define BTN_27  (uint32)(0x01u << 27)
#define BTN_28  (uint32)(0x01u << 28)
#define BTN_29  (uint32)(0x01u << 29)
#define BTN_30  (uint32)(0x01u << 30)
#define BTN_31  (uint32)(0x01u << 31)
    
    
/***************************************
*        global variables
***************************************/  

#if (Button_1_Events & BTN_PRESSED)    
    volatile uint32 Button_1_Pressed;   // button press latched flag 
#endif
        
#if (Button_1_Events & BTN_RELEASED)
    volatile uint32 Button_1_Released;  // button release latched flag     
#endif

//volatile uint32 Button_1_State;       // instant state      



/***************************************
*        read-only variables
***************************************/  


    
/***************************************
*        Function Prototypes
***************************************/

void  Button_1_Start();                 // start encoder
void  Button_1_Stop();                  // stop encoder 
void  Button_1_CheckStatus();           // return: 1=pressed, 0=released 


    
#endif /* Button_1_H */

/* [] END OF FILE */


