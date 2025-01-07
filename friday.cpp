#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For getch() and hiding password on Windows
#include <cctype>  // For checking character types
#include <vector>
#include <sstream>     // For parsing data from strings
#include <numeric>     // For std::accumulate (to calculate average)
#include <chrono>      // For time tracking
#include <iomanip>     // For formatting output (optional)
#include <cstdlib>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
#include <thread>
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;

// ANSI color codes for better visuals
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"

// Function prototypes
void signUp();
void forgottenPassword();
void login();

void logout();
void updateProfile(const string &username);
string hidePassword();

bool isValidPassword(const string &password);
void displayHeader(const string &title);
bool isEmailExists(const string &email);

void manageContent(const string & classInfo);
void assessment(const string &username, const string &classInput);
void saveMarks(const string& username, const vector<string>& subjects,
               const vector<vector<string>>& chaptersList, int subjectChoice,
               int chapterChoice, int marks);


void viewPerformance(const string& username);
void searchPerformance();
void displayPerformanceSummaryForUser(const string &username, const vector<int>& scores);

void performanceBoard();
void performanceMenu(const string& username);
void sortPerformances(vector<pair<string, double>>& studentScores);

// Graph-related functions
unordered_map<string, vector<pair<string, int>>> adjList;
void addEdge(const string &u, const string &v, int weight);
void loadFromFile(const string &filename, const string &subject);

void displayTreeRepresentation(const vector<string> &roadmap, const string &title);
int getClassChoice();
int getSubjectChoice();

string getFilename(int choice);
void handleRoadmapGeneration(int choice);
void collectfeedbackmain();

int displayMainMenu();
void collectRatings(unordered_map<string, int> &ratings, const vector<string> &categories);
void collectDetailedFeedback(string &feedback);

void collectUserDetails(string &username);
void recordFeedback(const string &username, const unordered_map<string, int> &ratings, const string &suggestions);
void displaySummary(const string &username, const unordered_map<string, int> &ratings, const string &suggestions);

void viewFeedbackHistory();
void clearFeedbackByUsername();
void collectFeedback();

void adminMenu();
void viewAllUsers();
void updateUserProfile();

void deleteUserProfile();
void viewFeedbackHistory();
void clearFeedbackHistory();

void viewPerformanceData();
void updatePerformanceData();
void displayUserScores();

void saveUserProfile(const string &username, const string &name, const string &email, const string &classInfo, const string &password);
bool isEmailExists(const string &email);

void loadUserProfiles(vector<string> &userProfiles);
void loadFeedbackHistory(vector<string> &feedbackHistory);
void loadPerformanceData(vector<string> &performanceData);

void saveFeedbackHistory(const vector<string> &feedbackHistory);
void savePerformanceData(const vector<string> &performanceData);
void displayHeader(const string &title);

void collectUserDetails(string &username, string &name, string &email, string &classInfo, string &password);
void collectFeedbackDetails(string &username, unordered_map<string, int> &ratings, string &suggestions);
void displayFeedbackSummary(const string &username, const unordered_map<string, int> &ratings, const string &suggestions);

void displayPerformanceSummary(const string &username, const vector<int> &scores);
void sortPerformanceData(vector<pair<string, double>> &studentScores);
void displayPerformanceBoard(const vector<pair<string, double>> &studentScores);

void updateUserProfileInFile(const string &username, const string &newName, const string &newEmail, const string &newClass, const string &newPassword);
bool deleteUserProfileFromFile(const string &username);
void updateFeedbackInFile(const string &username, const unordered_map<string, int> &ratings, const string &suggestions);

void clearFeedbackByUsername(const string &username);
void viewUserPerformance(const string &username);
void viewAllFeedback();

void viewUserFeedback(const string &username);
void updateUserPassword(const string &username, const string &newPassword);
void displayUserProfile(const string &username);

void displayAllUserProfiles();
void displayFeedbackHistoryForUser (const string &username);
void displayPerformanceDataForUser (const string &username);

void displayAllPerformanceData();
void saveAllUserProfiles(const vector<string> &userProfiles);
void saveAllFeedback(const vector<string> &feedbackHistory);

void saveAllPerformanceData(const vector<string> &performanceData);
void loadAllUserProfiles(vector<string> &userProfiles);
void loadAllFeedback(vector<string> &feedbackHistory);

void loadAllPerformanceData(vector<string> &performanceData);
void collectUserDetailsForUpdate(string &username, string &newName, string &newEmail, string &newClass, string &newPassword);
void collectFeedbackDetailsForUpdate(string &username, unordered_map<string, int> &ratings, string &suggestions);

void displayFeedbackSummaryForUser (const string &username, const unordered_map<string, int> &ratings, const string &suggestions);
void sortPerformanceDataForUser (vector<pair<string, double>> &studentScores);
void displayPerformanceBoardForUser (const vector<pair<string, double>> &studentScores);

void updateUserProfileInFileForAdmin(const string &username, const string &newName, const string &newEmail, const string &newClass, const string &newPassword);
void deleteUserProfileFromFileForAdmin(const string &username);
void updateFeedbackInFileForAdmin(const string &username, const unordered_map<string, int> &ratings, const string &suggestions);

void clearFeedbackByUsernameForAdmin(const string &username);
void viewUserPerformanceForAdmin(const string &username);
void viewAllFeedbackForAdmin();

void viewUserFeedbackForAdmin(const string &username);
void updateUserPasswordForAdmin(const string &username, const string &newPassword);
void displayUserProfileForAdmin(const string &username);

void displayAllUserProfilesForAdmin();
void displayFeedbackHistoryForUserForAdmin(const string &username);
 void displayPerformanceSummaryForUserA(const string &username, const vector<int>& scores);

void displayPerformanceDataForUserForAdmin(const string &username);
void displayAllPerformanceDataForAdmin();
void saveAllUserProfilesForAdmin(const vector<string> &userProfiles);

void saveAllFeedbackForAdmin(const vector<string> &feedbackHistory);
void saveAllPerformanceDataForAdmin(const vector<string> &performanceData);
void loadAllUserProfilesForAdmin(vector<string> &userProfiles);

void loadAllFeedbackForAdmin(vector<string> &feedbackHistory);
void loadAllPerformanceDataForAdmin(vector<string> &performanceData);
void viewFeedbackHistory1();

bool isEmailExists1(const string &email);
void displayPerformanceSummaryForUser(const std::string &username, const std::vector<int> &scores);

int main()
{
    int choice;
    do
        {
       displayHeader("Welcome to the Profile Management System");
    cout << CYAN << "1. Sign Up" << RESET << endl;
    cout << "   Create a new account to access the system.\n" << endl;

    cout << CYAN << "2. Login" << RESET << endl;
    cout << "   Access your existing account.\n" << endl;

    cout << CYAN << "3. Exit" << RESET << endl;
    cout << "   Exit the application.\n" << endl;

    cout << YELLOW << "Enter your choice: " << RESET;
    cin >> choice;


    // Handle user choice
    switch (choice)
    {

        case 1:
            cout <<YELLOW<< "You chose to Sign Up." << RESET<< endl;
             signUp();
            // Add sign-up logic here

            break;

        case 2:
            cout << YELLOW<< "You chose to Login." << RESET<< endl;
            login();
            // Add login logic here

            break;

        case 3:
            cout << YELLOW<< "Exiting the application. Goodbye!"<< RESET << endl;
            break;

        default:
            cout << YELLOW<< "Invalid choice. Please try again."<< RESET << endl;
            break;
    }

    } while (choice != 3);

    return 0;
}

void displayHeader(const string &title)
{
    system("cls"); // Clears the screen (Windows-specific, use clear for Linux/Mac)
    cout << MAGENTA << "========================================================================================================" << RESET << endl;
    cout << GREEN << "                                     " << title << RESET << endl;
    cout << MAGENTA << "========================================================================================================" << RESET << endl;
}

void signUp()
{
    string username, name, email, classInfo, password;

    displayHeader("Sign Up Page");
    cout << YELLOW << "Please enter your details to sign up:" << RESET << endl;
    cout << YELLOW << "Username    : " << RESET;
    cin.ignore();
    getline(cin, username);

    cout << YELLOW << "Name        : " << RESET;
    getline(cin, name);

    cout << YELLOW << "Email       : " << RESET;
    getline(cin, email);

    if (isEmailExists(email))
        {
        cout << RED << "Email already exists! Please try logging in or use a different email." << RESET << endl;

        return;
    }

    cout << YELLOW << "Class       : " << RESET;
    getline(cin, classInfo);

    cout << YELLOW << "Password    : " << RESET;
    password = hidePassword();

    // Validate password
    while (!isValidPassword(password))
        {
        cout << RED << "\nPassword must be 8 characters long and include digits, letters, and special characters." << RESET << endl;
        cout << YELLOW << "Please enter a valid password: " << RESET;
        password = hidePassword();
    }

    ofstream file("user_profile.txt", ios::app);
    if (file.is_open())
        {
        file << username << "," << name << "," << email << "," << classInfo << "," << password << endl;
        file.close();
        cout << GREEN << "\nSign up successful! Redirecting to main menu..." << RESET << endl;
    }
    else
        {

        cout << RED << "Error saving user data!" << RESET << endl;
    }

    cout << YELLOW << "Press any key to return to the main menu..." << RESET;

    _getch();
}


// string generateOTP()
//  {
//     srand(time(0)); // Seed the random number generator
//     int otp = rand() % 9000 + 1000; // Generate a random 4-digit number
//     return to_string(otp);
// }

// // Function to trim leading and trailing spaces
// string trim(const string &str)
//  {
//     size_t first = str.find_first_not_of(" \t\n\r");
//     size_t last = str.find_last_not_of(" \t\n\r");
//     return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
// }


// Function to mask password input
string getMaskedInput() {
    string password;
    char ch;
#ifdef _WIN32
    while ((ch = _getch()) != '\r') { // Windows: Enter key is '\r'
        if (ch == '\b') { // Handle backspace
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            cout << '*';
            password += ch;
        }
    }
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    newt.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while ((ch = getchar()) != '\n') { // Unix/Linux: Enter key is '\n'
        if (ch == 127 || ch == '\b') { // Handle backspace
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            cout << '*';
            password += ch;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
    cout << endl;
    return password;
}

// Mock generateOTP function
string generateOTP() {
    srand(time(0));
    return to_string(1000 + rand() % 9000); // Generate a 4-digit OTP
}

// Mock trim function
string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

void forgottenPassword() {
    string email, inputEmail, inputOTP, newPassword, line;
    bool emailFound = false;
    string storedEmail, storedPassword;

    cout << "Forgotten Password" << endl;
    cout << "Please enter your registered email address: ";
    cin >> inputEmail;

    // Trim spaces from the input email
    inputEmail = trim(inputEmail);

    // Open the user profile file to search for the email
    ifstream file("user_profile.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string username, name, email, classInfo, password;

            // Assume the format: username,name,email,phone,classname,password
            getline(ss, username, ',');
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, classInfo, ',');
            getline(ss, password, ',');

            // Trim spaces from the stored email
            storedEmail = trim(email);

            if (storedEmail == inputEmail) {
                emailFound = true;
                storedPassword = password;
                break;
            }
        }
        file.close();
    }

    if (!emailFound) {
        cout << "Email not found. Please check your email and try again." << endl;
        return;
    }

    // Generate OTP and display it (simulating OTP sent to phone)
    string otp = generateOTP();
    cout << "An OTP has been sent to your registered contact: " << otp << endl;

    // Ask the user for the OTP
    cout << "Enter the OTP to proceed: ";
    cin >> inputOTP;

    if (inputOTP == otp) {
        // OTP is correct, now allow the user to change the password
        cout << "Enter your new password: ";
        newPassword = getMaskedInput();

        // Update the password in the file (simplified approach)
        ifstream readFile("user_profile.txt");
        string updatedData = "";
        while (getline(readFile, line)) {
            stringstream ss(line);
            string username, name, email, classInfo, password;

            // Assume the format: username,name,email,phone,classname,password
            getline(ss, username, ',');
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, classInfo, ',');
            getline(ss, password, ',');

            if (email == inputEmail) {
                // Update password
                password = newPassword;
            }

            // Rebuild the data string for saving
            updatedData += username + "," + name + "," + email + "," + classInfo + "," + password + "\n";
        }
        readFile.close();

        // Write updated data back to the file
        ofstream writeFile("user_profile.txt");
        writeFile << updatedData;
        writeFile.close();

        cout << "Your password has been updated successfully!" << endl;
    } else {
        cout << "Invalid OTP. Please try again." << endl;
    }
}


// Function to get the current time as a string
string getCurrentTime()
{
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    return ctime(&now_time); // returns string representation of time
}

// Function to calculate duration in seconds
long long calculateDuration(chrono::system_clock::time_point start, chrono::system_clock::time_point end)
{
    return chrono::duration_cast<chrono::seconds>(end - start).count();
}

void logSessionTime(const string& username, long long duration)
 {
    ofstream sessionFile("session_log.txt", ios::app); // Open in append mode
    if (sessionFile.is_open()) {
        sessionFile << "Username: " << username << ", Time Spent: " << duration << " seconds\n";
        sessionFile.close();
    }
    else
        {
        cout << RED << "Error: Unable to log session time!" << RESET << endl;
    }
}

void login()
{
    string adminkey = "132020";
    string keyintake;
    string username, name, email, classInfo, password, line;
    string inputEmail, inputPassword;

    // Start session timer
    auto sessionStart = chrono::system_clock::now();

    displayHeader("Login Page");

    bool isValidEmail = false;
    bool isValidPassword = false;

    while (!isValidEmail || !isValidPassword)
        {
        cout << YELLOW << "Please enter your login credentials:" << RESET << endl;
        cout << YELLOW << "Email       : " << RESET;

        cin.ignore();
        getline(cin, inputEmail);

        cout << YELLOW << "Password    : " << RESET;
        inputPassword = hidePassword();

        isValidEmail = !inputEmail.empty();
        isValidPassword = !inputPassword.empty();

        if (!isValidEmail)
            {
            cout << RED << "Error: Email cannot be empty. Please re-enter the email." << RESET << endl;
        }
        if (!isValidPassword)
        {
            cout << RED << "Error: Password cannot be empty. Please re-enter the password." << RESET << endl;
        }
    }

    ifstream file("user_profile.txt");
    if (file.is_open())
        {
        bool isLoggedIn = false;
        while (getline(file, line))
        {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            size_t pos4 = line.find(',', pos3 + 1);

            username = line.substr(0, pos1);
            name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            email = line.substr(pos2 + 1, pos3 - pos2 - 1);
            classInfo = line.substr(pos3 + 1, pos4 - pos3 - 1);
            password = line.substr(pos4 + 1);

            if (email == inputEmail && password == inputPassword)
                {
                displayHeader("Welcome!");
                cout << GREEN << "Hello, " << name << "! You have successfully logged in." << RESET << endl;
                cout << "Class: " << classInfo << endl;
                isLoggedIn = true;

                // Declare variables outside the switch
                chrono::system_clock::time_point sessionEnd;
                long long duration = 0;

                start:
                cout << CYAN << "\nWelcome to the User Menu! Please choose an option:\n" << RESET << endl;
                cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

                cout << CYAN << "[1] Update Profile" << RESET << endl;
                cout << "  - Keep your personal information up to date.\n" << endl;

                cout << CYAN << "[2] Logout" << RESET << endl;
                cout << "  - Exit your account securely.\n" << endl;

                cout << CYAN << "[3] Content" << RESET << endl;
                cout << "  - Discover a variety of resources and materials.\n" << endl;

                cout << CYAN << "[4] Assessment" << RESET << endl;
                cout << "  - Test your knowledge with quizzes and assessments.\n" << endl;

                cout << CYAN << "[5] Feedback" << RESET << endl;
                cout << "  - Share your thoughts and help us improve!\n" << endl;

                cout << CYAN << "[6] Performance" << RESET << endl;
                cout << "  - Review your progress and performance metrics.\n" << endl;

                cout << CYAN << "[7] Admin" << RESET << endl;
                cout << "  - Access administrative features (admin only).\n" << endl;

                cout << CYAN << "[8] Roadmap" << RESET << endl;
                cout << "  - Check out what's coming next for our platform.\n" << endl;

                cout << CYAN << "[9] Exit" << RESET << endl;
                cout << "  - Close the application.\n" << endl;

                cout << CYAN << "---------------------------------------------------------------------------------------" << RESET << endl;

                //cout << CYAN << "Please enter your choice : " << RESET;

                int choice;
                cout << YELLOW << "Enter your choice: " << RESET;
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        updateProfile(username);
                        goto start;
                        break;

                    case 2:
                    sessionEnd = chrono::system_clock::now();
                        duration = calculateDuration(sessionStart, sessionEnd);
                        logSessionTime(username, duration);
                        logout();
                        break;

                    case 3:
                        manageContent(classInfo);
                        goto start;
                        break;

                    case 4:
                        assessment(username, classInfo);
                        goto start;
                        break;

                    case 5:
                        collectfeedbackmain();
                        goto start;
                        break;

                    case 6:
                        performanceMenu(username);
                        goto start;
                        break;

                    case 7:
                        cout << GREEN << "Enter the admin password or admin key: " << RESET;
                        cin >> keyintake;
                        if (adminkey == keyintake)
                            {
                            adminMenu();
                        }
                        else

                         {
                            cout << RED << "Invalid admin key!" << RESET << endl;
                            cout << "Press any key to continue..." << endl;
                            _getch();
                            system("cls");
                            displayHeader("Welcome again!");
                        }
                        goto start;
                        break;

                    case 8:
                        handleRoadmapGeneration(getClassChoice());
                        goto start;
                        break;

                    case 9:
                        sessionEnd = chrono::system_clock::now();
                        duration = calculateDuration(sessionStart, sessionEnd);
                        logSessionTime(username, duration);
                        cout << GREEN << "Exiting... Goodbye!" << RESET << endl;
                        exit(0);
                        break;
                    default:
                        cout << RED << "Invalid choice. Please try again." << RESET << endl;
                        goto start;
                }
            }
        }

        if (!isLoggedIn)
            {
            cout << RED << "\nInvalid email or password. Please try again." << RESET << endl;
             char pass;
            cout<<"enter 1 if you want to change the password"<<endl;
            cin>>pass;
            if(pass=='1'){
            forgottenPassword();
            }
        }
        file.close();
    }
    else
        {
        cout << RED << "Error reading user data!" << RESET << endl;
    }

    cout << YELLOW << "Press any key to return to the main menu..." << RESET;
    _getch();
}

void logout()
{
    cout << CYAN << "\nYou have been logged out. Redirecting to the main menu..." << RESET << endl;
    cout << YELLOW << "Press any key to continue..." << RESET;

    _getch();
}

string hidePassword()
{
    string password;
    char ch;
    while ((ch = _getch()) != '\r')
        { // '\r' is the Enter key
        if (ch == '\b')
        { // Backspace
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b"; // Erase the last * on screen
            }
        }
    else
        {
            password.push_back(ch);
            cout << "*";
        }
    }
    cout << endl;

    return password;
}

// Validate the password according to the specified rules
bool isValidPassword(const string &password)
{
    if (password.length() != 8) return false; // Check length
    bool hasLetter = false, hasDigit = false, hasSpecialChar = false;

    for (char ch : password)
        {
        if (isalpha(ch)) hasLetter = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (ispunct(ch)) hasSpecialChar = true;
    }

    return hasLetter && hasDigit && hasSpecialChar; // All conditions must be true
}

bool isEmailExists(const string &email)
{
    ifstream file("user_profile.txt");
    string line;
    while (getline(file, line))
        {
        size_t pos2 = line.find(',');
        size_t pos3 = line.find(',', pos2 + 1);
        string existingEmail = line.substr(pos2 + 1, pos3 - pos2 - 1);
        if (existingEmail == email)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void updateProfile(const string &username)
{
    string newName, newEmail, newClass, newPassword, line;
    string updatedData = "";
    bool updated = false;

    displayHeader("Update Profile");

    cout << YELLOW << "Enter new Name (leave blank to keep unchanged): " << RESET << endl;
    //cout << "  - Please provide your full name. If you do not wish to change it, simply press Enter." << endl;
    cin.ignore();
    getline(cin, newName);

    cout << YELLOW << "Enter new Email (leave blank to keep unchanged): " << RESET << endl;
    //cout << "  - Enter your new email address. If you want to keep your current email, just press Enter." << endl;
    getline(cin, newEmail);

    cout << YELLOW << "Enter new Class (leave blank to keep unchanged): " << RESET << endl;
    //cout << "  - Specify your new class or course. If you prefer to keep your current class, press Enter." << endl;
    getline(cin, newClass);

    cout << YELLOW << "Enter new Password (leave blank to keep unchanged): " << RESET << endl;
    //cout << "  - Type your new password. If you do not want to change it, simply press Enter." << endl;
    newPassword = hidePassword();

    ifstream file("user_profile.txt");
    if (file.is_open())
        {
        while (getline(file, line))
            {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            size_t pos4 = line.find(',', pos3 + 1);

            string oldUsername = line.substr(0, pos1);
            string oldName = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string oldEmail = line.substr(pos2 + 1, pos3 - pos2 - 1);
            string oldClass = line.substr(pos3 + 1, pos4 - pos3 - 1);
            string oldPassword = line.substr(pos4 + 1);

            // Update fields if new data is provided
            if (username == oldUsername)
                {
                updated = true;
                if (!newName.empty()) oldName = newName;
                if (!newEmail.empty()) oldEmail = newEmail;
                if (!newClass.empty()) oldClass = newClass;
                if (!newPassword.empty()) oldPassword = newPassword;
            }

            updatedData += oldUsername + "," + oldName + "," + oldEmail + "," + oldClass + "," + oldPassword + "\n";
        }

        file.close();

        if (updated)
            {
            ofstream outFile("user_profile.txt");
            outFile << updatedData;
            outFile.close();
            cout << GREEN << "\nProfile updated successfully!" << RESET << endl;
        }
        else
            {
            cout << RED << "Error: Username not found!" << RESET << endl;
        }
    }
    else
        {
        cout << RED << "Error reading user data!" << RESET << endl;
    }

    cout << YELLOW << "Press any key to return to the main menu..." << RESET;

    _getch();
}


// Function to display chapters and resources


void manageContent(const string& classInput)
{
    string fileName = "Class" + classInput + ".txt";
    ifstream file(fileName);
    if (!file.is_open())
        {
        cout << RED << "Failed to open file: " << fileName << RESET << endl;

        return;
    }

    string line, currentSubject;
    vector<string> subjects;
    vector<vector<string>> chaptersList;
    vector<vector<string>> websitesList;
    vector<vector<string>> videosList;
    vector<vector<string>> oneShortsList;

    bool subjectFound = false;

    while (getline(file, line))
        {
        // Remove whitespace from start and end of the line
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        // Collect subjects
        if (line.rfind("Subject:", 0) == 0)
            {
            currentSubject = line.substr(8); // Extract subject
            currentSubject.erase(0, currentSubject.find_first_not_of(" \t"));
            subjects.push_back(currentSubject);

            // Initialize subject-related data
            chaptersList.emplace_back();
            websitesList.emplace_back();
            videosList.emplace_back();
            oneShortsList.emplace_back();

            subjectFound = true;
        }

        // Collect chapters and resources under each subject
        if (subjectFound && line.rfind("Chapter", 0) == 0)
            {
            chaptersList.back().push_back(line); // Add chapter name

            if (getline(file, line)) websitesList.back().push_back(line.substr(9)); // Website
            if (getline(file, line)) videosList.back().push_back(line.substr(7));   // Video
            if (getline(file, line)) oneShortsList.back().push_back(line.substr(9)); // One Short
        }
    }

    if (subjects.empty())
        {
        cout << RED << "No subjects found for Class " << classInput << RESET << endl;

        return;
    }

    // Display Subject Choices
    int subjectChoice;
    cout << CYAN << "\nSelect Subject:\n" << RESET;
    for (size_t i = 0; i < subjects.size(); i++)
        {
        cout << "[" << i + 1 << "] " << subjects[i] << endl;
    }

    cout << YELLOW << "\nEnter your choice: " << RESET;
    cin >> subjectChoice;

    if (subjectChoice < 1 || subjectChoice > subjects.size())
        {
        cout << RED << "Invalid subject choice!" << RESET << endl;

        return;
    }

    // Display Chapter Choices
    int chapterChoice;
    cout << CYAN << "\nSelect Chapter:\n" << RESET;
    for (size_t i = 0; i < chaptersList[subjectChoice - 1].size(); i++)
        {
        cout << "[" << i + 1 << "] " << chaptersList[subjectChoice - 1][i] << endl;
    }

    cout << YELLOW << "\nEnter your choice: " << RESET;
    cin >> chapterChoice;

    if (chapterChoice < 1 || chapterChoice > chaptersList[subjectChoice - 1].size())
        {
        cout << RED << "Invalid chapter choice!" << RESET << endl;
        return;
    }

    // Display Resource Choices
    int resourceChoice;
   cout << CYAN << "\nSelect Resource:\n" << RESET;
   cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

   cout << "[1] Website" << endl;
   cout << "  - Access a comprehensive online resource with articles, tutorials, and interactive content.\n" << endl;

   cout << "[2] Video" << endl;
   cout << "  - Watch a full-length video that covers the topic in detail, providing visual and auditory learning.\n" << endl;

   cout << "[3] One Short Video" << endl;
   cout << "  - View a brief video that summarizes key points quickly, perfect for a quick overview.\n" << endl;

   cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
   //cout << "Please enter your choice (1-3): ";

    cout << YELLOW << "\nEnter your choice: " << RESET;
    cin >> resourceChoice;

    string url;
    switch (resourceChoice)
    {
        case 1:
            url = websitesList[subjectChoice - 1][chapterChoice - 1];
            break;

        case 2:
            url = videosList[subjectChoice - 1][chapterChoice - 1];
            break;

        case 3:
            url = oneShortsList[subjectChoice - 1][chapterChoice - 1];
            break;

        default:
            cout << RED << "Invalid resource choice!" << RESET << endl;
            return;
    }

    cout << GREEN << "\nOpening Link: " << url << RESET << endl;
#ifdef _WIN32
    system(("start " + url).c_str()); // Windows
#else
    system(("xdg-open " + url).c_str()); // Linux
#endif

    file.close();
     cout << YELLOW << "Press any key to continue" << RESET;
    _getch();
    system("cls");
    displayHeader("Welcome again!");

}

void assessment(const string &username, const string &classInput)
{
    int option;
    do
        {
         startagain:
        displayHeader("Assessment Menu");

        cout << CYAN << "\nQuiz Menu:\n" << RESET;
        cout << "---------------------------------------------------------------------------------" << endl;

        cout << CYAN << "[1] Take Quiz" << RESET << endl;
        cout << "  - Start a new quiz to test your knowledge on the subject.\n" << endl;

        cout << CYAN << "[2] View Scores" << RESET << endl;
        cout << "  - Check your previous quiz scores and performance metrics.\n" << endl;

        cout << CYAN << "[3] Return to Main Menu" << RESET << endl;
        cout << "  - Go back to the main menu to explore other options.\n" << endl;

        cout << "---------------------------------------------------------------------------------" << endl;

        cout << YELLOW << "Enter your choice: " << RESET;
        cin >> option;

        switch (option)
        {
            case 1:
                 {
                // Open the file for the class
                string fileName = "Class" + classInput + ".txt";
                ifstream file(fileName);

                if (!file.is_open())
                    {
                    cout << RED << "Failed to open file for Class " << classInput << RESET << endl;
                    break;
                }

                string line, currentSubject;
                vector<string> subjects;
                vector<vector<string>> chaptersList;
                vector<vector<string>> quizURLs;

                bool subjectFound = false;

                while (getline(file, line))
                    {
                    line.erase(0, line.find_first_not_of(" \t"));
                    line.erase(line.find_last_not_of(" \t") + 1);

                    if (line.rfind("Subject:", 0) == 0)
                        {
                        currentSubject = line.substr(8);
                        currentSubject.erase(0, currentSubject.find_first_not_of(" \t"));
                        subjects.push_back(currentSubject);

                        // Initialize data for this subject
                        chaptersList.emplace_back();
                        quizURLs.emplace_back();
                        subjectFound = true;
                    }

                    if (subjectFound && line.rfind("Chapter", 0) == 0)
                        {
                        chaptersList.back().push_back(line); // Add chapter
                        if (getline(file, line)) quizURLs.back().push_back(line.substr(9)); // Add Quiz URL
                    }
                }

                if (subjects.empty())
                    {
                    cout << RED << "No subjects found for Class " << classInput << RESET << endl;
                    break;
                }

                // Subject Selection
                int subjectChoice;
                cout << CYAN << "\nSelect Subject:\n" << RESET;
                for (size_t i = 0; i < subjects.size(); i++)
                    {
                    cout << "[" << i + 1 << "] " << subjects[i] << endl;
                }

                cout << YELLOW << "\nEnter your choice: " << RESET;
                cin >> subjectChoice;

                if (subjectChoice < 1 || subjectChoice > subjects.size())
                    {
                    cout << RED << "Invalid subject choice!" << RESET << endl;
                    break;
                }

                // Chapter Selection
                int chapterChoice;
                cout << CYAN << "\nSelect Chapter:\n" << RESET;
                for (size_t i = 0; i < chaptersList[subjectChoice - 1].size(); i++)
                    {
                    cout << "[" << i + 1 << "] " << chaptersList[subjectChoice - 1][i] << endl;
                }

                cout << YELLOW << "\nEnter your choice: " << RESET;
                cin >> chapterChoice;

                if (chapterChoice < 1 || chapterChoice > chaptersList[subjectChoice - 1].size())
                    {
                    cout << RED << "Invalid chapter choice!" << RESET << endl;
                    break;
                }

                // Open Quiz URL
                string quizURL = quizURLs[subjectChoice - 1][chapterChoice - 1];
                cout << GREEN << "\nOpening Quiz Link: " << quizURL << RESET << endl;

#ifdef _WIN32
                system(("start " + quizURL).c_str()); // Windows
#else
                system(("xdg-open " + quizURL).c_str()); // Linux
#endif

                // Record marks
                int marks;
                cout << YELLOW << "Enter the marks you scored in this quiz: " << RESET;
                cin >> marks;

             saveMarks(username, subjects, chaptersList, subjectChoice, chapterChoice, marks);

                break;
            }

            case 2:
                {
                // View Scores
               // View Scores
                displayHeader("Performance");
                ifstream scoreFile("user_scores.txt");  // Reading from the single user_scores.txt file
                if (scoreFile.is_open())
                    {
                    string line;
                    double totalMarks = 0;
                    int quizCount = 0;

                    cout << CYAN << "Scores for " << username << ":\n" << RESET;
                    while (getline(scoreFile, line))
                    {
                        if (line.find("Username: " + username) != string::npos)
                            {  // Check if the line contains the specified username
                            cout << line << endl;
                            size_t pos = line.rfind("Marks: ");
                            if (pos != string::npos)
                            {
                                totalMarks += stoi(line.substr(pos + 7));  // Extract and add marks
                                quizCount++;
                            }
                        }
                    }
                    scoreFile.close();

                    if (quizCount > 0)
                        {
                        double average = totalMarks / quizCount;
                        cout << GREEN << "\nAverage Score: " << average << RESET << endl;
                    }
                    else
                    {
                        cout << RED << "No scores found for " << username << RESET << endl;
                    }
                }
                else
                    {
                    cout << RED << "No score file found!" << RESET << endl;
                }

                cout << YELLOW << "Press any key to contiue." << RESET;
                _getch();
                  system("cls");
                goto startagain;
                break;
            }

            case 3:
            system("cls");
                cout << CYAN << "Returned to Main Menu..." << RESET << endl;
                break;

            default:
                cout << RED << "Invalid choice, please try again." << RESET << endl;
        }
    } while (option != 3);
}
void saveMarks(const string& username, const vector<string>& subjects,
               const vector<vector<string>>& chaptersList, int subjectChoice,
               int chapterChoice, int marks)
               {
    ofstream scoreFile("user_scores.txt", ios::app); // Single file for all users
    if (scoreFile.is_open())
        {
        scoreFile << "Username: " << username
                  << ", Subject: " << subjects[subjectChoice - 1]
                  << ", Chapter: " << chaptersList[subjectChoice - 1][chapterChoice - 1]
                  << ", Marks: " << marks << endl;
        scoreFile.close();
        cout << GREEN << "Marks saved successfully in 'user_scores.txt'!" << RESET << endl;
    }
    else
        {
        cerr << RED << "Error saving marks to 'user_scores.txt'!" << RESET << endl;
    }
}



void performanceMenu(const string& username)
{
    int choice;
    do
        {
        displayHeader("Performance Menu");
        cout << CYAN << "\nPerformance Menu:\n" << RESET;
        cout << "---------------------------------------------------------------------------------------------" << endl;

        cout << CYAN << "[1] View Your Performance" << RESET << endl;
        cout << "  - Check your own performance metrics, including scores and progress over time.\n" << endl;

        cout << CYAN << "[2] Search for Someone's Performance" << RESET << endl;
        cout << "  - Look up the performance metrics of another user by entering their details.\n" << endl;

        cout << CYAN << "[3] Performance Board (Sorted by Average Score)" << RESET << endl;
        cout << "  - View a leaderboard displaying users sorted by their average scores.\n" << endl;

        cout << CYAN << "[4] Back to Main Menu" << RESET << endl;
        cout << "  - Return to the main menu to access other features of the application.\n" << endl;

        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << YELLOW << "Enter your choice: " << RESET;
        cin >> choice;

        switch (choice)
        {
            case 1:
                viewPerformance(username);
                break;

            case 2:
                searchPerformance();
                break;

            case 3:
                performanceBoard();
                break;

            case 4:
                  system("cls");
                cout << GREEN << "Returning to main menu..." << RESET << endl;
                break;

            default:
                cout << RED << "Invalid choice! Please try again." << RESET << endl;
        }
    } while (choice != 4);
}

string capitalizeFirstLetter(const string& s)
{

    if (s.empty()) return s;
    string result = s;
    result[0] = toupper(result[0]);
    for (size_t i = 1; i < result.size(); ++i)
        {
        result[i] = tolower(result[i]);
    }
    return result;
}


void searchPerformance()
{
    // Prompt the admin to input a substring for username search.
    string searchUsername;
    cout << YELLOW << "Enter the substring to search for usernames: " << RESET;
    cin >> searchUsername;
     searchUsername=capitalizeFirstLetter(searchUsername);
    // Open the user profile file to read usernames.
    ifstream profileFile("user_profile.txt");
    if (!profileFile.is_open())
    {
        cout << RED << "Failed to open user profile file!" << RESET << endl;
        return;
    }

    string line;
    vector<string> usernames;

    // Read each line of the user profile file and extract the username.
    while (getline(profileFile, line))
    {
        size_t usernamePos = line.find(",");
        if (usernamePos != string::npos)
        {
            string username = line.substr(0, usernamePos); // Extract username before the first comma.
            usernames.push_back(username); // Add to the list of usernames.
        }
    }
    profileFile.close(); // Close the file after reading.

    // Vector to store matching usernames.
    vector<string> matchingUsers;

    // Search for usernames containing the search substring.
    for (const string& username : usernames)
    {
        // Ensure case-insensitive matching (optional).
        if (username.find(searchUsername) != string::npos)
        {
            matchingUsers.push_back(username); // Add to matching users list if it contains the substring.
        }
    }

    // If no matching usernames are found, display an appropriate message.
    if (matchingUsers.empty())
    {
        cout << RED << "No users found with the given search term!" << RESET << endl;
        cout << YELLOW << "Press any key to continue" << RESET;
        _getch(); // Wait for user input to continue.
        return;
    }

    // Display the matching usernames found.
    cout << YELLOW << "Found the following users matching your search:\n" << RESET;
    for (int i = 0; i < matchingUsers.size(); ++i)
    {
        cout << "[" << (i + 1) << "] " << matchingUsers[i] << endl;
    }

    // Ask the admin to select a username from the list.
    int choice;
    cout << YELLOW << "Enter the number of the user you want to view: " << RESET;
    cin >> choice;

    // Validate the selection and view the performance data of the selected user.
    if (choice >= 1 && choice <= matchingUsers.size())
    {
        string selectedUsername = matchingUsers[choice - 1];
        // View the performance of the selected user.
        viewPerformance(selectedUsername);
    }
    else
    {
        // Handle invalid selection.
        cout << RED << "Invalid selection!" << RESET << endl;
    }

    // Wait for user input before returning to the previous screen.
    cout << YELLOW << "Press any key to continue" << RESET;
    _getch();
}


void displayPerformanceSummaryForUserA(const string &username, const vector<int>& scores)
{
    if (scores.empty())
        {
        cout << "No performance scores available for " << username << "." << endl;
        return;
    }

    // Calculate the average score.
    int total = 0;
    for (int score : scores)
        {
        total += score;
    }
    double average = static_cast<double>(total) / scores.size();

    // Find the highest and lowest scores.
    int highest = *max_element(scores.begin(), scores.end());
    int lowest = *min_element(scores.begin(), scores.end());

    // Display the performance summary.
    cout << "Performance Summary for " << username << ":\n";
    cout << "---------------------------------\n";
   cout << CYAN << "Scores: " << RESET;
   for (int score : scores)
        {
    cout << score << " ";
   }
    cout << endl;

    cout << YELLOW << "Average: " << RESET << average << endl;
    cout << GREEN << "Highest Score: " << RESET << highest << endl;
    cout << RED << "Lowest Score: " << RESET << lowest << endl;

     cout << CYAN << "Press any key to continue..." << RESET;
    _getch(); // Wait for the user to press a key to continue.
}
void performanceBoard()
{
    // Read scores from the file (user_scores.txt)
    ifstream scoresFile("user_scores.txt");
    if (!scoresFile.is_open())
        {

        cout << RED << "Failed to open scores file!" << RESET << endl;

        return;
    }

    string line;
    vector<pair<string, double>> studentScores;
    string currentUsername;
    vector<int> currentScores;

    while (getline(scoresFile, line))
        {
        // Find the username and marks
        size_t usernamePos = line.find("Username: ");
        size_t marksPos = line.find("Marks: ");

        if (usernamePos != string::npos && marksPos != string::npos)
            {
            string username = line.substr(usernamePos + 10, line.find(",", usernamePos) - (usernamePos + 10));
            int score = stoi(line.substr(marksPos + 7));

            // If the username is different, calculate the average and store the old user
            if (!currentUsername.empty() && currentUsername != username)
                {
                double averageScore = accumulate(currentScores.begin(), currentScores.end(), 0.0) / currentScores.size();
                studentScores.push_back(make_pair(currentUsername, averageScore));
                currentScores.clear(); // Reset scores for the new user
            }

            // Add the current score to the user's score list
            currentUsername = username;
            currentScores.push_back(score);
        }
    }


    // After the loop ends, ensure the last user's scores are added
    if (!currentUsername.empty())
        {
        double averageScore = accumulate(currentScores.begin(), currentScores.end(), 0.0) / currentScores.size();
        studentScores.push_back(make_pair(currentUsername, averageScore));
    }

    scoresFile.close();

    // Sort students by average score using custom sort function
    sortPerformances(studentScores);

    // Display performance board
    displayHeader("Performance Board");
    cout << CYAN << "Performance Board (Sorted by Average Score)" << RESET << endl;
    int i=1;
    for (const auto& student : studentScores)
        {
        cout << YELLOW << "rank: "<<i<<" Username: " << student.first << " | Average Score: " << student.second << RESET << endl;
        i++;
    }

    cout << YELLOW << "Press Enter to return to the performance menu..." << RESET;
    cin.ignore();
    cin.get();
}


// Custom sort function to sort students by average score (descending order)
// Function to display time spent from session_log.txt for a specific user
void displayTimeSpentFromLog(const string& username) {
    ifstream sessionFile("session_log.txt");
    if (!sessionFile.is_open()) {
        cout << RED << "Failed to open session log file!" << RESET << endl;
        return;
    }

    string line;
    bool userFound = false;

    // Read each line and look for the username
    while (getline(sessionFile, line)) {
        if (line.find("Username: " + username) != string::npos) {
            // Display the time spent from this line
            cout << CYAN << "\nTime Spent (from session log) for " << username << ": " << line << RESET << endl;
            userFound = true;
        }
    }

    if (!userFound) {
        cout << RED << "No session data found for user: " << username << RESET << endl;
    }

    sessionFile.close();
}



void viewPerformance(const string& username)
{


    displayHeader("Your Performance");

    // Read scores from the file (user_scores.txt)
    ifstream scoresFile("user_scores.txt");
    if (!scoresFile.is_open())
        {
        cout << RED << "Failed to open scores file!" << RESET << endl;

        return;
    }

    string line;
    vector<int> scores;
    bool userFound = false;

    while (getline(scoresFile, line))
        {
        if (line.find("Username: " + username) != string::npos)
        {
            size_t pos = line.find("Marks: ");
            if (pos != string::npos)
            {
                try
                {
                    int score = stoi(line.substr(pos + 7));
                    scores.push_back(score);
                    userFound = true;
                } catch (...)
                {
                    cout << RED << "Error parsing score for user: " << username << RESET << endl;
                    scoresFile.close();

                    return;
                }
            }

        }
    }

    scoresFile.close();

    if (!userFound)
        {
        cout << RED << "No performance data found for user: " << username << RESET << endl;

        return;
    }

    // Calculate average score and determine rating
    double averageScore = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
    string rating;

    if (averageScore >= 90)
        {
        rating = "Excellent";
    }
    else if (averageScore >= 75)
        {
        rating = "Good";
    }
    else if (averageScore >= 50)
        {
        rating = "Average";
    }
    else
        {
        rating = "Needs Improvement";
    }

    // Display Performance Details
    cout << GREEN << "Performance Report for: " << username << RESET << endl;
    cout << YELLOW << "Scores: ";
    for (int score : scores)
        {
        cout << score << " ";
    }
    cout << RESET << endl;
    cout << YELLOW << "Average Score: " << averageScore << RESET << endl;
    cout << YELLOW << "Rating: " << rating << RESET << endl;

    // Display ASCII art based on performance
    if (rating == "Excellent")
        {
        cout << CYAN << "\n Outstanding Performance! Keep it up! " << RESET << endl;
    }
    else if (rating == "Good")
        {
        cout << CYAN << "\n Good Job! Aim Higher! " << RESET << endl;
    }
    else if (rating == "Average")
        {
        cout << CYAN << "\n Room for Improvement, Keep Trying! " << RESET << endl;
    }
    else
        {
        cout << CYAN << "\n Work Harder, You Can Do It! " << RESET << endl;
    }

     displayTimeSpentFromLog(username);
   // cout << CYAN << "\nTime Spent (Login to Performance Evaluation): " << elapsedSeconds << " seconds" << RESET << endl;

    cout << YELLOW << "Press Enter to return to the main menu..." << RESET;
    cin.ignore();
    cin.get();

}


void sortPerformances(vector<pair<string, double>>& studentScores)
{
    int n = studentScores.size();
    bool swapped;

    // Bubble Sort to sort in descending order based on average score
    for (int i = 0; i < n - 1; ++i)
        {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            // If the current student's average score is less than the next, swap them
            if (studentScores[j].second < studentScores[j + 1].second)
            {
                swap(studentScores[j], studentScores[j + 1]);
                swapped = true;
            }

        }

        // If no two elements were swapped in the inner loop, the list is already sorted
        if (!swapped)
            {
            break;
        }
    }
}



// Add an edge to the graph (chapter, weight)
void addEdge(const string &u, const string &v, int weight)
{
    adjList[u].emplace_back(v, weight);
}

// Dijkstra's Algorithm to find the shortest path from the start
vector<string> dijkstra(const string &start)
{
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;

    for (const auto &pair : adjList)
    {
        dist[pair.first] = INT_MAX; // Initialize distances to infinity
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    dist[start] = 0;
    pq.emplace(0, start); // Starting node with distance 0

    while (!pq.empty())
    {
        int currDist = pq.top().first;
        string u = pq.top().second;
        pq.pop();

        if (currDist > dist[u])
            continue;

        // Traverse through all adjacent nodes
        for (const auto &neighbor : adjList[u])
        {
            string v = neighbor.first;
            int weight = neighbor.second;
            int newDist = currDist + weight;

            if (newDist < dist[v])
            {
                dist[v] = newDist;
                prev[v] = u;
                pq.emplace(newDist, v);
            }
        }
    }

    // Reconstruct the optimal order of chapters
    vector<string> order;
    for (const auto &pair : dist)
    {
        if (pair.first != start && pair.second != INT_MAX)
        {
            order.push_back(pair.first);
        }
    }

    return order;
}

// Load data for a specific subject from a file

// Clear the adjacency list at the start of loading a new file
void loadFromFile(const string &filename, const string &subject)
{
    adjList.clear(); // Clear the adjacency list to avoid old data

    ifstream file(filename);
    string line, currentSubject, currentChapter;

    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (getline(file, line))
    {
        if (line.find("Subject:") != string::npos)
        {
            currentSubject = line.substr(line.find(":") + 2);
        }

        if (currentSubject != subject)
            continue;

        if (line.find("Chapter") != string::npos)
        {
            currentChapter = line.substr(line.find(":") + 2);
        }
        else if (line.find("Weightage") != string::npos)
        {
            try
            {
                int weightage = stoi(line.substr(line.find(":") + 2));
                if (!currentChapter.empty())
                {
                    addEdge("START", currentChapter, weightage);
                }
                else
                {
                    cerr << "Error: Encountered Weightage without a valid Chapter." << endl;
                }
            }
            catch (const invalid_argument& e)
            {
                cerr << "Error: Invalid weightage format in line: " << line << endl;
            }
            catch (const out_of_range& e)
            {
                cerr << "Error: Weightage value out of range in line: " << line << endl;
            }
        }
    }

    file.close();
}



// Display the tree representation
void displayTreeRepresentation(const vector<string> &roadmap, const string &title)
{
    cout << "\n===========================================================================" << endl;
    cout << "                         " << title << endl;
    cout << "=============================================================================" << endl;

    for (size_t i = 0; i < roadmap.size(); ++i)
        {
        cout << (i == roadmap.size() - 1 ? "  |-- " : "  |-- ") << roadmap[i] << endl;
    }

    cout << "==============================================================================" << endl << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get(); // Pause until Enter is pressed
    system("cls");
}


// Handle class choice
int getClassChoice()
{
    int choice;
   cout << CYAN << "\nSelect a class to view the roadmap:\n" << RESET;
   cout << "-----------------------------------------------------------------------------------------------" << endl;

cout << CYAN << "1. Class 8" << RESET << endl;
cout << "  - View the roadmap for Class 8, including topics covered and key milestones.\n" << endl;

cout << CYAN << "2. Class 9" << RESET << endl;
cout << "  - Explore the roadmap for Class 9, detailing the curriculum and important dates.\n" << endl;

cout << CYAN << "3. Class 10" << RESET << endl;
cout << "  - Access the roadmap for Class 10, highlighting essential learning objectives.\n" << endl;

cout << CYAN << "4. Exit" << RESET << endl;
cout << "  - Return to the previous menu or exit the application.\n" << endl;

cout << "--------------------------------------------------------------------------------------------------" << endl;
cout << YELLOW << "Enter your choice: " << RESET;
    cin >> choice;
    return choice;
}


// Handle subject choice
int getSubjectChoice()
{
    system("cls");
    int subjectChoice;
    cout << CYAN << "\nSelect a subject to view the roadmap:\n" << RESET;
cout << "----------------------------------------------------------------------------------------------------------" << endl;

cout << CYAN << "1. Mathematics" << RESET << endl;
cout << "  - Explore the roadmap for Mathematics, covering key concepts and learning objectives.\n" << endl;

cout << CYAN << "2. Science" << RESET << endl;
cout << "  - View the roadmap for Science, detailing important topics and experiments.\n" << endl;

cout << CYAN << "3. Social Science" << RESET << endl;
cout << "  - Access the roadmap for Social Science, highlighting essential themes and historical events.\n" << endl;

cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << YELLOW << "Enter your choice: " << RESET;
    cin >> subjectChoice;
    system("cls");
    return subjectChoice;
}


// Get filename based on class choice
string getFilename(int choice)
{
    switch(choice){
        case 1:
            return  "Weightage8.txt" ;
        case 2:
            return "Weightage9.txt" ;
        case 3:
            return "Weightage10.txt";
    }
}


// Handle roadmap generation
void handleRoadmapGeneration(int choice)
{
    int subjectChoice = getSubjectChoice();
    string subject;

    switch(subjectChoice) {
        case 1: subject = "Mathematics";
                break;

        case 2: subject = "Science";
                break;

        case 3: subject = "Social Science";
                 break;

        default:
            cout << "Invalid subject choice!" << endl;
            return;
    }

    string filename = getFilename(choice);
    loadFromFile(filename, subject); // Load clean data

    vector<string> roadmap;
    roadmap = dijkstra("START");

    // Remove duplicates and sort roadmap
    sort(roadmap.begin(), roadmap.end());
    roadmap.erase(unique(roadmap.begin(), roadmap.end()), roadmap.end());

    displayTreeRepresentation(roadmap, "Optimal Study Order for " + subject);
}



// Function to display a header

void collectfeedbackmain()
{
      start:
       displayHeader("Welcome to the Feedback System");
cout << CYAN << "Please select an option:\n" << RESET;
cout << "---------------------------------------------------------------------------------------" << endl;

cout << YELLOW << "1. Provide Feedback" << RESET << endl;
cout << "  - Share your thoughts and suggestions to help us improve.\n" << endl;

cout << YELLOW << "2. View Feedback History" << RESET << endl;
cout << "  - Review your past feedback submissions and responses.\n" << endl;

cout << YELLOW << "3. Clear Feedback History" << RESET << endl;
cout << "  - Remove all your previous feedback records from the system.\n" << endl;

cout << YELLOW << "4. Exit from Feedback" << RESET << endl;
cout << "  - Return to the main menu or exit the feedback system.\n" << endl;

cout << "-------------------------------------------------------------------------------------" << endl;
//cout << YELLOW << "Enter your choice: " << RESET;

        int mainChoice;
        cout << YELLOW << "Enter your choice : " << RESET;
        while (!(cin >> mainChoice) || mainChoice < 1 || mainChoice > 4)
            {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid choice. Please enter a number between 1 and 4: " << RESET;
        }

        cin.ignore(); // Clear the input buffer

        switch (mainChoice)
        {
            case 1:
                collectFeedback();
                goto start;
                break;

            case 2:
                viewFeedbackHistory();
                goto start;
                break;

            case 3:
                clearFeedbackByUsername();
                goto start;
                break;

            case 4:
                cout << GREEN << "Thank you for using the Feedback System. " << RESET << endl;
                cout << YELLOW << "Press any key to return " << RESET;
                _getch();
                system("cls");

              break;
        }


}



// Function to display the main feedback menu
int displayMainMenu()
{
    int choice;
    cout << YELLOW << "Please choose the type of feedback you want to provide:" << RESET << endl;
cout << "-----------------------------------------------------------------------------------------------------" << endl;

cout << CYAN << "1. Rate Content" << RESET << endl;
cout << "  - Share your rating for the educational content provided.\n" << endl;

cout << CYAN << "2. Rate Test" << RESET << endl;
cout << "  - Provide feedback on the tests, including difficulty and relevance.\n" << endl;

cout << CYAN << "3. Rate Presentation" << RESET << endl;
cout << "  - Evaluate the presentation quality of the materials.\n" << endl;

cout << CYAN << "4. Rate Usability" << RESET << endl;
cout << "  - Give your opinion on the usability of the platform.\n" << endl;

cout << CYAN << "5. Provide Suggestions" << RESET << endl;
cout << "  - Share any suggestions you have for improving the system.\n" << endl;

cout << CYAN << "6. Detailed Feedback on All" << RESET << endl;
cout << "  - Offer comprehensive feedback covering all aspects.\n" << endl;

cout << CYAN << "7. Return to Main Menu" << RESET << endl;
cout << "  - Go back to the main menu to explore other options.\n" << endl;

cout << "------------------------------------------------------------------------------------------------------" << endl;
cout << YELLOW << "Enter your choice: " << RESET;

    //cout << YELLOW << "Enter your choice (1-7): " << RESET;
    while (!(cin >> choice) || choice < 1 || choice > 7)
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Invalid choice. Please enter a number between 1 and 7: " << RESET;
    }
    cin.ignore();
    return choice;

}


// Function to collect ratings for specific categories
void collectRatings(unordered_map<string, int> &ratings, const vector<string> &categories)
{
    for (const auto &category : categories)
        {
        int rating;
        cout << YELLOW << "Rate the " << category << " out of 10: " << RESET;
        while (!(cin >> rating) || rating < 0 || rating > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid rating. Please enter a number between 0 and 10: " << RESET;
        }
        ratings[category] = rating;
        cin.ignore();
    }

}


// Function to collect detailed feedback
void collectDetailedFeedback(string &feedback)
{
    cout << YELLOW << "Any suggestions or feedback? (Press Enter to skip): " << RESET;
    getline(cin, feedback);
}


// Function to collect user details
void collectUserDetails(string &username)
{
    cout << YELLOW << "Enter your username: " << RESET;
    getline(cin, username);
}


// Function to record feedback in a file
void recordFeedback(const string &username, const unordered_map<string, int> &ratings, const string &suggestions)
{
    ofstream feedbackFile("feedback.txt", ios::app);
    if (feedbackFile.is_open())
        {
        feedbackFile << "Username: " << username << endl;
        for (const auto &rating : ratings)
        {
            feedbackFile << rating.first << " Rating: " << rating.second << "/10" << endl;
        }
        feedbackFile << "Suggestions: " << (suggestions.empty() ? "None" : suggestions) << endl;
        feedbackFile << "----------------------------------------" << endl;
        feedbackFile.close();
        cout << GREEN << "\nThank you for your feedback!" << RESET << endl;
    }
    else
        {
        cout << RED << "Error saving feedback!" << RESET << endl;
    }

}


// Function to display a summary of feedback
void displaySummary(const string &username, const unordered_map<string, int> &ratings, const string &suggestions)
{
    displayHeader("Feedback Summary");
    cout << GREEN << "Username: " << username << RESET << endl;
    for (const auto &rating : ratings)
        {
        cout << GREEN << rating.first << " Rating: " << rating.second << "/10" << RESET << endl;
    }

    cout << GREEN << "Suggestions: " << (suggestions.empty() ? "None" : suggestions) << RESET << endl;

}


// Function to view feedback history
void viewFeedbackHistory()
{
    ifstream feedbackFile("feedback.txt");
    if (feedbackFile.is_open())
        {
        string line;
        displayHeader("Feedback History");
        while (getline(feedbackFile, line))
        {
            cout << line << endl;
        }
        feedbackFile.close();
    }
    else
        {
        cout << RED << "No feedback history found!" << RESET << endl;
    }
    cout << YELLOW << "Press any key to continue" << RESET;
         _getch();

}


string trim1(const string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        {
        return ""; // No non-space characters
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);

}


// Function to clear feedback history
void clearFeedbackByUsername()
{
    string targetUsername;
    cout << YELLOW << "Enter the username to clear feedback: " << RESET;
    getline(cin, targetUsername);

        targetUsername = trim1(targetUsername);

    if (targetUsername.empty())
        {
        cout << RED << "Invalid input. Username cannot be empty!" << RESET << endl;
        cout << YELLOW << "Press any to continue" << RESET;
         _getch();

        return;
    }


    ifstream feedbackFile("feedback.txt");
    if (!feedbackFile.is_open())
        {
        cout << RED << "Error opening feedback file!" << RESET << endl;

        return;
    }

    vector<string> filteredFeedback;
    string line;
    bool isUserFeedback = false;
    bool userFound = false;

    // Read the feedback file line by line
    while (getline(feedbackFile, line))
        {
        if (line.find("Username: ") == 0)
        {
            isUserFeedback = (line == "Username: " + targetUsername);
            if (isUserFeedback)
            {
                userFound = true;
            }
        }

        // Only keep lines not related to the target username
        if (!isUserFeedback)
            {
            filteredFeedback.push_back(line);
        }
        else if (line == "----------------------------------------")
            {
            isUserFeedback = false; // End of a feedback block
        }

    }

    feedbackFile.close();

    // Rewrite the file with filtered feedback
    ofstream outputFeedbackFile("feedback.txt", ios::trunc);
    if (outputFeedbackFile.is_open())
        {
        for (const string &feedbackLine : filteredFeedback)
        {
            outputFeedbackFile << feedbackLine << endl;
        }
        outputFeedbackFile.close();


        if (userFound)
            {
            cout << GREEN << "Feedback for username '" << targetUsername << "' cleared successfully!" << RESET << endl;
            cout << YELLOW << "Press any to continue" << RESET;

         _getch();
        }
        else
            {
            cout << YELLOW << "No feedback found for username '" << targetUsername << "'." << RESET << endl;
            cout << YELLOW << "Press any to continue" << RESET;
         _getch();
        }

    }
    else
        {
        cout << RED << "Error writing to feedback file!" << RESET << endl;
        cout << YELLOW << "Press any to continue" << RESET;
         _getch();
    }

}


// Function to collect feedback
void collectFeedback()
{
    string username;
    unordered_map<string, int> ratings;
    string suggestions;

    // Collect user details
    collectUserDetails(username);

    while (true)
        {
        int choice = displayMainMenu();

        if (choice == 7)
            {
            break; // Return to the main menu
        }

        switch (choice)
        {
            case 1:
                collectRatings(ratings, {"Content"});
                break;

            case 2:
                collectRatings(ratings, {"Test"});
                break;

            case 3:
                collectRatings(ratings, {"Presentation"});
                break;

            case 4:
                collectRatings(ratings, {"Usability"});
                break;

            case 5:
                collectDetailedFeedback(suggestions);
                break;

            case 6:
                collectRatings(ratings, {"Content", "Test", "Presentation", "Usability"});
                collectDetailedFeedback(suggestions);
                break;

            default:
                cout << RED << "Invalid choice." << RESET << endl;
                break;

        }

        recordFeedback(username, ratings, suggestions);
        displaySummary(username, ratings, suggestions);
    }

}

// Function prototypes


// Main admin function
void adminMenu()
{

    int choice;
    do
        {
        displayHeader("Admin Menu");

       cout << CYAN << "Admin Menu:\n" << RESET;
cout << "---------------------------------------------------------------------------------------------" << endl;

cout << YELLOW << "1. View All Users" << RESET << endl;
cout << "  - Display a list of all registered users in the system.\n" << endl;

cout << YELLOW << "2. Update User Profile" << RESET << endl;
cout << "  - Modify the details of a specific user profile.\n" << endl;

cout << YELLOW << "3. Delete User Profile" << RESET << endl;
cout << "  - Remove a user profile from the system permanently.\n" << endl;

cout << YELLOW << "4. View Feedback History" << RESET << endl;
cout << "  - Access the feedback history submitted by users.\n" << endl;

cout << YELLOW << "5. Clear Feedback History" << RESET << endl;
cout << "  - Delete all feedback records from the system.\n" << endl;

cout << YELLOW << "6. View Performance Data" << RESET << endl;
cout << "  - Review performance metrics for all users.\n" << endl;

cout << YELLOW << "7. Update Performance Data" << RESET << endl;
cout << "  - Modify the performance records of a specific user.\n" << endl;

cout << YELLOW << "8. Search Performance of User" << RESET << endl;
cout << "  - Look up the performance data of a specific user.\n" << endl;

cout << YELLOW << "9. Exit" << RESET << endl;
cout << "  - Return to the previous menu or exit the admin panel.\n" << endl;

cout << "--------------------------------------------------------------------------------------------" << endl;
cout << YELLOW << "Enter your choice: " << RESET;
        cin >> choice;

          string usern;
        switch(choice)
        {
            case 1:
                viewAllUsers();
                break;

            case 2:
                updateUserProfile();
                break;

            case 3:
                deleteUserProfile();
                break;

            case 4:
                viewFeedbackHistory1();
                break;

            case 5:
                clearFeedbackHistory();
                break;

            case 6:
                viewPerformanceData();
                break;

            case 7:
                updatePerformanceData();
                break;

            case 8:

            //  cout<<"Enter the user name you want "<<endl;
            //  cin>>usern;

            //     viewUserPerformanceForAdmin(usern);
             searchPerformance();
                break;
            case 9:
                cout << "Exiting Admin Menu..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 9);

}


// Function to view all users
void viewAllUsers()
{
    vector<string> userProfiles;
    loadUserProfiles(userProfiles);
    displayHeader("User  Profiles");

    for (const auto &profile : userProfiles)
        {
        cout << profile << endl;
    }
    cout << "Press any key to continue...";
    _getch();

}


// Function to update user profile
void updateUserProfile()
{
    string username, name, email, classInfo, password;
    cout << "Enter username to update: ";
    cin >> username;

    collectUserDetails(username, name, email, classInfo, password);
    updateUserProfileInFile(username, name, email, classInfo, password);
    cout << "User  profile updated successfully!" << endl;
    cout << "Press any key to continue...";
    _getch();

}



// Function to delete user profile
void deleteUserProfile() {
    string username;
    cout << "Enter username to delete: ";
    cin >> username;

    if(deleteUserProfileFromFile(username)){
    cout<< GREEN << "User  profile deleted successfully!" << endl;
    cout << "Press any key to continue...";
    _getch();}
    else{
        cout<< RED <<"User not found to delete "<<endl;
        cout<<BLUE<<"press enter to continue"<<endl;
    }
    _getch();
}


// Function to view feedback history
void viewFeedbackHistory1()
{
    vector<string> feedbackHistory;
    loadFeedbackHistory(feedbackHistory);
    displayHeader("Feedback History");

    for (const auto &feedback : feedbackHistory)
        {
        cout << feedback << endl;
    }
    cout << "Press any key to continue...";

    _getch();
}


// Function to clear feedback history

void clearFeedbackHistory()
{
    ofstream feedbackFile("feedback.txt", ios::trunc);
    if (feedbackFile.is_open())
        {
        feedbackFile.close();
        cout<< GREEN << "Feedback history cleared successfully!" << endl;
    }
    else
        {
        cout<< RED << "Error clearing feedback history!" << endl;
    }

    cout << "Press any key to continue...";
    _getch();

}


// Function to view performance data

void viewPerformanceData()
{
    vector<string> performanceData;
    loadPerformanceData(performanceData);

    displayHeader("Performance Data");

    for (const auto &data : performanceData)
        {
        cout << data << endl;
    }
    cout << "Press any key to continue...";
    _getch();
}


// Function to update performance data

void updatePerformanceData()
{
    string username;
    cout << CYAN<<"Enter username to update performance data: ";
    cin >> username;

    // Load existing performance data
    ifstream scoreFile("user_scores.txt");
    if (!scoreFile.is_open())
    {
        cout << RED << "Error reading performance data!" << RESET << endl;
        return;
    }

    string line;
    vector<string> updatedData;
    bool userFound = false;

    // Read the performance data and update if the user is found
    while (getline(scoreFile, line))
    {
        if (line.find("Username: " + username) != string::npos)
        {
            userFound = true;
            cout << "Current performance data: " << line << endl;

            // Prompt for new marks
            int newMarks;
            cout << "Enter new marks for " << username << ": ";
            cin >> newMarks;

            // Update the line with new marks
            size_t marksPos = line.find("Marks: ");
            if (marksPos != string::npos)
            {
                line.replace(marksPos + 7, line.length(), to_string(newMarks)); // Update marks
            }
        }
        updatedData.push_back(line); // Store the updated or unchanged line
    }
    scoreFile.close();

    // If user was found, write the updated data back to the file
    if (userFound)
    {
        ofstream outFile("user_scores.txt", ios::trunc);
        if (outFile.is_open())
        {
            for (const auto& dataLine : updatedData)
            {
                outFile << dataLine << endl; // Write each line back to the file
            }
            outFile.close();
            cout << GREEN << "Performance data updated successfully!" << RESET << endl;
        }
        else
        {
            cout << RED << "Error saving updated performance data!" << RESET << endl;
        }
    }
    else
    {
        cout << RED << "User  not found!" << RESET << endl;
    }

    cout << "Press any key to continue...";
    _getch();
}


// Function to save user profile

void saveUserProfile(const string &username, const string &name, const string &email, const string &classInfo, const string &password)
{
    ofstream file("user_profile.txt", ios::app);
    if (file.is_open())
        {
        file << username << "," << name << "," << email << "," << classInfo << "," << password << endl;
        file.close();
    }
    else
        {
        cout << "Error saving user profile!" << endl;
    }

}


// Function to check if email exists

bool isEmailExists1(const string &email)
{
    ifstream file("user_profile.txt");
    string line;

    while (getline(file, line))
        {
        size_t pos2 = line.find(',');
        size_t pos3 = line.find(',', pos2 + 1);
        string existingEmail = line.substr(pos2 + 1, pos3 - pos2 - 1);
        if (existingEmail == email)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;

}


// Function to load user profiles

void loadUserProfiles(vector<string> &userProfiles)
{
    ifstream file("user_profile.txt");
    string line;

    while (getline(file, line))
        {
        userProfiles.push_back(line);
    }
    file.close();

}


// Function to load feedback history

void loadFeedbackHistory(vector<string> &feedbackHistory)
{
    ifstream file("feedback.txt");
    string line;

    while (getline(file, line))
        {
        feedbackHistory.push_back(line);
    }
    file.close();

}


// Function to load performance data

void loadPerformanceData(vector<string> &performanceData)
{
    ifstream file("user_scores.txt");
    string line;

    while (getline(file, line))
        {
        performanceData.push_back(line);
    }
    file.close();

}


// Function to save feedback history

void saveFeedbackHistory(const vector<string> &feedbackHistory)
{
    ofstream file("feedback.txt", ios::trunc);
    if (file.is_open())
        {
        for (const auto &feedback : feedbackHistory)
        {
            file << feedback << endl;
        }
        file.close();

    }
    else
        {
        cout << "Error saving feedback history!" << endl;
    }

}


// Function to save performance data

void savePerformanceData(const vector<string> &performanceData)
{
    ofstream file("user_scores.txt", ios::trunc);
    if (file.is_open())
        {
        for (const auto &data : performanceData)
        {
            file << data << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error saving performance data!" << endl;
    }

}


// Function to display header


// Function to collect user details
void collectUserDetails(string &username, string &name, string &email, string &classInfo, string &password)
{
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter class: ";
    getline(cin, classInfo);

    cout << "Enter password: ";
    password = hidePassword();

}


// Function to collect feedback details

void collectFeedbackDetails(string &username, unordered_map<string, int> &ratings, string &suggestions)
{
    cout << "Enter username for feedback: ";
    cin >> username;
    string categories[] = {"Content", "Test", "Presentation", "Usability"};
    for (const auto &category : categories)
        {
        int rating;
        cout << "Rate " << category << " (0-10): ";
        cin >> rating;
        ratings[category] = rating;

    }
    cout << "Any suggestions? ";
    cin.ignore();
    getline(cin, suggestions);

}


// Function to display feedback summary

void displayFeedbackSummary(const string &username, const unordered_map<string, int> &ratings, const string &suggestions)
{
    cout << "Feedback Summary for " << username << endl;
    for (const auto &rating : ratings)
        {
        cout << rating.first << ": " << rating.second << "/10" << endl;
    }
    cout << "Suggestions: " << suggestions << endl;

}


// Function to display performance summary

void displayPerformanceSummary(const string &username, const vector<int> &scores)
{
    cout << "Performance Summary for " << username << endl;
    for (int score : scores)
        {
        cout << "Score: " << score << endl;
    }

}


// Function to sort performance data

void sortPerformanceData(vector<pair<string, double>> &studentScores)
{
    sort(studentScores.begin(), studentScores.end(), [](const pair<string, double> &a, const pair<string, double> &b) {
        return a.second > b.second; // Sort in descending order
    });

}


// Function to display performance board

void displayPerformanceBoard(const vector<pair<string, double>> &studentScores)
{
    cout << "Performance Board" << endl;
    for (const auto &student : studentScores)
        {
        cout << "Username: " << student.first << " | Average Score: " << student.second << endl;
    }

}



void updateUserProfileInFile(const string &username, const string &newName, const string &newEmail, const string &newClass, const string &newPassword)
{
    ifstream inputFile("user_profile.txt");
    ofstream outputFile("temp.txt"); // Temporary file to write updated data
    string line;

    if (inputFile.is_open() && outputFile.is_open())
        {
        while (getline(inputFile, line))
        {
            stringstream ss(line);
            string existingUsername, existingName, existingEmail, existingClass, existingPassword;

            // Parse the existing profile data
            getline(ss, existingUsername, ',');
            getline(ss, existingName, ',');
            getline(ss, existingEmail, ',');
            getline(ss, existingClass, ',');
            getline(ss, existingPassword);

            // Check if the username matches
            if (existingUsername == username)
                {
                // Write updated profile data
                outputFile << username << ","
                           << (newName.empty() ? existingName : newName) << ","
                           << (newEmail.empty() ? existingEmail : newEmail) << ","
                           << (newClass.empty() ? existingClass : newClass) << ","
                           << (newPassword.empty() ? existingPassword : newPassword) << endl;
            }
            else
            {
                // Write the existing profile data unchanged
                outputFile << line << endl;
            }

        }
        inputFile.close();
        outputFile.close();

        // Replace the old file with the updated file
        remove("user_profile.txt");
        rename("temp.txt", "user_profile.txt");
    }
    else
    {
        cout << "Error opening files!" << endl;
    }
}



// Function to delete user profile from file


bool deleteUserProfileFromFile(const string &username) {
    vector<string> userProfiles;
    loadUserProfiles(userProfiles);

    bool userFound = false; // Flag to track if the username is found
    ofstream file("user_profile.txt", ios::trunc);

    if (file.is_open()) {
        for (const auto &profile : userProfiles) {
            stringstream ss(profile);
            string existingUsername;
            getline(ss, existingUsername, ',');
            if (existingUsername != username) {
                file << profile << endl;
            } else {
                userFound = true; // Set the flag if the username is found
            }
        }
        file.close();
    } else {
        cout << "Error deleting user profile!" << endl;
        return false;
    }

    return userFound; // Return true if the username was found and deleted, else false
}


// Function to update feedback in file

void updateFeedbackInFile(const string &username, const unordered_map<string, int> &ratings, const string &suggestions)
{
    vector<string> feedbackHistory;
    loadFeedbackHistory(feedbackHistory);

    ofstream file("feedback.txt", ios::trunc);
    if (file.is_open())
        {
        for (const auto &feedback : feedbackHistory)
        {
            if (feedback.find("Username: " + username) != string::npos)
            {
                file << "Username: " << username << endl;
                for (const auto &rating : ratings)
                {
                    file << rating.first << " Rating: " << rating.second << "/10" << endl;
                }
                file << "Suggestions: " << suggestions << endl;
                file << "----------------------------------------" << endl;
            }
    else
            {
                file << feedback << endl;
            }
        }
        file.close();

    }
    else
    {
        cout << "Error updating feedback!" << endl;
    }

}

// Function to clear feedback by username

void clearFeedbackByUsername(const string &username)
{
    vector<string> feedbackHistory;
    loadFeedbackHistory(feedbackHistory);
    ofstream file("feedback.txt", ios::trunc);
    if (file.is_open())
        {
        for (const auto &feedback : feedbackHistory)
        {
            if (feedback.find("Username: " + username) == string::npos)
            {
                file << feedback << endl;
            }
        }
        file.close();
        cout << "Feedback for user '" << username << "' cleared successfully!" << endl;
    }
    else
    {
        cout << "Error clearing feedback!" << endl;
    }

}


// Function to view user performance

void viewUserPerformance(const string &username)
{
    vector<int> scores;
    ifstream scoreFile("user_scores.txt");
    if (scoreFile.is_open())
        {
        string line;
        while (getline(scoreFile, line))
        {
            if (line.find("Username: " + username) != string::npos)
            {

                size_t pos = line.find("Marks: ");
                if (pos != string::npos)
                {
                    int score = stoi(line.substr(pos + 7));
                    scores.push_back(score);
                }
            }
        }
        scoreFile.close();
        displayPerformanceSummary(username, scores);
    }
    else
    {
        cout << "Error reading performance data!" << endl;
    }
}

// Function to view all feedback

void viewAllFeedback()
{
    vector<string> feedbackHistory;
    loadFeedbackHistory(feedbackHistory);
    displayHeader("All Feedback");

    for (const auto &feedback : feedbackHistory)
        {
        cout << feedback << endl;
    }
    cout << "Press any key to continue...";
    _getch();

}


// Function to view user feedback

void viewUserFeedback(const string &username)
{
    vector<string> feedbackHistory;
    loadFeedbackHistory(feedbackHistory);
    displayHeader("Feedback for " + username);
    for (const auto &feedback : feedbackHistory)
        {
        if (feedback.find("Username: " + username) != string::npos)
        {
            cout << feedback << endl;
        }
    }
    cout << "Press any key to continue...";
    _getch();

}

// Function to update user password

void updateUserPassword(const string &username, const string &newPassword)
{
    vector<string> userProfiles;
    loadUserProfiles(userProfiles);
    ofstream file("user_profile.txt", ios::trunc);

    if (file.is_open())
        {
        for (const auto &profile : userProfiles)
        {
            stringstream ss(profile);
            string existingUsername;
            string existingName;
        string existingEmail;
        string  existingClass;
        string existingPassword;
            getline(ss, existingUsername, ',');
            if (existingUsername == username)
            {
                file << username << "," << existingName << "," << existingEmail << "," << existingClass << "," << newPassword << endl;
            }
             else
            {
                file << profile << endl;
            }
        }
        file.close();
        cout << "User  password updated successfully!" << endl;
    }
     else
    {
        cout << "Error updating user password!" << endl;
    }

}


// Function to display user profile

void displayUserProfile(const string &username)
{
    vector<string> userProfiles;
    loadUserProfiles(userProfiles);

    for (const auto &profile : userProfiles)
        {
        stringstream ss(profile);
        string existingUsername;
        string existingName;
        string existingEmail;
        string  existingClass;
        string existingPassword;
        getline(ss, existingUsername, ',');

        if (existingUsername == username)
        {
            cout << "Username: " << existingUsername << endl;
            cout << "Name: " << existingName << endl;
            cout << "Email: " << existingEmail << endl;
            cout << "Class: " << existingClass << endl;
            cout << "Password: " << existingPassword << endl;
            break;
        }
    }

}


// Function to display all user profiles

void displayAllUserProfiles()
{
    vector<string> userProfiles;
    loadUserProfiles(userProfiles);
    displayHeader("All User Profiles");

    for (const auto &profile : userProfiles)
        {
        cout << profile << endl;
    }
    cout << "Press any key to continue...";

    _getch();
}


// Function to display feedback history for user

void displayFeedbackHistoryForUser  (const string &username)
{
    vector<string> feedbackHistory;
    loadFeedbackHistory(feedbackHistory);

    displayHeader("Feedback History for " + username);
    for (const auto &feedback : feedbackHistory)
    {
        if (feedback.find("Username: " + username) != string::npos)
        {

            cout << feedback << endl;
        }
    }
    cout << "Press any key to continue...";
    _getch();

}

// Function to display performance data for user

void displayPerformanceDataForUser  (const string &username)
{
    vector<string> performanceData;
    loadPerformanceData(performanceData);

    displayHeader("Performance Data for " + username);
    for (const auto &data : performanceData)
        {
        if (data.find("Username: " + username) != string::npos)
        {
            cout << data << endl;
        }
    }
    cout << "Press any key to continue...";
    _getch();

}


// Function to display all performance data

void displayAllPerformanceData()
{
    vector<string> performanceData;
    loadPerformanceData(performanceData);
    displayHeader("All Performance Data");

    for (const auto &data : performanceData)
        {
        cout << data << endl;
    }
    cout << "Press any key to continue...";
    _getch();

}


// Function to save all user profiles

void saveAllUserProfiles(const vector<string> &userProfiles)
{
    ofstream file("user_profile.txt", ios::trunc);

    if (file.is_open())
        {
        for (const auto &profile : userProfiles)
        {
            file << profile << endl;
        }
        file.close();

    }
     else
    {
        cout << "Error saving all user profiles!" << endl;
    }

}


// Function to save all feedback

void saveAllFeedback(const vector<string> &feedbackHistory)
{
    ofstream file("feedback.txt", ios::trunc);
    if (file.is_open())
        {
        for (const auto &feedback : feedbackHistory)
        {
            file << feedback << endl;
        }
        file.close();

    }
     else
    {
        cout << "Error saving all feedback!" << endl;
    }

}


// Function to save all performance data

void saveAllPerformanceData(const vector<string> &performanceData)
{
    ofstream file("user_scores.txt", ios::trunc);
    if (file.is_open())
        {
        for (const auto &data : performanceData)
        {
            file << data << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error saving all performance data!" << endl;
    }

}


// Function to load all user profiles

void loadAllUserProfiles(vector<string> &userProfiles)
{
    ifstream file("user_profile.txt");
    string line;

    while (getline(file, line))
        {
        userProfiles.push_back(line);
    }
    file.close();
}


// Function to load all feedback

void loadAllFeedback(vector<string> &feedbackHistory)
{
    ifstream file("feedback.txt");
    string line;

    while (getline(file, line))
        {
        feedbackHistory.push_back(line);
    }
    file.close();

}


// Function to load all performance data

void loadAllPerformanceData(vector<string> &performanceData)
{
    ifstream file("user_scores.txt");
    string line;

    while (getline(file, line))
        {
        performanceData.push_back(line);
    }
    file.close();

}

// Function to collect user details for update

void collectUserDetailsForUpdate(string &username, string &newName, string &newEmail, string &newClass, string &newPassword)
{
    cout << "Enter new name (leave blank to keep unchanged): ";
    cin.ignore();
    getline(cin, newName);

    cout << "Enter new email (leave blank to keep unchanged): ";
    getline(cin, newEmail);

    cout << "Enter new class (leave blank to keep unchanged): ";
    getline(cin, newClass);

    cout << "Enter new password (leave blank to keep unchanged): ";
    newPassword = hidePassword();

}


// Function to collect feedback details for update
void collectFeedbackDetailsForUpdate(string &username, unordered_map<string, int> &ratings, string &suggestions)
{
    cout << "Enter username for feedback: ";
    cin >> username;
    string categories[] = {"Content", "Test", "Presentation", "Usability"};
    for (const auto &category : categories)
        {
        int rating;
        cout << "Rate " << category << " (0-10): ";
        cin >> rating;
        ratings[category] = rating;
    }
    cout << "Any suggestions? ";
    cin.ignore();
    getline(cin, suggestions);
}



// Function to display the feedback summary for a user
void displayFeedbackSummaryForUser(const string &username, const unordered_map<string, int> &ratings, const string &suggestions)
{
    // Display the header with the username
    cout << "Feedback Summary for " << username << endl;

    // Loop through the ratings unordered map and display each category and its rating
    for (const auto &rating : ratings)
    {
        // Output the category name and the associated rating score
        cout << rating.first << ": " << rating.second << "/10" << endl;
    }

    // Display the suggestions provided for the user
    cout << "Suggestions: " << suggestions << endl;
}



// Function to display performance summary for user

// void displayPerformanceSummaryForUser (const string &username, const vector<int> &scores)
// {
//     cout << "Performance Summary for " << username << endl;
//     for (int score : scores)
//         {
//         cout << "Score: " << score << endl;
//     }

// }


// Function to sort student performance data based on scores in descending order
void sortPerformanceDataForUser(vector<pair<string, double>> &studentScores)
{
    // Sort the studentScores vector using a lambda function to compare the second element (score) in the pairs
    sort(studentScores.begin(), studentScores.end(), [](const pair<string, double> &a, const pair<string, double> &b) {
        return a.second > b.second; // Sort in descending order of scores (higher scores come first)
    });
}




// Function to display the performance board for users
void displayPerformanceBoardForUser(const vector<pair<string, double>> &studentScores)
{
    // Display the header for the performance board
    cout << "Performance Board" << endl;

    // Loop through the studentScores vector and display each student's username and average score
    for (const auto &student : studentScores)
    {
        // Print the username and corresponding average score
        cout << "Username: " << student.first << " | Average Score: " << student.second << endl;
    }
}





// Function to update a user's profile in the user profile file
void updateUserProfileInFileForAdmin(const string &username, const string &newName, const string &newEmail, const string &newClass, const string &newPassword)
{
    // Vector to store all user profiles
    vector<string> userProfiles;

    // Load all user profiles from the user profile file into the vector
    loadAllUserProfiles(userProfiles);

    // Open the user profile file in truncation mode to overwrite the existing content
    ofstream file("user_profile.txt", ios::trunc);

    // Check if the file is opened successfully
    if (file.is_open())
    {
        // Loop through each user profile in the vector
        for (const auto &profile : userProfiles)
        {
            // Use a stringstream to extract the username and other profile details
            stringstream ss(profile);
            string existingUsername;
            string existingName;
            string existingEmail;
            string existingClass;
            string existingPassword;

            // Extract the existing username from the profile
            getline(ss, existingUsername, ',');

            // If the username matches the one to update, update the profile
            if (existingUsername == username)
            {
                // If new values are provided, they are used; otherwise, keep the existing values
                file << username << ","
                     << (newName.empty() ? existingName : newName) << ","
                     << (newEmail.empty() ? existingEmail : newEmail) << ","
                     << (newClass.empty() ? existingClass : newClass) << ","
                     << (newPassword.empty() ? existingPassword : newPassword) << endl;
            }
            else
            {
                // If the username does not match, write the existing profile to the file
                file << profile << endl;
            }
        }

        // Close the file after processing
        file.close();
    }
    else
    {
        // If the file cannot be opened, display an error message
        cout << "Error updating user profile!" << endl;
    }
}



// Function to delete user profile from file for admin

// Function to delete a user profile from the user profile file based on the username
void deleteUserProfileFromFileForAdmin(const string &username)
{
    // Vector to store all user profiles
    vector<string> userProfiles;

    // Load all user profiles from the user profile file into the vector
    loadAllUserProfiles(userProfiles);

    // Open the user profile file in truncation mode, which clears the existing content
    ofstream file("user_profile.txt", ios::trunc);

    // Check if the file is opened successfully
    if (file.is_open())
    {
        // Loop through each user profile in the vector
        for (const auto &profile : userProfiles)
        {
            // Use a stringstream to extract the username from the profile
            stringstream ss(profile);
            string existingUsername;
            getline(ss, existingUsername, ',');  // Extract the username (before the first comma)

            // If the username does not match the one to delete, write the profile back to the file
            if (existingUsername != username)
            {
                file << profile << endl;
            }
        }

        // Close the file after processing
        file.close();
    }
    else
    {
        // If the file cannot be opened, display an error message
        cout << "Error deleting user profile!" << endl;
    }
}




// Function to update feedback for a specific user in the feedback file
void updateFeedbackInFileForAdmin(const string &username, const unordered_map<string, int> &ratings, const string &suggestions)
{
    // Vector to store all feedback history
    vector<string> feedbackHistory;

    // Load all existing feedback from the feedback file into the vector
    loadAllFeedback(feedbackHistory);

    // Open the feedback file in truncation mode, which clears the existing content
    ofstream file("feedback.txt", ios::trunc);

    // Check if the file opened successfully
    if (file.is_open())
    {
        // Loop through each feedback entry in the history
        for (const auto &feedback : feedbackHistory)
        {
            // Check if the current feedback belongs to the specified user
            if (feedback.find("Username: " + username) != string::npos)
            {
                // Write the new feedback information for the user
                file << "Username: " << username << endl;

                // Loop through the ratings map and write each rating to the file
                for (const auto &rating : ratings)
                {
                    file << rating.first << " Rating: " << rating.second << "/10" << endl;
                }

                // Write the suggestions provided for the user
                file << "Suggestions: " << suggestions << endl;

                // Add a separator line to distinguish feedback entries
                file << "----------------------------------------" << endl;
            }
            else
            {
                // For feedback entries not belonging to the user, keep the original feedback unchanged
                file << feedback << endl;
            }
        }

        // Close the file after processing the feedback updates
        file.close();
    }
    else
    {
        // If the file failed to open, display an error message
        cout << "Error updating feedback!" << endl;
    }
}




// Function to clear feedback for a specific user based on their username
void clearFeedbackByUsernameForAdmin(const string &username)
{
    // Vector to hold the feedback history
    vector<string> feedbackHistory;

    // Load all feedback from the feedback file
    loadAllFeedback(feedbackHistory);

    // Open the feedback file in write mode and truncate it (delete the existing content)
    ofstream file("feedback.txt", ios::trunc);

    // Check if the file is successfully opened
    if (file.is_open())
    {
        // Loop through each feedback entry in the history
        for (const auto &feedback : feedbackHistory)
        {
            // Check if the feedback does NOT belong to the specified user
            // If the username is not found in the feedback, keep the feedback
            if (feedback.find("Username: " + username) == string::npos)
            {
                // Write the feedback to the file
                file << feedback << endl;
            }
        }

        // Close the file after processing
        file.close();

        // Output a success message after clearing the feedback for the user
        cout << "Feedback for user '" << username << "' cleared successfully!" << endl;
    }
    else
    {
        // If there's an error opening the file, display an error message
        cout << "Error clearing feedback!" << endl;
    }
}



// Function to view user performance for admin

// void viewUserPerformanceForAdmin(const string &username)
// {
//     // Vector to store the scores for the specified user.
//     vector<int> scores;

//     // Open the user_scores.txt file to read performance data.
//     ifstream scoreFile("user_scores.txt");

//     // Check if the file is open and ready to be read.
//     if (scoreFile.is_open())
//     {
//         string line;
//         bool userFound = false;  // Flag to track if we find any data for the user.

//         // Loop through each line in the file to find records for the given username.
//         while (getline(scoreFile, line))
//         {
//             // Check if the line contains the specified username.
//             if (line.find("Username: " + username) != string::npos)
//             {
//                 userFound = true; // Mark user as found.

//                 // Find the position where the "Marks: " string starts.
//                 size_t pos = line.find("Marks: ");

//                 // If "Marks: " is found in the line, extract the score.
//                 if (pos != string::npos)
//                 {
//                     try {
//                         // Extract the score (after "Marks: ") and convert it to an integer.
//                         int score = stoi(line.substr(pos + 7));

//                         // Add the extracted score to the vector.
//                         scores.push_back(score);
//                     }
//                     catch (const invalid_argument& e) {
//                         // Handle case where score is not a valid integer.
//                         cout << "Error: Invalid score format in performance data." << endl;
//                     }
//                 }
//             }
//         }

//         // Close the file after reading.
//         scoreFile.close();

//         // If user data was found, display the performance summary.
//         if (userFound) {
//             displayPerformanceSummaryForUserA(username, scores);
//         } else {
//             cout << "No performance data found for user " << username << "." << endl;
//             cout << GREEN << "enter any key to return menu..." << endl;
//             _getch();
//         }
//     }
//     else
//     {
//         // If the file could not be opened, display an error message.
//         cout << "Error reading performance data!" << endl;
//     }
// }


// Function to view all feedback for admin

void viewAllFeedbackForAdmin()
{
    // Declare a vector to store all feedback history.
    vector<string> feedbackHistory;

    // Load all feedback records from an external function.
    loadAllFeedback(feedbackHistory);

    // Display the header to indicate that this is the admin's feedback view.
    displayHeader("All Feedback for Admin");

    // Iterate through all feedback records in the loaded feedback history.
    for (const auto &feedback : feedbackHistory)
    {
        // Display each feedback record.
        cout << feedback << endl;
    }

    // After displaying all feedback, prompt the admin to press any key to continue.
    cout << "Press any key to continue...";

    // Wait for the user to press a key before continuing.
    _getch();  // _getch() is used to pause execution until a key is pressed (works in Windows environments).
}


// Function to view user feedback for admin

void viewUserFeedbackForAdmin(const string &username)
{
    // Declare a vector to store all feedback history.
    vector<string> feedbackHistory;

    // Load all feedback records from an external function.
    loadAllFeedback(feedbackHistory);

    // Display the header indicating this is the admin view of feedback for the user.
    displayHeader("Feedback for " + username + " (Admin View)");

    // Iterate through all feedback records.
    for (const auto &feedback : feedbackHistory)
    {
        // Check if the feedback contains the username (to filter feedback for that user).
        if (feedback.find("Username: " + username) != string::npos)
        {
            // If the username matches, print the feedback record.
            cout << feedback << endl;
        }
    }

    // Wait for the user to press any key to continue.
    cout << "Press any key to continue...";
    _getch();  // Assuming _getch() is used for pausing the execution until a key is pressed.
}


// Function to update user password for admin

void updateUserPasswordForAdmin(const string &username, const string &newPassword)
{
    // Declare a vector to store all user profiles.
    vector<string> userProfiles;

    // Load all user profiles from the file using an external function.
    loadAllUserProfiles(userProfiles);

    // Open the file to save the updated profiles, using truncation to overwrite.
    ofstream file("user_profile.txt", ios::trunc);

    // Check if the file was successfully opened.
    if (file.is_open())
    {
        // Iterate through each user profile in the vector.
        for (const auto &profile : userProfiles)
        {
            // Create a stringstream to parse the profile string.
            stringstream ss(profile);

            // Variables to hold the profile fields.
            string existingUsername;
            string existingName;
            string existingEmail;
            string existingClass;
            string existingPassword;

            // Extract fields from the profile string.
            getline(ss, existingUsername, ',');
            getline(ss, existingName, ',');
            getline(ss, existingEmail, ',');
            getline(ss, existingClass, ',');
            getline(ss, existingPassword, ',');

            // If the current profile's username matches the one being updated.
            if (existingUsername == username)
            {
                // Write the updated profile with the new password to the file.
                file << existingUsername << "," << existingName << "," << existingEmail << "," << existingClass << "," << newPassword << endl;
            }
            else
            {
                // Otherwise, write the profile without changes.
                file << profile << endl;
            }
        }

        // Close the file after saving the changes.
        file.close();

        // Notify the admin that the password has been updated successfully.
        cout << "User password updated successfully!" << endl;
    }
    else
    {
        // If the file could not be opened, print an error message.
        cout << "Error updating user password!" << endl;
    }
}


// Function to display user profile for admin

void displayUserProfileForAdmin(const string &username)
{
    // Declare a vector to store all user profiles.
    vector<string> userProfiles;

    // Load all user profiles into the vector using an external function.
    loadAllUserProfiles(userProfiles);

    // Iterate through each user profile in the vector.
    for (const auto &profile : userProfiles)
    {
        // Create a stringstream to parse the profile string.
        stringstream ss(profile);

        // Variables to hold profile fields.
        string existingUsername;
        string existingName;
        string existingEmail;
        string existingClass;
        string existingPassword;

        // Extract profile fields separated by commas.
        getline(ss, existingUsername, ',');
        getline(ss, existingName, ',');
        getline(ss, existingEmail, ',');
        getline(ss, existingClass, ',');
        getline(ss, existingPassword, ',');

        // Check if the extracted username matches the target username.
        if (existingUsername == username)
        {
            // Display user profile details.
            cout << "Username: " << existingUsername << endl;
            cout << "Name: " << existingName << endl;
            cout << "Email: " << existingEmail << endl;
            cout << "Class: " << existingClass << endl;
            cout << "Password: " << existingPassword << endl;
            return; // Exit the function once the profile is found and displayed.
        }
    }

    // If no matching profile is found, display a message.
    cout << "User profile with username '" << username << "' not found." << endl;
}

// Function to display all user profiles for admin

void displayAllUserProfilesForAdmin()
{
    // Declare a vector to store all user profiles.
    vector<string> userProfiles;

    // Load all user profiles into the vector using an external function.
    loadAllUserProfiles(userProfiles);

    // Display a header indicating the start of user profile data display.
    displayHeader("All User Profiles (Admin View)");

    // Iterate through each entry in the userProfiles vector.
    for (const auto &profile : userProfiles)
    {
        // Print each user profile entry to the console.
        cout << profile << endl;
    }

    // Prompt the admin to press any key before exiting the function.
    cout << "Press any key to continue...";

    // Wait for a key press to allow the admin to review the data.
    _getch();
}


// Function to display feedback history for user for admin

void displayFeedbackHistoryForUserForAdmin(const string &username)
{
    // Declare a vector to store all feedback history.
    vector<string> feedbackHistory;

    // Load all feedback history into the vector using an external function.
    loadFeedbackHistory(feedbackHistory);

    // Display a header indicating whose feedback history is being shown.
    displayHeader("Feedback History for " + username + " (Admin View)");

    // Iterate through each entry in the feedbackHistory vector.
    for (const auto &feedback : feedbackHistory)
    {
        // Check if the current feedback entry contains the specified username.
        if (feedback.find("Username: " + username) != string::npos)
        {
            // If the username is found in the feedback entry, print it.
            cout << feedback << endl;
        }
    }

    // Prompt the admin to press any key before exiting the function.
    cout << "Press any key to continue...";

    // Wait for a key press to allow the admin to review the data.
    _getch();
}


// Function to display performance data for user for admin

void displayPerformanceDataForUserForAdmin(const string &username)
{
    // Declare a vector to store all performance data.
    vector<string> performanceData;

    // Load all performance data into the vector using an external function.
    loadPerformanceData(performanceData);

    // Display a header indicating whose performance data is being shown.
    displayHeader("Performance Data for " + username + " (Admin View)");

    // Iterate through each entry in the performanceData vector.
    for (const auto &data : performanceData)
    {
        // Check if the current data entry contains the specified username.
        if (data.find("Username: " + username) != string::npos)
        {
            // If the username is found in the entry, print the entry.
            cout << data << endl;
        }
    }

    // Prompt the admin to press any key before exiting the function.
    cout << "Press any key to continue...";

    // Wait for a key press to allow the admin to review the data.
    _getch();
}

// Function to display all performance data for admin

void displayAllPerformanceDataForAdmin()
{
    // Declare a vector to store performance data.
    vector<string> performanceData;

    // Load performance data into the vector using an external function.
    loadPerformanceData(performanceData);

    // Display a header to indicate the start of performance data display.
    displayHeader("All Performance Data (Admin View)");

    // Iterate through each entry in the performanceData vector.
    for (const auto &data : performanceData)
    {
        // Print each performance data entry to the console.
        cout << data << endl;
    }

    // Prompt the admin to press any key before exiting the function.
    cout << "Press any key to continue...";

    // Wait for a key press to allow the admin to review the data.
    _getch();
}



// Function to save all user profiles for admin

void saveAllUserProfilesForAdmin(const vector<string> &userProfiles)
{
    // Open the file "user_profile.txt" in truncation mode.
    // ios::trunc clears the file contents if it already exists.
    ofstream file("user_profile.txt", ios::trunc);

    // Check if the file was successfully opened.
    if (file.is_open())
    {
        // Iterate through each string in the userProfiles vector.
        for (const auto &profile : userProfiles)
        {
            // Write each profile entry to the file,
            // followed by a newline.
            file << profile << endl;
        }

        // Close the file to ensure all data is properly saved
        // and system resources are released.
        file.close();
    }
    else
    {
        // If the file could not be opened, print an error message.
        cout << "Error saving all user profiles!" << endl;
    }
}

// Function to save all feedback for admin

void saveAllFeedbackForAdmin(const vector<string> &feedbackHistory)
{
    // Open the file "feedback.txt" in truncation mode.
    // ios::trunc ensures that the file is cleared if it already exists.
    ofstream file("feedback.txt", ios::trunc);

    // Check if the file was successfully opened.
    if (file.is_open())
    {
        // Iterate through each string in the feedbackHistory vector.
        for (const auto &feedback : feedbackHistory)
        {
            // Write each feedback entry to the file,
            // followed by a newline.
            file << feedback << endl;
        }

        // Close the file to ensure all data is saved properly
        // and system resources are released.
        file.close();
    }
    else
    {
        // If the file could not be opened, print an error message.
        cout << "Error saving all feedback!" << endl;
    }
}


// Function to save all performance data for admin

void saveAllPerformanceDataForAdmin(const vector<string> &performanceData)
{
    // Open the file "user_scores.txt" in truncation mode.
    // ios::trunc ensures that the file is cleared if it already exists.
    ofstream file("user_scores.txt", ios::trunc);

    // Check if the file is successfully opened.
    if (file.is_open())
    {
        // Iterate through each string in the performanceData vector.
        for (const auto &data : performanceData)
        {
            // Write each string (performance data) to the file,
            // followed by a newline.
            file << data << endl;
        }

        // Close the file to ensure all data is saved properly
        // and resources are released.
        file.close();
    }
    else
    {
        // If the file could not be opened, print an error message.
        cout << "Error saving all performance data!" << endl;
    }
}


// Function to load all user profiles for admin

void loadAllUserProfilesForAdmin(vector<string> &userProfiles)
{
    // Open the file "user_profile.txt" in read mode.
    ifstream file("user_profile.txt");

    // Check if the file was successfully opened.
    if (!file.is_open())
    {
        cout << "Error opening user profiles file!" << endl;
        return;
    }

    string line; // Temporary variable to store each line from the file.

    // Read the file line by line.
    while (getline(file, line))
    {
        // Add each line (user profile) to the vector.
        userProfiles.push_back(line);
    }

    // Close the file to free system resources.
    file.close();
}

// Function to load all feedback for admin

void loadAllFeedbackForAdmin(vector<string> &feedbackHistory)
{
    // Open the file "feedback.txt" in read mode.
    ifstream file("feedback.txt");

    // Check if the file was successfully opened.
    if (!file.is_open())
    {
        cout << "Error opening feedback file!" << endl;
        return;
    }

    string line; // Temporary variable to store each line from the file.

    // Read the file line by line.
    while (getline(file, line))
    {
        // Add each line (feedback entry) to the vector.
        feedbackHistory.push_back(line);
    }

    // Close the file to free system resources.
    file.close();
}


// Function to load all performance data for admin

void loadAllPerformanceDataForAdmin(vector<string> &performanceData)
{
    ifstream file("user_scores.txt");
    string line;
    while (getline(file, line))
        {
        performanceData.push_back(line);
    }

    file.close();
}


// Main function to run the admin menu



