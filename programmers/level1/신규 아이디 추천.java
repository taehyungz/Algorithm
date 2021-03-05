class Solution {
    public String solution(String new_id) {
        String answer = new NewIdRec(new_id)
            .LowerCase()
            .removeChr()
            .removeDoubleDot()
            .removeFBDot()
            .changeEmptyString()
            .tooLong()
            .tooShort()
            .getResult();
        
        return answer;
        
    }
    
    public static class NewIdRec {
        private String str;
        
        NewIdRec(String str) {
            this.str = str;
        }
        
        public NewIdRec LowerCase() {
            this.str = this.str.toLowerCase();
            return this;
        }
        
        public NewIdRec removeChr() {
            StringBuilder builder = new StringBuilder();
            for(int i = 0; i < this.str.length(); i++) {
                char ch = this.str.charAt(i);
                if ((ch >= '0' && ch<='9') || (ch >= 'a' && ch <= 'z') || ch=='-' || ch=='_' || ch=='.') {
                    builder.append(ch);
                }
            }
            this.str = builder.toString();
            return this;
        }
        
        public NewIdRec removeDoubleDot() {
            StringBuilder builder = new StringBuilder();
            for(int i=0;i<this.str.length();i++) {
                if(this.str.charAt(i)=='.') {
                    while(i < this.str.length() && this.str.charAt(i)=='.') i++;
                    builder.append(".");
                    i--;
                } else builder.append(this.str.charAt(i));
            }
            this.str = builder.toString();
            return this;
        }
        
        public NewIdRec removeFBDot() {
            if(this.str.startsWith(".")) this.str = this.str.substring(1);
            if(this.str.endsWith(".")) this.str = this.str.substring(0, this.str.length()-1);
            return this;
        }
        
        public NewIdRec changeEmptyString() {
            if(this.str.equals("")) this.str = "a";
            return this;
        }
        
        public NewIdRec tooLong() {
            if(this.str.length() >=16 && this.str.charAt(14)=='.') this.str = this.str.substring(0,14);
            else if(this.str.length() >= 16) this.str = this.str.substring(0,15);
            return this;
            
        }
        
        public NewIdRec tooShort() {
            if(this.str.length() <=2) {
                int diff = 3 - this.str.length();
                if(diff==1) this.str = this.str + this.str.charAt(this.str.length()-1);
                else this.str = this.str + this.str.charAt(this.str.length()-1) + this.str.charAt(this.str.length()-1);
            }
            return this;
        }
        public String getResult() {
            return this.str;
        }
        
    }
}