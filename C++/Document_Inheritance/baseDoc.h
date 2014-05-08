//
//  baseDoc.h
//  Documents
//
//  Created by Scott Robinson on 5/7/14.
//  Copyright (c) 2014 Scott Robinson. All rights reserved.
//

#ifndef __Documents__baseDoc__
#define __Documents__baseDoc__

#include <iostream>
#include "documents.h"

class baseDoc
{
public:
    baseDoc();
    ~baseDoc();
    
    /** Reads uiBufLen bytes for storage on the class instance
     *    the buffer contains a header followed directly by data bytes.
     *    uiBufLen: input the number of bytes starting at *buff that belongs to the buffer to be read.
     *    returns: true on success
     */
    virtual bool read(const /*ubyte*/int8_t * const buff, uint uiBufLen);
    
    /** Writes the stored document to the buffer
     *    uiMaxLen: input to protect from buffer overflow
     *    returns: true on success
     */
    virtual bool write(/*ubyte*/int8_t * const buff, uint uiMaxLen);
    
protected:
    docType type;
    docHeader hdr;
    /*ubyte*/int8_t *dataBuff;
    
};

#endif /* defined(__Documents__baseDoc__) */
