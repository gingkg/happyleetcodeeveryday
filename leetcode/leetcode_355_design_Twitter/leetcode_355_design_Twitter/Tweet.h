#pragma once
class Tweet
{
public:
	int id;
	int time;
	Tweet* next;

public:
	Tweet() {
		id = 0;
		time = 0;
		next = nullptr;
	}
	Tweet(int id, int time) {
		Tweet::id = id;
		Tweet::time = time;
		next = nullptr;
	}
	~Tweet() {
		delete next;
		next = nullptr;
	}

};

