/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
#include "etherlib.h"
#include "options.h"

extern bool visitTransaction(CTransaction& trans, void *data);
//--------------------------------------------------------------
int main(int argc, const char *argv[]) {

    etherlib_init();

    // Parse command line, allowing for command files
    COptions options;
    if (!options.prepareArguments(argc, argv))
        return 0;

    while (!options.commandList.empty()) {
        SFString command = nextTokenClear(options.commandList, '\n');
        if (!options.parseArguments(command))
            return 0;
        forEveryTransactionInList(visitTransaction, &options, options.transList.queries);
    }
    return 0;
}

//--------------------------------------------------------------
bool visitTransaction(CTransaction& trans, void *data) {
    const COptions *opt = (const COptions*)data;

    bool badHash = !isHash(trans.hash);
    bool isBlock = trans.hash.Contains("block");
    trans.hash = trans.hash.Substitute("-block_not_found","").Substitute("-trans_not_found","");
    if (opt->isRaw) {
        if (badHash) {
            cerr << "{\"jsonrpc\":\"2.0\",\"result\":{\"hash\":\"" << trans.hash.Substitute(" ","") << "\",\"result\":\"";
            cerr << (isBlock ? "block " : "");
            cerr << "hash not found\"},\"id\":-1}" << "\n";
            return true;
        }

        // Note: this call is redundant. The transaction is already populated (if it's valid), but we need the raw data)
//        SFString results;
//        queryRawLogs(results, trans.getValueByName("hash"));
//        cout << results;
//        return true;
        cout << "Raw option is not implemented.\n";
        exit(0);
    }

    if (badHash) {
        cerr << cRed << "Warning:" << cOff << " The " << (isBlock ? "block " : "") << "hash " << cYellow << trans.hash << cOff << " was not found.\n";
        return true;
    }

	cout << "[";
	for (uint32_t i = 0 ; i < trans.receipt.logs.getCount() ; i++) {
		trans.receipt.logs[i].doExport(cout);
		cout << (i < trans.receipt.logs.getCount()-1 ? ",\n" : "\n");
	}
	cout << "]\n";

    return true;
}
