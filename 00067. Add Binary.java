
//Accepted	376 ms	java
public class Solution {
    public String addBinary(String a, String b) {
        StringBuffer sb = new StringBuffer();
        if(a.length() > b.length())
        {
            String tmp = a;
            a = b;
            b = tmp;
        }
        
//        System.out.println("a : " + a + "\nb : " + b);
        star = 1;
        base = 0;
        carry = 0;
        while(star <= a.length())
        {
            base = (a.charAt(a.length()-star)-'0') + (b.charAt(b.length()-star)-'0');
            base += carry;
            carry = base / 2;
            base = base % 2;
            sb.append(base);
            star++;
        }
        
        while(star <= b.length())
        {
            base = carry + (b.charAt(b.length() - star)-'0');
            carry = base / 2;
            base = base % 2;
            sb.append(base);
            star++;
        }
        if(carry == 1)
            sb.append(carry);
        sb.reverse(); 
        return sb.toString();
    }
    private int base,carry,star;
}
