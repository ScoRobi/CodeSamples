//
//  main.cpp
//  Documents
//
//  Created by Scott Robinson on 5/7/14.
//  Copyright (c) 2014 Scott Robinson. All rights reserved.
//

#include "MyTextDoc.h"

MyTextDoc *myFunc(/*ubyte*/int8_t *buff, unsigned int buffLength)
{
    MyTextDoc *tDoc = new MyTextDoc();
    
    tDoc->read(buff, buffLength);
    
    return tDoc;
}

int main(int argc, const char * argv[])
{
    char buff[16] = "Tenable";
    
    MyTextDoc *pTest = myFunc((int8_t*)buff, sizeof((int8_t*)buff));
    
    if (pTest)
    {
        pTest->printAttributes();
    }
    
    return 0;
}
