#include <iostream>
#include <string>
#include <fstream>

std::ifstream ver("mvd");
std::string version;
int n = 0;

std::string search(std::string a) {
	std::string nversion;
	while (std::getline(ver, version)) {
		if (version.find(a) != std::string::npos)
		{
			break;
		}
	}
	ver.close();
	return version;
}

std::string create(bool type) {
	if (type == 1) {
		std::string server_namec;
		std::cout << "Creating server..." << std::endl;
		std::cout << "Enter server name:   ";
		std::cin >> server_namec;
		return server_namec;
	}
	else
	{
		std::string server_version;
		std::cout << "Enter server version:   ";
		std::cin >> server_version;
		std::string server_version_file = search(server_version).substr(25,93);

		return server_version_file;
	}
	
}


int main() {
	std::cout << "this program is in beta and is only windows" << std::endl;
	std::cout << "dont delete mvd file" << std::endl;
	std::cout << "press enter for continue" << std::endl;
	std::system("pause >nul");
	std::system("cls");
	std::cout << "Welcome to Simple Minecraft Server Installer!" << std::endl;

	std::string server_name = create(1);
	std::string server_version = create(0);
	std::string ram;
	std::string java_command;
	char java_install;
	char sure;

	std::cout << "Do you have Java installed? (Y/N)   ";
	std::cin >> java_install;
	std::cout << "sure?(Y/N)   ";
	std::cin >> sure;


	if (sure == 'y' || sure == 'Y' && java_install == 'y' || java_install == 'Y')
	{
		std::system(("mkdir "+server_name).c_str());
		std::system(("curl.exe -o .\\" + server_name + "\\server.jar "+ server_version).c_str());
		std::cout << "Enter RAM amount (in GB or in MB with m at end):   ";
		std::cin >> ram;

		if (ram.back() == 'm' || ram.back() == 'M') {
			ram = ram.substr(0, ram.size() - 1);

			java_command = "java -Xmx" + ram + "M -Xms" + ram + "M -jar server.jar nogui";
			std::system(("echo " + java_command + " > .\\" + server_name + "\\start.bat").c_str());
			std::system(("cd " + server_name + " && " + java_command).c_str());
			std::system(("(echo #By changing the setting below to TRUE you are indicating your agreement to our EULA (https://aka.ms/MinecraftEULA). && echo echo eula=true)>> .\\" + server_name + "\\eula.txt"  ).c_str());
			std::system(("cd " + server_name + " && " + java_command).c_str());
		}
		else
		{
			java_command = "java -Xmx" + ram + "G -Xms" + ram + "G -jar server.jar nogui";
			std::system(("echo " + java_command + " > .\\" + server_name + "\\start.bat").c_str());
			std::system(("cd " + server_name + " && " + java_command).c_str());
			std::system(("(echo eula=true)>> .\\" + server_name + "\\eula.txt").c_str());
			std::system(("cd " + server_name + " && " + java_command).c_str());
		}
	}
	else if (java_install == 'n' || java_install == 'N')
	{
		std::cout << "Opening Java download page..." << std::endl;
		std::system("start https://www.oracle.com/it/java/technologies/downloads/#jdk21-windows");
		std::cout << "After installing Java, please restart the program." << std::endl;
		std::system("pause");
	}
	else
	{
		printf("canceled");
	}
	return 0;
}