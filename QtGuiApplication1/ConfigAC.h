#pragma once
#include<cstring>
#include <string>
#include <sstream>
#include <ios> // boolalpha
#include <vector>
#include <unordered_map>
#include <utility> // pair
#include<qstring.h>
#define TIMEFORMAT "yyyy-MM-dd HH:mm:ss"
#include <qstring.h>

enum ROLE {
	ROOM, ADMIN
};

enum AC {
	OFF = 0, ON = 1
};

enum STRATEGY {
	FIFS, PRI, RR
};
enum MODE {
	WARM = 0, COOL = 1
};

enum CONNECT {
	ONC, OFFC, CNTC
};

enum WIND {
	NON, LOW, MEDIUM, HIGH
};

QString AC2Qstr(AC ac);
QString STRATEGY2Qstr(STRATEGY st);
QString MODE2Qstr(int m);
QString WIND2Qstr(int w);

//Connect setting
class MySQLSetting {
public:
	MySQLSetting() {}
	char user[20] = "root";         //username
	char pswd[20] = "clan95588";         //password
	char host[20] = "localhost";    //or"127.0.0.1"
	unsigned int port = 3306;           //server port
	char table[20] = "DAC";        //database
};

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
	int port;
	bool unfilled = true;
	double Tcell, Tfloor, Tdefault;
	MODE mode;
	double Ecost;// price of electric
	std::vector<double> Epower;// consume of electric/wind
	std::vector<double> Eeffect; // effect of 1 min/wind
	int interval;//time-speed ratio

	ConfigAC();
	~ConfigAC();
	void defaultCFG();
};

/* for detail list */
enum EVENT {
	TOCOOL, TOWARM, TOLOW, TOMEDIUM, TOHIGH,
	TURNON, TURNOFF, TOFIFS, TOFRI, TORR,
	NEWTARGET
};

/* for GUI label */
extern const char* ACstr[14];

class ParserAC
{
public:
	int ok=1;
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
