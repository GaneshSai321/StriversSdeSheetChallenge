bool match(char a, char b) {
  if (a == '[' && b == ']')
    return true;
  if (a == '(' && b == ')')
    return true;
  if (a == '{' && b == '}')
    return true;
  return false;
}

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    for(int i=0;i<expression.length();i++){
        char ch= expression[i];
        if(ch=='['||ch=='{'||ch=='(') st.push(ch);
        else{
            if(st.empty()) return false;
            char topchar=st.top();
            // cout<<ch<<topchar<<endl;
            if(!match(topchar,ch)) return false;
            else st.pop();
        }
    }
     return st.empty();
}