//
//  main.c
//  ReadSeriesOfRecords
//
//  Created by Scott Robinson on 5/6/14.
//  Copyright (c) 2014 Scott Robinson. All rights reserved.
//

#include <stdio.h>

void ReadSeriesOfRecords(void *fd)
{
    // Start
    int8_t *p = fd;
    int nRecordNumber = 0;
    while (*p != EOF)
    {
        // Get record type
        int16_t type = *p;
        p+=sizeof(type);
        
        // Get data length (NOTE: Assumes that the length ONLY includes only the number of bytes of data)
        int32_t length = *p;
        p+=sizeof(length);
        
        // Get data pointer
        char *data = (char*)p;
        p+=length;
        
        // Increment the count of the records found
        nRecordNumber++;
        
        // Print desired info
        printf("Record #%d | Type: %d | Length: %d | Data: ", nRecordNumber, type, length);
        for (int i=0; i < length; i++) { printf("0x%02X ", (int16_t)*(data+i)); }
        printf("\n\n");
        
        // Increment past terminating null
        p++;
    }

    return;
}

int main() //(int argc, const char * argv[])
{
    //
    // Test0
    //
    int8_t test0[15];
    
    test0[0] = 0x01; // Type = 1
    test0[1] = 0x00;
    
    test0[2] = 0x08; // Length = 8
    test0[3] = 0x00;
    test0[4] = 0x00;
    test0[5] = 0x00;
    
    for (int x=6; x<14; x++) { test0[x] = x-5; } // Data = {1,8}
    
    test0[14] = 0x00; // Terminating Null
    
    //
    // Test1
    //
    int8_t test1[8];
    
    test1[0] = 0x02; // Type = 2
    test1[1] = 0x00;
    
    test1[2] = 0x01; // Length = 1
    test1[3] = 0x00;
    test1[4] = 0x00;
    test1[5] = 0x00;
    
    test1[6] = 0x0A; // Data = 10
    
    test1[7] = 0x00; // Terminating Null
    
    //
    // Test2
    //
    int8_t test2[71];
    
    test2[0] = 0x03; // Type = 3
    test2[1] = 0x00;
    
    test2[2] = 0x40; // Length = 64
    test2[3] = 0x00;
    test2[4] = 0x00;
    test2[5] = 0x00;
    
    for (int x=6; x<70; x++) { test2[x] = x-5; } // Data = {1,64}
    
    test2[70] = 0x00; // Terminating Null
    
    //
    // Test3
    //
    int8_t test3[7];
    
    test3[0] = 0x00; // Type = 0
    test3[1] = 0x00;
    
    test3[2] = 0x00; // Length = 0
    test3[3] = 0x00;
    test3[4] = 0x00;
    test3[5] = 0x00;
    
    test3[6] = 0x00; // Terminating Null
    
    //
    // Combine test records into single stream
    //
    int nTest0 = sizeof(test0);
    int nTest1 = sizeof(test1);
    
    int8_t pCombine[256];
    int8_t *pItr = pCombine;
    
    memcpy(pItr, &test0, nTest0);
    pItr+=nTest0;
    memcpy(pItr, &test1, nTest1);
    pItr+=nTest1;
    memcpy(pItr, &test2, sizeof(test2));
    pItr+=sizeof(test2);
    memcpy(pItr, &test3, sizeof(test3));
    pItr+=sizeof(test3);
    
    // Add EOF
    memset(pItr, -1, 1);

    printf(">>>START\n\n");
    
    ReadSeriesOfRecords(pCombine);
    
    printf(">>>END\n");
    
    return 0;
}

