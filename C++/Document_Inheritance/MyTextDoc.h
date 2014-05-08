//
//  MyTextDoc.h
//  Documents
//
//  Created by Scott Robinson on 5/7/14.
//  Copyright (c) 2014 Scott Robinson. All rights reserved.
//

#ifndef __Documents__MyTextDoc__
#define __Documents__MyTextDoc__

#include "baseDoc.h"

class MyTextDoc : public baseDoc
{
public:
    MyTextDoc();
    ~MyTextDoc();
    
    bool read(const /*ubyte*/int8_t * const buff, uint uiBufLen);
    
    // For testing
    void printAttributes();
    
protected:
    textDocHeader tdh;
    
};


#endif /* defined(__Documents__MyTextDoc__) */
