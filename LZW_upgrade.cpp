#include <bits/stdc++.h>
using namespace std;


vector<pair<int, char>> encoding(string s1)
{   
    
    /*
      Nén xâu s1
   */
    cout << "Encoding\n"; 
    unordered_map<string, int> table; 
    string p = "";
    string c;

    int cnt = 0;
    vector<pair<int, char>> encode;
    cout << "Input\tIndex\tString\n"; 
    for (int i = 0; i < s1.length(); i++) {

        /*
            Kiểm tra xem p có tồn tại trong bảng chưa
            Nếu tồn tại thì p = p + s1[i]
            Còn không thì ta thêm vào mảng encode(vị trí của p trong bảng, s1[i]) và thêm p + s1[i] vào bảng
        */

        if (p == "") {
            p += s1[i];
            if (table.find(p) == table.end()) {
                cnt++;
                encode.push_back({0, s1[i]});
                table[p] = cnt;
                p = "";
                cout << s1[i] << "\t" << cnt << "\t" <<"(0," << s1[i] << ')'<< endl;  
            }
        }

        else {
            if (table.find(p + s1[i]) != table.end()) {
                p += s1[i];
            }
            else {
                cnt++;
                encode.push_back({table[p], s1[i]});
                table[p + s1[i]] = cnt;
                cout << p << "\t" << cnt << "\t" <<'(' << table[p] << ',' << s1[i] << ')'<< endl;  
                p = "";
            }
        }
    }
    for (auto i : encode) {
        cout << i.first << i.second << " ";
    }
    cout << endl;
    return encode;
}

void decoding(vector<pair<int, char>> encode)
{   
    /*
        Giải nén chuỗi bị nén
    */
    cout << "\nDecoding\n"; 
    string decode = "";
    unordered_map<int,string> table;
    int cnt = 0;
    for (auto i : encode) {
        /*
            Với mỗi cặp bị nén ở dạng (vị trí p, kí tự c) ta chỉ cần lấy xâu đang ở vị trí p trong bảng rồi 
            cộng thêm c là ra được 1 xâu con. Cứ làm như vậy cho tới hết.
        */
        if (i.first == 0) {
            cnt++;
            decode += i.second;
            table[cnt] = i.second;
        }
        else{
            cnt++;
            decode += table[i.first] + i.second;
            table[cnt] = table[i.first] + i.second;
        }
    }
    cout << decode << endl;

}
int main()
{

    string s = "ABBCBCABABCAABCAAB";
    vector<pair<int, char>> encode;
    encode = encoding(s);
    decoding(encode);
    
}
