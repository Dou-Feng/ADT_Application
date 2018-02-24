#pragma once
#include "AVLTree.h"


class ADT
{
public:
	ADT();
	void getAllElem(Member *coll);
	int getSize();
	bool insert(Member coll);
	int insert(Member *coll, int size);
	int insert(ADT *A);
	bool remove(Member m);
	int remove(Member *m, int size);
	int remove(ADT *A);
	bool destroy();

	static ADT *set_intersection(Member *coll, ADT *a, ADT *b);
	static ADT *set_different(Member *coll, ADT *a, ADT *b);
	static ADT *set_union(Member *coll, ADT *a, ADT *b);
	static bool set_subset(ADT *a, ADT *b);
	static bool set_equal(ADT *a, ADT *b);

public:
	AVLTree *elems;

};

