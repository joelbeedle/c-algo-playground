#include <stdio.h>
#include <stdlib.h>

#include "data_structures/hashmap.h"
#include "data_structures/llist.h"
#include "data_structures/stack.h"

int main(int argc, char *argv[]) {
  int arr[3] = {1, 2, 3};

  HashMap *hm_strings = hmap_create(INT, STRING);
  char *str1 = "hello";
  char *str2 = "world";
  hmap_put(hm_strings, &arr[0], str1);
  hmap_put(hm_strings, &arr[1], str2);
  char *result = hmap_get(hm_strings, &arr[0]);
  printf("%s\n", result);
  return 0;
}