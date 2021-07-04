#include "User.h"

void User::follow(int userId)
{
	followed.emplace(userId);
}

void User::unfollow(int userId)
{
	if (userId != this->id) {
		followed.erase(userId);
	}
}

void User::post(int tweetId, int time)
{
	Tweet* twt = new Tweet(tweetId, time);
	twt->next = head;
	head = twt;
}
