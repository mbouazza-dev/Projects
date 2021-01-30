/* abstract-tree.h */

typedef enum {
  Program,
  VarDeclList,
  IntLiteral,
  CharLiteral,
  Identifier,
  VarDec,
  FunDeclList,
  FunDec,
  ParamList,
  Param,
  Pointeur,
  Body,
  Char,
  Int,
  EnTeteFonct,
  Void,
  SuiteInstr,
  Instr,
  LValue,
  Assign,
  Return,
  Expr,
  Or,
  And,
  Add,
  Sub,
  ReadE,
  ReadC,
  Print,
  Condition,
  ConditionTrue,
  Else,
  WhileBoucle,
  Equal,
  NotEqual,
  Greater,
  Less,
  GreaterOrEqual,
  LessOrEqual,
  Multiply,
  Div,
  Mod,
  Not,
  Adress,
  ArgList,
  ListExpr
  /* and allother node labels */
  /* The list must coincide with the strings in abstract-tree.c */
  /* To avoid listing them twice, see https://stackoverflow.com/a/10966395 */
} Kind;

typedef struct Node {
  Kind kind;
  union {
    int integer;
    char character;
    char identifier[64];
  } u;
  struct Node *firstChild, *nextSibling;
  int lineno;
  int type;
  int pos;
  int portee;
} Node;

Node *makeNode(Kind kind);
void addSibling(Node *node, Node *sibling);
void addChild(Node *parent, Node *child);
void deleteTree(Node*node);
void printTree(Node *node);

#define FIRSTCHILD(node) node->firstChild
#define SECONDCHILD(node) node->firstChild->nextSibling
#define THIRDCHILD(node) node->firstChild->nextSibling->nextSibling
