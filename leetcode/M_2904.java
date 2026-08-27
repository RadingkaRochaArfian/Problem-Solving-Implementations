import java.util.Scanner;

class Solution {
    public static String shortestBeautifulSubstring(String s, int k) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1')
                total++;
        }
        if (total < k)
            return "";
        String ans = s;
        var cnt = 0;
        var l = 0;
        for (int r = 0; r < s.length(); r++) {
            cnt += s.charAt(r) - '0';
            while (cnt > k || s.charAt(l) == '0') {
                cnt -= s.charAt(l++)-'0';
            }
            if (cnt == k) {
                var temp = s.substring(l, r + 1);
                if (temp.length() < ans.length()
                        || (temp.length() == ans.length() && temp.compareTo(ans)<0)) {
                            ans=temp;
                }
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println(shortestBeautifulSubstring(in.next(), in.nextInt()));
    }
}