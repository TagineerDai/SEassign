#include <fstream>
#include <iostream>
#include <algorithm> // find_if
#include <cctype> // isalpha
#include"ConfigAC.h"

const char* ACstr[14] = {
	"制冷", "制热", "未运行", "低速", "中速", "高速",
	"运行", "停止", "先到先服务", "优先级","Round Robin",
	"已连接", "未连接", "未开机"
};

ConfigAC::ConfigAC() {
	ParserAC parser = ParserAC("config.txt");
	parser.get("Tcell", Tcell);
	parser.get("Tfloor", Tfloor);
	parser.get("Tdefault", Tdefault);
	int type;
	parser.get("workmodel", type);
	if (type == 0)
		mode = AC::COOL;
	else
		mode = AC::WARM;
	parser.get("Ecost", Ecost);
	parser.get("Epower", Epower);
}

ConfigAC::~ConfigAC() {
}

ParserAC::ParserAC(const std::string& filename)
	: filename(filename)
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
	{
		std::cout << "ParserAC::ParserAC - Unable to open " << filename << "." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(ifs, line))
	{
		trim(line);
		auto pair = parse(line);

		if (!pair.first.empty() && !pair.second.empty())
			configMap[pair.first] = pair.second; // overwrite if exists
	}

	ifs.close();
}

ParserAC::~ParserAC()
{
	if (!modified)
		return;

	std::vector<KeyValuePair> content;

	/* READ CONTENT */
	std::ifstream ifs(filename);
	if (ifs.is_open())
	{
		std::string line;
		while (std::getline(ifs, line))
		{
			trim(line);
			auto pair = parse(line);

			if (!pair.first.empty() && !pair.second.empty())
			{
				auto found = configMap.find(pair.first);
				if (found != configMap.end())
					pair.second = found->second;
			}

			else
			{
				pair.first = line;
				pair.second = "";
			}
			content.emplace_back(pair);
		}
		ifs.close();
	}

	// add elements that doesn't exist in a file but exist in configMap
	// opened to the user to modify the complexity of the network {useless
	for (auto it = configMap.begin(); it != configMap.end(); ++it)
	{
		auto found = std::find_if(content.begin(), content.end(), [&](const KeyValuePair& p)
		{
			return p.first == it->first;
		});

		if (found == content.end())
			content.emplace_back(it->first, it->second);
	}

	/* WRITE CONTENT */
	std::ofstream ofs(filename);
	if (!ofs.is_open())
	{
		std::cout << "ParserAC::~ParserAC - Unable to open " << filename << std::endl;
		return;
	}

	for (const auto& element : content)
	{
		ofs << element.first;
		if (!element.second.empty())
			ofs << " = " << element.second;
		ofs << std::endl;
	}
	ofs.close();
}

void ParserAC::trim(std::string& str) const
{
	std::size_t first = str.find_first_not_of(" \t\n");
	std::size_t last = str.find_last_not_of(" \t\n");

	if (first == std::string::npos) // empty string
		str = "";
	else
		str = str.substr(first, last - first + 1);
}

ParserAC::KeyValuePair ParserAC::parse(const std::string& line) const
{
	std::string key, value;
	std::size_t equal = line.find('=');

	if (equal != std::string::npos && std::isalpha(line.front())) // !line.empty()
	{
		key = line.substr(0, equal);
		value = line.substr(equal + 1);

		trim(key);
		trim(value);
	}

	return std::make_pair(key, value);
}



template <typename T>
void ParserAC::toValue(std::string& str, T& value) const
{
	std::istringstream iss(str);
	iss >> std::boolalpha >> value;
}

template <>
inline void ParserAC::toValue<std::string>(std::string& str, std::string& value) const
{
	trim(str);
	value = str;
}

template <typename T>
void ParserAC::toValue(std::istringstream& iss, T& value) const
{
	std::string str;
	if (std::getline(iss, str, ','))
		toValue(str, value);
}

template <typename T, typename... Args>
void ParserAC::get(const std::string& key, T& value, Args&... args) const
{
	auto found = configMap.find(key);
	if (found != configMap.end())
	{
		std::istringstream iss(found->second);
		toValue(iss, value);
		int dummy[] = { 0, (toValue(iss, args), 0) ... }; // parameter pack expansion
	}
}

template <>
inline void ParserAC::get<std::string>(const std::string& key, std::string& value) const
{
	auto found = configMap.find(key);
	if (found != configMap.end())
		value = found->second;
}

template <typename T>
void ParserAC::get(const std::string& key, std::vector<T>& vector) const
{
	auto found = configMap.find(key);
	if (found != configMap.end())
	{
		std::istringstream iss(found->second);
		std::string str;
		while (std::getline(iss, str, ','))
		{
			vector.emplace_back();
			std::istringstream(str) >> std::boolalpha >> vector.back();
		}
	}
}

template <typename T, typename... Args>
void ParserAC::set(const std::string& key, const T& value, const Args&... args)
{
	std::ostringstream oss;
	oss << std::boolalpha << value;
	int dummy[] = { 0, (oss << ", " << args, 0) ... }; // parameter pack expansion

	if (configMap[key] != oss.str())
	{
		configMap[key] = oss.str();
		modified = true;
	}
}

template <typename T>
void ParserAC::set(const std::string& key, const std::vector<T>& vector)
{
	std::ostringstream oss;
	oss << std::boolalpha;
	for (auto it = vector.begin(); it != vector.end(); ++it)
	{
		if (it != vector.begin())
			oss << ", ";
		oss << *it;
	}

	if (configMap[key] != oss.str())
	{
		configMap[key] = oss.str();
		modified = true;
	}
}


/*Covert from QString to enum
code sample:
(QLabel*)stateLabel->setText(Enum2Str(AC::OFF))
*/
QString Enum2QStr(int index) {
	if (index >= (int)AC::COOL && index <= (int)AC::CNTC)
		return QString(ACstr[index]);
	return QString();
};
/*Convert from enum to QString*/
int QStr2Enum(QString str) {
	for (int i = (int)AC::COOL; i <= (int)AC::CNTC; i++)
		if (QString::compare(str, QString(ACstr[i])) == 0)
			return i;
	return -1;
};

/*Convert from socketmsg to enum
to finish
*/
int Str2Enum(std::string str) {
	if (str.compare("") == 0) {
		return EVENT::TOWARM;
	}
};
