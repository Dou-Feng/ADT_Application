#include "User.h"


/*��ʼ��*/
User::User(int id, char *name)
{
	this->id = id;
	strcpy_s(this->name, name);
	friends = new ADT();
	fans = new ADT();
	followed = new ADT();
}

/*��������*/
User::~User()
{
	friends->destroy();
	fans->destroy();
	followed->destroy();
}

/*��Ӻ��ѡ���˿����ע��*/
bool User::add(KINDS a, Member m)
{
	ADT *operatingObj = nullptr;
	switch (a)
	{
	case FRIEND:
		operatingObj = friends;
		break;
	case FAN:
		operatingObj = fans;
		break;
	case FOLLOWED:
		operatingObj = followed;
		break;
	default:
		break;
	}
	if (operatingObj->insert(m))
		return true;
	else
		return false;
}

/*ɾ�����ѡ���˿����ע��*/
bool User::remove(KINDS a, Member m)
{
	ADT *operatingObj = nullptr;
	switch (a)
	{
	case FRIEND:
		operatingObj = friends;
		break;
	case FAN:
		operatingObj = fans;
		break;
	case FOLLOWED:
		operatingObj = followed;
		break;
	default:
		break;
	}
	if (operatingObj->remove(m))
		return true;
	else
		return false;
}

/*�޸ĺ��ѡ���˿����ע��*/
bool User::modify(KINDS a, int key, Member new_m)
{
	ADT *operatingObj = nullptr;
	switch (a)
	{
	case FRIEND:
		operatingObj = friends;
		break;
	case FAN:
		operatingObj = fans;
		break;
	case FOLLOWED:
		operatingObj = followed;
		break;
	default:

		break;
	}
	if (operatingObj->modify(key, new_m))
		return true;
	else
		return false;
}

/*���Һ��ѡ���˿����ע��*/
Member User::find(KINDS a, Member m)
{
	ADT *operatingObj = nullptr;
	Member find_s;
	switch (a)
	{
	case FRIEND:
		operatingObj = friends;
		break;
	case FAN:
		operatingObj = fans;
		break;
	case FOLLOWED:
		operatingObj = followed;
		break;
	default:
		break;
	}
	if ((find_s = operatingObj->find(m.id)).id != UNINIT)
		return find_s;
	else
		return find_s;
}

/*�õ����Ѽ�*/
ADT User::getFriends()
{
	return *this->friends;
}

/*�õ���˿*/
ADT User::getFans()
{
	return *this->fans;
}

/*�õ���ע*/
ADT User::getFollowed()
{
	return *this->followed;
}

char * User::getName()
{
	return this->name;
}

/*�õ�id*/
int User::getId()
{
	return this->id;
}

#pragma warning(disable:4996)
/*��ȡ�ļ�*/
bool User::read()
{
	// int to char*
	string id_s = to_string(id);
	const char *id_c = id_s.c_str();
	//�����ļ���
	char file_name_friends[30] = "./user_data";
	char file_name_fans[30] = "./user_data";
	char file_name_followed[30] = "./user_data";
	strcat_s(file_name_friends, id_c);
	strcat_s(file_name_friends, "friends.dat");
	strcat_s(file_name_fans, id_c);
	strcat_s(file_name_fans, "fans.dat");
	strcat_s(file_name_followed, id_c);
	strcat_s(file_name_followed, "followed.dat");

	//���ļ�
	FILE *f_friends = fopen(file_name_friends, "r");
	FILE *f_fans = fopen(file_name_fans, "r");
	FILE *f_followed = fopen(file_name_followed, "r");
	
	//���ô��溯��
	if (
		friends->read(f_friends) &&
		fans->read(f_fans) &&
		followed->read(f_followed)) {
		fclose(f_friends);
		fclose(f_fans);
		fclose(f_followed);
		return true;
	}
	else
		return false;
}

/*д���ļ�*/
bool User::save()
{
	// int to char*
	string id_s = to_string(id);
	const char *id_c = id_s.c_str();
	//�����ļ���
	char file_name_friends[30] = "./user_data";
	char file_name_fans[30] = "./user_data";
	char file_name_followed[30] = "./user_data";
	strcat_s(file_name_friends, id_c);
	strcat_s(file_name_friends, "friends.dat");
	strcat_s(file_name_fans, id_c);
	strcat_s(file_name_fans, "fans.dat");
	strcat_s(file_name_followed, id_c);
	strcat_s(file_name_followed, "followed.dat");
	//���ļ�
	FILE *f_friends = fopen(file_name_friends, "w");
	FILE *f_fans = fopen(file_name_fans, "w");
	FILE *f_followed = fopen(file_name_followed, "w");
	//���ô��溯��
	if (
		friends->save(f_friends) &&
		fans->save(f_fans) &&
		followed->save(f_followed)) {
		fclose(f_friends);
		fclose(f_fans);
		fclose(f_followed);
		return true;
	}
	else
		return false;
}


/*�ҵ���ͬ��ע���ˣ����������coll��*/
void User::InterFollowings(Member * coll, User * a, User * b)
{
	ADT::set_intersection(coll, a->followed, b->followed);
}

/*�ҵ���ͬϲ�ã����������coll��*/
void User::InterFans(Member * coll, User * a, User * b)
{
	ADT::set_intersection(coll, a->fans, b->fans);
}

/*�ҵ���ͬ���ѣ����������coll��*/
void User::InterFriends(Member * coll, User * a, User * b)
{
	ADT::set_intersection(coll, a->friends, b->friends);
}


