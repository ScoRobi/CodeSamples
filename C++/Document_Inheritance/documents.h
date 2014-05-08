//
//  documents.h
//  Documents
//
//  Created by Scott Robinson on 5/7/14.
//  Copyright (c) 2014 Scott Robinson. All rights reserved.
//

#ifndef Documents_documents_h
#define Documents_documents_h

class MyTextDoc;

enum docType
{
    DT_UNKNOWN,
    DT_TEXT,
    DT_BINARY
};

struct docHeader
{
    uint uiNum1;
    uint uiNum2;
};

struct textDocHeader
{
    docHeader dHead;
    double dNum1;
    uint uiNum2;
};

struct binDocHeader
{
    docHeader dHead;
    uint uiNum1;
    double dNum2;
};

#endif
