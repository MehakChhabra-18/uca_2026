import java.util.*;

class balancedParenthesis
{
    public static boolean isBalanced(String str)
    {
        Stack<Character> st=new Stack<>();
        for(int i=0;i<str.length();i++)
        {
            char ch=str.charAt(i);
            if(ch=='('||ch=='{'||ch=='[')
            {
                st.push(ch);
            }
            else
            {
                if(st.isEmpty()) return false;
                char top=st.peek();
                if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='['))
                {
                    st.pop();
                }
            }
        }

        return st.isEmpty();
    }
    public static void main(String[] args)
    {
        String str="[()]{}{()()}";
        System.out.println(isBalanced(str));
    }
}