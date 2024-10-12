#include<iostream>
#include<stack>
using namespace std;
int minElementRequired(string s){
    stack<char>st;
    int count=0;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char top = st.top();
                if(ch=='(' && top ==')'){
                    st.pop();
                }
                else if(ch=='{' && top=='}'){
                    st.pop();
                }
                else if(ch=='[' && top==']'){
                    st.pop();
                }
                else{
                    count++;
                }
            }
            else{
                count++;
            }
        }
    }
    int size = st.size();
    int ans = size + count;
    return size;
}
int main(){
    string s = "((";

    cout<<"Minimum elements required are:"<<minElementRequired(s);
    

return 0;
}
