#include "cstl_map.h"

#include <stdlib.h>

int cstl_map_comparator(void *first,
                        void *second,
                        int (*comparator)(void *, void *))
{
   return comparator((cstl_map_element *)first->first,
                     (cstl_map_element *)second->first);
}

typedef struct cstl_map_destroy_arg cstl_map_destroy_arg;
struct cstl_map_destroy_arg
{
   void (*destroy_first)(void *, void *);
   void (*destroy_second)(void *, void *);
};

void cstl_map_destroy(void *data, void *destroy_arg)
{
   (cstl_map_destroy_arg *)destroy_arg->destroy_first(
                                             (cstl_map_element *)data->first);
   (cstl_map_destroy_arg *)destroy_arg->destroy_second(
                                             (cstl_map_element *)data->second);
   free(data);
}

/* initialize a map */
int cstl_map_initialize(cstl_map *map,
                        int (*comparator)(void *, void *),
                        void (*destroy)(void *))
{
   return cstl_rbtree_initialize(map,
                                 comparator,
                                 destroy);
}

/* destroy a map */
int cstl_map_destroy(cstl_map *map)
{
   return cstl_rbtree_destroy(map);
}

/* retrieve the number of elements in an map */
int cstl_map_size(cstl_map *map)
{
   return cstl_rbtree_size(map);
}

/* retrieve the data from an map element */
void *cstl_map_data(cstl_map_element *element)
{
   return cstl_map_data(element);
}

/* retrieve the element at the beginning of the linked map */
cstl_map_element *cstl_map_begin(cstl_map *map)
{
   return cstl_rbtree_begin(map);
}

/* retrieve the element at the end of the linked map */
cstl_map_element *cstl_map_end(cstl_map *map)
{
   return cstl_rbtree_end(map);
}

/* retrieve the next map element */
cstl_map_element *cstl_map_next(cstl_map_element *element)
{
   return cstl_rbtree_next(element);
}

/* retrieve the previous map element */
cstl_map_element *cstl_map_prev(cstl_map_element *element)
{
   return cstl_rbtree_next(element);
}

/* insert data into map */
int cstl_map_insert(cstl_map *map,
                    void *data)
{
   return cstl_rbtree_insert(map,
                             data);
}

/* retrieve data from map */
cstl_map_element *cstl_map_find(cstl_map *map,
                                void *data)
{
}

/* remove the element from the map while calling the destroy method */
int cstl_map_remove(cstl_map *map,
                    void *data)
{
   return cstl_rbtree_remove(map,
                             data);
}

/* remove the element from the map while calling the destroy method */
int cstl_map_remove_element(cstl_map_element *element)
{
   return cstl_rbtree_remove_element(element);
}

/* remove the element from the map while not calling the destroy method */
int cstl_map_unlink(cstl_map *map,
                    void *data,
                    void **retData)
{
   return cstl_rbtree_unlink(map,
                             data,
                             retData);
}

/* remove the element from the map while not calling the destroy method */
int cstl_map_unlink_element(cstl_map_element *element,
                            void **retData)
{
   return cstl_rbtree_unlink_element(element,
                                     retData);
}
