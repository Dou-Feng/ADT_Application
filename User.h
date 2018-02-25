#pragma once
#include "ADT.h"

enum KINDS{
	FRIEND,
	FAN,
	FOLLOWED
};

class User
{
public:
	User(int id, char *name);
	~User();
	bool add(KINDS a, Member m);
	bool remove(KINDS a, Member m);
	bool modify(KINDS a, int key, Member new_m);
	Member find(KINDS a, Member m);
	ADT getFriends();
	ADT getFans();
	ADT getFollowed();
	char *getName();
	int getId();
	bool read();
	bool save();

	static void InterFollowings(Member *coll, User *a, User *b);
	static void InterFans(Member *coll, User *a, User *b);
	static void InterFriends(Member *coll, User *a, User *b);

private:
	int id;
	char name[25];
	char des[200];
	ADT *friends;
	ADT *fans;
	ADT *followed;
};

