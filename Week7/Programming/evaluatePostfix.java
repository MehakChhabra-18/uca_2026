import java.util.*;

public class evaluatePostfix {
    public static int evalPostfix(String str)
    {
        Stack<Integer> st=new Stack<>();
        String[] tokens=str.split(" ");
        for(int i=0;i<tokens.length;i++)
        {
            String token=tokens[i];
            if(Character.isDigit(token.charAt(0)))
            {
                st.push(Integer.parseInt(token));
            }
            else
            {
                int val2=st.pop();
                int val1=st.pop();
                switch(token)
                {
                    case "+":
                        st.push(val1+val2);
                        break;
                    case "-":
                        st.push(val1-val2);
                        break;
                    case "*":
                        st.push(val1*val2);
                        break;
                    case "/":
                        st.push(val1/val2);
                        break;
                }
            }
        }

        return st.pop();
    }
    public static void main(String[] args)
    {
        String str="2 3 1 * + 9 -";
        System.out.print(evalPostfix(str));
    }
}
