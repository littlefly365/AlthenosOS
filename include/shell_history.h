/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#ifndef _SHELL_HISTORY_H
#define _SHELL_HISTORY_H 1

#include "tty.h"
#include "memory.h"
#include "string.h"

#define BUFFER_SIZE 1024

typedef struct node
{
    char buffer[BUFFER_SIZE];
    struct node *next;
} node_t;

node_t *create_new_node(char buffer[BUFFER_SIZE]);
void print_history(node_t *head);
void *insert_at_head(node_t **head, node_t *node_to_insert);

#endif
