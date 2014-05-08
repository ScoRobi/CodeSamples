//
//  baseDoc.cpp
//  Documents
//
//  Created by Scott Robinson on 5/7/14.
//  Copyright (c) 2014 Scott Robinson. All rights reserved.
//

#include "baseDoc.h"

baseDoc::baseDoc()
{
    type = DT_UNKNOWN;
    
    hdr.uiNum1 = 0;
    hdr.uiNum2 = 0;
    
    dataBuff = NULL;
}

baseDoc::~baseDoc()
{
    
}

bool baseDoc::read(const /*ubyte*/int8_t * const buff, uint uiBufLen)
{
    bool success = true;
    try
    {
        // Delete previous buffer
        if (dataBuff != NULL)
        {
            delete dataBuff;
            dataBuff = NULL;
        }
        
        // Create new buffer
        dataBuff = new int8_t[uiBufLen];
        
        // Copy data into new buffer
        memcpy(dataBuff, buff, uiBufLen);
        
        // Store size of new buffer
        hdr.uiNum2 = uiBufLen;
        
    } catch (...)
    {
        success = false;
        printf("ERROR: Exception caught in baseDoc::read!\n");
    }
    
    return success;
}

/** Writes the stored document to the buffer
 *    uiMaxLen: input to protect from buffer overflow
 *    returns: true on success
 */
bool baseDoc::write(/*ubyte*/int8_t * const buff, uint uiMaxLen)
{
    bool success = true;
    try
    {
        // Ensure data is present
        if (dataBuff != NULL)
        {
            // Copy data into given buffer based on smaller buffer
            if (uiMaxLen < hdr.uiNum2)
            {
                memcpy(buff, dataBuff, uiMaxLen);
            }
            else
            {
                memcpy(buff, dataBuff, hdr.uiNum2);
            }
        }
    
    } catch (...)
    {
        success = false;
        printf("ERROR: Exception caught in baseDoc::write!\n");
    }
    
    return success;
}
