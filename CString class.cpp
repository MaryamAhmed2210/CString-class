#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class CString
{
private:
    char *str;
    int size;

 
    int length(const char* s) const;
    char* concatstr(const char * s, const char *a) const;
    CString concatstring(const CString &s, const CString &a) const;
    CString& copystring(const CString & s);
    void clear();

public:
   
    CString();
    CString(char a);
    CString(const char* s);
    CString(const CString &ref);
    ~CString();

    
    CString& operator=(const CString & ref);
    CString operator+(const CString & s2) const;
    CString operator+(const char* const s2) const;
    void operator+=(const CString & s2);
    void operator+=(const char* s2);
    char& operator[](int index);

 
    int getlength() const;
    void display() const;
    int find(const char* substr, int start = 0) const;
    int find(char ch, int start = 0) const;
    int insert(int index, const char* substr); 
    int insert(int index, char ch);
    CString left(int count) const;
    CString right(int count) const;
    int remove(int index, int count = 1);
    int remove(char ch);
    void replace(char New);
    int replace(char old, char New);
    int replace(const char* old, const char* New);
    void trim();
    void trimLeft();
    void trimRight();
    void makeUpper();
    void makeLower();
    void reverse(); 
    void Resize(int add);
    CString concat(const CString& s2) const;
    void concatEqual(const CString& s2);
    void concatEqual(const char * s2);
    int isEqual(const CString & s2) const;
    int isEqual(const char * s2) const;
    void input();
    char& at(int index);
    int isEmpty();

 
    friend ostream &operator<<(ostream& out, const CString &a);
};


void CString::clear()
{
    delete [] str;
    str = nullptr;
}

int CString::length(const char* s) const
{
    if (!s) return 0;
    int l = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        l++;
    }
    return l;
}

char* CString::concatstr(const char * s, const char *a) const
{
    int c = length(s);
    int b = length(a);
    char* r = new char[c + b + 1];
    int i;
    for (i = 0; i < c; i++) {
        r[i] = s[i];
    }
    for (int j = 0; j < b; j++) {
        r[i] = a[j];
        i++;
    }
    r[c + b] = '\0';
    return r;
}

CString CString::concatstring(const CString &s, const CString &a) const
{
    CString r;
    int c = length(s.str);
    int b = length(a.str);
    r.size = c + b + 1;
    delete[] r.str;
    r.str = new char[r.size];
    int i;
    for (i = 0; i < c; i++) {
        r.str[i] = s.str[i];
    }
    for (int j = 0; j < b; j++) {
        r.str[i] = a.str[j];
        i++;
    }
    r.str[c + b] = '\0';
    return r;
}

CString& CString::copystring(const CString & s)
{
    clear();
    size = s.size;
    str = new char[size + 1];
    int i;
    for (i = 0; i < size; i++) {
        str[i] = s.str[i];
    }
    str[size] = '\0';
    return *this;
}


CString::CString()
{
    size = 1;
    str = new char[size];
    str[0] = '\0';
}

CString::CString(char a)
{
    size = 2;
    str = new char[size];
    str[0] = a;
    str[1] = '\0';
}

CString::CString(const char* s)
{
    int a = length(s);
    size = a + 1;
    str = new char[size];
    int i;
    for (i = 0; i < a; i++) {
        str[i] = s[i];
    }
    str[a] = '\0';    
}


CString::CString(const CString &ref)
{
    size = ref.size;
    str = new char[size];
    strcpy(str, ref.str);
}   

CString::~CString()
{
    clear();
}


CString& CString::operator=(const CString & ref)
{
    if (this != &ref) {
        clear();
        copystring(ref);
    }
    return *this;
}

CString CString::operator+(const CString & s2) const
{
    return (concatstring(*this, s2));
}

CString CString::operator+(const char* const s2) const
{
    char* temp = concatstr(str, s2);
    CString res(temp);
    delete[] temp;
    return res;
}

void CString::operator+=(const CString & s2)
{
    *this = *this + s2;
}

void CString::operator+=(const char* s2)
{
    char* temp = concatstr(str, s2);
    clear();
    str = temp;
    size = length(str) + 1;
}

char& CString::operator[](int index)
{
    return str[index];
}


int CString::getlength() const
{
    return length(str);
}

void CString::display() const
{
    for (int i = 0; i < length(str); i++) {
        cout << str[i];
    }
}

int CString::find(const char* substr, int start) const
{
    int i, j;
    int len = length(str);
    for (i = start; i < len; i++) {
        for (j = 0; substr[j] != '\0'; j++) {
            if (str[i + j] != substr[j])
                break;
        }
        if (substr[j] == '\0')   
            return i;
    }
    return -1; 
}

int CString::find(char ch, int start) const
{
    int ls = length(str);
    for (int i = start; i < ls; i++) {
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
}

int CString::insert(int index, const char* substr) 
{
    int ls = length(str);
    int lsub = length(substr);
    int nsize = ls + lsub + 1;
    char *nstr = new char[nsize];
    for (int i = 0; i < index; i++) {
        nstr[i] = str[i];
    }
    for (int i = 0; i < lsub; i++) {
        nstr[index + i] = substr[i];
    }
    for (int i = index; i < ls; i++) {
        nstr[i + lsub] = str[i];
    }
    nstr[nsize - 1] = '\0';
    size = nsize;
    delete [] str;
    str = nstr;
    return length(str);
}

int CString::insert(int index, char ch)
{
    int ls = length(str);
    int nsize = ls + 2;
    if (index < 0 || index > ls)
        return -1;
    char *nstr = new char [nsize];
    for (int i = 0; i < index; i++) {  
        nstr[i] = str[i];
    }
    nstr[index] = ch;
    for (int i = index; i < ls; i++) {
        nstr[i + 1] = str[i];
    }
    nstr[nsize - 1] = '\0';
    size = nsize;
    delete [] str;
    str = nstr;
    return length(str);
}

CString CString::left(int count) const
{
    CString c;
    int len = length(str);
    if (count > len) { count = len; }
    if (count <= 0) { return c; }
    
    c.size = count + 1;
    delete[] c.str;
    c.str = new char [c.size];
    
    for (int i = 0; i < count; i++) {
        c.str[i] = str[i];
    }
    c.str[count] = '\0';
    return c;
}

CString CString::right(int count) const
{
    CString c;
    int l = length(str);
    if (count > l) { count = l; }
    if (count <= 0) { return c; }
    
    c.size = count + 1;
    delete[] c.str;
    c.str = new char [c.size];

    int j = l - count;
    for (int i = 0; i < count; i++) {
        c.str[i] = str[j];
        j++;
    }
    c.str[count] = '\0';
    return c;
}

int CString::remove(int index, int count) 
{
    int a = length(str);
    if (index < 0 || index >= a || count <= 0)
        return -1;
    if (index + count > a) count = a - index;
    
    for (int i = index; i < a - count; i++) {
        str[i] = str[i + count];
    }
    str[a - count] = '\0';
    size = a - count + 1;
    return length(str);
}

int CString::remove(char ch) 
{
    int a = length(str);
    int c = 0;
    int j = 0;
    for (int i = 0; i < a; i++) {
        if (str[i] == ch) {
            c++;
        } else {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    size = j + 1;
    return c;
}

void CString::replace(char New)
{
    for (int i = 0; i < length(str); i++) {
        str[i] = New;
    }
}

int CString::replace(char old, char New) 
{
    int c = 0;
    for (int i = 0; i < length(str); i++) {
        if (str[i] == old) {
            str[i] = New;
            c++;
        }
    }
    return c;
}

int CString::replace(const char* old, const char* New) 
{
    int lo = length(old);
    int ln = length(New);
    int pos = find(old);
    int c = 0;
    while (pos != -1) {
        remove(pos, lo);
        insert(pos, New);
        c++;
        pos = find(old, pos + ln);
    }
    return c;
}
 
void CString::trim() 
{
    int len = length(str);
    if (len == 0) return;
    int c = -1;
    int d = -1;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            c = i;
            break;
        }
    }
    for (int j = len - 1; j >= 0; j--) {
        if (str[j] != ' ') {
            d = j;
            break;
        }
    }
    if (c == -1) { 
        str[0] = '\0';
        return;
    }
    for (int i = c; i <= d; i++) {
        str[i - c] = str[i];
    }
    str[d - c + 1] = '\0';
}

void CString::trimLeft()
{
    int len = length(str);
    int c = -1;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            c = i;
            break;
        }
    }
    if (c == -1) {
        str[0] = '\0';
        return;
    }
    int i;
    for (i = c; i < len; i++) {
        str[i - c] = str[i];
    }
    str[len - c] = '\0';
}

void CString::trimRight()
{
    int n = length(str);
    int d = n - 1;
    while (d >= 0 && str[d] == ' ')
        d--;
    str[d + 1] = '\0';
}

void CString::makeUpper()
{
    for (int i = 0; i < length(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

void CString::makeLower()
{
    for (int i = 0; i < length(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

void CString::reverse() 
{
    int j = length(str) - 1;
    for (int i = 0; i < j; i++) {
        swap(str[i], str[j]);
        j--;    
    }
}

void CString::Resize(int add) 
{  
    int a = length(str);
    int nsize = size + add;
    char* nstr = new char[nsize];
    int i;
    for (i = 0; i < a; i++) {
        nstr[i] = str[i];
    }
    nstr[i] = '\0';
    size = nsize;
    delete[] str;
    str = nstr;
}

CString CString::concat(const CString& s2) const 
{
    return *this + s2; 
}

void CString::concatEqual(const CString& s2)
{
    *this += s2; 
}

void CString::concatEqual(const char * s2)
{
    *this += s2; 
}

int CString::isEqual(const CString & s2) const 
{
    int i = 0;
    while (str[i] != '\0' && s2.str[i] != '\0') {
        if (str[i] != s2.str[i])
            return str[i] - s2.str[i]; 
        i++;
    }
    return str[i] - s2.str[i];  
}

int CString::isEqual(const char * s2) const 
{
    int i = 0;
    while (str[i] != '\0' && s2[i] != '\0') {
        if (str[i] != s2[i]) {
            return str[i] - s2[i];  
        }
        i++;
    }
    return str[i] - s2[i];
}

void CString::input()
{
    cout << "enter size " << endl;
    cin >> size;
    delete[] str;
    str = new char [size + 1];
    for (int i = 0; i < size; i++) {
        cout << "enter char at " << i + 1 << endl;
        cin >> str[i];
    }
    str[size] = '\0';
}

char& CString::at(int index) 
{
    return str[index];
}

int CString::isEmpty() 
{
    if (str == nullptr || str[0] == '\0')
        return 0;
    else
        return -1;
}

ostream &operator<<(ostream& out, const CString &a)
{
    for (int i = 0; i < a.length(a.str); i++) {
        out << a.str[i];
    }
    return out;
}

int main()
{
    cout << "CString Class Testing Suite" << endl;


    cout << "\n1. Testing Initialization & Assignment:" << endl;
    CString s1("Hello");
    CString s2;
    
    s2 = s1; 
    CString s3(s1); 
    
    cout << "Original (s1): " << s1 << endl;
    cout << "Assigned Copy (s2 = s1): " << s2 << endl;
    cout << "Constructed Copy (s3): " << s3 << endl;

    
    cout << "\n2. Testing Concatenation Operators:" << endl;
    CString space(" ");
    CString world("World");
    
    CString combined = s1 + space + world + "!"; 
    cout << "Operator+ Result: " << combined << endl;

    CString appendStr("OOP");
    appendStr += " Sem2"; 
    appendStr += space;
    appendStr += s1;     
    cout << "Operator+= Result: " << appendStr << endl;

    
    cout << "\n3. Testing Indexing & Element Access:" << endl;
    cout << "Character at index 1: " << combined[1] << endl;
    combined[0] = 'h'; 
    cout << "After Modification []: " << combined << endl;
    cout << "Access via at(6): " << combined.at(6) << endl;

    
    cout << "\n4. Testing Substring & Search Methods:" << endl;
    CString searchStr("programming");
    cout << "Target String: " << searchStr << endl;
    cout << "Find character 'g': Index " << searchStr.find('g') << endl;
    cout << "Find substring \"gram\": Index " << searchStr.find("gram") << endl;
    
    CString leftPart = searchStr.left(4);
    CString rightPart = searchStr.right(4);
    cout << "Left(4) Extract: " << leftPart << endl;
    cout << "Right(4) Extract: " << rightPart << endl;

    
    cout << "\n5. Testing Insert & Remove Methods:" << endl;
    CString mutStr("DataStructure");
    cout << "Base String: " << mutStr << endl;
    
    mutStr.insert(4, "And");
    cout << "After Substring Insert: " << mutStr << endl;
    
    mutStr.insert(0, '_');
    cout << "After Character Insert: " << mutStr << endl;
    
    mutStr.remove(1, 4); 
    cout << "After Index Remove (4): " << mutStr << endl;
    
    mutStr.remove('r');  
    cout << "After Char Remove ('r'): " << mutStr << endl;

    
    cout << "\n6. Testing Case & Reversal Utilities:" << endl;
    CString caseStr("C++ Programming");
    cout << "Original Text: " << caseStr << endl;
    
    caseStr.makeUpper();
    cout << "Upper Case: " << caseStr << endl;
    
    caseStr.makeLower();
    cout << "Lower Case: " << caseStr << endl;
    
    caseStr.reverse();
    cout << "Reversed String: " << caseStr << endl;

    
    cout << "\n7. Testing Trim Operations:" << endl;
    CString trimStr("   Data   ");
    cout << "Raw Padded String: [" << trimStr << "]" << endl;
    
    trimStr.trim();
    cout << "Fully Trimmed String: [" << trimStr << "]" << endl;

  
    cout << "\n8. Testing Equality & Comparison:" << endl;
    CString comp1("apple");
    CString comp2("apple");
    CString comp3("banana");
    
    cout << "Comparing 'apple' with 'apple': " << comp1.isEqual(comp2) << " (0 means equal)" << endl;
    cout << "Comparing 'apple' with 'banana': " << comp1.isEqual(comp3) << endl;
    cout << "Comparing 'apple' with \"apple\": " << comp1.isEqual("apple") << " (0 means equal)" << endl;
    
    cout << "\nTesting Completed Successfully" << endl;

    return 0;
}

