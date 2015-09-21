#include <iostream>
#include <string>
#include "abnerprint.h"

using namespace std;

int main(int argc, char** argv) {
	string msg;
	cout << "Digite a mensagem a ser tunada: ";
	getline(cin, msg);
	abner_print(msg, 10, 25);
	system("pause");
	return 0;
}
