#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


vector<string> split_into_3(string num) {
    //add zeroes in front of num to make printing easier
    int num_cur_length = num.length();
    if (num_cur_length % 3 > 0) {
        for (int i = 0; i < 3 - (num_cur_length % 3); i++) {
            num = "0" + num;
        }
    }

    //actual splitting
    vector<string> list_of_split_num;
    for (int i = num.length()-1; i >= 0; i -= 3) {
        if (num.length() <= 3) {
            list_of_split_num.push_back(num);
        } else {
            //cout << "i: " << i << endl;
            list_of_split_num.push_back(num.substr(i - 2, 3));
        }
    }
    return list_of_split_num;
}

string get_3num_to_str(string three_num) {
    //unordered maps of ones, teens, and tens words
    unordered_map<int, string> ones_list = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};
    unordered_map<int, string> teens_list = {{0, "ten"}, {1, "eleven"}, {2, "twelve"}, {3, "thirteen"}, {4, "fourteen"}, {5, "fifteen"}, {6, "sixteen"}, {7, "seventeen"}, {8, "eighteen"}, {9, "nineteen"}};
    unordered_map<int, string> tens_list = {{2, "twenty"}, {3, "thirty"}, {4, "forty"}, {5, "fifty"}, {6, "sixty"}, {7, "seventy"}, {8, "eighty"}, {9, "ninety"}};
    string building_str;
    string num = three_num;

    //building the string itself
    if(num.length() > 3) {
        return "error";
    }
    if((int)num[0] - 48 > 0) {
        building_str += ones_list[(int)num[0] - 48] + " hundred ";
    }
    if((int)num[1] - 48 > 0) {
        if (stoi(num.substr(1, 2)) >= 10 && stoi(num.substr(1, 2)) < 20) {
            building_str += teens_list[(int)num[2] - 48] + " ";
            return building_str;
        } else {
            building_str += tens_list[(int)num[1] - 48] + " ";
        }
    }
    if((int)num[2] - 48 > 0) {
        building_str += ones_list[(int)num[2] - 48] + " ";
    }
    return building_str;
}

string num_to_word(string num) {
    //all suffixes of thousands + -illions
    unordered_map<int, string> power_of_tens_list = {{1, ""}, {2, "thousand"}, {3, "million"}, {4, "billion"}, {5, "trillion"}, {6, "quadrillion"}, {7, "quintillion"}, {8, "sextillion"}, {9, "septillion"}, {10, "octillion"}, {11, "nonillion"}, {12, "decillion"}};
    vector<string> split_num = split_into_3(num);
    string final_string;

    //looping through the split string backwards and adding the suffix if needed
    for (int i = split_num.size() - 1; i >= 0; i--) {
        final_string += get_3num_to_str(split_num[i]) + power_of_tens_list[i + 1] + " ";
    }

    return final_string;
}

int main() {
    string num;
    cout << "Input a number: " << endl;
    getline(cin, num);
    cout << num_to_word(num) << endl;

    return 0;
}
