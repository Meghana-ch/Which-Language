#include <cctype>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void textToArray(basic_string<char> file, vector <int> &vect){
    ifstream inputFileStream;       // declare the input file stream
    char c = ' ';                   // input character
    string fileName = file;
    inputFileStream.open(fileName.c_str());  //Converts C++ string to expected c style.

    while (inputFileStream >> c){
        if(isalpha(c)){
            c = toupper(c);
            vect [c-'A']++;         //update letter count using character as the index
        }
    }//end while loop
    inputFileStream.close(); //stop taking in characters
}

void print()  // opens the files of different languages and print the freq count of all letters from each file
{
    // initialising vectors for frequency count of each file
    vector <int> english{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> finn{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> french{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> germ{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> hung{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> ital{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> port{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> span{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <char> letters{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W',
                          'X','Y','Z'};
    // opening all the files n incrementing the freq counts
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethEnglish.txt)", english);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethFinnish.txt)", finn);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethFrench.txt)", french);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethGerman.txt)", germ);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethHungarian.txt)", hung);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethItalian.txt)", ital);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethPortuguese.txt)", port);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethSpanish.txt)", span);

    // initialising variables to the start of the vector
    auto i = letters.begin();
    auto j = english.begin();
    auto k = finn.begin();
    auto l = french.begin();
    auto m = germ.begin();
    auto n = hung.begin();
    auto o = ital.begin();
    auto p = port.begin();
    auto q = span.begin();
    cout << setfill(' ');
    // printing the names of all the languages with proper spaces
    cout << "    Engl" << setw(8) << ' ' << "Finn" << setw(8) << ' ' << "Fren" << setw(8) << ' ' << "Germ" <<
         setw(8) << ' ' << "Hung" << setw(8) << ' ' << "Ital" << setw(8) << ' ' << "Port" << setw(8) << ' ' <<
         "Span" << endl;
    // for loop to increment in vectors and print all numbers in vectors
    for(;i != letters.end() and j != english.end() and k != finn.end() and l != french.end() and m != germ.end() and
         n != hung.end() and o != ital.end() and p != port.end() and q != span.end(); i++, j++, k++, l++, m++,
                 n++, o++, p++, q++)
    {

        cout << *i << ": " << setw(7) << setw(5) << *j << setw(7) << "  " << setw(5) << *k << setw(7)
             << "  " << setw(5) << *l << setw(7) << "  " << setw(5) << *m << setw(7) << "  " << setw(5) <<
             *n << setw(7) << "  " << setw(5) << *o << setw(7) << "  " << setw(5) << *p << setw(7) << "  "
             << setw(5) << *q << endl; // print letters and all files count side by side
        // setting the width to maintain gap between both sides of each column
    }
}

// stores the letters in descending order of frequency for a single file
void order(basic_string<char> file, vector <int> &vect1, vector <char> &vect2) {

    ifstream inputFileStream;       // declare the input file stream
    char c = ' ';                   // input character
    string fileName = file;
    inputFileStream.open(fileName.c_str());  //Converts C++ string to expected c style.

    // vect1 stores the frequency of all characters
    while (inputFileStream >> c) {
        if (isalpha(c)) {
            c = toupper(c);
            vect1[c - 'A']++;         //update letter count using character as the index
        }
    }//end while loop
    inputFileStream.close();

    vector<int> temp = vect1;
    int counter = 0;
    int index = 0;
    int max = 0;
    vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W',
                             'X','Y','Z'};
    // keeps checking for the max number which is greater than the previous max number
    while (counter != 26) {
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] > max) {
                max = temp[i];
                index = i;
            }
        }
        vect2.push_back(alphabet[index]);
        counter++;
        temp[index] = 0;
        max = 0;
    }
}

// prints the letters in descending order for each file
void print_order()
{
    // vectors into which the characters are stored in descending order
    vector <char> ENGLISH; vector <char> FINN; vector <char> FRENCH; vector <char> GERM;
    vector <char> HUNG; vector <char> ITAL; vector <char> PORT; vector <char> SPAN;
    // vectors in which the frequency count of each letter from 8 files r stored
    vector <int> english{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> finn{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> french{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> germ{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> hung{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> ital{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> port{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> span{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // function recall to rearrange the letters in descending order
    order(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethEnglish.txt)", english, ENGLISH);
    order(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethFinnish.txt)", finn, FINN);
    order(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethFrench.txt)", french, FRENCH);
    order(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethGerman.txt)", germ, GERM);
    order(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethHungarian.txt)", hung, HUNG);
    order(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethItalian.txt)", ital, ITAL);
    order(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethPortuguese.txt)", port, PORT);
    order(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethSpanish.txt)", span, SPAN);
    // initialsing variables to the start of each vector
    auto i = ENGLISH.begin(); auto j = FINN.begin(); auto k = FRENCH.begin(); auto l = GERM.begin();
    auto m = HUNG.begin(); auto n = ITAL.begin(); auto o = PORT.begin(); auto p = SPAN.begin();
    cout << setfill(' ');
    // printing the language with proper spaces
    cout << "Engl" << setw(8) << ' ' << "Finn" << setw(8) << ' ' << "Fren" << setw(8) << ' ' << "Germ" <<
         setw(8) << ' ' << "Hung" << setw(8) << ' ' << "Ital" << setw(8) << ' ' << "Port" << setw(8) << ' ' <<
         "Span" << endl;
    for(;i != ENGLISH.end() and j != FINN.end() and k != FRENCH.end() and l != GERM.end() and m != HUNG.end() and
         n != ITAL.end() and o != PORT.end() and p != SPAN.end(); i++, j++, k++, l++, m++,
                 n++, o++, p++) // for loop to increment in vectors and print all numbers in vectors
    {
        cout << *i << setw(7) << " " << setw(5) << *j << setw(7) << "  " << setw(5) << *k << setw(7)
             << "  " << setw(5) << *l << setw(7) << "  " << setw(5) << *m << setw(7) << "  " << setw(5) <<
             *n << setw(7) << "  " << setw(5) << *o << setw(7) << "  " << setw(5) << *p << endl; // print letters and all files count side by side
        // setting the width to maintain gap between both sides of each column
    }
}

// function takes in input of a paragraph or sentence from the user and displays the frequency count of each letter
void task3()
{
    string s;
    // taking input from user
    cout << "Copy and paste a paragraph of text to be analyzed, followed by ^z (PC) or ^d (Mac):" << endl;
    cin.ignore();
    getline(cin, s);
    vector <char> v(s.begin(), s.end()); // converting string in to vector
    vector <char> letters = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W',
                             'X','Y','Z'};
    vector <int> count = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(auto i : v)
    {
        if(isalpha(i)) // checking if the character is an alphabet or not
        {
            i = toupper(i);
            for(int j=0; j < letters.size(); j++) // j is the index of letters vector
            {
                if( i == letters[j])
                {
                    count[j]++; // incrementing the frequency in count vector, of each letter found in the input
                }
            }
        }
    }
    auto a = letters.begin(); auto b = count.begin(); // initialising variables to the start of vectors
    cout << "\n";
    for(; a!=letters.end() and b != count.end(); a++, b++)
    {
        cout << *a << ":" << *b << " "; // printing the frequency of each letter based on input given
    }
    cout << "\n";
}

//multiply and sum up elements of array (step 4)
double dotProduct(vector <int> vect_A, vector <int> vect_B) {
    double product = 0;
    double mod_A = 0;
    double mod_B = 0;

    // Loop to calculate dot product, mod of A and B
    for (int i = 0; i < 26; i++)
    {
        product = product + (vect_A[i] * vect_B[i]);
        mod_A += vect_A[i] * vect_A[i];
        mod_B += vect_B[i] * vect_B[i];
    }

    return product/(sqrt(mod_A) * sqrt(mod_B));
}

// takes input from user for a para, displays the frequency count of each letter and displays the language
void task4()
{
    string s;
    vector <int> ENGLISH = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> FINN = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> FRENCH = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> GERM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> HUNG = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> ITAL = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> PORT = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> SPAN = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethEnglish.txt)", ENGLISH);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethFinnish.txt)", FINN);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethFrench.txt)", FRENCH);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethGerman.txt)", GERM);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethHungarian.txt)", HUNG);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethItalian.txt)", ITAL);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethPortuguese.txt)", PORT);
    textToArray(R"(C:\Users\91966\Desktop\meghana\CODING\Clion Projects\which language\MacbethSpanish.txt)", SPAN);
//    for (int then : ENGLISH)
//    {
//        cout << then << " ";
//    }
    // taking input from user
    cout << "Copy and paste a paragraph of text to be analyzed, followed by ^z (PC) or ^d (Mac):" << endl;
    cin.ignore();
    getline(cin, s);
    vector <char> v(s.begin(), s.end()); // converting string in to vector
//    for (char z :v)
//    {
//        cout << z;
//    }
    vector <char> letters = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W',
                             'X','Y','Z'};
    vector <int> count = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(auto i : v)
    {
        if(isalpha(i)) // checking if the character is an alphabet or not
        {
            i = toupper(i);
            for(int j=0; j < letters.size(); j++) // j is the index of letters vector
            {
                if( i == letters[j])
                {
                    count[j]++; // incrementing the frequency in count vector, of each letter found in the input
                }
            }
        }
    }
//    for (int items: count)
//    {
//        cout << items << " ";
//    }
    double a = dotProduct(count, ENGLISH); double b = dotProduct(count, FINN); double c =  dotProduct(count, FRENCH);
    double d = dotProduct(count, GERM); double e = dotProduct(count, HUNG); double f = dotProduct(count, ITAL);
    double g = dotProduct(count, PORT); double h = dotProduct(count, SPAN);
    vector <double> values = {a, b, c, d, e, f, g, h};
    sort(values.begin(), values.end());
    double closest = 0.0;
    if (values[7] < 1)
    {
        if (values[7] == a)
        {
            cout << "Language is English." << endl;
        }
        if (values[7] == b)
        {
            cout << "Language is Finnish." << endl;
        }
        if (values[7] == c)
        {
            cout << "Language is French." << endl;
        }
        if (values[7] == d)
        {
            cout << "Language is German." << endl;
        }
        if (values[7] == e)
        {
            cout << "Language is Hungarian." << endl;
        }
        if (values[7] == f)
        {
            cout << "Language is Italian." << endl;
        }
        if (values[7] == g)
        {
            cout << "Language is Portuguese." << endl;
        }
        if (values[7] == h)
        {
            cout << "Language is Spanish." << endl;
        }
    }
    else if(values[0] > 1)
    {
        if (values[0] == a)
        {
            cout << "Language is English." << endl;
        }
        if (values[0] == b)
        {
            cout << "Language is Finnish." << endl;
        }
        if (values[0] == c)
        {
            cout << "Language is French." << endl;
        }
        if (values[0] == d)
        {
            cout << "Language is German." << endl;
        }
        if (values[0] == e)
        {
            cout << "Language is Hungarian." << endl;
        }
        if (values[0] == f)
        {
            cout << "Language is Italian." << endl;
        }
        if (values[0] == g)
        {
            cout << "Language is Portuguese." << endl;
        }
        if (values[0] == h)
        {
            cout << "Language is Spanish." << endl;
        }
    }
}

int main()
{
    int select;
    char want;
    // initialising vectors for each language file
    vector <int> english{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> finn{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> french{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> germ{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> hung{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> ital{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> port{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> span{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // printing the basic instructions
    cout << "Select from the following stages of output to display:\n"
            "   1. Letter frequency counts\n"
            "   2. Letter frequency order\n"
            "   3. Get user input and display frequency counts\n"
            "   4. Get user input, display frequency counts, and display language\n"
            "   0. Exit the program." << endl;

    // giving option to select any one of the tasks to perform
    cout << "Please choose an option from 1-5:";
    cin >> select;

    switch (select)
    {
        case 1:
            print(); // prints the freq count of each letters from all files
            break;
        case 2:
            print();
            cout << "\n";
            print_order(); // prints the frequency order from each file
            break;
        case 3:
            print();
            cout << "\n";
            print_order();
            cout << "\n";
            task3(); // takes input n displays frequency count of each letter
            break;
        case 4:
            print();
            cout << "\n";
            print_order();
            cout << "\n";
            task4();
            break;
        case 0:
            exit(0); // exits the program
        default:
            cout << "Please enter a number below 6." << endl;
            // if player enters less than 0 or greater than 6, asks the player to choose below 6
            break;
    }
    return 0;
}