#include <cassert>
#include "my_json.h"

#define EXPECT(c, c_expect) do { assert(c.json[0] == c_expect); } while(0)

class j_context { // wrap the input parameter up
  public:
    j_context (const string& input_json) : json(input_json){}
    string json;
};

static void j_parse_whitespace(j_context& c);
static bool j_parse_singular(j_context& c);
static int j_parse_value(j_context& c, j_node* v);
static int j_parse_null(j_context& c, j_node* v);
static int j_parse_true(j_context& c, j_node* v);
static int j_parse_false(j_context& c, j_node* v);

j_type j_get_type(const j_node* v) {
  return v->type;
}

int j_parse(j_node* v, const string& json) {
  assert(v != NULL);
  j_context c = j_context(json);
  v->type = J_NULL; //all type initialized as null
  j_parse_whitespace(c);
  return j_parse_value(c, v);
}


static void j_parse_whitespace(j_context& c) {
  int pos = 0;
  while ((c.json[pos] == ' ' || c.json[pos] == '\t' || c.json[pos] == '\n' || c.json[pos] == '\r' ) && pos < c.json.size())
    pos++;
  c.json = c.json.substr(pos);//using substring has defect
}

static bool j_parse_singular(j_context& c) {
  j_parse_whitespace(c);
  return c.json.empty();
}

static int j_parse_null(j_context& c, j_node* v) {
  EXPECT(c, 'n');
  if (c.json.substr(0, 4) != "null") return J_PARSE_INVALID_VALUE;
  c.json = c.json.substr(4);
  v->type = J_NULL;
  if (!j_parse_singular(c)) return J_PARSE_ROOT_NOT_SINGULAR;
  else return J_PARSE_OK;
}

static int j_parse_true(j_context& c, j_node* v) {
  EXPECT(c, 't');
  if (c.json.substr(0, 4) != "true") return J_PARSE_INVALID_VALUE;
  c.json = c.json.substr(4);
  v->type = J_TRUE;
  if (!j_parse_singular(c)) return J_PARSE_ROOT_NOT_SINGULAR;
  else return J_PARSE_OK;
}

static int j_parse_false(j_context& c, j_node* v) {
  EXPECT(c, 'f');
  if (c.json.substr(0, 5) != "false") return J_PARSE_INVALID_VALUE;
  c.json = c.json.substr(5);
  v->type = J_FALSE;
  if (!j_parse_singular(c)) return J_PARSE_ROOT_NOT_SINGULAR;
  else return J_PARSE_OK;
}

static int j_parse_value(j_context& c, j_node* v) {
  if (c.json[0] == '\0') return J_PARSE_EXPECT_VALUE;
  else if (c.json[0] == 'n') return j_parse_null(c, v);
  else if (c.json[0] == 't') return j_parse_true(c, v);
  else if (c.json[0] == 'f') return j_parse_false(c, v);
  else return J_PARSE_INVALID_VALUE;
}


