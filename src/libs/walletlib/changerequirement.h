#pragma once
/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include "transaction.h"

//--------------------------------------------------------------------------
class QChangeRequirement;
typedef SFArrayBase<QChangeRequirement>         QChangeRequirementArray;
typedef SFList<QChangeRequirement*>             QChangeRequirementList;
typedef SFUniqueList<QChangeRequirement*>       QChangeRequirementListU;

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
class QChangeRequirement : public CTransaction {
public:
    SFUintBN _newRequired;

public:
    QChangeRequirement(void);
    QChangeRequirement(const QChangeRequirement& ch);
    virtual ~QChangeRequirement(void);
    QChangeRequirement& operator=(const QChangeRequirement& ch);

    DECLARE_NODE(QChangeRequirement);

    // EXISTING_CODE
    // EXISTING_CODE
    friend ostream& operator<<(ostream& os, const QChangeRequirement& item);

protected:
    void Clear(void);
    void Init(void);
    void Copy(const QChangeRequirement& ch);
    bool readBackLevel(SFArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline QChangeRequirement::QChangeRequirement(void) {
    Init();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline QChangeRequirement::QChangeRequirement(const QChangeRequirement& ch) {
    // EXISTING_CODE
    // EXISTING_CODE
    Copy(ch);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline QChangeRequirement::~QChangeRequirement(void) {
    Clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QChangeRequirement::Clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QChangeRequirement::Init(void) {
    CTransaction::Init();

    _newRequired = 0;

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QChangeRequirement::Copy(const QChangeRequirement& ch) {
    Clear();
    CTransaction::Copy(ch);

    _newRequired = ch._newRequired;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline QChangeRequirement& QChangeRequirement::operator=(const QChangeRequirement& ch) {
    Copy(ch);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//---------------------------------------------------------------------------
IMPLEMENT_ARCHIVE_ARRAY(QChangeRequirementArray);
IMPLEMENT_ARCHIVE_ARRAY_C(QChangeRequirementArray);
IMPLEMENT_ARCHIVE_LIST(QChangeRequirementList);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

