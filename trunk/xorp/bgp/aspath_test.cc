// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001,2002 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/bgp/aspath_test.cc,v 1.3 2002/12/15 04:09:28 mjh Exp $"

#include <stdio.h>
#include <unistd.h>
#include "aspath.hh"

int
main(int argc, char* argv[])
{
    int c;
    bool verbose = false;

    while ((c = getopt(argc, argv, "v")) != EOF) {
	switch (c) {
	case 'v':
	    verbose = true;
	    break;
	}
    }

    AsNum *as[13];
    int i;
    for (i=0;i<=9;i++) {
	as[i] = new AsNum((uint16_t)i);
    }
    AsSegment seq1 = AsSegment(AS_SEQUENCE);
    seq1.add_as(*(as[1]));
    seq1.add_as(*(as[2]));
    seq1.add_as(*(as[3]));

    AsSegment seq2 = AsSegment(AS_SEQUENCE);
    seq2.add_as(*(as[7]));
    seq2.add_as(*(as[8]));
    seq2.add_as(*(as[9]));

    AsSegment set1 = AsSegment(AS_SET);
    set1.add_as(*(as[4]));
    set1.add_as(*(as[5]));
    set1.add_as(*(as[6]));

    for (i=0;i<=9;i++) {
	delete as[i];
    }

    AsPath *aspath= new AsPath;
    aspath->add_segment(seq1);
    aspath->add_segment(set1);
    aspath->add_segment(seq2);

    assert(aspath->num_segments() == 3);
    if (verbose) printf("Original: %s\n", aspath->str().c_str());

    AsPath *aspathcopy= new AsPath(*aspath);
    if (verbose) printf("Copy: %s\n", aspathcopy->str().c_str());
    if (verbose) printf("Deleting orginal\n");
    delete aspath;
    if (verbose) printf("Copy: %s\n", aspathcopy->str().c_str());

    AsNum *asn;
    for (i=1;i<=9;i++) {
	asn = new AsNum((uint16_t)i);
	assert(aspathcopy->contains(*asn) == true);
	delete asn;
    }
    asn = new AsNum(AsNum::invalid_As);	// XXX should never do this
    assert(aspathcopy->contains(*asn) == false);
    delete asn;

    if (verbose) 
	printf("Testing add_As_in_sequence - adding to existing sequence\n");
    asn = new AsNum((uint16_t)65000);
    aspathcopy->add_AS_in_sequence(*asn);
    if (verbose) printf("Extended: %s\n", aspathcopy->str().c_str());
    assert(aspathcopy->contains(*asn) == true);
    delete asn;

    for (i=10;i<=12;i++) {
	as[i] = new AsNum((uint16_t)i);
    }
    AsSegment set2 = AsSegment(AS_SET);
    set2.add_as(*(as[10]));
    set2.add_as(*(as[11]));
    set2.add_as(*(as[12]));
    aspath= new AsPath;
    aspath->add_segment(set2);
    aspath->add_segment(seq2);
    aspath->add_segment(set1);
    aspath->add_segment(seq1);
    if (verbose) 
	printf("Testing add_As_in_sequence - adding to existing set\n");
    asn = new AsNum((uint16_t)65001);
    if (verbose) printf("Before: %s\n", aspath->str().c_str());
    aspath->add_AS_in_sequence(*asn);
    if (verbose) printf("Extended: %s\n", aspath->str().c_str());
    assert(aspath->contains(*as[10]) == true);
    assert(aspath->contains(*as[11]) == true);
    assert(aspath->contains(*as[12]) == true);
    assert(aspath->contains(*asn) == true);
    delete asn;
    for (i=10;i<=12;i++) 
	delete as[i];

    if (verbose)
	printf("Test constructing an As Path from a string");

    AsPath aspath_str("65008,1,2,(3,4,5),6,(7,8),9"); // From string
    AsPath aspath_con;      // Constructed

    {
	AsSegment seq = AsSegment(AS_SEQUENCE);
	seq.add_as(AsNum((uint16_t)65008));
	seq.add_as(AsNum((uint16_t)1));
	seq.add_as(AsNum((uint16_t)2));
	
	aspath_con.add_segment(seq);
    }

    {
	AsSegment set = AsSegment(AS_SET);
	set.add_as(AsNum((uint16_t)3));
	set.add_as(AsNum((uint16_t)4));
	set.add_as(AsNum((uint16_t)5));
	
	aspath_con.add_segment(set);
    }	

    {
	AsSegment seq = AsSegment(AS_SEQUENCE);
	seq.set_type(AS_SEQUENCE);
	seq.add_as(AsNum((uint16_t)6));
	
	aspath_con.add_segment(seq);
    }

    {
	AsSegment set = AsSegment(AS_SET);
	set.add_as(AsNum((uint16_t)7));
	set.add_as(AsNum((uint16_t)8));
	
	aspath_con.add_segment(set);
    }	

    {
	AsSegment seq;
	seq.set_type(AS_SEQUENCE);
	seq.add_as(AsNum((uint16_t)9));
	
	aspath_con.add_segment(seq);
    }

    assert(aspath_str == aspath_con);

    if (verbose) printf("All tests passed\n");
#if 0
    printf("Check for space leak: check memory usage now....\n");
    sleep(5);
    printf("Continuing...\n");
    aspath = new AsPath(*aspathcopy);
    delete aspathcopy;
    for(i=0; i< 10000; i++) {
	aspathcopy= new AsPath(*aspath);
	delete aspath;
	aspath = new AsPath(*aspathcopy);
	delete aspathcopy;
    }
    printf("Done...\n");


    for (i=1;i<=9;i++) {
	asn = new AsNum((uint16_t)i);
	assert(aspath->contains(*asn) == true);
	delete asn;
    }
    asn = new AsNum;
    assert(aspath->contains(*asn) == false);
    delete asn;
    sleep(10);
#else
    delete aspath;
    delete aspathcopy;
#endif
    exit(0);
}
