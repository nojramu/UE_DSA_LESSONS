#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <chrono>
#include <sstream>

using namespace std;

class Attendance {
public:
    string studentName;
    bool present;
    string timeOfAttendance;

    Attendance(const string& name, bool isPresent, const string& time)
        : studentName(name), present(isPresent), timeOfAttendance(time) {}
};

class AttendanceEngine {
private:
    vector<Attendance> records;

    string getCurrentTime() {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        stringstream ss;
        ss << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

public:
    void markAttendanceFromList(const vector<string>& names) {
        string input;
        for (const auto& name : names) {
            while (true) {
                cout << "Is " << name << " present? (y/n): ";
                getline(cin, input);
                if (input.length() == 1 && (input[0] == 'y' || input[0] == 'Y' || input[0] == 'n' || input[0] == 'N')) {
                    break;
                } else {
                    cout << "Invalid input. Please enter a single 'y' or 'n'.\n";
                }
            }
            bool isPresent = (input[0] == 'y' || input[0] == 'Y');
            records.push_back(Attendance(name, isPresent, getCurrentTime()));
        }
    }

    void exportToCSV(const string& filename) {
        string outFilename = filename;
        // Ensure the filename ends with ".csv"
        if (outFilename.length() < 4 || outFilename.substr(outFilename.length() - 4) != ".csv") {
            outFilename += ".csv";
        }
        ofstream file(outFilename.c_str());
        if (file.is_open()) {
            file << "Student Name,Present,Time of Attendance\n";
            for (const auto& rec : records) {
                file << '"' << rec.studentName << "\","
                     << (rec.present ? "Yes" : "No") << ","
                     << '"' << rec.timeOfAttendance << "\"\n";
            }
            file.close();
            cout << "Data exported successfully to '" << outFilename << "'.\n";
        } else {
            cerr << "Error: Unable to open file '" << outFilename << "' for writing.\n";
        }
    }

    void printStatistics() {
        int total = records.size();
        int presentCount = 0;
        for (const auto& rec : records) {
            if (rec.present) presentCount++;
        }
        int absentCount = total - presentCount;
        double percentPresent = total > 0 ? (100.0 * presentCount / total) : 0.0;

        cout << "\nAttendance Statistics:\n";
        cout << "---------------------\n";
        cout << "Total students: " << total << "\n";
        cout << "Present:        " << presentCount << "\n";
        cout << "Absent:         " << absentCount << "\n";
        cout << fixed << setprecision(2);
        cout << "Percentage present: " << percentPresent << "%\n";
    }
};

vector<string> readNamesFromCSV(const string& filename) {
    vector<string> names;
    ifstream file(filename.c_str());
    string line;
    while (getline(file, line)) {
        // Skip empty lines and possible header
        if (line.empty()) continue;
        // If the file has a header, skip it
        if (line.find("Student Name") != string::npos) continue;
        // Remove possible carriage return
        if (!line.empty() && line.back() == '\r') line.pop_back();
        names.push_back(line);
    }
    return names;
}

int main() {
    AttendanceEngine engine;
    string inputFilename = "attendance.csv";
    string outputFilename;

    cout << "Attendance Marking System\n";
    cout << "Reading names from '" << inputFilename << "'...\n";

    vector<string> names = readNamesFromCSV(inputFilename);
    if (names.empty()) {
        cout << "No names found in '" << inputFilename << "'. Exiting.\n";
        return 1;
    }

    cout << "Enter filename to export attendance (e.g., attendance_marked.csv): ";
    getline(cin, outputFilename);

    engine.markAttendanceFromList(names);
    engine.exportToCSV(outputFilename);

    engine.printStatistics();

    cout << "Thank you for using the Attendance Marking System.\n";
    return 0;
}