#ifndef MY_JSON_H
#define MY_JSON_H
#include <iostream>
#include <string>

using namespace std;
enum j_type {J_NULL, J_FALSE, J_TRUE, J_NUMBER, J_STRING, J_ARRAY, J_OBJECT};// there are 6 types in JSON
enum j_parse_result {J_PARSE_OK = 0, J_PARSE_EXPECT_VALUE, J_PARSE_INVALID_VALUE, J_PARSE_ROOT_NOT_SINGULAR};
class j_node {
  public:
    j_node (j_type input_type) : type(input_type) {}
    j_type type;
};// j_node is the node structure in a JSON tree
int j_parse(j_node* v, const string& json); // parse the input string type json into tree type json and change the root node v
j_type j_get_type(const j_node* v); // retrieve the value inside the node class

#endif
