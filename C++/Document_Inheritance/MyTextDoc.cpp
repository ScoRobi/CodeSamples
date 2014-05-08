//
//  MyTextDoc.cpp
//  Documents
//
//  Created by Scott Robinson on 5/7/14.
//  Copyright (c) 2014 Scott Robinson. All rights reserved.
//

#include "MyTextDoc.h"

MyTextDoc::MyTextDoc()
{
    type = DT_TEXT;
    
    tdh.dHead = docHeader();
    tdh.dNum1 = 0;
    tdh.uiNum2 = 0;
    
    dataBuff = NULL;
}

MyTextDoc::~MyTextDoc()
{
    
}

bool MyTextDoc::read(const /*ubyte*/int8_t * const buff, uint uiBufLen)
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
        tdh.uiNum2 = uiBufLen;
        hdr.uiNum2 = uiBufLen;
        
    } catch (...)
    {
        success = false;
        printf("ERROR: Exception caught in MyTextDoc::read!\n");
    }
    
    return success;
}

void MyTextDoc::printAttributes()
{
    printf("Document Type: %d\nData: %s\n", type, (char*)dataBuff);
}