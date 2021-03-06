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
#include "logentry.h"
#include "etherlib.h"

namespace qblocks {

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CLogEntry, CBaseNode);

//---------------------------------------------------------------------------
extern SFString nextLogentryChunk(const SFString& fieldIn, const void *dataPtr);
static SFString nextLogentryChunk_custom(const SFString& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void CLogEntry::Format(CExportContext& ctx, const SFString& fmtIn, void *dataPtr) const {
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
        ctx << getNextChunk(fmt, nextLogentryChunk, this);
}

//---------------------------------------------------------------------------
SFString nextLogentryChunk(const SFString& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return ((const CLogEntry *)dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool CLogEntry::setValueByName(const SFString& fieldName, const SFString& fieldValue) {
    // EXISTING_CODE
    if (pReceipt)
        if (((CReceipt*)pReceipt)->setValueByName(fieldName, fieldValue))
            return true;
    // EXISTING_CODE

    switch (tolower(fieldName[0])) {
        case 'a':
            if ( fieldName % "address" ) { address = toAddress(fieldValue); return true; }
            break;
        case 'd':
            if ( fieldName % "data" ) { data = fieldValue; return true; }
            break;
        case 'l':
            if ( fieldName % "logIndex" ) { logIndex = toUnsigned(fieldValue); return true; }
            break;
        case 't':
            if ( fieldName % "topics" ) {
                SFString str = fieldValue;
                while (!str.empty()) {
                    topics[topics.getCount()] = toTopic(nextTokenClear(str,','));
                }
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CLogEntry::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CLogEntry::Serialize(SFArchive& archive) {

    if (archive.isWriting())
        return ((const CLogEntry*)this)->SerializeC(archive);

    // If we're reading a back level, read the whole thing and we're done.
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    archive >> address;
    archive >> data;
    archive >> logIndex;
    archive >> topics;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CLogEntry::SerializeC(SFArchive& archive) const {

    // Writing always write the latest version of the data
    CBaseNode::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE
    archive << address;
    archive << data;
    archive << logIndex;
    archive << topics;

    return true;
}

//---------------------------------------------------------------------------
void CLogEntry::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    uint32_t fieldNum = 1000;
    ADD_FIELD(CLogEntry, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(CLogEntry, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(CLogEntry, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(CLogEntry, "address", T_ADDRESS, ++fieldNum);
    ADD_FIELD(CLogEntry, "data", T_TEXT, ++fieldNum);
    ADD_FIELD(CLogEntry, "logIndex", T_NUMBER, ++fieldNum);
    ADD_FIELD(CLogEntry, "topics", T_OBJECT|TS_ARRAY, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CLogEntry, "schema");
    HIDE_FIELD(CLogEntry, "deleted");
    HIDE_FIELD(CLogEntry, "showing");

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
SFString nextLogentryChunk_custom(const SFString& fieldIn, const void *dataPtr) {
    const CLogEntry *log = (const CLogEntry *)dataPtr;
    if (log) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, log);
                break;

            default:
                break;
        }
    }

    return "";
}

//---------------------------------------------------------------------------
bool CLogEntry::handleCustomFormat(CExportContext& ctx, const SFString& fmtIn, void *dataPtr) const {
    // EXISTING_CODE
    // EXISTING_CODE
    return false;
}

//---------------------------------------------------------------------------
bool CLogEntry::readBackLevel(SFArchive& archive) {

    CBaseNode::readBackLevel(archive);
    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
SFArchive& operator<<(SFArchive& archive, const CLogEntry& log) {
    log.SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
SFArchive& operator>>(SFArchive& archive, CLogEntry& log) {
    log.Serialize(archive);
    return archive;
}

//---------------------------------------------------------------------------
SFString CLogEntry::getValueByName(const SFString& fieldName) const {

    // Give customized code a chance to override first
    SFString ret = nextLogentryChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // Return field values
    switch (tolower(fieldName[0])) {
        case 'a':
            if ( fieldName % "address" ) return fromAddress(address);
            break;
        case 'd':
            if ( fieldName % "data" ) return data;
            break;
        case 'l':
            if ( fieldName % "logIndex" ) return asStringU(logIndex);
            break;
        case 't':
            if ( fieldName % "topics" || fieldName % "topicsCnt" ) {
                uint32_t cnt = topics.getCount();
                if (fieldName.endsWith("Cnt"))
                    return asStringU(cnt);
                if (!cnt) return "";
                SFString retS;
                for (uint32_t i = 0 ; i < cnt ; i++) {
                    retS += ("\"" + fromTopic(topics[i]) + "\"");
                    retS += ((i < cnt - 1) ? ",\n" + indent() : "\n");
                }
                return retS;
            }
            break;
    }

    // EXISTING_CODE
    // See if this field belongs to the item's container
    ret = nextReceiptChunk(fieldName, pReceipt);
    if (ret.Contains("Field not found"))
        ret = EMPTY;
    if (!ret.empty())
        return ret;
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CBaseNode::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const CLogEntry& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    os << item.Format() << "\n";
    return os;
}

//---------------------------------------------------------------------------
const SFString CLogEntry::getStringAt(const SFString& name, uint32_t i) const {
    if ( name % "topics" && i < topics.getCount() )
        return fromTopic(topics[i]);
    return "";
}

//---------------------------------------------------------------------------
// EXISTING_CODE
#define EQ_TEST(a) { if (test.a != a) { cout << " diff at " << #a << " " << test.a << ":" << a << " "; return false; } }
bool CLogEntry::operator==(const CLogEntry& test) const {

    EQ_TEST(address);
    EQ_TEST(data);
    EQ_TEST(logIndex);
    EQ_TEST(topics.getCount());
    for (uint32_t i = 0 ; i < topics.getCount() ; i++)
        if (test.topics[i] != topics[i])
            return false;

    return true;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
}  // namespace qblocks

