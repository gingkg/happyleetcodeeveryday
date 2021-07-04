#pragma once

#include <iostream>
#include <unordered_set>
#include "Tweet.h"
using namespace std;


class User
{
public:
	int id;
	unordered_set<int> followed;
	Tweet* head;

public:
	User() {
		id = 0;
		head = nullptr;
		// 关注⼀下⾃⼰
		follow(id);
	}
	User(int userId) {
		id = userId;
		head = nullptr;
		// 关注⼀下⾃⼰
		follow(id);
	}
	~User() {
		delete head;
		head = nullptr;
	}

public:
	void follow(int userId);
	void unfollow(int userId);
	void post(int tweetId, int time);
};



