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


#include <Filter_1.h> // must specify API prefix in Symbol->Properties->Doc.APIPrefix


//====================================
//        read-only parameters
//====================================

#define FilterSize  (21)    // Filter length  
#define STOPPER     ((int32_t) 0x80000000)       // STOPPER must be smaller than any datum, -128(int8), -32536(int16), -2147483648(int32), 0u (uint8,-16,-32)                                          


//====================================
//        private variables
//====================================



//==============================================================================
// Median filter. Input: next data value; output: filtered data 
//==============================================================================
int32 Filter_1_AddValue(int32 datum)
{
    
    struct pair
    {
        struct pair *point;                                 // Pointers forming list linked in sorted order 
        int32   value;                                 // Values to sort 
    };
 
    static struct pair buffer[FilterSize]={};               // Buffer of nwidth pairs 
    static struct pair *datpoint = buffer;                  // Pointer into circular buffer of data 
    static struct pair small = {NULL, STOPPER};             // Chain stopper 
    static struct pair big = {&small, 0};                   // Pointer to head (largest) of linked list.
   
    struct pair *successor;                                 // Pointer to successor of replaced data item 
    struct pair *scan;                                      // Pointer used to scan down the sorted list 
    struct pair *scanold;                                   // Previous value of scan 
    struct pair *median;                                    // Pointer to median 
    

    if (datum == STOPPER) { datum =  STOPPER + 1; }         // No stoppers allowed.   

    if ( (++datpoint - buffer) >= FilterSize) {
        datpoint = buffer;                                  // Increment and wrap data in pointer.
    }

    datpoint->value = datum;                                // Copy in new datum 
    successor = datpoint->point;                            // Save pointer to old value's successor 
    median = &big;                                          // Median initially to first in chain 
    scanold = NULL;                                         // Scanold initially null. 
    scan = &big;                                            // Points to pointer to first (largest) datum in chain 

    
    if (scan->point == datpoint) {                          // Handle chain-out of first item in chain as special case 
        scan->point = successor;
    }
    
    scanold = scan;                                         // Save this pointer and   
    scan = scan->point ;                                    // step down chain 
 
    uint16 i;
    for (i = 0; i < FilterSize; ++i)                        // Loop through the chain, normal loop exit via break.
    {
         
        if (scan->point == datpoint) {                      // Handle odd-numbered item in chain 
            scan->point = successor;                        // Chain out the old datum.
        }

        if (scan->value < datum)                            // If datum is larger than scanned value,
        {
            datpoint->point = scanold->point;               // Chain it in here.  
            scanold->point  = datpoint;                     // Mark it chained in. 
            datum = STOPPER;
        };

        // Step median pointer down chain after doing odd-numbered element 
        median = median->point;                             // Step median pointer.  
        
        if (scan == &small) break;                          // Break at end of chain  
        
        scanold = scan;                                     // Save this pointer and   
        scan = scan->point;                                 // step down chain 
  
        if (scan->point == datpoint) {                      // Handle even-numbered item in chain.
            scan->point = successor;
        }

        if (scan->value < datum)
        {
            datpoint->point = scanold->point;
            scanold->point  = datpoint;
            datum = STOPPER;
        }

        if (scan == &small) break;

        scanold = scan;
        scan = scan->point;
    }
 
    return median->value;
}



/* [] END OF FILE */



