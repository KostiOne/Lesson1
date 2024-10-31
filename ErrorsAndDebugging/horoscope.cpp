#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string toLower(string month) {
    string _month = month;
    transform(_month.begin(), _month.end(), _month.begin(), ::tolower);
    return _month;
}

int getMonthNumber(const string& month) {
    string lowerMonth = toLower(month);
    if (lowerMonth == "january") return 1;
    if (lowerMonth == "february") return 2;
    if (lowerMonth == "march") return 3;
    if (lowerMonth == "april") return 4;
    if (lowerMonth == "may") return 5;
    if (lowerMonth == "june") return 6;
    if (lowerMonth == "july") return 7;
    if (lowerMonth == "august") return 8;
    if (lowerMonth == "september") return 9;
    if (lowerMonth == "october") return 10;
    if (lowerMonth == "november") return 11;
    if (lowerMonth == "december") return 12;
    return 0;
}

string detectZodiacSign(int day, int month) {
    switch (month) {
    case 1:  return (day <= 19) ? "Capricorn" : "Aquarius";
    case 2:  return (day <= 18) ? "Aquarius" : "Pisces";
    case 3:  return (day <= 20) ? "Pisces" : "Aries";
    case 4:  return (day <= 19) ? "Aries" : "Taurus";
    case 5:  return (day <= 20) ? "Taurus" : "Gemini";
    case 6:  return (day <= 20) ? "Gemini" : "Cancer";
    case 7:  return (day <= 22) ? "Cancer" : "Leo";
    case 8:  return (day <= 22) ? "Leo" : "Virgo";
    case 9:  return (day <= 22) ? "Virgo" : "Libra";
    case 10: return (day <= 22) ? "Libra" : "Scorpio";
    case 11: return (day <= 21) ? "Scorpio" : "Sagittarius";
    case 12: return (day <= 21) ? "Sagittarius" : "Capricorn";
    default: return "Unknown sign";
    }
}

void showRandomHoroscope() {
    vector<string> horoscopes = {
        "Today is your day for new discoveries!",
        "Luck will be on your side; make use of it!",
        "Pay attention to your relationships with loved ones.",
        "An interesting meeting awaits you.",
        "Today is favorable for work-related matters.",
        "A new idea will come to you, changing your perspective.",
        "Rest and recharge – a significant event is coming soon.",
        "Your efforts today will yield great results."
    };

    // Initialize random number generator
    srand(time(nullptr));
    int randomIndex = rand() % horoscopes.size();
    cout << horoscopes[randomIndex] << endl;
}

int main() {
    int day;
    string month;

    cout << "Enter your birth month (e.g., April): ";
    getline(cin, month);
    cout << "Enter your birth day: ";
    cin >> day;

    int monthNumber = getMonthNumber(month);
    if (monthNumber == 0) {
        cout << "Invalid month input." << endl;
        return 1;
    }

    string zodiacSign = detectZodiacSign(day, monthNumber);
    cout << "Your zodiac sign: " << zodiacSign << endl;
    cout << "Your horoscope: ";
    showRandomHoroscope();

    return 0;
}