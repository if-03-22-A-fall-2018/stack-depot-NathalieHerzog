#include "memcheck.h"

#ifndef __DEPOT_H
#define __DEPOT_H

#define STACK_SIZE_LIMIT 3

typedef struct DepotImplementation *Depot;

typedef struct
{
    int serial_no;
} Product;

Depot create_depot();
void delete_depot(Depot depot);
int get_count(Depot depot);
void push_depot(Depot depot, Product *product);
Product *pop_depot(Depot depot);

#endif