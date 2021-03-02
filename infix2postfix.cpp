#include<stdio.h>
#include<stack>
/*
 * 利用栈将中缀表达式转换为后缀表达式.
 * 为方便起见,用英文字母a-zA-Z代替数字,加减乘除和括号:['+','-','*','/','(',')']
 * 乘法符号可为x或*,除法符号可为÷或/,故用全局常量替代.
 * 不处理用户输入异常的情况.
 * eg:a*b+c ==> a b * c +
 */

using namespace std;

const char mulSign='*';
const char divSign='/';

//操作符优先级比较,a>b返回true,否则返回false.
bool operatorPriority(char a,char b){
    if((a==mulSign || a==divSign) && (b=='+' || b=='-'))//a为乘除且b为加减,则a优先级高于b
        return true;
    else
        return false;
}

//判断字符是否是字母,是字母返回true,否则返回假.
bool isLetter(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        return true;
    else
        return false;
}
int main(){
    stack<char> NumOperator;
    char ch=0;
    while((ch=getchar())!='\n'){
        if(isLetter(ch)){//是字母,原样输出.
            printf("%c ",ch);
        } else{//非字母
            if(NumOperator.empty())//栈空则直接压栈.
                NumOperator.push(ch);
            else {//栈非空,处理括号或比较运算符的优先级.
                if(ch=='('){
                    NumOperator.push(ch);
                } else if(ch==')'){
                    char temp;
                    while((temp=NumOperator.top())!='('){
                        printf("%c ",temp);
                        NumOperator.pop();
                    }
                    NumOperator.pop();//遇到')'时,要抛弃一次最近的'('符号.
                } else if(NumOperator.top()=='('){
                    NumOperator.push(ch);
                } else if(operatorPriority(ch,NumOperator.top())){
                    //当前操作符优先级比栈顶操作符优先级高则直接压栈
                    //否则先弹出并输出栈顶元素然后再压栈--在这里犯了一个bug,2021年03月02日14:24:09
                    //有一个措施是循环弹出并输出所有的栈顶比当前操作符优先级高或相等的操作符,但我认为在数学上
                    //相同优先级的操作符无所谓谁先谁后,故只必须把栈内优先级高的操作符输出出去.
                    NumOperator.push(ch);
                } else{
                    printf("%c ",NumOperator.top());
                    NumOperator.pop();
                    NumOperator.push(ch);
                }
            }
        }
    }
    while(!NumOperator.empty()){
        printf("%c ",NumOperator.top());
        NumOperator.pop();
    }
    printf("\n");
}    
