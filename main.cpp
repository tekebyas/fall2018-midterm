/*
    Description: This program will take two inputs (a string and a character) and will find how many times the character occurs in the string.
    Filename: main.cpp
    Author: Teke Byas
    Date: Thursday, October 18, 2018
*/
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

bool is_printable(char c);
string get_string(string prompt);
char char_to_find(string prompt);
int char_count(string input, char find);

int main()
{
    cout << "\n--- Case of letter DOES matter ---\n\n" << endl;

    string input = get_string("Please enter a string: ");
    char find = char_to_find("Please enter a character to find in the string: ");

    cout << endl;

    int count = char_count(input,find);

    cout << "There were " << count << " " << find << "'s in your string." << endl;
    cout << endl;

    return 0;
}

/*
    Determines if the character is printable
    @param c the character being checked
    @return true or false
*/
bool is_printable(char c)
{
    return (c >= ' ' && c <= '~');
}

/*
    Gets a string from the user and guarantees it can be printed
    @param prompt what you want to prompt the user
    @return returns what the user entered if it is printable
*/
string get_string(string prompt)
{
    cout << prompt;

    string input;
    getline(cin,input); // getline was used to allow multiple words in the input

    for(int i = 0; i < input.length(); i++)
        if(!is_printable(input.at(i)))
            return " ";

    return input;
}

/*
    Gets a char from the user and guarantees it can be printed
    @param prompt what you want to prompt the user
    @return returns what the user entered if it is printable
*/
char char_to_find(string prompt)
{
    cout << prompt;

    char input;
    cin >> input;

    if(!is_printable(input))
        return ' ';

    return input;
}

/*
    Counts how many times the character to search for was found
    @param input the string to search
    @param find the character to find in the string
    @return how many times the character was found in the string
*/
int char_count(string input, char find)
{
    int count = 0;

    for(int i = 0; i < input.length(); i++)
        if(find == input.at(i))
            count++;

    return count;
}
