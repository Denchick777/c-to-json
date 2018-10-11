/**
 * Abstract Syntax Tree building functions for parser
 * of the C Programming Language (ISO/IEC 9899:2018).
 *
 * @authors: Denis Chernikov, Vladislav Kuleykin
 */

#ifndef C_PARSER_AST_BUILDER_H_INCLUDED
#define C_PARSER_AST_BUILDER_H_INCLUDED

#include <stddef.h>

/// Types of AST node content.
typedef enum
{
    TranslationUnit,
    // TODO content types
}
AST_NODE_TYPE;

/// Structure for storing AST node data.
typedef struct AST_NODE
{
    AST_NODE_TYPE type;
    void *content;
    int children_number;
    struct AST_NODE **children;
}
AST_NODE;

/// Root of built AST after parsing.
AST_NODE *ast_root;

/// Create node with a given set of children.
/// Needs to be freed.
///
/// \param type Type of AST node
/// \param n_children Number of children
/// \param ... List of children
/// \return New AST node
AST_NODE *ast_create_node(AST_NODE_TYPE type, size_t n_children, ...);

/// Append given child to the given AST node.
///
/// \param node Node to append child to
/// \param to_append Child to append to the node
/// \return New node after expansion
AST_NODE *ast_expand_node(AST_NODE *node, AST_NODE *to_append);

/// Convert enum AST_NODE_TYPE to string.
///
/// \param type Enum value to convert
/// \return Actual string representation of a value
char *ast_type_to_str(AST_NODE_TYPE type);

/// Free memory associated with node and it's children.
///
/// \param root Root of the tree to be freed recursively
void ast_free(AST_NODE *root);

/// Get JSON string representation of an AST. Needs to be freed.
///
/// \param root Root of the tree to be converted to JSON
/// \param shift Shift size at the beginning of line
/// \param tab String representation of the tabulation
/// \return JSON representation of a tree
char *ast_to_json(AST_NODE *root, int shift, char *tab);

#endif //C_PARSER_AST_BUILDER_H_INCLUDED
