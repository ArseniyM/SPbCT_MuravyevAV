using namespace std;

string& replace_all(string& str, string Old, string New) {
    for (string::size_type pos(0); pos != string::npos; pos += New.length()) {
        if ((pos = str.find(Old, pos)) != string::npos) {
            str.replace(pos, Old.length(), New);
        }
        else break;
    }
    return str;
}