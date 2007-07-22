#include "cstl_set.h"

/* initialize a set */
int cstl_set_initialize(cstl_set *set,
                        int (*comparator)(void *, void *),
                        void (*destroy)(void *))
{
   return cstl_rbtree_initialize(set,
                                 comparator,
                                 destroy);
}

/* destroy a set */
int cstl_set_destroy(cstl_set *set)
{
   return cstl_rbtree_destroy(set);
}

/* retrieve the number of elements in an set */
int cstl_set_size(cstl_set *set)
{
   return cstl_rbtree_size(set);
}

/* retrieve the data from an set element */
void *cstl_set_data(cstl_set_element *element)
{
   return cstl_set_data(element);
}

/* retrieve the element at the beginning of the linked set */
cstl_set_element *cstl_set_begin(cstl_set *set)
{
   return cstl_rbtree_begin(set);
}

/* retrieve the element at the end of the linked set */
cstl_set_element *cstl_set_end(cstl_set *set)
{
   return cstl_rbtree_end(set);
}

/* retrieve the next set element */
cstl_set_element *cstl_set_next(cstl_set_element *element)
{
   return cstl_rbtree_next(element);
}

/* retrieve the previous set element */
cstl_set_element *cstl_set_prev(cstl_set_element *element)
{
   return cstl_rbtree_next(element);
}

/* insert data into set */
int cstl_set_insert(cstl_set *set,
                    void *data)
{
   return cstl_rbtree_insert(set,
                             data);
}

/* retrieve data from set */
cstl_set_element *cstl_set_find(cstl_set *set,
                                void *data)
{
}

/* remove the element from the set while calling the destroy method */
int cstl_set_remove(cstl_set *set,
                    void *data)
{
   return cstl_rbtree_remove(set,
                             data);
}

/* remove the element from the set while calling the destroy method */
int cstl_set_remove_element(cstl_set_element *element)
{
   return cstl_rbtree_remove_element(element);
}

/* remove the element from the set while not calling the destroy method */
int cstl_set_unlink(cstl_set *set,
                    void *data,
                    void **retData)
{
   return cstl_rbtree_unlink(set,
                             data,
                             retData);
}

/* remove the element from the set while not calling the destroy method */
int cstl_set_unlink_element(cstl_set_element *element,
                            void **retData)
{
   return cstl_rbtree_unlink_element(element,
                                     retData);
}
