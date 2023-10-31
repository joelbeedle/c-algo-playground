#include "data_structures/linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <stdlib.h>

TestSuite(linked_list_tests);

// Test for 'createNode' function
Test(linked_list_tests, test_createNode) {
  DataType type = INT;
  int value = 123;
  Node *result = createNode(type, &value, sizeof(value));

  cr_assert_not_null(result, "createNode returned NULL");
  cr_assert_eq(result->data.type, type, "Type mismatch in created node");
  cr_assert_not_null(result->data.data, "Data field is NULL in created node");
  cr_assert_eq(*(int *)result->data.data, value,
               "Data value mismatch in created node");

  // Cleanup
  free(result->data.data);
  free(result);
}

// Test for 'llist_create' function
Test(linked_list_tests, test_llist_create) {
  DataType type = FLOAT;
  LinkedList *list = llist_create(type);

  cr_assert_not_null(list, "llist_create returned NULL");
  cr_assert_eq(list->type, type, "Type mismatch in created list");

  // Cleanup
  llist_free(list); // assuming it handles NULL head
}

// Test for 'llist_append' function
Test(linked_list_tests, test_llist_append) {
  DataType type = INT;
  int values[] = {10, 20, 30};
  int num_values = sizeof(values) / sizeof(values[0]);

  LinkedList *list = llist_create(type);

  // Append values to the list and check if the list contains the right values
  for (int i = 0; i < num_values; ++i) {
    llist_append(list, &values[i]);

    Node *current = list->head;
    for (int j = 0; j <= i; ++j) {
      cr_assert_not_null(current, "Node is unexpectedly NULL");
      cr_assert_eq(*(int *)current->data.data, values[j],
                   "Data value mismatch in node");
      current = current->next;
    }
    cr_assert_null(current, "List longer than expected after append operation");
  }

  // Cleanup
  llist_free(list);
}

// Test for 'llist_fromarr' function
Test(linked_list_tests, test_llist_fromarr) {
  DataType type = INT;
  int values[] = {10, 20, 30};
  int num_values = sizeof(values) / sizeof(values[0]);

  LinkedList *list = llist_create(type);
  llist_fromarr(list, values, num_values);

  Node *current = list->head;
  for (int i = 0; i < num_values; ++i) {
    cr_assert_not_null(current, "Node is unexpectedly NULL");
    cr_assert_eq(*(int *)current->data.data, values[i],
                 "Data value mismatch in node");
    current = current->next;
  }
  cr_assert_null(current, "List longer than expected");

  // Cleanup
  llist_free(list);
}

// Test for 'llist_delete' function
Test(linked_list_tests, test_llist_delete) {
  DataType type = INT;
  int values[] = {10, 20, 30, 40};
  int num_values = sizeof(values) / sizeof(values[0]);

  LinkedList *list = llist_create(type);
  for (int i = 0; i < num_values; ++i) {
    llist_append(list, &values[i]);
  }

  // Attempt to delete a non-existent value
  int non_existent_value = 100;
  llist_delete(list, &non_existent_value);

  Node *current = list->head;
  for (int i = 0; i < num_values; ++i) {
    cr_assert_not_null(current,
                       "Node is unexpectedly NULL after failed delete");
    cr_assert_eq(*(int *)current->data.data, values[i],
                 "Data value mismatch in node after failed delete");
    current = current->next;
  }

  // Delete middle element and check
  llist_delete(list, &values[1]);

  int expected_remaining_values[] = {10, 30, 40};
  current = list->head;
  for (int i = 0; i < num_values - 1; ++i) {
    cr_assert_not_null(current, "Node is unexpectedly NULL after deletion");
    cr_assert_eq(*(int *)current->data.data, expected_remaining_values[i],
                 "Data value mismatch in node after deletion");
    current = current->next;
  }

  // Cleanup
  llist_free(list);
}
