/*-
 * Copyright (c) 2018, Joseph Koshy
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer
 *    in this position and unchanged.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* $Id$ */

#include <stddef.h>

#include "test.h"

/*
 * This source defines a single test case named 'helloworld' containing a
 * single test function named 'sayhello' contained in that test case. At
 * test execution time the test case would be selectable using the tags
 * "tag1" or "tag2", or by its name 'helloworld'.  The test function can
 * be selected using tags "tag3" or "tag4", or by its name
 * 'helloworld_sayhello'.
 *
 * Given the object code generated from this file, the
 * 'make-test-scaffolding' utility will prepare the scaffolding needed
 * to create a executable that can be used to execute these tests.
 *
 * Specifically the 'make-test-scaffolding' utilit will generate test and
 * test case descriptors equivalent to:
 *
 *   struct test_descriptor test_functions_helloworld[] = {
 *       {
 *           .t_description = tf_description_helloworld_sayhello,
 *           .t_tags = tf_tags_helloworld_sayhello,
 *           .t_func = tf_helloworld_sayhello
 *       }
 *   };
 *
 *   struct test_case_descriptor test_cases[] = {
 *       {
 *            .tc_description = tc_description_helloworld,
 *            .tc_tags = tc_tags_helloworld,
 *            .tc_tests = test_functions_helloworld
 *       }
 *   };
 */

/*
 * A symbol name prefixed with 'tc_description_' contains a
 * test case description. In the case of the symbol below,
 * the test case named is 'helloworld'.
 */
TESTCASE_DESCRIPTION(helloworld) = "A description for a test case.";

/*
 * Function names prefixed with 'tc_setup_' are assumed to be test
 * case set up functions.
 */
enum testcase_status
tc_setup_helloworld(testcase_state *state)
{
	return (TESTCASE_OK);
}

/*
 * Function names prefixed with 'tc_teardown_' are assumed to be test
 * case tear down functions.
 */
enum testcase_status
tc_teardown_helloworld(testcase_state state)
{
	return (TESTCASE_OK);
}

/*
 * Names prefixed with 'tc_tags_' denote the tags associated with
 * test cases.
 *
 * In the example below, all test functions belonging to the test case
 * named 'helloworld' would be associated with tags "tag1" and "tag2".
 */
TESTCASE_TAGS(helloworld) = {
	"tag1",
	"tag2",
	NULL
};

/*
 * Function names prefixed with 'tf_' name test functions.
 */
enum test_result
tf_helloworld_sayhello(testcase_state state)
{
	return (TEST_PASS);
}

/*
 * Names prefixed by 'tf_description_' contain descriptions of test
 * functions.
 */
TEST_DESCRIPTION(helloworld_sayhello) =
    "A description for the test function 'tf_helloworld_sayhello'.";

/*
 * Names prefixed by 'tf_tags_' contain the tags associated with
 * test functions.
 *
 * In the example below, the tags 'tag3' and 'tag4' are associated
 * with the test function 'tf_helloworld_sayhello'.
 */
test_tags tf_tags_helloworld_sayhello = {
	"tag3",
	"tag4",
	NULL
};
