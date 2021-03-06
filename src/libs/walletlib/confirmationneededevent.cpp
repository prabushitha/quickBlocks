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
#include "confirmationneededevent.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(QConfirmationNeededEvent, CLogEntry);

//---------------------------------------------------------------------------
static SFString nextConfirmationneededeventChunk(const SFString& fieldIn, const void *dataPtr);
static SFString nextConfirmationneededeventChunk_custom(const SFString& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void QConfirmationNeededEvent::Format(CExportContext& ctx, const SFString& fmtIn, void *dataPtr) const {
    if (!m_showing)
        return;

    if (fmtIn.empty()) {
        ctx << toJson();
        return;
    }

    SFString fmt = fmtIn;
    if (handleCustomFormat(ctx, fmt, dataPtr))
        return;

    while (!fmt.empty())
        ctx << getNextChunk(fmt, nextConfirmationneededeventChunk, this);
}

//---------------------------------------------------------------------------
SFString nextConfirmationneededeventChunk(const SFString& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return ((const QConfirmationNeededEvent *)dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool QConfirmationNeededEvent::setValueByName(const SFString& fieldName, const SFString& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CLogEntry::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case 'd':
            if ( fieldName % "data" ) { data = toLower(fieldValue); return true; }
            break;
        case 'i':
            if ( fieldName % "initiator" ) { initiator = toAddress(fieldValue); return true; }
            break;
        case 'o':
            if ( fieldName % "operation" ) { operation = toLower(fieldValue); return true; }
            break;
        case 't':
            if ( fieldName % "to" ) { to = toAddress(fieldValue); return true; }
            break;
        case 'v':
            if ( fieldName % "value" ) { value = toWei(fieldValue); return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void QConfirmationNeededEvent::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool QConfirmationNeededEvent::Serialize(SFArchive& archive) {

    if (archive.isWriting())
        return ((const QConfirmationNeededEvent*)this)->SerializeC(archive);

    // If we're reading a back level, read the whole thing and we're done.
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    archive >> operation;
    archive >> initiator;
    archive >> value;
    archive >> to;
    archive >> data;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool QConfirmationNeededEvent::SerializeC(SFArchive& archive) const {

    // Writing always write the latest version of the data
    CLogEntry::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE
    archive << operation;
    archive << initiator;
    archive << value;
    archive << to;
    archive << data;

    return true;
}

//---------------------------------------------------------------------------
void QConfirmationNeededEvent::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CLogEntry::registerClass();

    uint32_t fieldNum = 1000;
    ADD_FIELD(QConfirmationNeededEvent, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(QConfirmationNeededEvent, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(QConfirmationNeededEvent, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(QConfirmationNeededEvent, "operation", T_TEXT, ++fieldNum);
    ADD_FIELD(QConfirmationNeededEvent, "initiator", T_ADDRESS, ++fieldNum);
    ADD_FIELD(QConfirmationNeededEvent, "value", T_NUMBER, ++fieldNum);
    ADD_FIELD(QConfirmationNeededEvent, "to", T_ADDRESS, ++fieldNum);
    ADD_FIELD(QConfirmationNeededEvent, "data", T_TEXT, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(QConfirmationNeededEvent, "schema");
    HIDE_FIELD(QConfirmationNeededEvent, "deleted");
    HIDE_FIELD(QConfirmationNeededEvent, "showing");

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
SFString nextConfirmationneededeventChunk_custom(const SFString& fieldIn, const void *dataPtr) {
    const QConfirmationNeededEvent *con = (const QConfirmationNeededEvent *)dataPtr;
    if (con) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, con);
                break;

            default:
                break;
        }
    }

    return "";
}

//---------------------------------------------------------------------------
bool QConfirmationNeededEvent::handleCustomFormat(CExportContext& ctx, const SFString& fmtIn, void *dataPtr) const {
    // EXISTING_CODE
    // EXISTING_CODE
    return false;
}

//---------------------------------------------------------------------------
bool QConfirmationNeededEvent::readBackLevel(SFArchive& archive) {

    CLogEntry::readBackLevel(archive);
    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
SFString QConfirmationNeededEvent::getValueByName(const SFString& fieldName) const {

    // Give customized code a chance to override first
    SFString ret = nextConfirmationneededeventChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // Return field values
    switch (tolower(fieldName[0])) {
        case 'd':
            if ( fieldName % "data" ) return data;
            break;
        case 'i':
            if ( fieldName % "initiator" ) return fromAddress(initiator);
            break;
        case 'o':
            if ( fieldName % "operation" ) return operation;
            break;
        case 't':
            if ( fieldName % "to" ) return fromAddress(to);
            break;
        case 'v':
            if ( fieldName % "value" ) return asStringBN(value);
            break;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CLogEntry::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const QConfirmationNeededEvent& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    os << item.Format() << "\n";
    return os;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

