#pragma once

#include <fstream>
#include <string>
#include <map>

#include "cocos2d.h"

class DataEngine
{
	DataEngine() {
		load();
	};
public:
	inline static DataEngine* instance = nullptr;
	std::map<std::string, std::string> data;

	static DataEngine* getInstance() {
		if (instance == nullptr)
			instance = new DataEngine();
		return instance;
	}

	void set(std::string varname, std::string value) {
		data[varname] = value;

		save();
	}

	std::string at(std::string key) {
		return data[key];
	}
	
	void add(std::string key, int val) {
		if (data[key] == "")
			data[key] = "0";
		data[key] = std::to_string(stoi(data[key]) + val);

		save();
	}

	void save() {
		cocos2d::log("data saved");
		std::ofstream writer("data");
		for (const std::pair<const std::string, std::string>& var : data) {
			writer << var.first << '~' << var.second << '\n';
		}
		writer.close();
	}

	void load() {
		std::ifstream reader("data");
		if (!reader.is_open()) return;
		std::string key, val;
		while (getline(reader, key, '~') && getline(reader, val))
			data[key] = val;
		reader.close();
	}

	std::string& operator[] (std::string key) {
		return data[key];
	}

	~DataEngine() {
		save();
	}

};
