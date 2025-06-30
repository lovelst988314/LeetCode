#include<iostream>
#include<string>

using namespace std;

int longestPalindrome(string s) {
        int num1[26] = {0}, num2[26] = {0}, result = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                num1[s[i]-'a']++;
            }
            if(s[i] >= 'A' && s[i] <= 'Z') {
                num2[s[i]-'A']++;
            }
        }
        for(int i = 0; i < 26; i++) {
            cout << "num1: " << num1[i] << "  num2: " << num2[i] << endl;
        }
        for(int i = 0; i < 26; i++) {
            if(num1[i]%2 == 0) {
                result += num1[i];
            } else {
                result += num1[i]-1;
            }
            if(num2[i]%2 == 0) {
                result += num2[i];
            } else {
                result += num2[i]-1;
            }
    }
    return result+1;
}
//回文选取字符是可以选奇数个字符中的偶数

int main () {
    string str = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    cout << str.size() << endl;;
    cout << longestPalindrome(str) <<endl;
    return 0;
}