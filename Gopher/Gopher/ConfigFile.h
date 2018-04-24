#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include "Convert.h"

class ConfigFile
{
private:
	std::map<std::string, std::string> contents;
	std::string fName;

	//Keybind Variables Gopher Variables
	std::string Left_Mouse = "0x1000";
	std::string Right_Mouse = "0x4000";
	std::string Middle_Mouse = "0x0040";
	std::string Hide= "0x8000";
	std::string Disable= "0x0030";
	std::string Vibration_Disable= "0x0011";
	std::string Speed_Change = "0x0300";
	std::string Open_Keyboard= "0x0010";

	//Keybind Variables Gamepad Bindings
	std::string Dpad_Up = "0x26";
	std::string Dpad_Down= "0x28";
	std::string Dpad_Left= "0x25";
	std::string Dpad_Right= "0x27";
	std::string Start= "0";
	std::string Back= "0";
	std::string Left_Thumb= "0";
	std::string Right_Thumb= "0x71";
	std::string Left_Shoulder= "0xAE";
	std::string Right_Shoulder= "0xAF";
	std::string A= "0";
	std::string B= "0x0D";
	std::string X= "0";
	std::string Y= "0";
	std::string Trigger_Left= "0x20";
	std::string Trigger_Right= "0xA8";

	void removeComment(std::string &line) const;

	bool onlyWhitespace(const std::string &line) const;
	bool validLine(const std::string &line) const;

	void extractKey(std::string &key, size_t const &sepPos, const std::string &line) const;
	void extractValue(std::string &value, size_t const &sepPos, const std::string &line) const;

	void extractContents(const std::string &line);

	void parseLine(const std::string &line, size_t const lineNo);

	void ExtractKeys();

public:
	ConfigFile(const std::string &fName);

	bool keyExists(const std::string &key) const;

	template <typename ValueType>
	ValueType getValueOfKey(const std::string &key, ValueType const &defaultValue = ValueType()) const
	{
		if (!keyExists(key))
			return defaultValue;

		return Convert::string_to_T<ValueType>(contents.find(key)->second);
	};

	void exitWithError(const std::string &error);
};