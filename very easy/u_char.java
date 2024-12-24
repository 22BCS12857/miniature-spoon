


class Solution {
    public int firstUniqChar(String s) {
        int[] alphabet = new int[26];
        char[] charArray = s.toCharArray();
        for (int i = 0; i < charArray.length; i++) {
            alphabet[charArray[i] - 'a']++;
        }
        for (int i = 0; i < charArray.length; i++) {
            if (alphabet[charArray[i] - 'a'] == 1) return i;
        }
        return -1;
    }
}
public class u_char {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "aabb";
        int result = sol.firstUniqChar(s);
        System.out.println("The first unique character in the string is at: " + result);
    }
}

