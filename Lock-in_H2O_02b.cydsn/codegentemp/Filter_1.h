/* ============================================================================
 * Component Name: MedianFilter_v0_0
 *
 * Description:
 *   Fast Median Filter component implementation for streamed data
 *   Range: int8, int16, int32, uint8, uint16, uin32
 *   Has has fixed execution time: 86 + N * 26; N-filter size
 *
 * Credits:
 *   Phil Ekstrom median filtering algorithm:
 *   https://www.embedded.com/better-than-average/
 *   https://embeddedgurus.com/stack-overflow/2010/10/median-filtering/  (code borrowed from here)
 *
 * Uses:
 *   Serial PLOT v0.10.0
 *   by Yavuz Ozderya
 *   https://hasanyavuz.ozderya.net/?p=244
 *   https://bitbucket.org/hyOzd/serialplot   
 *
 * ============================================================================
 * PROVIDED AS-IS, NO WARRANTY OF ANY KIND, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * FREE TO SHARE, USE AND MODIFY UNDER TERMS: CREATIVE COMMONS - SHARE ALIKE
 * ============================================================================
*/



#ifndef Filter_1_H
#define Filter_1_H
 
    
#include <project.h>
#include <cytypes.h>
           
#define true  1
#define false 0

/***************************************
*        read-only parameters
***************************************/  

//#define Filter_1_FilterRange   3           // Output data type. Valid options int8 (uint8), int16 (uint16), int32 (uint32), float.  
//#define Filter_1_FilterSize    21           // Filter length  // todo: -> private?
//#define Filter_1_range         int32          // int8, int16, int32, float32   


    
/***************************************
*        global variables
***************************************/  
    

/***************************************
*        read-only variables
***************************************/    
 
    
/***************************************
*        Function Prototypes
***************************************/

int32 Filter_1_AddValue(int32 datum); // add next data point to the filter     

    
#endif /* Filter_1_H */


/* [] END OF FILE */
