/* ============================================================================
 * File Name: ButtonSw32.c
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
   
#include <Button_1.h> // must specify API prefix in Symbol->Properties->Doc.APIPrefix


#define Button_1_MASK   ((Button_1_InpWidth==32)? (~0u) : ~(~0u<<Button_1_InpWidth))   // buttons mask 
 

//====================================
//        private variables
//====================================


//====================================
//        private functions
//====================================
//CY_ISR_PROTO(Button_1_myPollInt);   // interrupt on external polling clock

    
 
    
//==============================================================================
// interrupt on external clock for polling states
//
//==============================================================================

CY_ISR(Button_1_myPollInt) 
{   
    
    Button_1_CheckStatus();  
    
}    

    
//==============================================================================
// Read pins status (using default read functions)
// returns current state: 32-bit word combining REG_3, REG_2, REG_1, REG_0 
//==============================================================================
/*
__INLINE uint32 Button_1_ReadPins() // 
{
    uint32 result; // 

    
    #if (Button_1_InpWidth <= 8u)    
        result  = ((uint32)Button_1_REG_0_Read());      // 
      
    #elif (Button_1_InpWidth <= 16u)
        result  = ((uint32)Button_1_REG_0_Read())    |  // 
                  ((uint32)Button_1_REG_1_Read()<<8u);  // 
          
    #elif (Button_1_InpWidth <= 24u)
        result  = ((uint32)Button_1_REG_0_Read())     |
                  ((uint32)Button_1_REG_1_Read()<<8u) |  // 
                  ((uint32)Button_1_REG_2_Read()<<16u);  // 
          
    #elif (Button_1_InpWidth <= 32u)
        result  = ((uint32)Button_1_REG_0_Read())     |
                  ((uint32)Button_1_REG_1_Read()<<8u) |    
                  ((uint32)Button_1_REG_2_Read()<<16u)|  // 
                  ((uint32)Button_1_REG_3_Read()<<24u);  // 
          
    #endif            

    return result;
}
*/

//==============================================================================
// Read pins status (fast inline code)
// returns current state: 32-bit word combining REG_3, REG_2, REG_1, REG_0 
//==============================================================================

__INLINE uint32 Button_1_ReadPins() // 
{
    uint32 result; // 
    
    #if (Button_1_InpWidth <= 8u)    
        result  = ((uint32)((Button_1_REG_0_PS & Button_1_REG_0_MASK) >> Button_1_REG_0_SHIFT));       
      
    #elif (Button_1_InpWidth <= 16u)
        result  = ((uint32)((Button_1_REG_0_PS & Button_1_REG_0_MASK) >> Button_1_REG_0_SHIFT))    |   
                  ((uint32)((Button_1_REG_1_PS & Button_1_REG_1_MASK) >> Button_1_REG_1_SHIFT)<<8u);   
          
    #elif (Button_1_InpWidth <= 24u)
        result  = ((uint32)((Button_1_REG_0_PS & Button_1_REG_0_MASK) >> Button_1_REG_0_SHIFT))     |
                  ((uint32)((Button_1_REG_1_PS & Button_1_REG_1_MASK) >> Button_1_REG_1_SHIFT)<<8u) |    
                  ((uint32)((Button_1_REG_2_PS & Button_1_REG_2_MASK) >> Button_1_REG_2_SHIFT)<<16u);   
          
    #elif (Button_1_InpWidth <= 32u)
        result  = ((uint32)((Button_1_REG_0_PS & Button_1_REG_0_MASK) >> Button_1_REG_0_SHIFT))     |
                  ((uint32)((Button_1_REG_1_PS & Button_1_REG_1_MASK) >> Button_1_REG_1_SHIFT)<<8u) |      
                  ((uint32)((Button_1_REG_2_PS & Button_1_REG_2_MASK) >> Button_1_REG_2_SHIFT)<<16u)|    
                  ((uint32)((Button_1_REG_3_PS & Button_1_REG_3_MASK) >> Button_1_REG_3_SHIFT)<<24u);   
          
    #endif            

    return result;
}


//==============================================================================
// Checks pins status using vertical counters algorithm
// and sets event flags: pressed and released 
//==============================================================================

__INLINE void Button_1_CheckStatus() // 
{
           uint32 sample;           // pins sample
           uint32 delta;            // sample change
           uint32 toggle;           // toggled pins
    static uint32 cnt0, cnt1;       // counters
    static uint32 state;            // current pins state (1-pressed, 0-released)

    
    sample = Button_1_ReadPins();
    sample  = ~sample & Button_1_MASK; // 
    

    // code returns the state and transition->
    delta = sample ^ state;
    cnt1 = (cnt1 ^ cnt0) & delta;
    cnt0 = ~cnt0 & delta;

    toggle = delta & ~(cnt0 | cnt1);
    state ^= toggle;
    
    //Button_1_State = state;
    
    #if (Button_1_Events & BTN_PRESSED)
        uint32 fBtnPressed = toggle & state;              // on rising edge
        Button_1_Pressed |= fBtnPressed;    // latch pressed 
    #endif
        
    #if (Button_1_Events & BTN_RELEASED)
        uint32 fBtnReleased = toggle & ~state;             // on falling edge
        Button_1_Released |= fBtnReleased;  // latch pressed  //+9 ticks
    #endif    
}


//==============================================================================
// Initialize encoder 
//==============================================================================

void Button_1_Start()
{ 
    #if Button_1_IsrInternal
        Button_1_isrPoll_StartEx(Button_1_myPollInt);//start isrPoll interrupt
    #endif    
} 

//==============================================================================
// Stop encoder 
//==============================================================================

void Button_1_Stop()
{    
    #if Button_1_IsrInternal
        Button_1_isrPoll_Stop();    //stop isrPoll interrupt
    #endif    
} 



/* [] END OF FILE */
