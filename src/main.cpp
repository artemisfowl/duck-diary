#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstring>

int main()
{
	std::string s;
	bool can_run = true;
	char time[100], fname[100];

	memset(time, '\0', 100);
	memset(fname, '\0', 100);

	std::fstream fs;
	std::time_t lt = std::time(nullptr);
	strftime(fname, 100, "./%d_%m_%Y", std::localtime(&lt));
	fs.open(fname, std::fstream::out | std::fstream::app);

	while (can_run) {
		std::time_t ct = std::time(nullptr);
		strftime(time, 100, "%H:%M:%S", std::localtime(&ct));
		std::cout << "$ ";
		std::getline(std::cin, s);

		/* breaking condition */
		if (s.length() == 1 && s == ";")
			can_run = false;

		if (can_run) {
			std::cout << time
				<< " : " << s << std::endl;
			fs << time << " : " << s << "\n";
		}
		memset(time, '\0', 100);
	}

	fs.close();
	return 0;
}
