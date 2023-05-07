#include "errorCode.h"
#include "omikuji.h"
#include <iostream>

int main(int argc, char **argv) {
	omikuji::OmikujiItf* b = omikuji::OmikujiItf::CreateBox();

	// virtual Error DrawStatus(char** status) = 0;
	std::cout << "virtual Error DrawStatus(char** status) = 0;" << std::endl;
	
	char* status;
	omikuji::Error result1 = b->DrawStatus(&status);
	if (result1 != omikuji::Error::NONE) {
		std::cout << int(result1) << std::endl;
	} else {
		std::cout << status << std::endl;
	}

	// virtual Error Draw(Paper *paper) = 0;
	std::cout << "virtual Error DrawPaper(Paper *paper) = 0;" << std::endl;

	omikuji::Paper paper;
	omikuji::Error result2 = b->DrawPaper(&paper);
	if (result2 != omikuji::Error::NONE) {
		std::cout << int(result2) << std::endl;
	} else {
		std::cout << paper.status << std::endl;
		std::cout << paper.description << std::endl;
	}

    return 0;
}