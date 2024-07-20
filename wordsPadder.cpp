#include <iostream>

const int NUMBER_OF_WORDS = 7;

static const char* logLevelNames[NUMBER_OF_WORDS] = { "None", "Critical", "Error", "Warning", "Debug", "Info", "All" };

static int getMaxLength() {

	int highestLength = 0;
	int length = 0;

	for (int counter = 0; counter < NUMBER_OF_WORDS; counter++) {
		
		const char* x = logLevelNames[counter];
		length = 0;
		
		while ((*x) != '\0') {
			x++; // turn this to pointer  add 1 -- loop till /0
			length++;
		}

		if (highestLength < length) { highestLength = length; }
	}

	return highestLength;
}

static void writeWordsWithPaddingToArray(int maxWordLength, int wordBorderSize, char* array) {

	for (int counter = 0; counter < NUMBER_OF_WORDS; counter++) {

		// Gets current words length

		const char* wordPtr = logLevelNames[counter];
		int length = 0;

		while ((*wordPtr) != '\0') {
			wordPtr++;
			length++;
		}

		// Turns the first char of the new word to [

		char* currentCounter = array + counter * (maxWordLength + wordBorderSize + 1);

		*(currentCounter) = '[';
		
		// adds a set amount of spaces

		int buffersize = ((maxWordLength - length) - (maxWordLength - length) % 2) / 2;

		for (int increment = 0; increment < buffersize; increment++) {
			currentCounter++;
			*(currentCounter) = ' ';
		}

		wordPtr = logLevelNames[counter];

		while ((*wordPtr) != '\0') {
			currentCounter++;
			*(currentCounter) = *(wordPtr);
			wordPtr++;
		}

		buffersize = ((maxWordLength - length) + (maxWordLength - length) % 2) / 2;

		for (int increment = 0; increment < buffersize; increment++) {
			currentCounter++;
			*(currentCounter) = ' ';
		}

		currentCounter++;
		(*currentCounter) = ']';

		currentCounter++;
		(*currentCounter) = '\0';

	}
}

int main() {

	int longestWord = getMaxLength();

	int wordsBorderSize = 2; // +2 for [] on the edges.

	char* paddedWords = new char[(longestWord + wordsBorderSize + 1) * NUMBER_OF_WORDS];

	writeWordsWithPaddingToArray(longestWord, wordsBorderSize, paddedWords);

	for (int counter = 0; counter < NUMBER_OF_WORDS; counter++) {
		auto word = (paddedWords + (longestWord + wordsBorderSize + 1)*counter);
		std::cout << word << std::endl;
		//std::cout << "\"" << (word) << "\",";
	}

	delete [] paddedWords;
}
