#include <iostream>
#include <cstring>
#include <stack>
#include <cstdlib>

using namespace std;

string convertToPostfix (string);
int evaluatePostfix (string);
int pres (char);

int main() {
    string str;
    int res;
	//cout<<"Enter the expression in infix (with/without) paranthesis"<<endl;
	cin>>str;
	
	str=convertToPostfix(str);
	cout<<"Postfix expression is "<<endl<<str<<endl;
	
	res=evaluatePostfix(str);
	cout<<"Result is "<<res;
	return 0;
}

string convertToPostfix (string str){
    int len=str.length();
    stack <char> s;
    string post;
    
    for(int i=0;i<len;i++){
        if(str[i]=='(')
            s.push('(');
            
        else if(str[i]==')'){
            while(!s.empty() and s.top()!='('){
                post+=s.top();
                s.pop();
            }
            s.pop();
        }
        
        else if(str[i]=='+' or str[i]=='-' or str[i]=='/' or str[i]=='*'){
            if( s.empty()==true or s.top()=='(' or (pres(str[i]) > pres(s.top())))
                s.push(str[i]);
                 
            else{
                while(!s.empty() and pres(str[i]) <= pres(s.top()) and s.top()!='('){
                    post+=s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
        
        else{
            post+=str[i];
        }
        //cout<<"entered"<<endl;
    }
    
    while(!s.empty()){
        post+=s.top();
        //cout<<s.top()<<endl;
        s.pop();
    }
    
    return post;
}

int evaluatePostfix (string str){
    stack <int> s;
    int op1,op2;
    for(int i=0;i<str.size();i++){
        if(str[i]=='+' or str[i]=='-' or str[i]=='*' or str[i]=='/'){
            op2=s.top();
            s.pop();
            op1=s.top();
            s.pop();
            
            switch(str[i]){
                case '+': s.push(op1+op2);
                          break;
                case '-': s.push(op1-op2);
                          break;
                case '/': s.push(op1/op2);
                          break;
                case '*': s.push(op1*op2);
                          break;
            }
        }
        
        
        else{
            s.push(str[i]-'0');
        }
    }
    
    return s.top();
}

int pres(char c){
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
}
