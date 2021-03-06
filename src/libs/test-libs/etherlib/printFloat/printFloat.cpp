/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
#include "etherlib.h"
#include "options.h"

//--------------------------------------------------------------
int main(int argc, const char *argv[]) {

    etherlib_init();

    // Parse command line, allowing for command files
    COptions options;
    if (!options.prepareArguments(argc, argv))
        return 0;

    //while (!options.commandList.empty())
    {
        SFString command = nextTokenClear(options.commandList, '\n');
        if (!options.parseArguments(command))
            return 0;

        // Test 'zero' is an old bug that originally motivated this code. We used to print 10.2147483648 when we know
        // the value was 1.400001000001. Weird, but true
        if (options.testNum == 1) {
            HIDE_FIELD(CPriceQuote, "timestamp");
            HIDE_FIELD(CPriceQuote, "date");

            CPriceQuote bug;
            bug.close = 1.40000010000001;
            cerr << bug.Format() << "\n";

        } else if (options.testNum == 2) {
            cout << "Test " << options.testNum << "\n";

        } else {
            return usage("Unknown test: " + asString(options.testNum) + "\n");

        }
    }

    return 0;
}

#if 0
// PRINTING HEX
int main(int argc, char *argv[]) {
    uint64_t x = NOPOS;
    char ss[100];
    sprintf(ss,"%016llx\n", x);
    SFString s = ss;
    cout << "0x" << toLower(s) << "\n";
    return 1;
}
#endif
