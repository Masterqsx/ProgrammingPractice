#include <iostream>
#include <string>
#include "my_json.h"

using namespace std;
static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
  do {\
    test_count++;\
    if (equality)\
      test_pass++;\
    else {\
      fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
      main_ret = 1;\
    }\
  } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")
static void test_parse_null() {
  j_node v = j_node(J_NULL);
  v.type = J_TRUE;
  EXPECT_EQ_INT(J_PARSE_OK, j_parse(&v, "null"));
  EXPECT_EQ_INT(J_NULL, j_get_type(&v));
  EXPECT_EQ_INT(J_PARSE_ROOT_NOT_SINGULAR, j_parse(&v, " null a"));
}

static void test_parse_true() {
  j_node v = j_node(J_NULL);
  EXPECT_EQ_INT(J_PARSE_OK, j_parse(&v, "true"));
  EXPECT_EQ_INT(J_TRUE, j_get_type(&v));
  EXPECT_EQ_INT(J_PARSE_ROOT_NOT_SINGULAR, j_parse(&v, "true a"));
}

static void test_parse_false() {
  j_node v = j_node(J_NULL);
  EXPECT_EQ_INT(J_PARSE_OK, j_parse(&v, "false"));
  EXPECT_EQ_INT(J_FALSE, j_get_type(&v));
  EXPECT_EQ_INT(J_PARSE_ROOT_NOT_SINGULAR, j_parse(&v, "false a"));
}

static void test_parse() {
  test_parse_null();
  test_parse_true();
  test_parse_false();
}

int main() {
  test_parse();
  printf("%d %d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
  return main_ret;
}
