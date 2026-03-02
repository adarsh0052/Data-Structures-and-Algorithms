class Solution {
    public boolean isPalindrome(String s) {
        int st = 0;
        int e = s.length() - 1;
        while (st < e) { 
            char startChar = s.charAt(st);
            char endChar = s.charAt(e);
            if (!Character.isLetterOrDigit(startChar)) {
                st++;
                continue; 
            }
            if (!Character.isLetterOrDigit(endChar)) {
                e--;
                continue; 
            }
            if (Character.toLowerCase(startChar) != Character.toLowerCase(endChar)) {
                return false; 
            }
            st++;
            e--;
        }
        return true; 
    }
}