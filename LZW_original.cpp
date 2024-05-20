#include <bits/stdc++.h> 
using namespace std; 

vector<int> encoding(string s1) 
{  
   /*
      Nén xâu s1
   */
   cout << "Encoding\n"; 
   unordered_map<string, int> table;
   /*
      Chuẩn bị trước một bảng gồm các kí tự đơn
   */ 
   for (int i = 0; i <= 255; i++) { 
      string ch = ""; 
      ch += char(i); 
      table[ch] = i; 
   } 

   string p = "", c = ""; 
   p += s1[0]; 
   int code = 256; 
   vector<int> output_code; 
   cout << "String\tOutput_Code\tAddition\n"; 
   for (int i = 0; i < s1.length(); i++) { 
      if (i != s1.length() - 1) 
         c += s1[i + 1]; 
      /*
         Nếu p + c đã xuất hiện trong bảng thì p = p + c
      */
      if (table.find(p + c) != table.end()) { 
         p = p + c; 
      } 
      else { 
         /*
            Nếu không thì ta thêm p vào mảng output_code và thêm p + c vào bảng
         */
         cout << p << "\t" << table[p] << "\t\t" << p + c << "\t" << code << endl; 
         output_code.push_back(table[p]); 
         table[p + c] = code; 
         code++; 
         p = c; 
      } 
      c = ""; 
   } 
   cout << p << "\t" << table[p] << endl; 
   output_code.push_back(table[p]); 
   return output_code; 
} 

void decoding(vector<int> op) 
{ 

   /*
      Giải nén chuỗi đã bị mã hoá
   */
   cout << "\nDecoding\n"; 
   unordered_map<int, string> table;

   /*
      Chuẩn bị trước 1 bảng gồm các kí tự đơn, ngược lại so với nén
   */

   for (int i = 0; i <= 255; i++) { 
      string ch = ""; 
      ch += char(i); 
      table[i] = ch; 
   } 
   int old = op[0], n;        // gán old = số đầu tiên trong chuỗi bị nén
   string s = table[old];     // Thêm kí tự đầu tiên vào chuỗi giải nén 
   string c = ""; 
   c += s[0];                 // c = kí tự đầu tiên
   cout << s; 
   int count = 256; 
   for (int i = 0; i < op.size() - 1; i++) { 
      n = op[i + 1]; 
      /* 
         n = kí tự kế tiếp 
         Nếu n chưa xuất hiện trong bảng
         Thì ta gán s = s + c
         Nếu xuất hiện rồi thì ta thêm table[old] + c vào bảng rồi gán old = n
      */
      if (table.find(n) == table.end()) { 
         s = table[old];  
         s = s + c;
      } 
      else { 
         s = table[n]; 
      } 
      cout << s; 
      c = ""; 
      c += s[0];                       
      table[count] = table[old] + c;   
      count++;                         
      old = n;                         
   } 
   cout << endl;
} 
int main()  
{  
   freopen("test.inp", "r", stdin);
   freopen("test.out", "w", stdout);
   string s;
   cin >> s;
   vector<int> output_code = encoding(s); 
   cout << "Output Codes are: "; 
   for (int i = 0; i < output_code.size(); i++) { 
      cout << '<' << output_code[i] << "> "; 
   } 
   cout << endl; 
   decoding(output_code);
    
} 
