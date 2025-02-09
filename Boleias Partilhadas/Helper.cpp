#include "Helper.h"

string readLine()
{
	bool done = false;
	string linha;

	while (!done) {
		cout << "> ";
		getline(cin, linha);
		if (linha != "" || linha != "\n" || linha.size() > 0)
			done = true;
	}
	return linha;
}

string readPassword(const char *prompt, bool show_asterisk)
{
	const char BACKSPACE = 8;
	const char RETURN = 13;

	string password;
	unsigned char ch = 0;

	cout << prompt << endl;
	cout << "> ";

	while ((ch = _getch()) != RETURN)
	{
		if (ch == BACKSPACE)
		{
			if (password.length() != 0)
			{
				if (show_asterisk)
					cout << "\b \b";
				password.resize(password.length() - 1);
			}
		}
		else if (ch == 0 || ch == 224) // handle escape sequences
		{
			_getch(); // ignore non printable chars
			continue;
		}
		else
		{
			password += ch;
			if (show_asterisk)
				cout << '*';
		}
	}
	return password;
}

void getEnter() {

	int ENTER = 13;
	//FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	char ch = _getch();

	while (ch != ENTER)
	{
		ch = _getch();
	}

	//PressKey();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}



void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

//elimina os espa�os inicias de uma string
string ltrim(std::string& s)
{
	s.erase(0, s.find_first_not_of(' '));
	return s;
}

//elimina os espa�os finais de uma string
string rtrim(string& s)
{
	size_t endpos = s.find_last_not_of(" \t");
	if (string::npos != endpos)
	{
		s = s.substr(0, endpos + 1);
	}
	//s.erase(0, s.find_first_of(' ') + 1);
	return s;
}

void loading() {
	cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
	cout << endl << TAB << " ...loading... " << endl;
	Sleep(600);
	ClearScreen();
}
