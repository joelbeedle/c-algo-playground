#include <criterion/criterion.h>
#include <criterion/logging.h>

#include "data_structures/hashmap.h"

TestSuite(hashmap_tests);

Test(hashmap_tests, test_hmap_hash) {
  HashMap *hm = hmap_create(INT, INT);
  int key_int = 123;
  cr_assert(hash(hm, &key_int) < TABLE_SIZE);

  hm->key_type = FLOAT;
  float key_float = 123.456;
  cr_assert(hash(hm, &key_float) < TABLE_SIZE);

  hm->key_type = STRING;
  char *key_string = "test";
  cr_assert(hash(hm, &key_string) < TABLE_SIZE);

  // Cleanup
  hmap_free(hm);
}

Test(hashmap_tests, test_hmap_create) {
  DataType key_type = INT;
  DataType val_type = FLOAT;
  HashMap *hm = hmap_create(key_type, val_type);

  cr_assert_not_null(hm, "hmap_create returned NULL");
  cr_assert_eq(hm->key_type, key_type, "Key type mismatch in created hashmap");
  cr_assert_eq(hm->val_type, val_type,
               "Value type mismatch in created hashmap");

  for (int i = 0; i < TABLE_SIZE; i++) {
    cr_assert(hm->table[i]);
  }
  // Cleanup
  hmap_free(hm);
}

Test(hashmap_tests, test_hmap_put_get_int_keys) {
  HashMap *i_hm = hmap_create(INT, INT);
  HashMap *f_hm = hmap_create(INT, FLOAT);
  HashMap *s_hm = hmap_create(INT, STRING);
  int key = 123;
  int i_value = 456;
  float f_value = 456.789f;
  char *s_value = "hello";

  // Ints
  hmap_put(i_hm, &key, &i_value);
  int *i_retrieved_value = (int *)hmap_get(i_hm, &key);
  cr_assert_eq(*i_retrieved_value, i_value);

  // Floats
  hmap_put(f_hm, &key, &f_value);
  float *f_retrieved_value = (float *)hmap_get(f_hm, &key);
  cr_assert_float_eq(*f_retrieved_value, f_value, 1e-6);

  // Strings
  hmap_put(s_hm, &key, s_value);
  char *s_retrieved_value = (char *)hmap_get(s_hm, &key);
  cr_assert_str_eq(s_retrieved_value, s_value);

  hmap_free(i_hm);
  hmap_free(f_hm);
  hmap_free(s_hm);
}

Test(hashmap_tests, test_hmap_put_get_float_keys) {
  HashMap *i_hm = hmap_create(FLOAT, INT);
  HashMap *f_hm = hmap_create(FLOAT, FLOAT);
  HashMap *s_hm = hmap_create(FLOAT, STRING);
  float key = 12.3f;
  int i_value = 456;
  float f_value = 456.789f;
  char *s_value = "hello";

  // Ints
  hmap_put(i_hm, &key, &i_value);
  int *i_retrieved_value = (int *)hmap_get(i_hm, &key);
  cr_assert_eq(*i_retrieved_value, i_value);

  // Floats
  hmap_put(f_hm, &key, &f_value);
  float *f_retrieved_value = (float *)hmap_get(f_hm, &key);
  cr_assert_float_eq(*f_retrieved_value, f_value, 1e-6);

  // Strings
  hmap_put(s_hm, &key, s_value);
  char *s_retrieved_value = (char *)hmap_get(s_hm, &key);
  cr_assert_str_eq(s_retrieved_value, s_value);

  hmap_free(i_hm);
  hmap_free(f_hm);
  hmap_free(s_hm);
}

Test(hashmap_tests, test_hmap_put_get_str_keys) {
  HashMap *i_hm = hmap_create(STRING, INT);
  HashMap *f_hm = hmap_create(STRING, FLOAT);
  HashMap *s_hm = hmap_create(STRING, STRING);
  char *key = "test";
  int i_value = 456;
  float f_value = 456.789f;
  char *s_value = "hello";

  // Ints
  hmap_put(i_hm, &key, &i_value);
  int *i_retrieved_value = (int *)hmap_get(i_hm, &key);
  cr_assert_eq(*i_retrieved_value, i_value);

  // Floats
  hmap_put(f_hm, &key, &f_value);
  float *f_retrieved_value = (float *)hmap_get(f_hm, &key);
  cr_assert_float_eq(*f_retrieved_value, f_value, 1e-6);

  // Strings
  hmap_put(s_hm, &key, s_value);
  char *s_retrieved_value = (char *)hmap_get(s_hm, &key);
  cr_assert_str_eq(s_retrieved_value, s_value);

  hmap_free(i_hm);
  hmap_free(f_hm);
  hmap_free(s_hm);
}