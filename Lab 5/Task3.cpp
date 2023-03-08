#include <iostream>
using namespace std;

class Quotation{
	char** quote;
	int numOfQuotations;
	char** author;
	int capacity;
public:
	Quotation(int size = 10) {
		quote = new char *[size];
		author = new char* [size];
		capacity = size;
		numOfQuotations = 0;
	}
	void addQuotation(char* newquote, char * newauthor ) {
		int newquoteSize = strlen(newquote) +1;
		int newauthorSize = strlen(newauthor) +1;
		quote[numOfQuotations] = new char[newquoteSize];
		for (int i = 0; i < newquoteSize; i++) {
			quote[numOfQuotations][i] = newquote[i];
		}
		
		author[numOfQuotations] = new char[newauthorSize];
		for (int i = 0; i < newauthorSize; i++) {
			author[numOfQuotations][i] = newauthor[i];
		}
		
		numOfQuotations++;
		if (numOfQuotations >= capacity) {
			char** temp = new char* [capacity * 2];
			char** temp2 = new char* [capacity * 2];
			for (int i = 0; i < capacity; i++){
				temp[i] = quote[i];
				temp2[i] = author[i];

			}
			delete[] quote;
			delete[] author;
			quote = temp;
			author = temp2;
			temp = nullptr;
			temp2 = nullptr;
			

		}
	}
	void displayAuthorWise( char* name) {
		int namesize = strlen(name);
		int match = 0;
		for (int i = 0; i < numOfQuotations; i++) {
			for (int j = 0; name[j] != '\0'; j++) {
				if (author[i][j] == name[j]) {
					match++;
				}
			}
			if (match == namesize) {
				cout << i << " ";
		
				for (int k = 0; k < quote[i][k] != '\0'; k++) {
					cout << quote[i][k];
				}
				cout << endl;
			}
			match = 0;
		}
	
		
	}

	void displayQuotation(char* string) {
		int stringsize = strlen(string);
		int match = 0;
		int x = 0;
		for (int i = 0; i < numOfQuotations; i++) {
			match = 0;
			for (int j = 0; quote[i][j] != '\0'; j++) {
				if (quote[i][j] == string[x]) {
					match++;
					x++;
				}
				else {
					
					x = 0;
					
				}
				
			}
			if (match == stringsize) {
				cout << i << " ";
				
				
				for (int k = 0; k < quote[i][k] != '\0'; k++) {
					cout << quote[i][k];
				}
				cout << endl;
			}
			
		}
	}
	void removeQuotation(char * s) {
		displayQuotation(s);
		cout << "Choose the string number you want to remove " << endl;
		int i;
		cin >> i;
		for (int j = i; j < numOfQuotations-1; j++) {
			quote[j] = quote[j + 1];
		}
		quote[numOfQuotations-1] = nullptr;
		numOfQuotations--;
	}
	~Quotation() {
		for (int i = 0; i < numOfQuotations; i++) {
			delete[] quote[i];
		}
		for (int i = 0; i < numOfQuotations; i++) {
			delete[] author[i];
		}
		delete[] quote;
		delete[] author;
	}
	Quotation(const Quotation& obj) {
		capacity = obj.capacity;
		numOfQuotations = 0;
		quote = new char* [capacity];
		author = new char * [capacity];

		for (int i = 0; i < numOfQuotations; i++) {
			for (int j = 0; quote[i][j] != '\0'; j++) {
				 quote[i][j] = obj.quote[i][j] ;
			}
		}
		for (int i = 0; i < numOfQuotations; i++) {
			for (int j = 0; author[i][j] != '\0'; j++) {
				 author[i][j] = obj.author[i][j] ;
			}
		}
	}
};

int main() {
	Quotation book(100);
	char quote1[] = { "Smart Work Over Hard Work" };
	char author1[] = {"Taaha"};
	char quote2[] = { "My name is Taaha" };
	char author2[] = { "Taaha" };
	book.addQuotation(quote1,author1);
	book.addQuotation(quote2,author2);
	cout << "Displaying Author Wise Quotes " << endl;
	book.displayAuthorWise(author1);
	cout << endl << "Displaying all quotes with the Word Smart in it " << endl;
	char quote3[] = { "Over" };
	book.displayQuotation(quote3);
	cout << endl << "Menu for removing quote " << endl;
	book.removeQuotation(quote3);

	cout << endl << "Author wise display after removal " << endl;
	book.displayAuthorWise(author1);
}