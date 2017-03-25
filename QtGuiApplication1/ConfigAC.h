#pragma once
#include<cstring>
#include <string>
#include <sstream>
#include <ios> // boolalpha
#include <vector>
#include <unordered_map>
#include <utility> // pair
#include<qstring.h>

/*const*/
#define POWERHIGH 1.25
#define POWERMEDIUM 1
#define POWERLOW 0.75
#define POWERNON 0

#define ELECOST 1

#define TCELL 35
#define TFLOOR 10
#define TDEFAULT 25


class ConfigAC{
public:
	ConfigAC();
	~ConfigAC();
	bool filled;//unused
	double Tcell, Tfloor, Tdefault;
	int mode;
	double Ecost;
	std::vector<double> Epower;
};

enum AC {
	COOL, WARM, NON, LOW, MEDIUM, HIGH, 
	ON, OFF, FIFS, PRI, RR, 
	ONC, OFFC, CNTC
};

/* for detail list */
enum EVENT {
	TOCOOL, TOWARM, TOLOW, TOMEDIUM, TOHIGH,
	TURNON, TURNOFF, TOFIFS, TOFRI, TORR,
	NEWTARGET
};

/* for GUI label */
extern const char* ACstr[14];

QString Enum2QStr(int index);
int QStr2Enum(QString str);
int Str2Enum(std::string str);


class ParserAC
{
public:
	ParserAC(const std::string& filename);
	~ParserAC();

	template <typename T, typename... Args>
	void get(const std::string& key, T& value, Args&... args) const;
	template <typename T>
	void get(const std::string& key, std::vector<T>& vector) const;

	template <typename T, typename... Args>
	void set(const std::string& key, const T& value, const Args&... args);
	template <typename T>
	void set(const std::string& key, const std::vector<T>& vector);

private:
	typedef std::pair<std::string, std::string> KeyValuePair;
	template <typename T>
	void toValue(std::string& str, T& value) const;
	template <typename T>
	void toValue(std::istringstream& iss, T& value) const;

	void trim(std::string& string) const; // trim whitespace from string
	KeyValuePair parse(const std::string& line) const;

private:
	bool modified = false;
	std::string filename;
	std::unordered_map<std::string, std::string> configMap;
};
