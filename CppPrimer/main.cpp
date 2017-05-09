#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>
//#include "chapter6.h"
#include "salesdata.h"
#include "person.h"
#include "ex7_23.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ///////////////////////////////////////////////////////////Chapter 3//////////////////////////////////////////
//    3.2
//    for(string str;getline(cin,str);cout<<str<<endl);
//    for(string str;cin>>str;cout<<str<<endl);

//    3.4
//    string s1, s2;
//    while(cin >> s1 >> s2)
//    {
//        if(s1==s2)
//            cout << "The two strings are equal" << endl;
//    else if(s1.size()>s2.size())
//            cout << "First string is bigger in size" << endl;
//        else
//            cout << "Second string is bigger in size" << endl;
//    }

//    3.5
//    string concat;
//    for(string buffer;cin>>buffer;concat+=buffer);
//    cout << "The concatenated string is " << concat;

//    3.6
//    string s("Fear is a mind killer.");
//    for(char c:s)
//        c = 'X';
//    cout << s << endl;

//    3.8
//    string s("Fear is a mind killer.");
////    auto i = s.size()-s.size();
////    while(i<s.size())
////    {
////        s[i]='X';
////        i++;
////    }
//    cout << s << endl;

//    for (auto j = 0; j!=s.size();++j)
//        s[j] = 'X';
//    cout << s << endl;

//    3.10
//    cout << "Enter a string of characters including punctuation." << endl;
//        for (string s; getline(cin, s); cout << endl)
//            for (auto i : s)
//                if (!ispunct(i)) cout << i;

//    3.14
//    vector<int> v;
//    for(int i =0; cin >> i; v.push_back(i));
//    for(auto c : v)
//        cout << c;

//    3.15
//    vector<string> vstr;
//    for(string str;getline(cin,str);vstr.push_back(str));


//    3.20
//    vector<int> v;
//    for(auto i =0; cin >> i; v.push_back(i));

//    auto i = v.begin(), j = v.end();
//    cout << *i << endl << *(j-1) << endl;

//    while(i!=j)
//    {
//        cout << *i + *(j-1) << endl;
//        i++; j--;
//    }

//    3.22

//    vector<string> v;
//    //Read in the paragraph
//    for(string i; getline(cin,i); v.push_back(i));

//    for (auto it = v.begin(); it!=v.end(); ++it)
//    {
//        string s = *it;
//        for (auto it2 = s.begin();it2!=s.end();++it2)
//            *it2 = toupper(*it2);
//        cout << s << endl;
//    }

//    3.23
//    vector<int> v(10,1);
//    for(auto i=v.begin();i!=v.end();i++)
//        *i *= 2;

//    for(auto i:v)
//        cout << i;

//    3.25
//    vector<unsigned> scores(11, 0);
//        for (unsigned grade; cin >> grade;/* */)
//            if (grade <= 100)
//                ++*(scores.begin() + grade / 10);

//        for (auto s : scores)
//            cout << s << " ";
//    cout << endl;

//    3.31 and 3.32
//    int arr[10];
//    for(int i = 0; i<10;++i)
//        arr[i] = i+1;


//    for(auto i =0; i!=10; ++i)
//        brr[i] = arr[i];

//    3.40
//    const char cstr1[]="Hello";
//    const char cstr2[]="world!";


//    const size_t new_size = strlen(cstr1) + strlen(" ") + strlen(cstr2) +1;
//    char cstr3[new_size];

//    strcpy(cstr3, cstr1);
//    strcat(cstr3, " ");
//    strcat(cstr3, cstr2);

//    std::cout << cstr3 << std::endl;

    ////////////////////////////////////////////////////Chapter 5///////////////////////////////////////////////////////




//    5.9
//    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
//    char ch;
//    while (cin >> ch)
//    {
//        if (ch == 'a') ++aCnt;
//        else if (ch == 'e') ++eCnt;
//        else if (ch == 'i') ++iCnt;
//        else if (ch == 'o') ++oCnt;
//        else if (ch == 'u') ++uCnt;
//    }
//    cout << "Number of vowel a: \t" << aCnt << '\n'
//        << "Number of vowel e: \t" << eCnt << '\n'
//        << "Number of vowel i: \t" << iCnt << '\n'
//        << "Number of vowel o: \t" << oCnt << '\n'
//        << "Number of vowel u: \t" << uCnt << endl;

//    5.12
//       unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
//       char ch, prech = '\0';
//       while (cin >> std::noskipws >> ch)
//       {
//           switch (ch)
//           {
//               case 'a':
//               case 'A':
//                   ++aCnt;
//                   break;
//               case 'e':
//               case 'E':
//                   ++eCnt;
//                   break;
//               case 'i':
//                   if (prech == 'f') ++fiCnt;
//               case 'I':
//                   ++iCnt;
//                   break;
//               case 'o':
//               case 'O':
//                   ++oCnt;
//                   break;
//               case 'u':
//               case 'U':
//                   ++uCnt;
//                   break;
//               case ' ':
//                   ++spaceCnt;
//                   break;
//               case '\t':
//                   ++tabCnt;
//                   break;
//               case '\n':
//                   ++newLineCnt;
//                   break;
//               case 'f':
//                   if (prech == 'f') ++ffCnt;
//                   break;
//               case 'l':
//                   if (prech == 'f') ++flCnt;
//                   break;
//           }
//           prech = ch;
//   }

//    5.17
//    vector<int> l = {0,0,1,1,2};
//    vector<int> r = {0,1,1,2,3,5,8};

//    int lower = 0;

//    if (l.size()<r.size())
//        lower = l.size();
//    else
//        lower = r.size();

//    for(auto i =0; i!=lower;++i)
//    {
//        if(l[i]!=r[i])
//        {
//            cout << "False" << endl;
//            break;
//        }
//        else if(i==lower-1)
//            cout << "True" << endl;

//    }

//    5.19
//    string rsp;
//       do {
//           cout << "Input two strings: ";
//           string str1, str2;
//           cin >> str1 >> str2;
//           cout << (str1 <= str2 ? str1 : str2)
//                << " is less than the other. " << "\n\n"
//                << "More? Enter yes or no: ";
//           cin >> rsp;
//   } while (tolower(rsp[0]) == 'y');

//    5.20 and 5.21
//    string str;
//    string prev_str;
//    int flag=0;
//    while(cin >> str)
//    {
//        char c = str[0];
//        if(prev_str[0]==str[0] && isupper(c))
//        {
//            cout << "The repeated word is:" << str << endl;
//            flag = 1;
//            break;

//        }
//        prev_str = str;
//    }

//    if(flag==0)
//        cout << "No word was repeated." << endl;

//////////////////////////////////////////////////Chapter 6///////////////////////////////////////////////////////////////////

//    6.3
//    cout << fact(-5) << endl;

//    6.7
//    for(int i=0;i<10;i++)
//        cout << func();

//    6.21
//    int i = 7;
//    cout << new_func(6,&i) << endl;

//    6.22
//    int p1 = 10;
//    int p2 = 11;

    //////////////////////////////////////////////////Chapter 7///////////////////////////////////////////////////////////////////
//  7.1

//        Sales_data total;
//        if(cin >> total.bookNo >> total.units_sold >> total.revenue)
//        {
//            Sales_data temp;
//            while(cin >> temp.bookNo >> temp.units_sold >> temp.revenue)
//            {
//                if(total.bookNo == temp.bookNo)
//                {
//                    total.units_sold += temp.units_sold;
//                    total.revenue += temp.revenue;
//                }
//                else
//                {
//                    cout << total.bookNo << total.units_sold << total.revenue << endl;
//                    total = temp;
//                }
//            }
//        }
//        else
//        {
//            cerr << "No data" << endl;
//            return -1;
//        }

//    7.2 and 7.3
//    Sales_data total;
//    if(cin >> total.bookNo >> total.units_sold >> total.revenue)
//    {
//        Sales_data temp;
//        while(cin >> temp.bookNo >> temp.units_sold >> temp.revenue)
//        {
//            if(total.isbn()==temp.isbn())
//            {
//                total.combine(temp);
//            }
//            else
//            {
//                cout << total.bookNo << total.units_sold << total.revenue << endl;
//                total = temp;

//            }
//        }
//         cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
//    }
//    else
//    {
//        cerr << "No input data" << endl;
//    }

//    7.5
//    Person me;
//    cout << me.get_address() << endl;

//    Sales_data total;
//        if (read(std::cin, total))
//        {
//            Sales_data trans;
//            while (read(std::cin, trans)) {
//                if (total.isbn() == trans.isbn())
//                    total.combine(trans);
//                else {
//                    print(std::cout, total) << std::endl;
//                    total = trans;
//                }
//            }
//            print(std::cout, total) << std::endl;
//        }
//        else
//        {
//            std::cerr << "No data?!" << std::endl;
//            return -1;
//        }

//    7.11
//    Sales_data obj1;
//    string book_no = "abc";
//    Sales_data obj2(book_no);
//    Sales_data obj3(book_no,10,100);
//    Sales_data obj4(std::cin);

//    7.13
//    Sales_data total(std::cin);
//    if(!total.isbn().empty())
//    {
//        std::istream &is = std::cin;
//        while(is)
//        {
//            Sales_data trans(is);
//            if(total.isbn()==trans.isbn())
//            {
//                total.combine(trans);
//            }
//            else
//            {
//                total = trans;
//            }
//        }
//    }
//    else
//    {
//        std::cerr << "No data" << endl;
//        return -1;
//    }

//    7.15
//    Person p1;
//    Person p2("Karan","404 S");
//    Person p3("Karan");
//    Person p4(cin);


    return 0;

}

