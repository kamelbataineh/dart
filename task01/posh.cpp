#include <iostream>
#include <stack>
#include <string>
using namespace std;

float ch_and_num(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

 float T_F(char ch)
 {
    switch (ch) 
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
    }
}

int symbols(char ch)
{
    switch (ch)
    {
        case '^':
            return 4;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        default:
            return 0;
    }
}

string infix_To_Postfix(string infix)
{
    stack<char> s;
    string postfix;
    cout << "Infix string= " << infix << endl;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch_and_num(ch))
        {
            postfix += ch;
            cout << "get " << ch << endl;
        }
        else if (ch == '(')
        {
            s.push(ch);
            cout << "push(" << endl;
        }
        else if (ch == ')') 
        {
            while (!s.empty() && s.top() != '(')
            {
                char top = s.top();
                s.pop();
                postfix += top;
                cout << "pop " << top << endl;
            }

            if (s.empty()) 
            {
                return "Invalid expression";
            }
            else
            {
                s.pop();
            }
        }
        else if (T_F(ch))
        {
            while (!s.empty() && symbols(ch) <= symbols(s.top())) 
            {
                char top = s.top();
                s.pop();
                postfix += top;
                cout << "pop " << top << endl;
            }

            s.push(ch);
            cout << "push" << ch << endl;
        }
    }

    while (!s.empty())
    {
        char top = s.top();
        s.pop();
        postfix += top;
        cout << "Pop " << top << endl;
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Input: ";
    getline(cin, infix);

    string postfix = infix_To_Postfix(infix);

    cout << "Postfix string" << endl << postfix << endl;

    return 0;
}
